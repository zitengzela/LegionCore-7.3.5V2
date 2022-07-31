#include "BattlePayPackets.h"
#include "BattlePayMgr.h"
#include "BattlePayData.h"
#include "CharacterService.h"
#include "DatabaseEnv.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include <stdsoap2.h>
#include "QuestData.h"
#include <BattlenetHandler.cpp>
#include "SourceService.h"
#include "GameTables.h"
#include "Guild.h"
#include "GuildPackets.h"
#include "GuildMgr.h"

CharacterService* CharacterService::instance()
{
    static CharacterService instance;
    return &instance;
}

void CharacterService::SetRename(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_RENAME);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_RENAME);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::ChangeFaction(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CHANGE_FACTION);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::ChangeRace(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CHANGE_RACE);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::Customize(Player* player)
{
    player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);

    auto stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
    stmt->setUInt16(0, AT_LOGIN_CUSTOMIZE);
    stmt->setUInt64(1, player->GetGUID().GetCounter());
    CharacterDatabase.Execute(stmt);
}

void CharacterService::Boost(Player* player)
{
    player->GetSession()->AddAuthFlag(AT_AUTH_FLAG_90_LVL_UP);
}

void CharacterService::RestoreDeletedCharacter(WorldSession* session)
{
    session->AddAuthFlag(AT_AUTH_FLAG_RESTORE_DELETED_CHARACTER);
}

void CharacterService::Promo(Player* player)
{
	// Ridding
	player->learnSpell(33388, false);
	player->learnSpell(33391, false);
	player->learnSpell(34090, false);
	player->learnSpell(34091, false);
	player->learnSpell(90265, false);
	player->learnSpell(54197, false);
	player->learnSpell(90267, false);
	// Mounts
	player->learnSpell(63956, false); // https://es.wowhead.com/spell=63956/protodraco-vinculahierro
	player->SendCustomMessage("|cffff8000  En hora buena..");
}

