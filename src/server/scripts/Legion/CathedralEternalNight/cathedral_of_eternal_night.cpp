/*
    https://uwow.biz/
*/

#include "cathedral_of_eternal_night.h"
#include "SpellScript.h"

enum Paths
{
    PATH_ILLIDAN_INTRO       = 387377,
    PATH_MAIEV_INTRO         = 387378,
    
    PATH_MAIEV_SECOND_BOSS   = 387379,
    PATH_TO_THIRD_BOSS       = 387384,  
    PATH_FROM_THIRD          = 387385,
    
};

// 120793
struct npc_mefistrot_intro : public ScriptedAI
{
    npc_mefistrot_intro(Creature* creature) : ScriptedAI(creature)
    {
        SetCanSeeEvenInPassiveMode(true);
    }
    
    bool eventDone = false;
    
    void MoveInLineOfSight(Unit* who) override
    {  
        if (!who->IsPlayer() || who->ToPlayer()->isGameMaster())
            return;

        if (!eventDone && me->IsWithinDistInMap(who, 85.0f) && who->GetPositionZ() <= 349.94)
        {
            who->CreateConversation(4868);
            
            eventDone = true;
            if (Creature* illidan = me->FindNearestCreature(NPC_ILLIDAN_INTRO, 130.0f, true))
            {
                illidan->GetMotionMaster()->MovePath(PATH_ILLIDAN_INTRO, false);
                illidan->AddDelayedEvent(20000, [illidan] () -> void
                {
                    illidan->CastSpell(illidan, 239485);
                    illidan->DespawnOrUnsummon(1000);
                });
                
            }
            if (Creature* maiev = me->FindNearestCreature(NPC_MAIEV_INTRO, 130.0f, true))
            {
                maiev->GetMotionMaster()->MovePath(PATH_MAIEV_INTRO, false);
                maiev->AddDelayedEvent(25000, [maiev] ()-> void
                {
                    maiev->CastSpell(maiev, 240727);
                    maiev->DespawnOrUnsummon(2000);
                });
            }
            
            for (uint32 entry = 119952; entry <= 120550; entry+=598)
                if (Creature* add = me->FindNearestCreature(entry, 15.0f, true))
                {
                    add->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                    add->GetMotionMaster()->MoveJump(add->GetPositionX() - 14.0f, add->GetPositionY(), 334.53f, 5.0f, 15.0f);

                    add->SetHomePosition(add->GetPositionX() - 14.0f, add->GetPositionY(), 334.53f, add->GetOrientation());
                    add->AddDelayedEvent(3000, [add] ()-> void
                    {
                        add->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                        if (Player * plr = add->FindNearestPlayer(80.0f, true))
                            add->AI()->AttackStart(plr);
                    });
                }
                
            me->AddDelayedEvent(5000, [this] () -> void
            {
                me->SetHomePosition(me->GetPositionX() - 14.0f, me->GetPositionY(), 334.53f, me->GetOrientation());
                me->GetMotionMaster()->MoveJump(me->GetPositionX() - 14.0f, me->GetPositionY(), 334.53f, 5.0f, 15.0f);
            });
            
            me->AddDelayedEvent(18000, [this] () -> void
            {
                DoCast(240738);
            });
        }
    }
    
    void SpellFinishCast(const SpellInfo* spell) override
    {
        if (spell->Id == 241909)
            me->DespawnOrUnsummon(1);
    }
};


// 118704
struct npc_dulzak : public ScriptedAI
{
    npc_dulzak(Creature* creature) : ScriptedAI(creature)
    {
        SetCanSeeEvenInPassiveMode(true);
        me->m_SightDistance = 130.0f;
    }
    EventMap events;
    bool trashIntro = false;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.RescheduleEvent(EVENT_1, 22000);
    }

    void MoveInLineOfSight(Unit* who) override
    {  
        if (!who || !who->IsPlayer() || who->ToPlayer()->isGameMaster())
            return;

        if (!trashIntro && me->GetDistance2d(who) >= 90 &&  me->GetDistance2d(who) <= 130.0f && who->GetPositionX() >= -615.99f && who->GetPositionZ() <= 349.94)  // farther, than 100.0f
        {
            trashIntro = true;
            who->CreateConversation(4679);
            AttackStart(who);
            me->SetHomePosition(who->GetPositionX(), who->GetPositionY(), who->GetPositionZ(), me->GetOrientation());
        }
    }

    void UpdateAI(uint32 diff) override
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
                case EVENT_1:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(target, 238653);
                    events.RescheduleEvent(EVENT_1, 22000);
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

