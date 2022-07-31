/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "heart_of_fear.h"

enum eSpells
{
    SPELL_OVERWHELMING_ASSAULT  = 123474,
    SPELL_INTENSIFY             = 123470,
    SPELL_INTENSIFY_TRIGGER_EF  = 123471,
    SPELL_TEMPEST_SLASH         = 122854,
    SPELL_WIND_STEP             = 123180,
    SPELL_UNSEEN_STRIKE_DMG     = 122994,
    SPELL_UNSEEN_STRIKE_TARGET  = 123017,
};

enum eEvents
{
    EVENT_ASSAULT               = 1,
    EVENT_SUMMON_TEMPEST        = 2,
    EVENT_STEP                  = 3,
    EVENT_PRE_UNSEEN_STRIKE     = 4,
    EVENT_UNSEEN_STRIKE         = 5,
};

class boss_lord_tayak : public CreatureScript
{
    public:
        boss_lord_tayak() : CreatureScript("boss_lord_tayak") {}

        struct boss_lord_tayakAI : public BossAI
        {
            boss_lord_tayakAI(Creature* creature) : BossAI(creature, DATA_LORD_TAYAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            ObjectGuid striketarget;
            bool lastphase;

            void Reset() override
            {
                _Reset();
                lastphase = false;
                striketarget.Clear();
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveAurasDueToSpell(SPELL_INTENSIFY);
                me->RemoveAurasDueToSpell(SPELL_INTENSIFY_TRIGGER_EF);
            }

            void DamageTaken(Unit* attacker, uint32 &damage, DamageEffectType dmgType) override
            {
                if (HealthBelowPct(20) && !lastphase)
                {
                    lastphase = true;
                    events.CancelEvent(EVENT_STEP);
                    events.CancelEvent(EVENT_SUMMON_TEMPEST);
                    events.CancelEvent(EVENT_PRE_UNSEEN_STRIKE);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                me->AddAura(SPELL_INTENSIFY, me);
                events.RescheduleEvent(EVENT_ASSAULT,           urand(15000, 20000));
                events.RescheduleEvent(EVENT_SUMMON_TEMPEST,    urand(20000, 30000));
                events.RescheduleEvent(EVENT_STEP,              urand(25000, 35000));
                events.RescheduleEvent(EVENT_PRE_UNSEEN_STRIKE,               60000);
            }

            void WindStep()
            {
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                {
                    float x, y, z;
                    target->GetPosition(x, y, z);
                    me->NearTeleportTo(x, y, z, 0.0f);

                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 8.0f);
                    for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                    {
                        if (Player* pl = *itr)
                            pl->AddAura(SPELL_WIND_STEP, pl);
                    }
                }
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 100.0f);
                events.RescheduleEvent(EVENT_STEP, urand(25000, 35000));
            }

            void PrepareStrike()
            {
                striketarget.Clear();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                {
                    striketarget = target->GetGUID();
                    target->AddAura(SPELL_UNSEEN_STRIKE_TARGET, target);
                }

                if (striketarget)
                {
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetVisible(false);
                    events.RescheduleEvent(EVENT_UNSEEN_STRIKE, 5000);
                }
            }

            void StartUnseenStrike()
            {
                if (Player* pl = me->GetPlayer(*me, striketarget))
                {
                    if (pl->isAlive())
                    {
                        float x, y, z;
                        pl->GetPosition(x, y, z);
                        me->NearTeleportTo(x, y, z, 0.0f);
                        me->SetVisible(true);
                        me->SetFacingToObject(pl);
                        DoCast(pl, SPELL_UNSEEN_STRIKE_DMG);
                    }
                }
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 100.0f);
                events.RescheduleEvent(EVENT_PRE_UNSEEN_STRIKE, 60000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_ASSAULT:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_OVERWHELMING_ASSAULT);
                        events.RescheduleEvent(EVENT_ASSAULT, urand(15000, 20000));
                        break;
                    case EVENT_SUMMON_TEMPEST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                        {
                            Position pos;
                            target->GetPosition(&pos);
                            if (Creature* t = me->SummonCreature(90901, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
                                t->GetMotionMaster()->MoveCharge(pos.GetPositionX(), pos.GetPositionY(), me->GetPositionZ(), 20.0f);
                        }
                        events.RescheduleEvent(EVENT_SUMMON_TEMPEST, urand(20000, 30000));
                        break;
                    case EVENT_STEP:
                        events.DelayEvents(1500);
                        WindStep();
                        break;
                    case EVENT_PRE_UNSEEN_STRIKE:
                        events.DelayEvents(7000);
                        PrepareStrike();
                        break;
                    case EVENT_UNSEEN_STRIKE:
                        StartUnseenStrike();
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_lord_tayakAI(creature);
        }
};

class mob_tempest_slash : public CreatureScript
{
    public:
        mob_tempest_slash() : CreatureScript("mob_tempest_slash") {}

        struct mob_tempest_slashAI : public ScriptedAI
        {
            mob_tempest_slashAI(Creature* creature) : ScriptedAI(creature)
            {
                InstanceScript* instance = creature->GetInstanceScript();
                me->SetDisplayId(11686);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            }

            InstanceScript* instance;
            
            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_TEMPEST_SLASH, me);
            }

            void EnterCombat(Unit* who) override {}

            void EnterEvadeMode() override {}

            void UpdateAI(uint32 diff) override {}
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_tempest_slashAI(creature);
        }
};

void AddSC_boss_lord_tayak()
{
    new boss_lord_tayak();
    new mob_tempest_slash();
}
