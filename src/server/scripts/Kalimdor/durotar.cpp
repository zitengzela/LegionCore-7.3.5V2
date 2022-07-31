/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ObjectMgr.h"
#include "Vehicle.h"
#include "Creature.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "TransportMgr.h"


/*######
## Quest 25134: Lazy Peons
## npc_lazy_peon
######*/

enum LazyPeonYells
{
	SAY_SPELL_HIT = 2
};

enum LazyPeon
{
	QUEST_LAZY_PEONS = 37446,
	GO_LUMBERPILE = 175784,
	SPELL_BUFF_SLEEP = 17743,
	SPELL_AWAKEN_PEON = 19938
};

class npc_lazy_peon : public CreatureScript
{
public:
	npc_lazy_peon() : CreatureScript("npc_lazy_peon") { }

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_lazy_peonAI(creature);
	}

	struct npc_lazy_peonAI : public ScriptedAI
	{
		npc_lazy_peonAI(Creature* creature) : ScriptedAI(creature)
		{
			Initialize();
		}

		void Initialize()
		{
			RebuffTimer = 0;
			work = false;
		}

		uint32 RebuffTimer;
		bool work;

		void Reset() override
		{
			Initialize();
		}

		void MovementInform(uint32 /*type*/, uint32 id) override
		{
			if (id == 1)
				work = true;
		}

		void SpellHit(Unit* caster, const SpellInfo* spell) override
		{
			if (spell->Id != SPELL_AWAKEN_PEON)
				return;

			Player* player = caster->ToPlayer();
			if (player && player->GetQuestStatus(QUEST_LAZY_PEONS) == QUEST_STATUS_INCOMPLETE)
			{
				player->KilledMonsterCredit(me->GetEntry(), me->GetGUID());
				Talk(SAY_SPELL_HIT, caster->GetGUID());
				me->RemoveAllAuras();
				if (GameObject* Lumberpile = me->FindNearestGameObject(GO_LUMBERPILE, 20))
					me->GetMotionMaster()->MovePoint(1, Lumberpile->GetPositionX() - 1, Lumberpile->GetPositionY(), Lumberpile->GetPositionZ());
			}
		}

		void UpdateAI(uint32 diff) override
		{
			if (work == true)
				me->HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);
			if (RebuffTimer <= diff)
			{
				DoCast(me, SPELL_BUFF_SLEEP);
				RebuffTimer = 300000; //Rebuff agian in 5 minutes
			}
			else
				RebuffTimer -= diff;
			if (!UpdateVictim())
				return;
			DoMeleeAttackIfReady();
		}
	};
};


enum VoodooSpells
{
    SPELL_BREW      = 16712, // Special Brew
    SPELL_GHOSTLY   = 16713, // Ghostly
    SPELL_HEX1      = 16707, // Hex
    SPELL_HEX2      = 16708, // Hex
    SPELL_HEX3      = 16709, // Hex
    SPELL_GROW      = 16711, // Grow
    SPELL_LAUNCH    = 16716, // Launch (Whee!)
};

// 17009
class spell_voodoo : public SpellScriptLoader
{
    public:
        spell_voodoo() : SpellScriptLoader("spell_voodoo") {}

        class spell_voodoo_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_voodoo_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_BREW) || !sSpellMgr->GetSpellInfo(SPELL_GHOSTLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX1) || !sSpellMgr->GetSpellInfo(SPELL_HEX2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_HEX3) || !sSpellMgr->GetSpellInfo(SPELL_GROW) ||
                    !sSpellMgr->GetSpellInfo(SPELL_LAUNCH))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellid = RAND(SPELL_BREW, SPELL_GHOSTLY, RAND(SPELL_HEX1, SPELL_HEX2, SPELL_HEX3), SPELL_GROW, SPELL_LAUNCH);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, spellid, false);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_voodoo_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_voodoo_SpellScript();
        }
};

enum eOrgrimmar
{
	QUEST_A_PERSONAL_SUMMONS = 28790,
};

// 52514 
class item_thonks_spyglass_52514 : public ItemScript
{
public:
	item_thonks_spyglass_52514() : ItemScript("item_thonks_spyglass_52514") { }

