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
    //Empress
    //phase 1
    SPELL_CRY_OF_TERROR      = 123788,
    SPELL_DREAD_SCREECH      = 123735,
    //phase 3
    SPELL_CALAMITY           = 124845,
    SPELL_SHA_ENERGY         = 125464,
    SPELL_CONSUMING_TERROR   = 124849,
    SPELL_VISIONS_OF_DEMISE  = 124862,

    //Sentinels
    //Setthik
    SPELL_TOXIC_SLIME        = 124807,
    SPELL_TOXIC_BOMB         = 124777,
    //Korthik
    SPELL_DISPATCH           = 124077,
};

enum eEvents
{
    //Empress
    EVENT_CHECK_POWER        = 1,
    EVENT_GO_IN_CASE_WORM    = 2,
    EVENT_TERROR             = 3,
    EVENT_SCREECH            = 4,
    EVENT_CALAMITY           = 5,
    EVENT_SHA_ENERGY         = 6,
    EVENT_CONSUMING_TERROR   = 7,
    EVENT_VISIONS_OF_DEMISE  = 8,

    //Sentinels
    EVENT_TOXIC_SLIME        = 9,
    EVENT_TOXIC_BOMB         = 10,
    EVENT_DISPATCH           = 11,
};

enum Actions
{
    ACTION_PHASE_1           = 1,
    ACTION_PHASE_2           = 2,
    ACTION_PHASE_3           = 3,
    ACTION_SENTINEL_DIED     = 4,
};

enum Phase
{
    PHASE_NONE               = 0, 
    PHASE_ONE                = 1, 
    PHASE_TWO                = 2, 
    PHASE_THREE              = 3, 
};

enum eSentinels
{
    NPC_SETTHIK_WINDBLADE    = 64453,
    NPC_KORTHIK_REAVER       = 63591,
};

uint32 sumwave[4] = 
{
    NPC_SETTHIK_WINDBLADE,
    NPC_SETTHIK_WINDBLADE,
    NPC_SETTHIK_WINDBLADE,
    NPC_KORTHIK_REAVER,
};

Position const cocoonpos  = {-2478.709f, 1068.170f, 584.953f};
Position const lsummonpos = {-2520.776f, 983.256f, 569.630f};
Position const rsummonpos = {-2435.437f, 984.290f, 569.630f};

class boss_empress_shekzeer : public CreatureScript
{
    public:
        boss_empress_shekzeer() : CreatureScript("boss_empress_shekzeer") {}

        struct boss_empress_shekzeerAI : public BossAI
        {
            boss_empress_shekzeerAI(Creature* creature) : BossAI(creature, DATA_SHEKZEER)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            Phase phase;
            uint8 sdiedval;

            void Reset() override
            {
                _Reset();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetVisible(true);
                me->SetReactState(REACT_DEFENSIVE);
                phase = PHASE_NONE;
                events.SetPhase(PHASE_NONE);
                me->setPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 150);
                me->SetPower(POWER_ENERGY, 150);
                sdiedval = 0;
            }

            void RegeneratePower(Powers power, float &value) override
            {
                if (!me->isInCombat() || phase == PHASE_ONE)
                    value = 0;
                else if (phase == PHASE_TWO)
                    value = 2;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.SetPhase(PHASE_ONE);
                phase = PHASE_ONE;
                events.RescheduleEvent(EVENT_CHECK_POWER, 1000);
                events.RescheduleEvent(EVENT_SCREECH, urand(15000, 20000), 0, PHASE_ONE);
                events.RescheduleEvent(EVENT_TERROR,  urand(25000, 35000), 0, PHASE_ONE);
            }

            void DamageTaken(Unit* attacker, uint32 &damage, DamageEffectType dmgType) override
            {
                if (HealthBelowPct(30) && phase != PHASE_THREE)
                {
                    phase = PHASE_THREE;
                    events.SetPhase(PHASE_THREE);
                    DoAction(ACTION_PHASE_3);
                }
            }
            
