/*
* Pichulin - Manu
*/

#ifndef SOURCESERVICE_H
#define SOURCESERVICE_H

#define EXISTING   "Ya has aprendido esta profesion"
#define ALREADY_KNOWN   "Ya has aprendido dos profesiones principales"

#include "Language.h"
#include "SpellPackets.h"
#include "Chat.h"

bool IsSecondarySkill(SkillType skill)
{
	return skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
}

bool PlayerHasItemOrSpell(const Player* plr, uint32 itemId, uint32 spellId)
{
	return plr->HasItemCount(itemId, 1, true) || const_cast<Player*>(plr)->HasSpell(spellId);
}

void LearnSkillRecipesHelper(Player* player, uint32 skill_id)
{
	uint32 classmask = player->getClassMask();

	WorldPackets::Spells::LearnedSpells packet;
	for (SkillLineAbilityEntry const* skillLine : sDB2Manager._skillLineAbilityContainer[skill_id])
	{
		// not high rank
		if (skillLine->SupercedesSpell)
			continue;

		// skip racial skills
		if (skillLine->RaceMask != 0)
			continue;

		// skip wrong class skills
		if (skillLine->ClassMask && (skillLine->ClassMask & classmask) == 0)
			continue;

		SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->Spell);
		if (!spellInfo)
			continue;

		if (player->addSpell(skillLine->Spell, true, true, false, false))
			packet.SpellID.push_back(skillLine->Spell);
	}
	player->SendDirectMessage(packet.Write());
}

bool LearnAllRecipesInProfession(Player* player, SkillType skill)
{
	SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
	if (!SkillInfo)
		return false;

	ChatHandler handler(player->GetSession());
	player->GetAchievementMgr()->m_canUpdateAchiev = 0;
	LearnSkillRecipesHelper(player, SkillInfo->ID);
	player->GetAchievementMgr()->m_canUpdateAchiev = 1;

	char const* skill_name = SkillInfo->DisplayName[DEFAULT_LOCALE].Str[DEFAULT_LOCALE];
	player->SetSkill(SkillInfo->ID, player->GetSkillStep(SkillInfo->ID), 800, 800);
	handler.PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name);
	return true;
}

void CompleteLearnProfession(Player* player, SkillType skill)
{
	if (!player->GetFreePrimaryProfessionPoints() && !IsSecondarySkill(skill))
		player->GetSession()->SendNotification("¡Ya has estudiado dos profesiones!", player->GetGUID());
	else
	{
		if (!LearnAllRecipesInProfession(player, skill))
			player->GetSession()->SendNotification("¡Error interno!", player->GetGUID());
	}
}
bool PlayerAlreadyHasTwoProfessions(Player* player)
{
	uint32 skillCount = 0;

	if (player->HasSkill(SKILL_MINING))
		skillCount++;
	if (player->HasSkill(SKILL_SKINNING))
		skillCount++;
	if (player->HasSkill(SKILL_HERBALISM))
		skillCount++;

	if (skillCount >= 2)
		return true;

	for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
	{
		SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(i);
		if (!SkillInfo)
			continue;

		if (SkillInfo->CategoryID == SKILL_CATEGORY_SECONDARY)
			continue;

		if ((SkillInfo->CategoryID != SKILL_CATEGORY_PROFESSION) || !SkillInfo->CanLink)
			continue;

		uint32 skillID = SkillInfo->ID;
		if (player->HasSkill(skillID))
			skillCount++;

		if (skillCount >= 2)
			return true;
	}

	return false;
}


#endif