void CharacterService::PremadePve(Player* player)
{
	// Bags
	for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
		if (Item* bag = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
			player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

	for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
		player->EquipNewItem(slot, 1100, true);

	player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
	player->SetUInt32Value(PLAYER_FIELD_XP, 0);
	player->InitTalentForLevel();
	player->ModifyMoney(200000000);
	player->AddItem(50435, 1); // Montura vermis
	player->EquipNewItem(EQUIPMENT_SLOT_NECK, 131736, true); // Cuello
	player->EquipNewItem(EQUIPMENT_SLOT_BACK, 139248, 1); // Capa
	player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 139237, true);
	player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 139236, true); // Anillo
	player->learnSpell(33388, false); // Equitacion
	player->learnSpell(33391, false);
	player->learnSpell(34090, false);
	player->learnSpell(34091, false);
	player->learnSpell(90265, false);
	player->learnSpell(54197, false);
	player->learnSpell(90267, false);
	player->learnSpell(115913, true);
	player->learnSpell(110406, true);
	player->learnSpell(104381, true);

	if (player->getClass() == CLASS_DEATH_KNIGHT)
	{
		player->learnSpell(53428, true); // Spell runas de forjas
		player->learnSpell(48778, true); // Bayo
		player->learnSpell(50977, true); // porton
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, true);//Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, true); // abalorio1
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124386, true); //  espada de una mano 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124385, true);  // espada de una mano
		player->AddItem(124388, 1); // arma tanque y dps

	}
	if (player->getClass() == CLASS_MAGE)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, true); // disciplina // sagrado // sombra 

	}
    if (player->getClass() == CLASS_DRUID)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->AddItem(139326, 1);//Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, true); // heler
		player->AddItem(124378, 1); // feral

	}
	if (player->getClass() == CLASS_HUNTER)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139214, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139222, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139212, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 141694, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139221, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139215, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139218, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139219, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124361, true); // punteria // bestias 
		player->AddItem(124368, 1); //supervivencia

	}
	if (player->getClass() == CLASS_MONK)
	{
		player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
		player->InitTalentForLevel();
		player->SetUInt32Value(PLAYER_FIELD_XP, 0);
		//   add end - level quests
		bool IsPandarenNeutral = player->getRace() == RACE_PANDAREN_NEUTRAL;
		std::vector<uint32> questsToAdd;
		if (player->GetTeam() == HORDE || IsPandarenNeutral)
		{
			// quests for Pandaria map
			questsToAdd.push_back(29611);   // The Art of War
			questsToAdd.push_back(31853);   // All Aboard!
			questsToAdd.push_back(29690);   // Into the Mists
			if (player->getClass() == CLASS_DEATH_KNIGHT)
				questsToAdd.push_back(13189);
		}
		if (player->GetTeam() == ALLIANCE || IsPandarenNeutral)
		{
			// quests for Pandaria map
			questsToAdd.push_back(29547);   // The King's Command
			questsToAdd.push_back(29548);   // The Mission
			if (player->getClass() == CLASS_DEATH_KNIGHT)
				questsToAdd.push_back(13188);
		}
		// pandarens
		if (IsPandarenNeutral)
		{
			// add "A New Fate" quest
			if (Quest const* quest = sQuestDataStore->GetQuestTemplate(31450))
			{
				player->AddQuest(quest, NULL);
				player->CompleteQuest(quest->GetQuestId());
			}
			// send faction selection screen
			player->ShowNeutralPlayerFactionSelectUI();
		}
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124368, true); //  dps 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124368, true);  // dps
		player->AddItem(124378, 1); // tanke
		player->AddItem(124382, 1); // heler

	}
	if (player->getClass() == CLASS_PALADIN)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, true);//Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124374, true); //  tanke 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, true);  // escudo
		player->AddItem(124388, 1); // dps
		player->AddItem(124376, 1); // heler

	}
	if (player->getClass() == CLASS_PRIEST)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, true); // disciplina // sagrado // sombra 
        
	}
	if (player->getClass() == CLASS_ROGUE)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124367, true); //  asesinato //sutileza 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124367, true);  //  asesinato //sutileza 
		player->AddItem(124387, 1); // foragido
		player->AddItem(124387, 1); // foragido

	}
	if (player->getClass() == CLASS_SHAMAN)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139214, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139222, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139212, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 141694, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139221, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139215, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139218, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139219, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->AddItem(139326, 1); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124372, true); //  elemental // heler
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, true);  //  elemental // heler 
		player->AddItem(124359, 1); // mejora
		player->AddItem(124359, 1); // mejora
		
	}
	if (player->getClass() == CLASS_WARLOCK)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139189, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139196, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 138217, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 138212, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139193, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139190, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139191, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139195, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139321, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139326, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124382, true); // las 3 ramas

	}
	if (player->getClass() == CLASS_WARRIOR)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139231, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 138218, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139228, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 139225, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139224, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139230, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139233, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139234, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139325, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139328, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124374, true); //  tanke 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124355, true);  // escudo
		player->AddItem(124388, 1); // dps
		player->AddItem(124388, 1); // dps
		
	}
	if (player->getClass() == CLASS_DEMON_HUNTER)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad

	}

	player->SaveToDB();

}