            void SummonRoyalSentinels()
            {
                for (uint8 n = 0; n < 4; n++)
                {
                    if (Creature* sentinel = me->SummonCreature(sumwave[n], lsummonpos.GetPositionX(), lsummonpos.GetPositionY(), lsummonpos.GetPositionZ()))
                        sentinel->AI()->DoZoneInCombat(sentinel, 150.0f);
                }

                for (uint8 n = 0; n < 4; n++)
                {
                    if (Creature* sentinel = me->SummonCreature(sumwave[n], rsummonpos.GetPositionX(), rsummonpos.GetPositionY(), rsummonpos.GetPositionZ()))
                        sentinel->AI()->DoZoneInCombat(sentinel, 150.0f);
                }
            }

            void DoAction(const int32 action) override
            {
                switch (action)
                {
                case ACTION_PHASE_2:
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_TERROR);
                    events.CancelEvent(EVENT_SCREECH);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    me->SetVisible(false);
                    sdiedval = 0;
                    SummonRoyalSentinels();
                    break;
                case ACTION_PHASE_1:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    me->SetVisible(true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat(me, 150.0f);
                    events.RescheduleEvent(EVENT_SCREECH, urand(15000, 20000), 0, PHASE_ONE);
                    events.RescheduleEvent(EVENT_TERROR,  urand(25000, 35000), 0, PHASE_ONE);
                    break;
                case ACTION_SENTINEL_DIED:
                    if (sdiedval++ >= 7 && phase == PHASE_TWO)
                    {
                        sdiedval = 0;
                        me->SetPower(POWER_ENERGY, 150);
                    }
                    break;
                case ACTION_PHASE_3:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    me->SetVisible(true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat(me, 150.0f);
                    me->SetPower(POWER_ENERGY, 150);
                    events.CancelEvent(EVENT_CHECK_POWER);
                    events.RescheduleEvent(EVENT_CALAMITY,          urand(60000, 90000), 0, PHASE_THREE);
                    events.RescheduleEvent(EVENT_SHA_ENERGY,        urand(20000, 30000), 0, PHASE_THREE);
                    events.RescheduleEvent(EVENT_CONSUMING_TERROR,  urand(40000, 50000), 0, PHASE_THREE);
                    events.RescheduleEvent(EVENT_VISIONS_OF_DEMISE, urand(25000, 30000), 0, PHASE_THREE);
                    break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || (me->HasUnitState(UNIT_STATE_CASTING) && phase == PHASE_THREE))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_CHECK_POWER:
                        {
                            switch (phase)
                            {
                            case PHASE_ONE:
                                {
                                    if (me->GetPower(POWER_ENERGY) >= 1)
                                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 1);
                                    else if (me->GetPower(POWER_ENERGY) == 0)
                                    {
                                        phase = PHASE_TWO;
                                        events.SetPhase(PHASE_TWO);
                                        DoAction(ACTION_PHASE_2);
                                    }
                                    break;
                                }
                            case PHASE_TWO:
                                {
                                    if (me->GetPower(POWER_ENERGY) == 150)
                                    {
                                        phase = PHASE_ONE;
                                        events.SetPhase(PHASE_ONE);
                                        DoAction(ACTION_PHASE_1);
                                    }
                                    break;
                                }
                            default:
                                break;
                            }
                            events.RescheduleEvent(EVENT_CHECK_POWER, 1000);
                            break;
                        }
                    case EVENT_SCREECH:
                        {
                            if (Is25ManRaid())
                            {
                                for (uint8 n = 0; n < 5; n++)
                                {
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                                        target->CastSpell(target, SPELL_DREAD_SCREECH);
                                }
                            }
                            else
                            {
                                for (uint8 n = 0; n < 2; n++)
                                {
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                                        target->CastSpell(target, SPELL_DREAD_SCREECH);
                                }
                            }
                            events.RescheduleEvent(EVENT_SCREECH, urand(15000, 20000), 0, PHASE_ONE);
                            break;
                        }
                    case EVENT_TERROR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                            target->AddAura(SPELL_CRY_OF_TERROR, target);
                        events.RescheduleEvent(EVENT_TERROR,  urand(25000, 35000), 0, PHASE_ONE);
                        break;
                    case EVENT_CALAMITY:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_CALAMITY);//AOE
                        events.RescheduleEvent(EVENT_CALAMITY, urand(60000, 90000), 0, PHASE_THREE);
                        break;
                    case EVENT_SHA_ENERGY:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_SHA_ENERGY);//AOE
                        events.RescheduleEvent(EVENT_SHA_ENERGY, urand(20000, 30000), 0, PHASE_THREE);
                        break;
                    case EVENT_CONSUMING_TERROR:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_CONSUMING_TERROR);//Cone AOE
                        events.RescheduleEvent(EVENT_CONSUMING_TERROR, urand(40000, 50000), 0, PHASE_THREE);
                        break;
                    case EVENT_VISIONS_OF_DEMISE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                            target->AddAura(SPELL_VISIONS_OF_DEMISE, target);
                        events.RescheduleEvent(EVENT_VISIONS_OF_DEMISE, urand(25000, 30000), 0, PHASE_THREE);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_empress_shekzeerAI(creature);
        }
};

