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

#ifndef APPENDER_H
#define APPENDER_H

#include "Define.h"
#include "LogCommon.h"
#include <time.h>
#include <string>
#include <map>

enum LogFilterType
{
    LOG_FILTER_GENERAL             = 0,                        // This one should only be used inside Log.cpp
    LOG_FILTER_UNITS               = 1,                        // Anything related to units that doesn't fit in other categories. ie. creature formations
    LOG_FILTER_PETS                = 2,
    LOG_FILTER_VEHICLES            = 3,
    LOG_FILTER_TSCR                = 4,                        // C++ AI, instance scripts, etc.
    LOG_FILTER_DATABASE_AI         = 5,                        // SmartAI, Creature* * AI
    LOG_FILTER_MAPSCRIPTS          = 6,
    LOG_FILTER_NETWORKIO           = 7,
    LOG_FILTER_SPELLS_AURAS        = 8,
    LOG_FILTER_ACHIEVEMENTSYS      = 9,
    LOG_FILTER_CONDITIONSYS        = 10,
    LOG_FILTER_POOLSYS             = 11,
    LOG_FILTER_AUCTIONHOUSE        = 12,
    LOG_FILTER_BATTLEGROUND        = 13,
    LOG_FILTER_OUTDOORPVP          = 14,
    LOG_FILTER_CHATSYS             = 15,
    LOG_FILTER_LFG                 = 16,
    LOG_FILTER_MAPS                = 17,
    LOG_FILTER_PLAYER              = 18,                       // Any player log that does not fit in other player filters
    LOG_FILTER_PLAYER_LOADING      = 19,                       // Debug output from Player::_Load functions
    LOG_FILTER_PLAYER_ITEMS        = 20,
    LOG_FILTER_PLAYER_SKILLS       = 21,
    LOG_FILTER_PLAYER_CHATLOG      = 22,
    LOG_FILTER_LOOT                = 23,
    LOG_FILTER_GUILD               = 24,
    LOG_FILTER_TRANSPORTS          = 25,
    LOG_FILTER_SQL                 = 26,
    LOG_FILTER_GMCOMMAND           = 27,
    LOG_FILTER_REMOTECOMMAND       = 28,
    LOG_FILTER_WARDEN              = 29,
    LOG_FILTER_AUTHSERVER          = 30,
    LOG_FILTER_WORLDSERVER         = 31,
    LOG_FILTER_GAMEEVENTS          = 32,
    LOG_FILTER_CALENDAR            = 33,
    LOG_FILTER_CHARACTER           = 34,
    LOG_FILTER_ARENAS              = 35,
    LOG_FILTER_SQL_DRIVER          = 36,
    LOG_FILTER_SQL_DEV             = 37,
    LOG_FILTER_PLAYER_DUMP         = 38,
    LOG_FILTER_BATTLEFIELD         = 39,
    LOG_FILTER_SERVER_LOADING      = 40,
    LOG_FILTER_OPCODES             = 41,
    LOG_FILTER_UWOW_CORE           = 42,
    LOG_FILTER_POWER               = 43,
    LOG_FILTER_REALMLIST           = 44,
    LOG_FILTER_BATTLENET           = 45,
    LOG_FILTER_IPC                 = 46,
    LOG_FILTER_BNET_SESSION        = 47,
    LOG_FILTER_PROC                = 48,
    LOG_FILTER_DUPE                = 49,
    LOG_FILTER_DONATE              = 50,
    LOG_FILTER_BATTLEPET           = 51,
    LOG_FILTER_PROTOBUF            = 52,
    LOG_FILTER_AREATRIGGER         = 53,
    LOG_FILTER_GOLD                = 54,
    LOG_FILTER_WORLD_QUEST         = 55,
    LOG_FILTER_CHALLENGE           = 56,
    LOG_FILTER_DYNLOS              = 57,
    LOG_FILTER_PATH_GENERATOR      = 58,
    LOG_FILTER_MMAPS               = 59,
    LOG_FILTER_VMAPS               = 60,
	LOG_FILTER_UPDATE_SQL          = 61,

    LOG_FILTER_MAX
};

struct LogMessage
{
    LogMessage(LogLevel _level, LogFilterType _type, std::string&& _text);

    LogMessage(LogMessage const& /*other*/) = delete;
    LogMessage& operator=(LogMessage const& /*other*/) = delete;

    static std::string getTimeStr(time_t time);
    std::string getTimeStr();

    LogLevel level;
    LogFilterType type;
    std::string text;
    std::string prefix;
    std::string param1;
    time_t mtime;
};

class Appender
{
public:
    Appender(uint8 _id, std::string name, AppenderType type = APPENDER_NONE, LogLevel level = LOG_LEVEL_DISABLED, AppenderFlags flags = APPENDER_FLAGS_NONE);
    virtual ~Appender();

    uint8 getId() const;
    std::string const& getName() const;
    AppenderType getType() const;
    LogLevel getLogLevel() const;
    AppenderFlags getFlags() const;

    void setLogLevel(LogLevel);
    void write(LogMessage* message);
    static const char* getLogLevelString(LogLevel level);
    static const char* getLogFilterTypeString(LogFilterType type);

private:
    virtual void _write(LogMessage const* /*message*/) = 0;

    uint8 id;
    std::string name;
    AppenderType type;
    LogLevel level;
    AppenderFlags flags;
};

#endif