// 119768
struct npc_coen_event_first : public ScriptedAI
{
    npc_coen_event_first(Creature* creature) : ScriptedAI(creature)
    {
        SetCanSeeEvenInPassiveMode(true);
        
        me->AddDelayedEvent(1000, [this] () -> void
        {
            eventDone = !me->HasAura(237597);
            if (!eventDone)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PREVENT_EMOTES);
                me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
            }
        });
    }

    bool eventDone;
    
    void MoveInLineOfSight(Unit* who) override
    {  
        if (!who || !who->IsPlayer() || who->ToPlayer()->isGameMaster())
            return;

        if (!eventDone && me->IsWithinDistInMap(who, 40.0f))
        {
            eventDone = true;
            
            std::list<Creature*> trash;
            GetCreatureListWithEntryInGrid(trash, me, 119930, 35.0f);

            if (!trash.empty())
                for (std::list<Creature*>::iterator itr = trash.begin(); itr != trash.end(); ++itr)
                {
                    (*itr)->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 10.0f, 10.0f);
                    (*itr)->SetHomePosition(me->GetPositionX() + frand(-3, 3), me->GetPositionY() + frand(-3, 3), me->GetPositionZ(), (*itr)->GetOrientation()+frand(0, 1));
                }
                
            me->AddDelayedEvent(1000, [this] () -> void
            {
                me->CastSpell(me, 240373, true);
                me->DespawnOrUnsummon(4000);
            });
        }
    }
    
};

// 120312 119147
struct npc_coen_maiev_events : public ScriptedAI
{
    npc_coen_maiev_events(Creature* creature) : ScriptedAI(creature)
    {
        SetCanSeeEvenInPassiveMode(true);
    }
    
    bool eventDone = false, isThirdBossIntro = false;
    
    void LastWPReached() override
    {
        if (isThirdBossIntro)
        {
            isThirdBossIntro = false;
            if (Creature* khadgar = me->SummonCreature(118797, -594.75f, 2526.80f, 532.37f, 3.19f))
            {
                khadgar->CastSpell(khadgar, 241351);
                khadgar->CastSpell(khadgar, 243274);
                khadgar->AddDelayedEvent(1000, [khadgar]()-> void
                {
                    khadgar->CastSpell(khadgar, 240949);
                });
                khadgar->DespawnOrUnsummon(29000);
            }
            
            if (Creature* illidan = me->FindNearestCreature(NPC_ILLIDAN_INTRO, 40.0f, true))
                illidan->AddDelayedEvent(3000, [illidan]()-> void
                {
                    illidan->GetMotionMaster()->MovePath(PATH_FROM_THIRD, false, frand(-3, 3), frand(-3, 3));
                    illidan->DespawnOrUnsummon(25000);
                });
                
                me->AddDelayedEvent(3000, [this]()-> void
                {
                    me->GetMotionMaster()->MovePath(PATH_FROM_THIRD, false, frand(-3, 3), frand(-3, 3));
                    me->DespawnOrUnsummon(25000);
                });
            
        }
    }
    

    void MoveInLineOfSight(Unit* who) override
    {  
        if (!who || !who->IsPlayer() || who->ToPlayer()->isGameMaster())
            return;

        if (!eventDone && me->IsWithinDistInMap(who, 17.0f))
        {
            eventDone = true;
            
            switch(me->GetEntry())
            {
                case 120312: // second boss
                {
                    me->AddDelayedEvent(1000, [this]()-> void
                    {
                        DoCast(243561);
                    });
                    
                    me->AddDelayedEvent(2000, [this]()-> void
                    {
                        Talk(0);
                    });
                    
                    me->AddDelayedEvent(3000, [this]()-> void
                    {
                        me->GetMotionMaster()->MovePath(PATH_MAIEV_SECOND_BOSS, false);
                    });
                    
                    me->AddDelayedEvent(25000, [this]()-> void
                    {
                        Talk(1);
                        DoCast(240727);
                        me->DespawnOrUnsummon(2000);
                    });
                    break;
                }
                case 119147: // i need maiev before third boss
                {
                    if (uint32(ceil(me->GetPositionZ())) == 484) // third boss only
                    {
                        isThirdBossIntro = true;
                        if (Creature* illidan = me->FindNearestCreature(NPC_ILLIDAN_INTRO, 40.0f, true))
                        {
                            illidan->GetMotionMaster()->MovePath(PATH_TO_THIRD_BOSS ,false, frand(-3, 3), frand(-3, 3));
                            
                            me->AddDelayedEvent(500, [this] () -> void
                            {
                                me->GetMotionMaster()->MovePath(PATH_TO_THIRD_BOSS, false, frand(-3, 3), frand(-3, 3));
                                me->CreateConversation(4910);
                            });
                        }
                    } 
                    break;
                }
            }
        }
    }
    
};

