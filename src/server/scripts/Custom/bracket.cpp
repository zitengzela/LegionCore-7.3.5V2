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
#include "ObjectMgr.h"
#include "Chat.h"
#include "Bracket.h"

class rbg_commandscript : public CommandScript
{
public:
    rbg_commandscript() : CommandScript("rbg_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> rgbSetCommandTable =
        {
            { "info",          SEC_PLAYER,               false,  &HandleRBGCommand,         ""},
            { "join",          SEC_MODERATOR,            false,  &HandleJoinCommand,        ""}
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "bracket",       SEC_PLAYER,               true,  NULL,  "", rgbSetCommandTable }
        };
        return commandTable;
    }

    static bool HandleRBGCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Bracket* rbg = player->getBracket(MS::Battlegrounds::BracketType::RatedBattleground);
        handler->PSendSysMessage("Rating: %u;", rbg->getRating());
        handler->PSendSysMessage("Wins: %u; Total: %u;", rbg->GetBracketInfo(BRACKET_SEASON_WIN), rbg->GetBracketInfo(BRACKET_SEASON_GAMES));
        return true;
    }

    //! 0 - MS::Battlegrounds::BracketType::Arena2v2, 3 - MS::Battlegrounds::BracketType::RatedBattleground, look at enum of BracketType
    static bool HandleJoinCommand(ChatHandler* handler, const char* args)
    {
       
        handler->GetSession()->JoinBracket(MS::Battlegrounds::BracketType::RatedBattleground);
        return true;
    }
};

void AddSC_bracket_commandscript()
{
    new rbg_commandscript();
}