void CharacterService::PremadePvp(Player* player)
{
	// Bags
	for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
		if (Item* bag = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
			player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

	for (int slot = INVENTORY_SLOT_BAG_START; slot < INVENTORY_SLOT_BAG_END; slot++)
		player->EquipNewItem(slot, 1100, true);

	player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
	player->SetUInt32Value(PLAYER_FIELD_XP, 0);
	player->InitTalentForLevel();
	player->ModifyMoney(200000000);
	player->AddItem(50435, 1); // Montura vermis
	player->EquipNewItem(EQUIPMENT_SLOT_NECK, 0, true); // Cuello
	player->EquipNewItem(EQUIPMENT_SLOT_BACK, 0, 1); // Capa
	player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, 0, true);
	player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, 0, true); // Anillo
	player->learnSpell(33388, false); // Equitacion
	player->learnSpell(33391, false);
	player->learnSpell(34090, false);
	player->learnSpell(34091, false);
	player->learnSpell(90265, false);
	player->learnSpell(54197, false);
	player->learnSpell(90267, false);
	player->learnSpell(115913, true);
	player->learnSpell(110406, true);
	player->learnSpell(104381, true);

	if (player->getClass() == CLASS_DEATH_KNIGHT)
	{
		player->learnSpell(53428, true); // Spell runas de forjas
		player->learnSpell(48778, true); // Bayo
		player->learnSpell(50977, true); // porton
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true);//Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true); // abalorio1
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); //  espada de una mano 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 0, true);  // espada de una mano
		player->AddItem(124388, 1); // arma tanque y dps

	}
	if (player->getClass() == CLASS_MAGE)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); // 3 ramas

	}
	if (player->getClass() == CLASS_DRUID)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Agilidad
		player->AddItem(0, 1);//Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); // heler
		player->AddItem(124378, 1); // feral

	}
	if (player->getClass() == CLASS_HUNTER)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); // punteria // bestias 
		player->AddItem(124368, 1); //supervivencia

	}
	if (player->getClass() == CLASS_MONK)
	{
		player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
		player->InitTalentForLevel();
		player->SetUInt32Value(PLAYER_FIELD_XP, 0);
		//   add end - level quests
		bool IsPandarenNeutral = player->getRace() == RACE_PANDAREN_NEUTRAL;
		std::vector<uint32> questsToAdd;
		if (player->GetTeam() == HORDE || IsPandarenNeutral)
		{
			// quests for Pandaria map
			questsToAdd.push_back(29611);   // The Art of War
			questsToAdd.push_back(31853);   // All Aboard!
			questsToAdd.push_back(29690);   // Into the Mists
			if (player->getClass() == CLASS_DEATH_KNIGHT)
				questsToAdd.push_back(13189);
		}
		if (player->GetTeam() == ALLIANCE || IsPandarenNeutral)
		{
			// quests for Pandaria map
			questsToAdd.push_back(29547);   // The King's Command
			questsToAdd.push_back(29548);   // The Mission
			if (player->getClass() == CLASS_DEATH_KNIGHT)
				questsToAdd.push_back(13188);
		}
		// pandarens
		if (IsPandarenNeutral)
		{
			// add "A New Fate" quest
			if (Quest const* quest = sQuestDataStore->GetQuestTemplate(31450))
			{
				player->AddQuest(quest, NULL);
				player->CompleteQuest(quest->GetQuestId());
			}
			// send faction selection screen
			player->ShowNeutralPlayerFactionSelectUI();
		}
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 139205, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 139209, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 139197, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 140996, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 139208, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 139201, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 139206, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 139199, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 139329, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 139334, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 124368, true); //  dps 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 124368, true);  // dps
		player->AddItem(124378, 1); // tanke
		player->AddItem(124382, 1); // heler

	}
	if (player->getClass() == CLASS_PALADIN)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true);//Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); //  tanke 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 0, true);  // escudo
		player->AddItem(124388, 1); // dps
		player->AddItem(124376, 1); // heler

	}
	if (player->getClass() == CLASS_PRIEST)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); // disciplina // sagrado // sombra 

	}
	if (player->getClass() == CLASS_ROGUE)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Agilidad
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); //  asesinato //sutileza 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 0, true);  //  asesinato //sutileza 
		player->AddItem(124387, 1); // foragido
		player->AddItem(124387, 1); // foragido

	}
	if (player->getClass() == CLASS_SHAMAN)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Agilidad
		player->AddItem(0, 1); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); //  elemental // heler
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 0, true);  //  elemental // heler 
		player->AddItem(124359, 1); // mejora
		player->AddItem(124359, 1); // mejora

	}
	if (player->getClass() == CLASS_WARLOCK)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps intelecto
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); // 3 ramas

	}
	if (player->getClass() == CLASS_WARRIOR)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Fuerza
		player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, 0, true); //  tanke 
        player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, 0, true);  // escudo
		player->AddItem(124388, 1); // dps
		player->AddItem(124388, 1); // dps

	}
	if (player->getClass() == CLASS_DEMON_HUNTER)
	{
		player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 0, true); //Head - Cabeza
		player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, 0, true); //Wrists - Muñecas
		player->EquipNewItem(EQUIPMENT_SLOT_WAIST, 0, true); //Wrais - Cintura
		player->EquipNewItem(EQUIPMENT_SLOT_HANDS, 0, true); // Hands - Manos
		player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 0, true); // Pecho
		player->EquipNewItem(EQUIPMENT_SLOT_LEGS, 0, true); // Legs - Pantalones
		player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, 0, true); // Shoulder - Hombros
		player->EquipNewItem(EQUIPMENT_SLOT_FEET, 0, true); // feet - pies
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, 0, true);
		player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 0, true); //Abalario Dps Agilidad

	}

	player->SaveToDB();
}