// 236737
class spell_coen_fel_strike : public SpellScript
{
    PrepareSpellScript(spell_coen_fel_strike);

    void HandleOnHit()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        
        if (caster && target)
        {
            Position pos;
            float angle = caster->GetRelativeAngle(target);
            uint32 hit_range = 0;
            for (uint8 i = 0; i < 11; i++)
            {
                hit_range += 3;
                caster->GetNearPoint2D(pos, hit_range, angle);
                caster->AddDelayedEvent(100*i, [caster, pos] () -> void
                {
                    caster->CastSpell(pos, 240276, false);
                });
            }
        }
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_coen_fel_strike::HandleOnHit);
    }
};

// 238653
class spell_coen_shadow_wave : public SpellScript
{
    PrepareSpellScript(spell_coen_shadow_wave);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
            
        if (caster && target)
        {
            Position pos;
            float angle = caster->GetRelativeAngle(target);
            uint32 hit_range = 0;
            for (uint8 i = 0; i < 11; i++)
            {
                hit_range += 5;
                caster->GetNearPoint2D(pos, hit_range, angle);
                caster->AddDelayedEvent(100+i, [caster, pos] () -> void
                {
                    caster->CastSpell(pos, 238654, false);
                });
            }
            
            for (uint8 i = 10; i < 20; i++)
            {
                hit_range += 5;
                target->GetNearPoint2D(pos, frand(1, 6), frand(0,6.28f));
                caster->AddDelayedEvent(100+i, [caster, pos] () -> void
                {
                    caster->CastSpell(pos, 238654, false);
                });
            }
        }
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_coen_shadow_wave::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 239217
class spell_coen_blinding_glare : public SpellScript
{
    PrepareSpellScript(spell_coen_blinding_glare);

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.remove_if([caster](WorldObject* object) -> bool
        {
            if (object == nullptr)
                return true;

            if (!object->isInFront(caster, M_PI))
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coen_blinding_glare::CorrectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coen_blinding_glare::CorrectTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_coen_blinding_glare::CorrectTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 239052
 class spell_coen_summon_spider : public SpellScript
 {
     PrepareSpellScript(spell_coen_summon_spider);

     void HandleAfterCast()
     {
         Unit* caster = GetCaster();
         
         if (!caster)
             return;

         for (uint8 i =0; i < 3; ++i)
         {
             if (Creature* kokon = caster->SummonCreature(120015, caster->GetPositionX() + frand(-6, 6), caster->GetPositionY() + frand(-6, 6), 510.94f))
             {
                 if (Creature* spider = caster->SummonCreature(120016, kokon->GetPositionX(), kokon->GetPositionY(), kokon->GetPositionZ()))
                 {
                     spider->CastSpell(kokon, 218073);
                     spider->AddDelayedEvent(10000, [spider, kokon, caster] () -> void
                     {
                         if (!kokon || !spider)
                             return;
                         
                         spider->CastSpell(kokon, 116894);
                         kokon->DespawnOrUnsummon(3000);
                         spider->GetMotionMaster()->MoveJump(spider->GetPositionX(), spider->GetPositionY(), caster->GetPositionZ(), 50, 50);
                     });
                 }
             }
         }
     }

     void Register()
     {
         AfterCast += SpellCastFn(spell_coen_summon_spider::HandleAfterCast);
     }
 };

// 239522
class spell_coen_fel_blaze : public SpellScript
{
    PrepareSpellScript(spell_coen_fel_blaze);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (!caster->IsVisible())
                return;
            
            for (uint8 i = 0; i < 20; i++)
            {
                caster->AddDelayedEvent(100+i, [caster] () -> void
                {
                    caster->CastSpell(frand(-570.43f, -513.22f), frand(2497.36f, 2556.18f), 533.94f, 239524, false);
                });
            }
        }
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_coen_fel_blaze::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_cathedral_of_eternal_night()
{
   RegisterCreatureAI(npc_mefistrot_intro);
   RegisterCreatureAI(npc_dulzak);
   RegisterCreatureAI(npc_coen_event_first);
   RegisterCreatureAI(npc_coen_maiev_events);

   RegisterSpellScript(spell_coen_fel_strike);
   RegisterSpellScript(spell_coen_shadow_wave);
   RegisterSpellScript(spell_coen_blinding_glare);
   RegisterSpellScript(spell_coen_summon_spider);
   RegisterSpellScript(spell_coen_fel_blaze);
}
