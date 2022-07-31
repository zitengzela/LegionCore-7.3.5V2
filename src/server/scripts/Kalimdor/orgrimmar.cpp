#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"


enum KingSpells
{
	// King - Garrosh Hellscream
	SPELL_BERSERKER_CHARGE = 84742,
	SPELL_DEMO_SHOUT = 61044,
	SPELL_SHOCKWAVE = 84715,
	SPELL_WHIRLWIND = 84724,
};

enum KingEvents
{
	// King - Garrosh Hellscream
	EVENT_BERSEKER_CHARGE,
	EVENT_DEMO_SHOUT,
	EVENT_SHOCKWAVE,
	EVENT_WHIRLWIND,
};

class npc_garrosh_quest : public CreatureScript
{
public:
	npc_garrosh_quest() : CreatureScript("npc_garrosh_quest") { }

	bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
	{
		if (quest->GetQuestId() == 31013) // The Horde Way
		{
			if (Creature* master = player->SummonCreature(62087, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 300000))
			{
				master->AI()->SetGUID(player->GetGUID());
			}
		}

		return true;
	}
};

class npc_garrosh_the_horde_way : public CreatureScript
{
public:
	npc_garrosh_the_horde_way() : CreatureScript("npc_garrosh_the_horde_way") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_garrosh_the_horde_wayAI(creature);
	}

	struct npc_garrosh_the_horde_wayAI : public ScriptedAI
	{
		npc_garrosh_the_horde_wayAI(Creature* creature) : ScriptedAI(creature) {}

		uint32 phaseId;
		uint32 phaseTimer;
		ObjectGuid playerGUID;

		void Reset()
		{
			phaseId = 0;
			phaseTimer = 2000;
		}

		void SetGUID(ObjectGuid const& guid, int32)
		{
			playerGUID = guid;
		}

		void UpdateAI(const uint32 diff)
		{
			if (playerGUID)
				return;

			if (phaseTimer < diff)
			{
				if (phaseId > 17)
				{
					me->GetMotionMaster()->MovePoint(1, 1634.78f, -4361.15f, 26.76f);
					if (Player * player = Unit::GetPlayer(*me, playerGUID))
						player->KilledMonsterCredit(62089);
					me->ForcedDespawn(5000);
				}

				Talk(phaseId, playerGUID);

				phaseTimer = 6500;
				if (phaseId == 0)
					phaseTimer = 6000;
				else if (phaseId == 5 || phaseId == 7)
					phaseTimer = 5000;
				else if (phaseId == 6)
					phaseTimer = 8500;
				else if (phaseId == 8 || phaseId == 15)
					phaseTimer = 2000;
				else if (phaseId == 11 || phaseId == 14)
					phaseTimer = 4000;
				else if (phaseId == 12)
					phaseTimer = 13000;
				else if (phaseId == 13)
					phaseTimer = 15000;
				++phaseId;
			}
			else
				phaseTimer -= diff;
		}
	};
};

class boss_garrosh_hellscream_orgrimmar : public CreatureScript
{
public:
	boss_garrosh_hellscream_orgrimmar() : CreatureScript("boss_garrosh_hellscream_orgrimmar") { }

	struct boss_garrosh_hellscream_orgrimmarAI : public ScriptedAI
	{
		boss_garrosh_hellscream_orgrimmarAI(Creature* creature) : ScriptedAI(creature) { }

		void Reset() { events.Reset(); }

		void EnterCombat(Unit* /*who*/)
		{
			events.ScheduleEvent(EVENT_BERSEKER_CHARGE, 20000);
			events.ScheduleEvent(EVENT_DEMO_SHOUT, 5000);
			events.ScheduleEvent(EVENT_SHOCKWAVE, 10000);
			events.ScheduleEvent(EVENT_WHIRLWIND, 40000);
		}

		void UpdateAI(const uint32 diff)
		{
			if (!UpdateVictim())
				return;

			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_BERSEKER_CHARGE:
					DoCast(SelectTarget(SELECT_TARGET_FARTHEST, 0, 40.0f, true), SPELL_BERSERKER_CHARGE);
					events.ScheduleEvent(EVENT_BERSEKER_CHARGE, urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
					break;
				case EVENT_DEMO_SHOUT:
					DoCast(SPELL_DEMO_SHOUT);
					events.ScheduleEvent(EVENT_DEMO_SHOUT, urand(50 * IN_MILLISECONDS, 80 * IN_MILLISECONDS));
					break;
				case EVENT_SHOCKWAVE:
					DoCastVictim(SPELL_SHOCKWAVE);
					events.ScheduleEvent(EVENT_SHOCKWAVE, urand(40 * IN_MILLISECONDS, 50 * IN_MILLISECONDS));
					break;
				case EVENT_WHIRLWIND:
					DoCastVictim(SPELL_WHIRLWIND);
					events.ScheduleEvent(EVENT_WHIRLWIND, urand(1 * MINUTE*IN_MILLISECONDS, 2 * MINUTE*IN_MILLISECONDS));
					break;
				}
			}
			DoMeleeAttackIfReady();
		}
	private:
		EventMap events;
	};

	CreatureAI* GetAI(Creature* creature) const
	{
		return new boss_garrosh_hellscream_orgrimmarAI(creature);
	}
};


