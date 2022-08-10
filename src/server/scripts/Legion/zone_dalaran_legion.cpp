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

#include "QuestData.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

 // 44663 44184
struct quest_blink_of_an_eye : public QuestScript
{
    quest_blink_of_an_eye() : QuestScript("quest_blink_of_an_eye") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus oldStatus, QuestStatus /*newStatus*/) override
    {
        if (oldStatus == QUEST_STATUS_NONE)
            player->CreateConversation(3827);
    }
};

enum Spellsfollower
{
    SPELL_FOLLOVER_WARRIOR_HORDE    = 216443, 
    SPELL_FOLLOVER_WARRIOR_ALLIANCE = 216497, 
    SPELL_FOLLOVER_PALADIN          = 190886,
    SPELL_FOLLOVER_HUNTER           = 196908,
    SPELL_FOLLOVER_ROGUE            = 201208,
    SPELL_FOLLOVER_PRIEST_HORDE     = 226409,
    SPELL_FOLLOVER_PRIEST_ALLIANCE  = 226412,
    SPELL_FOLLOVER_DK               = 200023,
    SPELL_FOLLOVER_SHAMAN           = 227324,
    SPELL_FOLLOVER_MAGE             = 195356,
    SPELL_FOLLOVER_WARLOCK          = 204860,
    SPELL_FOLLOVER_MONK             = 193978,
    SPELL_FOLLOVER_DRUID            = 199277,
    SPELL_FOLLOVER_DH               = 195286
};

// 111109
struct npc_emissary_auldbridge : public ScriptedAI
{
    npc_emissary_auldbridge(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestReward(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == 44184 || quest->GetQuestId() == 44663)
        {
            if (player->getClass() == CLASS_WARRIOR)
            { 
                if (player->GetTeam() == ALLIANCE)
                    player->CastSpell(player, SPELL_FOLLOVER_WARRIOR_ALLIANCE);
                if (player->GetTeam() == HORDE)
                    player->CastSpell(player, SPELL_FOLLOVER_WARRIOR_HORDE);
            }
            if (player->getClass() == CLASS_PALADIN)
                player->CastSpell(player, SPELL_FOLLOVER_PALADIN);
            if (player->getClass() == CLASS_HUNTER)
                player->CastSpell(player, SPELL_FOLLOVER_HUNTER);
            if (player->getClass() == CLASS_ROGUE)
                player->CastSpell(player, SPELL_FOLLOVER_ROGUE);
            if (player->getClass() == CLASS_PRIEST)
            {
                if (player->GetTeam() == ALLIANCE)
                    player->CastSpell(player, SPELL_FOLLOVER_PRIEST_ALLIANCE);
                if (player->GetTeam() == HORDE)
                    player->CastSpell(player, SPELL_FOLLOVER_PRIEST_HORDE);
            }
            if (player->getClass() == CLASS_DEATH_KNIGHT)
                player->CastSpell(player, SPELL_FOLLOVER_DK);
            if (player->getClass() == CLASS_SHAMAN)
                player->CastSpell(player, SPELL_FOLLOVER_SHAMAN);
            if (player->getClass() == CLASS_MAGE)
                player->CastSpell(player, SPELL_FOLLOVER_MAGE);
            if (player->getClass() == CLASS_WARLOCK)
                player->CastSpell(player, SPELL_FOLLOVER_WARLOCK);
            if (player->getClass() == CLASS_MONK)
                player->CastSpell(player, SPELL_FOLLOVER_MONK);
            if (player->getClass() == CLASS_DRUID)
                player->CastSpell(player, SPELL_FOLLOVER_DRUID);
            if (player->getClass() == CLASS_DEMON_HUNTER)
                player->CastSpell(player, SPELL_FOLLOVER_DH);
        }
    }
};

// 192465 
class spell_teleport_the_skyfire : public SpellScript
{
    PrepareSpellScript(spell_teleport_the_skyfire);

    SpellCastResult CheckRequirement()
    {
        if (Player* player = GetCaster()->ToPlayer())
            if (player->GetQuestObjectiveData(38035, 96644))
                return SPELL_CAST_OK;

        return SPELL_FAILED_BAD_TARGETS;
    }
    
    void HandleOnCast()
    {
        if (Unit* caster = GetCaster())
            caster->ToPlayer()->KilledMonsterCredit(92122);
    }
    
    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_teleport_the_skyfire::CheckRequirement);
        OnCast += SpellCastFn(spell_teleport_the_skyfire::HandleOnCast);
    }
};

void AddSC_zone_dalaran_legion() 
{
    RegisterCreatureAI(npc_emissary_auldbridge);

    RegisterSpellScript(spell_teleport_the_skyfire);

    RegisterQuestScript(quest_blink_of_an_eye);
}