void CharacterService::Level(Player* player)
{
	player->GiveLevel(sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL));
	player->InitTalentForLevel();
	player->SetUInt32Value(PLAYER_FIELD_XP, 0);
	//   add end - level quests
	bool IsPandarenNeutral = player->getRace() == RACE_PANDAREN_NEUTRAL;
	std::vector<uint32> questsToAdd;
	if (player->GetTeam() == HORDE || IsPandarenNeutral)
	{
		// quests for Pandaria map
		questsToAdd.push_back(29611);   // The Art of War
		questsToAdd.push_back(31853);   // All Aboard!
		questsToAdd.push_back(29690);   // Into the Mists
		if (player->getClass() == CLASS_DEATH_KNIGHT)
			questsToAdd.push_back(13189);
	}
	if (player->GetTeam() == ALLIANCE || IsPandarenNeutral)
	{
		// quests for Pandaria map
		questsToAdd.push_back(29547);   // The King's Command
		questsToAdd.push_back(29548);   // The Mission
		if (player->getClass() == CLASS_DEATH_KNIGHT)
			questsToAdd.push_back(13188);
	}
	// pandarens
	if (IsPandarenNeutral)
	{
		// add "A New Fate" quest
		if (Quest const* quest = sQuestDataStore->GetQuestTemplate(31450))
		{
			player->AddQuest(quest, NULL);
			player->CompleteQuest(quest->GetQuestId());
		}
		// send faction selection screen
		player->ShowNeutralPlayerFactionSelectUI();
	}

}