	bool OnUse(Player* player, Item* item, SpellCastTargets const& targets) override
	{
		if (player->GetQuestStatus(25187) == QUEST_STATUS_INCOMPLETE)
		{
			if (!player->GetReqKillOrCastCurrentCount(25187, 39357))
				player->CastSpell(player, 73741, TRIGGERED_NONE);
			else if (!player->GetReqKillOrCastCurrentCount(25187, 39358))
				player->CastSpell(player, 73763, TRIGGERED_NONE);
			else if (!player->GetReqKillOrCastCurrentCount(25187, 39359))
				player->CastSpell(player, 73764, TRIGGERED_NONE);
			else if (!player->GetReqKillOrCastCurrentCount(25187, 39360))
				player->CastSpell(player, 73765, TRIGGERED_NONE);
		}

		return false;
	}
};

// 39320 Raggan
class npc_durotar_watershed_telescope_39320 : public CreatureScript
{
public:
	npc_durotar_watershed_telescope_39320() : CreatureScript("npc_durotar_watershed_telescope_39320") { }

	enum eQuest
	{
		EVENT_TIMEOUT = 1,
		EVENT_EMOTE = 2,
		EVENT_FINALE = 3,
	};

	struct npc_durotar_watershed_telescope_39320AI : public ScriptedAI
	{
		npc_durotar_watershed_telescope_39320AI(Creature* creature) : ScriptedAI(creature) { }

		ObjectGuid m_playerGUID;
		ObjectGuid m_homeGUID;
		EventMap m_events;
		Position pos;

		void InitializeAI() override
		{
			m_playerGUID = me->GetCharmerOrOwnerOrOwnGUID();
			m_events.ScheduleEvent(EVENT_TIMEOUT, 60000);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
				if (GameObject* gobject = player->FindNearestGameObject(301050, 10.0f))
				{
					pos = player->GetPosition();
					m_homeGUID = gobject->GetGUID();
				}
		}

		void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
		{
			me->SetSpeed(MOVE_RUN, 12.0f);
			me->GetMotionMaster()->MovePath(3932001, false);
		}

		void MovementInform(uint32 type, uint32 pointId) override
		{
			if (type == WAYPOINT_MOTION_TYPE)
				if (pointId == 2)
					m_events.ScheduleEvent(EVENT_EMOTE, 4000);
				else if (pointId == 3)
					m_events.ScheduleEvent(EVENT_FINALE, 1000);
		}

		void UpdateAI(uint32 diff) override
		{
			m_events.Update(diff);

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_TIMEOUT:
				{
					me->DespawnOrUnsummon(100);
					break;
				}
				case EVENT_EMOTE:
				{
					if (Creature* npc = me->FindNearestCreature(39326, 30.0f))
						npc->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
					break;
				}
				case EVENT_FINALE:
				{
					if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
						if (GameObject* go = ObjectAccessor::GetGameObject(*me, m_homeGUID))
						{
							player->KilledMonsterCredit(39357);
							player->ExitVehicle();
							player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation());
							me->DespawnOrUnsummon(100);
						}
					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_durotar_watershed_telescope_39320AI(creature);
	}
};

// 39345 Tekla
class npc_durotar_watershed_telescope_39345 : public CreatureScript
{
public:
	npc_durotar_watershed_telescope_39345() : CreatureScript("npc_durotar_watershed_telescope_39345") { }

	enum eQuest
	{
		EVENT_TIMEOUT = 1,
		EVENT_FINALE = 2,
	};

	struct npc_durotar_watershed_telescope_39345AI : public ScriptedAI
	{
		npc_durotar_watershed_telescope_39345AI(Creature* creature) : ScriptedAI(creature) { }

		ObjectGuid m_playerGUID;
		ObjectGuid m_homeGUID;
		EventMap m_events;
		Position pos;

		void InitializeAI() override
		{
			m_playerGUID = me->GetCharmerOrOwnerOrOwnGUID();
			m_events.ScheduleEvent(EVENT_TIMEOUT, 60000);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
				if (GameObject* gobject = player->FindNearestGameObject(301050, 10.0f))
				{
					pos = player->GetPosition();
					m_homeGUID = gobject->GetGUID();
				}
		}

		void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
		{
			me->SetSpeed(MOVE_RUN, 12.0f);
			me->GetMotionMaster()->MovePath(3934501, false);
		}

		void MovementInform(uint32 type, uint32 pointId) override
		{
			if (type == WAYPOINT_MOTION_TYPE && pointId == 3)
				m_events.ScheduleEvent(EVENT_FINALE, 1000);
		}

		void UpdateAI(uint32 diff) override
		{
			m_events.Update(diff);

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_TIMEOUT:
				{
					me->DespawnOrUnsummon(100);
					break;
				}
				case EVENT_FINALE:
				{
					if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
						if (GameObject* go = ObjectAccessor::GetGameObject(*me, m_homeGUID))
						{
							player->KilledMonsterCredit(39358);
							player->ExitVehicle();
							player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation());
							me->DespawnOrUnsummon(100);
						}
					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_durotar_watershed_telescope_39345AI(creature);
	}
};

// 39346 Misha
class npc_durotar_watershed_telescope_39346 : public CreatureScript
{
public:
	npc_durotar_watershed_telescope_39346() : CreatureScript("npc_durotar_watershed_telescope_39346") { }

