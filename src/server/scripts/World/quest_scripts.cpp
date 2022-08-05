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

void AddSC_quest_scripts() 
{
    RegisterQuestScript(quest_blink_of_an_eye);
}