////////////////
/// Monedas  ///
////////////////
void CharacterService::Gold20k(Player* player)
{
	player->ModifyMoney(200000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 20.000 de oro..");
}
void CharacterService::Gold50k(Player* player)
{
	player->ModifyMoney(500000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 50.000 de oro..");
}
void CharacterService::Gold100k(Player* player)
{
	player->ModifyMoney(1000000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 100.000 de oro..");
}
void CharacterService::Gold250k(Player* player)
{
	player->ModifyMoney(2500000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 250.000 de oro..");
}
void CharacterService::Gold500k(Player* player)
{
	player->ModifyMoney(5000000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 500.000 de oro..");
}
void CharacterService::Gold1000k(Player* player)
{
	player->ModifyMoney(10000000000);
	player->SendCustomMessage("|cffff8000  Se han agregado 1.000.000 de oro..");
}
void CharacterService::AppareanceArtifac(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(10460));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11165));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10743));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10748));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11163));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11160));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10747));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10602));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10853));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11144));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10746));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10461));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10460));
	player->CompletedAchievement(sAchievementStore.LookupEntry(10459));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11162));
	if (player->GetTeam() == ALLIANCE)
	{
		// Alianza
		player->CompletedAchievement(sAchievementStore.LookupEntry(10749));
		player->CompletedAchievement(sAchievementStore.LookupEntry(10743));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11165));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11167));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11169));
	}
	else // Horda
	{
		player->CompletedAchievement(sAchievementStore.LookupEntry(11170));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11168));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11166));
		player->CompletedAchievement(sAchievementStore.LookupEntry(10745));
		player->CompletedAchievement(sAchievementStore.LookupEntry(11173));
	}
	player->SendCustomMessage("|cffff8000  Nuevas apariencias Desbloqueadas..");
}
void CharacterService::Currency1(Player* player)
{
	player->ModifyCurrency(1226, 2000);
	player->SendCustomMessage("|cff00FF00Se han agregado 5.000 Fragmentos del vacio..");
}
void CharacterService::Currency2(Player* player)
{
	player->ModifyCurrency(1342, 2000);
	player->SendCustomMessage("|cff00FF00Se han agregado 1,000 Suministros del Ocaso de la Legión.");
}
/////////////////////////////
// Profesiones Primarias ///
////////////////////////////
void CharacterService::ProfPriAlchemy(Player* player)
{
	if (player->HasSkill(SKILL_ALCHEMY))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ALCHEMY);
	CompleteLearnProfession(player, SKILL_ALCHEMY);
}
void CharacterService::ProfPriSastre(Player* player)
{
	if (player->HasSkill(SKILL_TAILORING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_TAILORING);
	CompleteLearnProfession(player, SKILL_TAILORING);
}
void CharacterService::ProfPriJoye(Player* player)
{
	if (player->HasSkill(SKILL_JEWELCRAFTING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_JEWELCRAFTING);
	CompleteLearnProfession(player, SKILL_JEWELCRAFTING);
}
void CharacterService::ProfPriHerre(Player* player)
{
	if (player->HasSkill(SKILL_BLACKSMITHING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_BLACKSMITHING);
	CompleteLearnProfession(player, SKILL_BLACKSMITHING);
}
void CharacterService::ProfPriPele(Player* player)
{
	if (player->HasSkill(SKILL_LEATHERWORKING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_LEATHERWORKING);
	CompleteLearnProfession(player, SKILL_LEATHERWORKING);

}
void CharacterService::ProfPriInge(Player* player)
{
	if (player->HasSkill(SKILL_ENGINEERING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ENGINEERING);
	CompleteLearnProfession(player, SKILL_ENGINEERING);
}
void CharacterService::ProfPriInsc(Player* player)
{
	if (player->HasSkill(SKILL_INSCRIPTION))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_INSCRIPTION);
	CompleteLearnProfession(player, SKILL_INSCRIPTION);
}
void CharacterService::ProfPriEncha(Player* player)
{
	if (player->HasSkill(SKILL_ENCHANTING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_ENCHANTING);
	CompleteLearnProfession(player, SKILL_ENCHANTING);
}
void CharacterService::ProfPriDesu(Player* player)
{
	if (player->HasSkill(SKILL_SKINNING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_SKINNING);
	CompleteLearnProfession(player, SKILL_SKINNING);
}
void CharacterService::ProfPriMing(Player* player)
{
	if (player->HasSkill(SKILL_MINING))
	{
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_MINING);
	CompleteLearnProfession(player, SKILL_MINING);
}
void CharacterService::ProfPriHerb(Player* player, WorldSession* session)
{
	Battlepay::PaymentFailed;
	Battlepay::PurchaseDenied;
	Battlepay::Purchase purchase;
	if (player->HasSkill(SKILL_HERBALISM))
	{
		player->SendCustomMessage(GetCustomMessage(Battlepay::CustomMessage::StoreBuyFailed));
		Battlepay::Error::PurchaseDenied;
		player->GetSession()->SendNotification(EXISTING, LANG_UNIVERSAL, NULL);
		return;
	}
	if (PlayerAlreadyHasTwoProfessions(player))
	{
		Battlepay::Error::PurchaseDenied;
		player->SendCustomMessage(GetCustomMessage(Battlepay::CustomMessage::StoreBuyFailed));
		player->GetSession()->SendNotification(ALREADY_KNOWN, LANG_UNIVERSAL, NULL);
		return;
	}
	else
		player->HasSkill(SKILL_HERBALISM);
	CompleteLearnProfession(player, SKILL_HERBALISM);
}
/////////////////////////////
// Profesiones Secundarias //
/////////////////////////////
void CharacterService::ProfSecCoci(Player* player)
{
	player->HasSkill(SKILL_COOKING);
	CompleteLearnProfession(player, SKILL_COOKING);
	player->GetSession()->SendNotification("|cff00FF00Has aprendido Cocina con todas sus recetas y subido al maximo nivel");
}
void CharacterService::ProfSecPrau(Player* player)
{
	player->HasSkill(SKILL_FIRST_AID);
	CompleteLearnProfession(player, SKILL_FIRST_AID);
	player->GetSession()->SendNotification("|cff00FF00Has aprendido Primeros Auxilio con todas sus recetas y subido al maximo nivel");
}
void CharacterService::ProfSecArque(Player* player)
{
	player->learnSpell(80836, false);
	player->learnSpell(89129, false);
	player->learnSpell(89723, false);
	player->learnSpell(89724, false);
	player->learnSpell(89725, false);
	player->learnSpell(89726, false);
	player->learnSpell(89727, false);
	player->learnSpell(110394, false);
	player->learnSpell(158763, false);
	player->learnSpell(201709, false);
	CompleteLearnProfession(player, SKILL_ARCHAEOLOGY);
	player->GetSession()->SendNotification("|cff00FF00Has aprendido Arqueologia con todas sus recetas y subido al maximo nivel");
}
void CharacterService::ProfSecFish(Player* player)
{
	player->learnSpell(7733, false);
	player->learnSpell(7734, false);
	player->learnSpell(18249, false);
	player->learnSpell(19889, false);
	player->learnSpell(33100, false);
	player->learnSpell(51293, false);
	player->learnSpell(88869, false);
	player->learnSpell(110412, false);
	player->learnSpell(158744, false);
	player->learnSpell(210829, false);
	player->HasSkill(SKILL_FISHING);
	CompleteLearnProfession(player, SKILL_FISHING);
	player->GetSession()->SendNotification("|cff00FF00Has aprendido Pesca con todas sus recetas y subido al maximo nivel");
}
// Vuelo Legion y Draenor
void CharacterService::VueloDL(Player* player)
{
	player->AddItem(128706, 1);
	player->CompletedAchievement(sAchievementStore.LookupEntry(10018));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11190));
	player->CompletedAchievement(sAchievementStore.LookupEntry(11446));
	player->GetSession()->SendNotification("|cff00FF00Has aprendido poder volar en las Islas Abruptas, Costas Abruptas y Draenor");
}
// Reiniciar Bandas y Mazmorras
void CharacterService::Unbinall(Player* player)
{
	for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
	{
		Player::BoundInstancesMap& binds = player->GetBoundInstances(Difficulty(i));
		for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
		{
			InstanceSave* save = itr->second.save;
			if (itr->first != player->GetMapId())
				player->UnbindInstance(itr, Difficulty(i));
			else
				++itr;
		}
	}
	player->GetSession()->SendNotification("|cff00FF00Se Han Reiniciado todas las mazmorras y bandas");
}

void CharacterService::RepClassic(Player* player)
{
	player->SetReputation(21, 42000);
	player->SetReputation(576, 42000);
	player->SetReputation(87, 42000);
	player->SetReputation(92, 42000);
	player->SetReputation(93, 42000);
	player->SetReputation(609, 42000);
	player->SetReputation(529, 42000);
	player->SetReputation(909, 42000);
	player->SetReputation(369, 42000);
	player->SetReputation(59, 42000);
	player->SetReputation(910, 42000);
	player->SetReputation(349, 42000);
	player->SetReputation(809, 42000);
	player->SetReputation(749, 42000);
	player->SetReputation(270, 42000);
	player->SetReputation(470, 42000);
	player->SetReputation(577, 42000);
	player->SetReputation(70, 42000);
	player->SetReputation(1357, 42000);
	player->SetReputation(1975, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(890, 42000);
		player->SetReputation(1691, 42000);
		player->SetReputation(1419, 42000);
		player->SetReputation(69, 42000);
		player->SetReputation(930, 42000);
		player->SetReputation(47, 42000);
		player->SetReputation(1134, 42000);
		player->SetReputation(54, 42000);
		player->SetReputation(730, 42000);
		player->SetReputation(509, 42000);
		player->SetReputation(1353, 42000);
		player->SetReputation(72, 42000);
		player->SetReputation(589, 42000);
	}
	else // Repu Horda
	{
		player->SetReputation(1690, 42000);
		player->SetReputation(1374, 42000);
		player->SetReputation(1133, 42000);
		player->SetReputation(81, 42000);
		player->SetReputation(729, 42000);
		player->SetReputation(68, 42000);
		player->SetReputation(889, 42000);
		player->SetReputation(510, 42000);
		player->SetReputation(911, 42000);
		player->SetReputation(76, 42000);
		player->SetReputation(1352, 42000);
		player->SetReputation(530, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones Clasicas!");
	return;
}
void CharacterService::RepBurnig(Player* player)
{
	player->SetReputation(1015, 42000);
	player->SetReputation(1011, 42000);
	player->SetReputation(933, 42000);
	player->SetReputation(967, 42000);
	player->SetReputation(970, 42000);
	player->SetReputation(942, 42000);
	player->SetReputation(1031, 42000);
	player->SetReputation(1012, 42000);
	player->SetReputation(990, 42000);
	player->SetReputation(932, 42000);
	player->SetReputation(934, 42000);
	player->SetReputation(935, 42000);
	player->SetReputation(1077, 42000);
	player->SetReputation(1038, 42000);
	player->SetReputation(989, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(946, 42000);
		player->SetReputation(978, 42000);
	}
	else // Repu Horda
	{
		player->SetReputation(941, 42000);
		player->SetReputation(947, 42000);
		player->SetReputation(922, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones Burning Crusade!");
	return;
}
void CharacterService::RepTLK(Player* player)
{
	player->SetReputation(1242, 42000);
	player->SetReputation(1376, 42000);
	player->SetReputation(1387, 42000);
	player->SetReputation(1135, 42000);
	player->SetReputation(1158, 42000);
	player->SetReputation(1173, 42000);
	player->SetReputation(1171, 42000);
	player->SetReputation(1204, 42000);
	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1177, 42000);
		player->SetReputation(1174, 42000);
	}
	else // Repu Horda
	{
		player->SetReputation(1172, 42000);
		player->SetReputation(1178, 42000);
	}
	player->SetReputation(529, 42000);
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones The Lich King!");
	return;
}
void CharacterService::RepCata(Player* player)
{
	player->SetReputation(1091, 42000);
	player->SetReputation(1098, 42000);
	player->SetReputation(1106, 42000);
	player->SetReputation(1156, 42000);
	player->SetReputation(1090, 42000);
	player->SetReputation(1119, 42000);
	player->SetReputation(1073, 42000);
	player->SetReputation(1105, 42000);
	player->SetReputation(1104, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1094, 42000);
		player->SetReputation(1050, 42000);
		player->SetReputation(1068, 42000);
		player->SetReputation(1126, 42000);
		player->SetReputation(1037, 42000);
	}
	else // Repu Horda
	{
		player->SetReputation(1052, 42000);
		player->SetReputation(1067, 42000);
		player->SetReputation(1124, 42000);
		player->SetReputation(1064, 42000);
		player->SetReputation(1085, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones Cataclismo!");
	return;
}
void CharacterService::RepPanda(Player* player)
{
	player->SetReputation(1216, 42000);
	player->SetReputation(1435, 42000);
	player->SetReputation(1277, 42000);
	player->SetReputation(1359, 42000);
	player->SetReputation(1275, 42000);
	player->SetReputation(1492, 42000);
	player->SetReputation(1281, 42000);
	player->SetReputation(1283, 42000);
	player->SetReputation(1279, 42000);
	player->SetReputation(1273, 42000);
	player->SetReputation(1341, 42000);
	player->SetReputation(1345, 42000);
	player->SetReputation(1337, 42000);
	player->SetReputation(1272, 42000);
	player->SetReputation(1351, 42000);
	player->SetReputation(1302, 42000);
	player->SetReputation(1269, 42000);
	player->SetReputation(1358, 42000);
	player->SetReputation(1271, 42000);
	player->SetReputation(1282, 42000);
	player->SetReputation(1440, 42000);
	player->SetReputation(1270, 42000);
	player->SetReputation(1278, 42000);
	player->SetReputation(1280, 42000);
	player->SetReputation(1276, 42000);

	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1242, 42000);
		player->SetReputation(1376, 42000);
		player->SetReputation(1387, 42000);

	}
	else // Repu Horda
	{
		player->SetReputation(1388, 42000);
		player->SetReputation(1228, 42000);
		player->SetReputation(1375, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones de Pandaria!");
	return;
}
void CharacterService::RepDraenor(Player * player)
{
	player->SetReputation(1850, 42000);
	player->SetReputation(1515, 42000);
	player->SetReputation(1520, 42000);
	player->SetReputation(1732, 42000);
	player->SetReputation(1735, 42000);
	player->SetReputation(1741, 42000);
	player->SetReputation(1849, 42000);
	player->SetReputation(1737, 42000);
	player->SetReputation(1711, 42000);
	player->SetReputation(1736, 42000);
	// Repu Alianza
	if (player->GetTeam() == ALLIANCE)
	{
		player->SetReputation(1731, 42000);
		player->SetReputation(1710, 42000);
		player->SetReputation(1738, 42000);
		player->SetReputation(1733, 42000);
		player->SetReputation(1847, 42000);
		player->SetReputation(1682, 42000);
	}
	else // Repu Horda
	{
		player->SetReputation(1740, 42000);
		player->SetReputation(1681, 42000);
		player->SetReputation(1445, 42000);
		player->SetReputation(1708, 42000);
		player->SetReputation(1848, 42000);
		player->SetReputation(1739, 42000);
	}
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones de Draenor!");
	return;
}
void CharacterService::RepLegion(Player * player)
{
	player->SetReputation(1919, 42000);
	player->SetReputation(1859, 42000);
	player->SetReputation(1900, 42000);
	player->SetReputation(1899, 42000);
	player->SetReputation(1989, 42000);
	player->SetReputation(1947, 42000);
	player->SetReputation(1894, 42000);
	player->SetReputation(1984, 42000);
	player->SetReputation(1862, 42000);
	player->SetReputation(1861, 42000);
	player->SetReputation(1860, 42000);
	player->SetReputation(1815, 42000);
	player->SetReputation(1883, 42000);
	player->SetReputation(1828, 42000);
	player->SetReputation(1948, 42000);
	player->SetReputation(2018, 42000);
	player->SetReputation(1888, 42000);
	player->SetReputation(2045, 42000);
	player->SetReputation(2170, 42000);
	player->SetReputation(2165, 42000);
	player->GetSession()->SendNotification("|cff00FF00Se ha aumentado todas las Reputaciones de Legion!");
	return;
}
void CharacterService::RacesAlliedHighmountainTauren(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(10059)); // Tauren Alta Montaña
	player->CompletedAchievement(sAchievementStore.LookupEntry(12245));
	player->learnSpell(258060, false);
}

void CharacterService::RacesAlliedNightborne(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(11340)); // Nocheterna
	player->CompletedAchievement(sAchievementStore.LookupEntry(12244));
	player->learnSpell(258845, false);
}

void CharacterService::RacesAlliedVoidElf(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(12066)); // Elfos del Vacio
	player->CompletedAchievement(sAchievementStore.LookupEntry(12242));
	player->learnSpell(259202, false);
}

void CharacterService::RacesAlliedLighForgedDraenei(Player* player)
{
	player->CompletedAchievement(sAchievementStore.LookupEntry(12066)); // Draenei Forjadoz por la luz
	player->CompletedAchievement(sAchievementStore.LookupEntry(12243));
	player->learnSpell(258022, false);
}


void CharacterService::ArtifactLevel(Player* player)
{
	if (Item* artifact = player->GetArtifactWeapon())
	{
		artifact->GiveArtifactXp(2229000000, NULL, 55);
		player->SaveToDB();
		player->SendCustomMessage("|cffff8000  Se han agregado 2,229 millones poder de artefacto a tu arma..");
	}
}

void CharacterService::ArtifactPower101(Player* player)
{
	if (Item* artifact = player->GetArtifactWeapon())
	{
		artifact->GiveArtifactXp(100000000000, NULL, 55);
		player->SaveToDB();
		player->SendCustomMessage("|cffff8000  Se han agregado 100 billones poder de artefacto a tu arma..");
	}
}

void CharacterService::GuildRename(Player* player)
{
	Guild* guild = player->GetGuild();

	if (!guild)
	{
		Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PLAYER_NOT_IN_GUILD);
		return;
	}

	if (guild->GetLeaderGUID() != player->GetGUID())
	{
		Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PERMISSIONS);
		return;
	}

	guild->SetRename(true);
	player->SaveToDB();
	player->SendCustomMessage("|cffff8000  Ahora ya podras renombrar tu hermandad..");
}

void CharacterService::HonorLvl(Player* target)
{
	target->RewardHonor(NULL, 0, 22150, false);
	target->SaveToDB();
	target->SendCustomMessage("|cffff8000  Se ha Aumentado el nivel de Honor..");
}