/*
PANDARIA START EVENT
*/
enum Npcs
{
	NPC_GENERAL_NAZIM = 54870
};
enum eFlameSpoutEvents
{
	EVENT_DARKSCREEN = 1,
	EVENT_MOVIEINTRO = 2,
	EVENT_FLAME_SPOUT_3 = 3
};

enum Quests
{
	QUEST_THE_ART_OF_WAR = 29611,
	QUEST_ALL_ABOARD = 31853
};

enum Spells
{
	SPELL_FADE_TO_BLACK = 130411,
	SPELL_PANDA_INTRO_MOVIE = 130409
};

Position const GeneralPoints[2] =
{
	{ 1667.2f, -4354.32f, 26.3474f, 3.01652f }, // General Nazim Position
	{ 1664.66f, -4354.21f, 26.3546f, 6.22487f }, // Player Teleport Position

};

/*NPC ID */
class npc_general_nazim : public CreatureScript
{
public:
	npc_general_nazim() : CreatureScript("npc_general_nazim") { }

	CreatureAI* GetAI(Creature* creature) const
	{
		return new npc_general_nazimAI(creature);
	}

	struct npc_general_nazimAI : public ScriptedAI
	{
		npc_general_nazimAI(Creature* creature) : ScriptedAI(creature) {}

		EventMap events;
		std::list<uint64> _playerDataList;
		std::list<Player*> _players;
		std::list<uint64> _playersWithSpell;
		uint32 checkTimer;
		ObjectGuid playerGUID;
		Creature* General;
		bool intro;
		bool intro_movie;

		void Reset()
		{
			checkTimer = 2000;
			intro = false;
			intro_movie = false;

		}

		bool IsPlayerOnlist(Player* player, std::list<uint64> &list)
		{
			for (auto _cPlayer : list)
			{
				if (_cPlayer || player->GetGUID())
				{
					return true;
					break;
				}
			}

			return false;
		}

		void SetStageFor(Player* player)
		{
			General = me->SummonCreature(NPC_GENERAL_NAZIM, GeneralPoints[0], TEMPSUMMON_MANUAL_DESPAWN, 0, 0, player->GetGUID());
		}

		void UpdateAI(const uint32 diff)
		{
			events.Update(diff);

			if (checkTimer <= diff)
			{
				if (!intro)
				{
					std::list<Player*> _players;
					GetPlayerListInGrid(_players, me, 10.0f);
					for (auto player : _players)
					{
						if (player->GetQuestStatus(QUEST_THE_ART_OF_WAR) == QUEST_STATUS_INCOMPLETE)/*PENDIENTE */
						{
							events.ScheduleEvent(EVENT_DARKSCREEN, 300);
							intro = true;
						}
					}
				}
			}
			else checkTimer -= diff;

			if (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_DARKSCREEN:
				{
					if (intro)
					{
						/*By Lester*/
						GetPlayerListInGrid(_players, me, 15.0f);
						for (auto player : _players)
						{
							if (!this->IsPlayerOnlist(player, _playersWithSpell))
							{
								player->CastSpell(player, SPELL_FADE_TO_BLACK);
								events.ScheduleEvent(EVENT_MOVIEINTRO, 2000);
								intro_movie = true;
							}
						}
					}
				}
				break;
				case EVENT_MOVIEINTRO:
				{
					if (intro && intro_movie)
					{
						events.CancelEvent(EVENT_DARKSCREEN);
						if (Player* player = me->FindNearestPlayer(50.0f, true))
						{
							player->CastSpell(player, SPELL_PANDA_INTRO_MOVIE);
							player->TeleportTo(1, 1664.66f, -4354.21f, 26.3546f, 6.22487f);
							if (!IsPlayerOnlist(player, _playerDataList))
								SetStageFor(player);
						}
					}
				}
				break;
				default:
					break;
				}
			}

		}
	};
};

void AddSC_orgrimmar()
{
	new npc_general_nazim();
	new npc_garrosh_quest();
	new npc_garrosh_the_horde_way();
	new boss_garrosh_hellscream_orgrimmar();
}