	enum eQuest
	{
		EVENT_TIMEOUT = 1,
		EVENT_FINALE = 2,
	};

	struct npc_durotar_watershed_telescope_39346AI : public ScriptedAI
	{
		npc_durotar_watershed_telescope_39346AI(Creature* creature) : ScriptedAI(creature) { }

		ObjectGuid m_playerGUID;
		ObjectGuid m_homeGUID;
		EventMap m_events;
		Position pos;

		void InitializeAI() override
		{
			m_playerGUID = me->GetCharmerOrOwnerOrOwnGUID();
			m_events.ScheduleEvent(EVENT_TIMEOUT, 60000);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
				if (GameObject* gobject = player->FindNearestGameObject(301050, 10.0f))
				{
					pos = player->GetPosition();
					m_homeGUID = gobject->GetGUID();
				}
		}

		void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
		{
			me->SetSpeed(MOVE_RUN, 12.0f);
			me->GetMotionMaster()->MovePath(3934601, false);
		}

		void MovementInform(uint32 type, uint32 pointId) override
		{
			if (type == WAYPOINT_MOTION_TYPE && pointId == 3)
				m_events.ScheduleEvent(EVENT_FINALE, 1000);
		}

		void UpdateAI(uint32 diff) override
		{
			m_events.Update(diff);

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_TIMEOUT:
				{
					me->DespawnOrUnsummon(100);
					break;
				}
				case EVENT_FINALE:
				{
					if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
						if (GameObject* go = ObjectAccessor::GetGameObject(*me, m_homeGUID))
						{
							player->KilledMonsterCredit(39359);
							player->ExitVehicle();
							player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation());
							me->DespawnOrUnsummon(100);
						}
					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_durotar_watershed_telescope_39346AI(creature);
	}
};

// 39347 Zen'Taji
class npc_durotar_watershed_telescope_39347 : public CreatureScript
{
public:
	npc_durotar_watershed_telescope_39347() : CreatureScript("npc_durotar_watershed_telescope_39347") { }

	enum eQuest
	{
		EVENT_TIMEOUT = 1,
		EVENT_FINALE = 2,
	};

	struct npc_durotar_watershed_telescope_39347AI : public ScriptedAI
	{
		npc_durotar_watershed_telescope_39347AI(Creature* creature) : ScriptedAI(creature) { }

		ObjectGuid m_playerGUID;
		ObjectGuid m_homeGUID;
		EventMap m_events;
		Position pos;

		void InitializeAI() override
		{
			m_playerGUID = me->GetCharmerOrOwnerOrOwnGUID();
			m_events.ScheduleEvent(EVENT_TIMEOUT, 60000);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
				if (GameObject* gobject = player->FindNearestGameObject(301050, 10.0f))
				{
					pos = player->GetPosition();
					m_homeGUID = gobject->GetGUID();
				}
		}

		void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
		{
			me->SetSpeed(MOVE_RUN, 12.0f);
			me->GetMotionMaster()->MovePath(3934701, false);
		}

		void MovementInform(uint32 type, uint32 pointId) override
		{
			if (type == WAYPOINT_MOTION_TYPE && pointId == 3)
				m_events.ScheduleEvent(EVENT_FINALE, 1000);
		}

		void UpdateAI(uint32 diff) override
		{
			m_events.Update(diff);

			while (uint32 eventId = m_events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_TIMEOUT:
				{
					me->DespawnOrUnsummon(100);
					break;
				}
				case EVENT_FINALE:
				{
					if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
						if (GameObject* go = ObjectAccessor::GetGameObject(*me, m_homeGUID))
						{
							player->KilledMonsterCredit(39360);
							player->ExitVehicle();
							player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetOrientation());
							me->DespawnOrUnsummon(100);
						}
					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new npc_durotar_watershed_telescope_39347AI(creature);
	}
};

void AddSC_durotar()
{
	new npc_lazy_peon();
	new spell_voodoo();
	new item_thonks_spyglass_52514();
	new npc_durotar_watershed_telescope_39320();
	new npc_durotar_watershed_telescope_39345();
	new npc_durotar_watershed_telescope_39346();
	new npc_durotar_watershed_telescope_39347();
}
