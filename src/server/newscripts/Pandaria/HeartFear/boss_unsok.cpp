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
    SPELL_AMBER_CARAPACE        = 122540,
    SPELL_AMBER_EXPLOSION       = 122402,
    SPELL_AMBER_SCALPEL         = 121994,
    SPELL_MASSIVE_STOMP         = 122408,
    SPELL_CONCENTRATED_MUTATION = 122556,
    SPELL_EXPLOSE               = 122532,
    SPELL_CORROSIVE_AURA        = 122348,
};

enum sSummons
{
    NPC_AMBER_BEAM_STALKER      = 90903,
    NPC_LIVING_AMBER            = 62691,
};

enum eEvents
{
    //Unsok
    EVENT_AMBER_SCALPEL         = 1,

    //Amber Monster
    EVENT_MASSIVE_STOMP         = 2,
};

enum Actions
{
    ACTION_INTRO_P3             = 1,
};

//62511
class boss_unsok : public CreatureScript
{
    public:
        boss_unsok() : CreatureScript("boss_unsok") {}

        struct boss_unsokAI : public BossAI
        {
            boss_unsokAI(Creature* creature) : BossAI(creature, DATA_UNSOK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            bool phasetwo, phasethree;

            void Reset()
            {
                _Reset();
                phasetwo = false;
                phasethree = false;
                me->RemoveAurasDueToSpell(SPELL_AMBER_CARAPACE);
                me->RemoveAurasDueToSpell(SPELL_CONCENTRATED_MUTATION);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.RescheduleEvent(EVENT_AMBER_SCALPEL, 10000);
            }

            void DamageTaken(Unit* attacker, uint32 &damage, DamageEffectType dmgType)
            {
                if (HealthBelowPct(70) && !phasetwo)
                {
                    phasetwo = true;
                    DoCast(me, SPELL_AMBER_CARAPACE, true);
                    if (Creature* am = me->SummonCreature(NPC_AMBER_MONSTER, me->GetPositionX(), me->GetPositionY() + 5.0f, me->GetPositionZ()))
                        am->AI()->DoZoneInCombat(am, 100.0f);
                }
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_INTRO_P3 && !phasethree)
                {
                    phasethree = true;
                    me->RemoveAurasDueToSpell(SPELL_AMBER_CARAPACE);
                    me->AddAura(SPELL_CONCENTRATED_MUTATION, me);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                
                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_AMBER_SCALPEL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                        {
                            if (Creature* abeam = me->SummonCreature(NPC_AMBER_BEAM_STALKER, target->GetPositionX()+6, target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 12000))
                            {
                                abeam->AI()->AttackStart(target);
                                DoCast(abeam, SPELL_AMBER_SCALPEL);
                            }
                        }
                        events.RescheduleEvent(EVENT_AMBER_SCALPEL, urand(20000, 30000));
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_unsokAI(creature);
        }
};

class npc_amber_monster : public CreatureScript
{
    public:
        npc_amber_monster() : CreatureScript("npc_amber_monster") {}

        struct npc_amber_monsterAI : public ScriptedAI
        {
            npc_amber_monsterAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            InstanceScript* instance;
            EventMap events;

            void Reset(){}
            
            void EnterCombat(Unit* attacker)
            {
                events.RescheduleEvent(EVENT_MASSIVE_STOMP, urand(10000, 20000));
            }

            void JustDied(Unit* killer)
            {
                if (instance)
                {
                    if (Creature* unsok = me->GetCreature(*me, instance->GetGuidData(NPC_UNSOK)))
                        unsok->AI()->DoAction(ACTION_INTRO_P3);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_MASSIVE_STOMP:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_MASSIVE_STOMP);
                        events.RescheduleEvent(EVENT_MASSIVE_STOMP, urand(20000, 30000));
                        break;
                    }
                    
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_amber_monsterAI(creature);
        }
};

class npc_amberbeam_stalker : public CreatureScript
{
public:
    npc_amberbeam_stalker() : CreatureScript("npc_amberbeam_stalker") { }

    struct npc_amberbeam_stalkerAI : public ScriptedAI
    {
        npc_amberbeam_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_SCHOOL_DAMAGE, true);
            me->SetDisplayId(11686);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
            me->SetReactState(REACT_PASSIVE);
        }

        InstanceScript* instance;
        uint32 sum;

        void Reset()
        {
            sum = 10000;
        }
        
        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (sum)
            {
                if (sum <= diff)
                {
                    sum = 0;
                    if (Creature* lamber = me->SummonCreature(NPC_LIVING_AMBER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000))
                    {
                        lamber->AI()->DoZoneInCombat(lamber, 100.0f);
                        lamber->AddAura(SPELL_CORROSIVE_AURA, lamber);
                    }
                }
                else 
                    sum -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_amberbeam_stalkerAI (pCreature);
    }
};

class npc_living_amber : public CreatureScript
{
public:
    npc_living_amber() : CreatureScript("npc_living_amber") { }

    struct npc_living_amberAI : public ScriptedAI
    {
        npc_living_amberAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->SetReactState(REACT_AGGRESSIVE);
        }

        InstanceScript* instance;
        bool explose;

        void Reset()
        {
            explose = false;
        }

        void DamageTaken(Unit* attacker, uint32 &damage, DamageEffectType dmgType)
        {
            if (damage >= me->GetHealth() && !explose)
            {
                explose = true;
                DoCastAOE(SPELL_EXPLOSE);
            }
        }
        
        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_living_amberAI (pCreature);
    }
};

void AddSC_boss_unsok()
{
    new boss_unsok();
    new npc_amber_monster();
    new npc_amberbeam_stalker();
    new npc_living_amber();
}
