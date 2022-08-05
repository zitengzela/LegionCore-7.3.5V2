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

// 47890
struct quest_visions_of_torment : public QuestScript
{
    quest_visions_of_torment() : QuestScript("quest_visions_of_torment") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus oldStatus, QuestStatus /*newStatus*/) override
    {
        if (oldStatus == QUEST_STATUS_NONE)
            if (player->GetQuestStatus(47890) == QUEST_STATUS_INCOMPLETE)
                player->SummonCreature(124595, Position(983.268f, 1665.89f, 525.221f, 2.56006f), TEMPSUMMON_TIMED_DESPAWN, 50000, 0, player->GetGUID());
    }
};

void AddSC_zone_krokuun()
{
    RegisterQuestScript(quest_visions_of_torment);
}
