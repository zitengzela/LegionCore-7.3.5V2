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
#include "ScriptedGossip.h"

//90401
class npc_azsuna_allari_q37660 : public CreatureScript
{
public:
    npc_azsuna_allari_q37660() : CreatureScript("npc_azsuna_allari_q37660") {}

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (player->GetQuestObjectiveData(37660, 90403))
            return false;

        player->PlayerTalkClass->SendCloseGossip();
        player->RewardPlayerAndGroupAtEvent(90403, player);
        creature->AI()->Talk(1);

        return true;
    }

    struct npc_azsuna_allari_q37660AI : public ScriptedAI
    {
        npc_azsuna_allari_q37660AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void IsSummonedBy(Unit* who) override
        {
            who->AddPlayerInPersonnalVisibilityList(who->GetGUID());
            me->GetMotionMaster()->MovePath(90401, false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (id == 2)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
            case 1:
                me->AddDelayedEvent(1500, [this] {
                    if (Creature* firstdemon = me->FindNearestCreature(90402, 60.0f, true))
                        DoCast(firstdemon, 178939);
                    });
                me->AddDelayedEvent(4500, [this] {
                    Talk(2);
                    });
                break;
            case 2:
                me->AddDelayedEvent(1500, [this] {
                    if (Creature* seconddemon = me->FindNearestCreature(89276, 60.0f, true))
                        DoCast(seconddemon, 178939);
                    });
                me->AddDelayedEvent(4500, [this] {
                    Talk(2);
                    });
                me->AddDelayedEvent(10000, [this] {
                    if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                        if (Player* player = Owner->ToPlayer())
                            player->RewardPlayerAndGroupAtEvent(89276, player);
                    });
                me->AddDelayedEvent(15000, [this] {
                    Talk(5);
                    });
                me->AddDelayedEvent(20000, [this] {
                    Talk(6);
                    });
                me->AddDelayedEvent(25000, [this] {
                    Talk(7);
                    });
                me->AddDelayedEvent(30000, [this] {
                    me->DespawnOrUnsummon(500);
                    });
                break;
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_azsuna_allari_q37660AI(creature);
    }
};

//107995
class npc_azsuna_stellagosa_q37862 : public CreatureScript
{
public:
    npc_azsuna_stellagosa_q37862() : CreatureScript("npc_azsuna_stellagosa_q37862") {}

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (player->GetQuestObjectiveData(37862, 107995) || (player->GetQuestStatus(37862) == QUEST_STATUS_REWARDED
            || player->GetQuestStatus(37862) == QUEST_STATUS_COMPLETE))
            return false;

        player->PlayerTalkClass->SendCloseGossip();
        player->SummonCreature(107995, creature->GetPosition());

        return true;
    }

    struct npc_azsuna_stellagosa_q37862AI : public ScriptedAI
    {
        npc_azsuna_stellagosa_q37862AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisableGravity(true);
        }

        void IsSummonedBy(Unit* who) override
        {
            if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                if (Player* player = Owner->ToPlayer())
                    player->RewardPlayerAndGroupAtEvent(107995, player);
            who->AddPlayerInPersonnalVisibilityList(who->GetGUID());
            who->CastSpell(me, 77901);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AddDelayedEvent(2000, [this] {
                me->GetMotionMaster()->MovePath(107995, false);;
                });
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != WAYPOINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                    if (Player* player = Owner->ToPlayer())
                        player->CastSpell(player, 214402);
                Talk(0);
            }

            if (id == 2)
                Talk(1);

            if (id == 3)
                Talk(2);

            if (id == 4)
                Talk(3);

            if (id == 9)
            {
                if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                    if (Player* player = Owner->ToPlayer())
                        player->RemoveAurasDueToSpell(214402);
                me->DespawnOrUnsummon(1000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_azsuna_stellagosa_q37862AI(creature);
    }
};

//91185
class npc_azsuna_daglop_q38237 : public CreatureScript
{
public:
    npc_azsuna_daglop_q38237() : CreatureScript("npc_azsuna_daglop_q38237") {}

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (player->GetQuestObjectiveData(38237, 91185))
            return false;

        player->PlayerTalkClass->SendCloseGossip();
        player->RewardPlayerAndGroupAtEvent(91185, player);
        if (Creature* daglop = player->SummonCreature(91185, creature->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 200000))
            daglop->AddPlayerInPersonnalVisibilityList(player->GetGUID());

        return true;
    }

    struct npc_azsuna_daglop_q38237AI : public ScriptedAI
    {
        npc_azsuna_daglop_q38237AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() {}

        void IsSummonedBy(Unit* who) override
        {
            me->SetVisible(true);
            me->GetMotionMaster()->MovePoint(0, -541.24f, 5648.40f, 3.06f);
            me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
        {
            if (summon->GetEntry() == 91184)
            {
                me->AddDelayedEvent(1000, [this] {
                    Talk(1);
                    me->SetReactState(REACT_PASSIVE);
                    });
                me->AddDelayedEvent(2000, [this] {
                    me->GetMotionMaster()->MovePoint(1, -519.28f, 5607.60f, 4.59f);
                    });
            }
        }

        void SpellFinishCast(SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == 181029)
            {
                if (Unit* Owner = me->ToTempSummon()->GetSummoner())
                    if (Player* player = Owner->ToPlayer())
                        if (Creature* sum = me->SummonCreature(91184, -546.67f, 5658.04f, 2.81f, 5.22f, TEMPSUMMON_TIMED_DESPAWN, 200000))
                        {
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            sum->AddPlayerInPersonnalVisibilityList(player->GetGUID());
                            sum->SetVisible(true);
                        }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 0:
                    me->AddDelayedEvent(1500, [this] {
                        DoCast(181029);
                        });
                    break;
                case 1:
                    me->SetVisible(false);
                    me->DespawnOrUnsummon(500);
                    break;
                default:
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoSpellAttackIfReady(36227);
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_azsuna_daglop_q38237AI(creature);
    }
};

//97648
class npc_grasp_of_underking_quest : public CreatureScript
{
public:
    npc_grasp_of_underking_quest() : CreatureScript("npc_grasp_of_underking_quest") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(39025) == QUEST_STATUS_INCOMPLETE)
        {
            for (uint32 npcs : { 95051, 94255, 94286})
                if (Creature* crea = creature->FindNearestCreature(npcs, 5.0f, true))
                {
                    if (uint32 id = crea->GetEntry())
                        player->RewardPlayerAndGroupAtEvent(id, player);
                    crea->SetDisableGravity(false);
                    crea->ExitVehicle();
                    crea->AddDelayedEvent(500, [crea] {
                        crea->AI()->Talk(0);
                        crea->GetMotionMaster()->MoveRandom(12.0f);
                        crea->DespawnOrUnsummon(6500);
                        });
                    creature->Kill(creature);
                }
            return true;
        }
        player->PlayerTalkClass->SendCloseGossip();
        return true;
    }

    struct npc_grasp_of_underking_questAI : public ScriptedAI
    {
        npc_grasp_of_underking_questAI(Creature* creature) : ScriptedAI(creature)
        {
            boarded = false;
        }

        bool boarded;

        void Reset()
        {
            ResetGrasp();
        }

        void JustDied(Unit* /*killer*/) override
        {
            boarded = false;
        }

        void ResetGrasp()
        {
            if (!boarded)
            {
                boarded = true;
                me->AddDelayedEvent(2000, [this] {
                    if (me->GetPositionX() == 3736.11f && me->GetPositionY() == 4887.47f)
                        if (Creature* oro = me->SummonCreature(95051, me->GetPosition()))
                            oro->EnterVehicle(me, 0);
                    if (me->GetPositionX() == 3649.89f && me->GetPositionY() == 4908.65f)
                        if (Creature* jale = me->SummonCreature(94255, me->GetPosition()))
                            jale->EnterVehicle(me, 0);
                    if (me->GetPositionX() == 3575.87f && me->GetPositionY() == 4839.52f)
                        if (Creature* oakin = me->SummonCreature(94286, me->GetPosition()))
                            oakin->EnterVehicle(me, 0);
                    });
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_grasp_of_underking_questAI(creature);
    }
};

// 90317
enum npcs
{
    NPC_DOG = 90241,
    NPC_SOLDIER = 101943,
    NPC_INFERNAL = 93619,
    NPC_GUARD = 90230
};

Position const dogsdrpos[3] =
{
    { -201.42f, 7005.10f, 4.75f, 5.69f }, //bridge
    { -153.57f, 7091.64f, 0.27f, 5.15f }, //center
    { -181.03f, 7032.41f, -0.83f, 4.97f },
};

Position const infpos = { -154.46f, 7105.88f, 0.0f, 4.9f };

struct npc_azsuna_illidari_outpost_initiator : public ScriptedAI
{
    npc_azsuna_illidari_outpost_initiator(Creature* creature) : ScriptedAI(creature) {}

    uint32 spawnTimer = urand(5000, 9000);
    bool dog = false;
    bool sdr = false;
    bool inf = false;
    bool ncr = false;

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
        case NPC_DOG:
            dog = false;
            break;
        case NPC_SOLDIER:
            sdr = false;
            break;
        case NPC_INFERNAL:
            inf = false;
            break;
        case NPC_GUARD:
            ncr = false;
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (spawnTimer <= diff)
        {
            if (!dog)
            {
                if (auto _add = me->SummonCreature(NPC_DOG, dogsdrpos[urand(0, 1)], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                {
                    _add->SetWalk(false);
                    if (_add->GetPositionX() < -170.0f)
                        _add->GetMotionMaster()->MovePoint(0, -167.0f, 6979.0f, 5.05f);
                    else
                        _add->GetMotionMaster()->MovePoint(0, -126.0f, 7017.0f, 1.15f);
                    dog = true;
                }
            }
            if (!sdr)
            {
                if (auto _add = me->SummonCreature(NPC_SOLDIER, dogsdrpos[urand(0, 1)], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                {
                    _add->SetWalk(false);
                    if (_add->GetPositionX() < -170.0f)
                        _add->GetMotionMaster()->MovePoint(0, -167.0f, 6979.0f, 5.05f);
                    else
                        _add->GetMotionMaster()->MovePoint(0, -126.0f, 7017.0f, 1.15f);
                    sdr = true;
                }
            }
            if (!inf)
            {
                if (auto _add = me->SummonCreature(NPC_INFERNAL, infpos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                {
                    _add->GetMotionMaster()->MovePoint(0, -126.0f, 7017.0f, 1.15f);
                    inf = true;
                }
            }
            if (!ncr)
            {
                if (auto _add = me->SummonCreature(NPC_GUARD, dogsdrpos[2], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 15000))
                {
                    _add->SetWalk(false);
                    _add->GetMotionMaster()->MovePoint(0, -126.0f, 7017.0f, 1.15f);
                    ncr = true;
                }
            }
            spawnTimer = urand(5000, 9000);
        }
        else spawnTimer -= diff;
    }
};

//239338 239332 Q37660
class go_azsuna_soul_gem : public GameObjectScript
{
public:
    go_azsuna_soul_gem() : GameObjectScript("go_azsuna_soul_gem") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (go->GetEntry() == 239338)
        {
            if (!player->GetQuestObjectiveData(37660, 239338) && player->GetQuestObjectiveData(37660, 90403))
            {
                GuidList* allari = player->GetSummonList(90401);
                for (GuidList::const_iterator iter = allari->begin(); iter != allari->end(); ++iter)
                {
                    if (Creature* summon = ObjectAccessor::GetCreature(*player, (*iter)))
                        if (!go->FindNearestCreature(90402, 50.0f, true) || !go->FindNearestCreature(89276, 50.0f, true))
                        {
                            summon->GetAI()->DoAction(1);
                            go->SummonCreature(90402, go->GetPosition());
                            player->QuestObjectiveSatisfy(239338, 1, QUEST_OBJECTIVE_GAMEOBJECT);

                            player->AddDelayedEvent(8000, [player] {
                                player->RewardPlayerAndGroupAtEvent(90402, player);
                                });
                        }
                    return true;
                }
            }
        }

        if (go->GetEntry() == 239332)
        {
            if (!player->GetQuestObjectiveData(37660, 239332) && player->GetQuestObjectiveData(37660, 90403))
            {
                GuidList* allari = player->GetSummonList(90401);
                for (GuidList::const_iterator iter = allari->begin(); iter != allari->end(); ++iter)
                {
                    if (Creature* summon = ObjectAccessor::GetCreature(*player, (*iter)))
                        if (!go->FindNearestCreature(90402, 50.0f, true) || !go->FindNearestCreature(89276, 50.0f, true))
                        {
                            summon->GetAI()->DoAction(2);
                            go->SummonCreature(89276, go->GetPosition());
                            player->QuestObjectiveSatisfy(239332, 1, QUEST_OBJECTIVE_GAMEOBJECT);

                            player->AddDelayedEvent(15000, [player] {
                                player->RewardPlayerAndGroupAtEvent(90402, player);
                                });
                        }
                    return true;
                }
            }
        }
        return false;
    }
};

void AddSC_zone_azsuna() 
{
    new npc_azsuna_allari_q37660();
    new npc_azsuna_stellagosa_q37862();
    new npc_azsuna_daglop_q38237();
    new npc_grasp_of_underking_quest();
    RegisterCreatureAI(npc_azsuna_illidari_outpost_initiator);

    new go_azsuna_soul_gem;
}