class npc_generic_royal_sentinel : public CreatureScript
{
    public:
        npc_generic_royal_sentinel() : CreatureScript("npc_generic_royal_sentinel") {}

        struct npc_generic_royal_sentinelAI : public ScriptedAI
        {
            npc_generic_royal_sentinelAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            InstanceScript* instance;
            EventMap events;

            void Reset() override {}
            
            void EnterCombat(Unit* attacker) override
            {
                switch (me->GetEntry())
                {
                case NPC_SETTHIK_WINDBLADE:
                    events.RescheduleEvent(EVENT_TOXIC_SLIME, urand(10000, 15000));
                    events.RescheduleEvent(EVENT_TOXIC_BOMB,  urand(20000, 25000));
                    break;
                case NPC_KORTHIK_REAVER:
                    events.RescheduleEvent(EVENT_DISPATCH,    urand(15000, 20000));
                    break;
                }
            }

            void JustDied(Unit* killer) override
            {
                if (instance)
                {
                    if (Creature* shekzeer = me->GetCreature(*me, instance->GetGuidData(NPC_SHEKZEER)))
                        shekzeer->AI()->DoAction(ACTION_SENTINEL_DIED);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_TOXIC_SLIME:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_TOXIC_SLIME);
                        events.RescheduleEvent(EVENT_TOXIC_SLIME, urand(10000, 15000));
                        break;
                    case EVENT_TOXIC_BOMB:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                            DoCast(target, SPELL_TOXIC_BOMB);
                        events.RescheduleEvent(EVENT_TOXIC_BOMB, urand(20000, 25000));
                        break;
                    case EVENT_DISPATCH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                            DoCast(target, SPELL_DISPATCH);
                        events.RescheduleEvent(EVENT_DISPATCH,   urand(15000, 20000));
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_generic_royal_sentinelAI(creature);
        }
};

class spell_calamity : public SpellScriptLoader
{
    public:
        spell_calamity() : SpellScriptLoader("spell_calamity") { }

        class spell_calamity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_calamity_SpellScript);

            void DealDamage()
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();

                if (!caster || !target)
                    return;
                
                int32 curdmg = target->GetMaxHealth()/2;

                if (curdmg)
                    SetHitDamage(curdmg);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_calamity_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_calamity_SpellScript();
        }
};

void AddSC_boss_empress_shekzeer()
{
    new boss_empress_shekzeer();
    new npc_generic_royal_sentinel();
    new spell_calamity();
}
