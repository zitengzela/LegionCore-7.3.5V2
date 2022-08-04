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
#include "QuestData.h"

// Example
//struct quest_speaker_of_the_horde : public QuestScript
//{
//    quest_speaker_of_the_horde() : QuestScript("quest_speaker_of_the_horde") { }
//
//    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
//    {
//        if (newStatus == QUEST_STATUS_NONE || newStatus == QUEST_STATUS_REWARDED)
//        {
//            Quest const* questt = sQuestDataStore->GetQuestTemplate(34378);
//            player->AddQuest(questt, nullptr);
//        }
//    }
//};

void AddSC_quest_scripts()
{
    // Example
    //RegisterQuestScript(quest_speaker_of_the_horde);
}
