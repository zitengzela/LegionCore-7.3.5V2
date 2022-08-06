/*
	http://uwow.biz
	Kloaka pvp zone
	https://www.wowhead.com/zone=7897/the-underbelly
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "GameEventMgr.h"

enum Spells
{
	NO_GUARDS               = 223202,
	SEWER_GUARDS            = 223203,
	FAIR_GAME               = 223176,
	SUMMON_UNDERBELLY_GUARD = 203892,

	// spells items
	SCREECHER_WHISTLE       = 220260,
	IMP_BINDING_CONTRACT    = 220265,
	WIDOWSISTER_CONTRACT    = 220266,
	CROC_FLUSHER            = 220253,
	UNDERBELLY_BANQUET      = 220021,
	YOUNG_MUTANT_WARTURTLES = 220236,
	FEL_CHUM                = 220237
};

enum Events
{
	EVENT_PVP_ON            = 80,
	EVENT_PVP_OFF           = 81
};

// 97359
class npc_kloaka_capitan : public CreatureScript
{
public:
	npc_kloaka_capitan() : CreatureScript("npc_kloaka_capitan") {}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->KilledMonsterCredit(97359);

		if (creature->isQuestGiver())
			player->PrepareQuestMenu(creature->GetGUID());

		player->ADD_GOSSIP_ITEM_DB(18778, 0, GOSSIP_SENDER_MAIN, 1);

		if (sGameEventMgr->IsActiveEvent(EVENT_PVP_OFF))
			player->ADD_GOSSIP_ITEM_DB(18778, 1, GOSSIP_SENDER_MAIN, 2);
		else if (sGameEventMgr->IsActiveEvent(EVENT_PVP_ON))
		{
			player->ADD_GOSSIP_ITEM_DB(18778, 2, GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM_DB(18778, 3, GOSSIP_SENDER_MAIN, 4);
		}

		player->SEND_GOSSIP_MENU(27321, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();

		switch (action)
		{
		case 1:
			player->GetSession()->SendListInventory(creature->GetGUID());
			player->CLOSE_GOSSIP_MENU();
			break;
		case 2:
			if (!player->HasCurrency(1149, 50))
			{
				player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 1149);
				player->CLOSE_GOSSIP_MENU();
				return false;
			}
            player->CLOSE_GOSSIP_MENU();
			player->ModifyCurrency(1149, -50, true, true);
			creature->AI()->Talk(0);
			creature->AddDelayedEvent(5000, [creature]() -> void
			{
				sGameEventMgr->StopEvent(EVENT_PVP_OFF);
				sGameEventMgr->StartEvent(EVENT_PVP_ON);
			});
			break;
		case 3:
			if (!player->HasCurrency(1149, 50))
			{
				player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY, creature, 1149);
				player->CLOSE_GOSSIP_MENU();
				return false;
			}
			player->CLOSE_GOSSIP_MENU();
			player->ModifyCurrency(1149, -50, true, true);
			creature->AI()->Talk(1);
			creature->AddDelayedEvent(5000, [creature]() -> void
			{
				sGameEventMgr->StopEvent(EVENT_PVP_ON);
				sGameEventMgr->StartEvent(EVENT_PVP_OFF);
			});
			break;
		case 4:
			player->CastSpell(player, SUMMON_UNDERBELLY_GUARD);
			break;
		default:
			break;
		}

		return true;
	}

	struct npc_kloaka_capitanAI : public ScriptedAI
	{
		npc_kloaka_capitanAI(Creature* creature) : ScriptedAI(creature) 
		{
			checkTimer = 300000; //5min
		}

		uint32 checkTimer;

		void UpdateAI(uint32 diff) override
		{
			if (!sGameEventMgr->IsActiveEvent(EVENT_PVP_OFF))
			{
				if (sGameEventMgr->IsActiveEvent(EVENT_PVP_ON))
				{
					if (checkTimer <= diff)
					{
						sGameEventMgr->StopEvent(EVENT_PVP_ON);
						sGameEventMgr->StartEvent(EVENT_PVP_OFF);

						checkTimer = 300000;
					}
					else
						checkTimer -= diff;
				}
			}
			else
				checkTimer = 300000;

			if (!sGameEventMgr->IsActiveEvent(EVENT_PVP_OFF) && !sGameEventMgr->IsActiveEvent(EVENT_PVP_ON))
				sGameEventMgr->StartEvent(EVENT_PVP_OFF);
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_kloaka_capitanAI(creature);
	}
};

// 220260 220265 220266 220253 220021 220236
class spell_kloaka_call_some_adds : public SpellScript
{
	PrepareSpellScript(spell_kloaka_call_some_adds);

	void HandleAfterCast()
	{
		uint32 eventid = 0;
		switch (GetSpellInfo()->Id)
		{
		case SCREECHER_WHISTLE:
			eventid = 82;
			break;
		case IMP_BINDING_CONTRACT:
			eventid = 83;
			break;
		case WIDOWSISTER_CONTRACT:
			eventid = 84;
			break;
		case CROC_FLUSHER:
			eventid = 85;
			break;
		case UNDERBELLY_BANQUET:
			eventid = 200;
			break;
		case YOUNG_MUTANT_WARTURTLES:
			eventid = 201;
			break;
		case FEL_CHUM:
			eventid = 202;
			break;
		default:
			break;
		}

		if (eventid)
			sGameEventMgr->StartEvent(eventid, true);
	}

	void Register() override
	{
		AfterCast += SpellCastFn(spell_kloaka_call_some_adds::HandleAfterCast);
	}
};

class Underbelly_pvp_kill : public PlayerScript
{
public:
	Underbelly_pvp_kill() : PlayerScript("Underbelly_pvp_kill") { }

	void OnPVPKill(Player* killer, Player* killed) override
	{
		if (killed->HasAura(NO_GUARDS) || killed->HasAura(FAIR_GAME))
			killer->ModifyCurrency(1149, urand(15, 50), true, true);
	}
};

class Underbelly_event_controller : public PlayerScript
{
public:
	Underbelly_event_controller() : PlayerScript("Underbelly_event_controller") {}

	void OnUpdate(Player* player, uint32 /*diff*/) override
	{
		if (sGameEventMgr->IsActiveEvent(EVENT_PVP_OFF))
		{
			if (player->GetAreaId() == 7594 || player->GetAreaId() == 7825) // pvp off
			{
				player->RemoveAura(NO_GUARDS);
				player->RemoveAura(FAIR_GAME);
				player->AddAura(SEWER_GUARDS, player);
				return;
			}
			else
				player->RemoveAura(SEWER_GUARDS);
		}

		if (sGameEventMgr->IsActiveEvent(EVENT_PVP_ON))
			if (player->GetAreaId() == 7594 || player->GetAreaId() == 7825) // pvp on
			{
				player->RemoveAura(SEWER_GUARDS);
				player->AddAura(NO_GUARDS, player);
			}
			else
				player->RemoveAura(NO_GUARDS);
	}

	// Fair Game Aura
	void OnUpdateArea(Player* player, uint32 NewArea) override
	{
		if (NewArea == 7825 && player->HasAura(NO_GUARDS))
		{
			player->AddAura(FAIR_GAME, player);
		}
	}
};

struct npc_underbelly_banquet : public ScriptedAI
{
	npc_underbelly_banquet(Creature* creature) : ScriptedAI(creature)
	{
		count = 0;
	}

	uint8 count;

	void OnSpellClick(Unit* clicker) override
	{
		count++;
		if (count >= 25)
			me->DespawnOrUnsummon();
	}
};

void AddSC_Kloaka()
{
	new npc_kloaka_capitan();
	RegisterCreatureAI(npc_underbelly_banquet);

	RegisterSpellScript(spell_kloaka_call_some_adds);

	RegisterPlayerScript(Underbelly_pvp_kill);
	RegisterPlayerScript(Underbelly_event_controller);
};