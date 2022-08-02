//UWoWCore
//Heart of Fear

#ifndef HEARTOFFEAR
#define HEARTOFFEAR

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
    DATA_VIZIER_ZORLOK     = 1,
    DATA_LORD_TAYAK        = 2,
    DATA_GARALON           = 3,
    DATA_MELJARAK          = 4,
    DATA_UNSOK             = 5,
    DATA_SHEKZEER          = 6,
};

enum eCreatures
{
    NPC_VIZIER_ZORLOK      = 62980,
    NPC_GAS_CONTROLLER     = 90900,
    NPC_LORD_TAYAK         = 62543,
    NPC_GARALON            = 62164,
    NPC_MELJARAK           = 62397,
    NPC_UNSOK              = 62511,
    NPC_AMBER_MONSTER      = 62711,
    NPC_SHEKZEER           = 62837,

    //Meljarak soldiers
    NPC_SRATHIK            = 65499,
    NPC_ZARTHIK            = 62408,
    NPC_KORTHIK            = 65500,
};

enum Soldiers
{
    NPC_SRATHIK_1          = 10,
    NPC_SRATHIK_2          = 11,
    NPC_SRATHIK_3          = 12,

    NPC_ZARTHIK_1          = 13,
    NPC_ZARTHIK_2          = 14,
    NPC_ZARTHIK_3          = 15,

    NPC_KORTHIK_1          = 16,
    NPC_KORTHIK_2          = 17,
    NPC_KORTHIK_3          = 18,
};

enum eGameObjects
{   
    GO_VIZIER_ENT_DOOR     = 214485,
    GO_VIZIER_ARENA_DOOR   = 212916,
    GO_VIZIER_EX_DOOR      = 214486,
    GO_TAYAK_EX_DOOR       = 214487,
    GO_GARALON_ENT_DOOR    = 214488,
    GO_GARALON_COMBAT_DOOR = 212695,
    GO_GARALON_EX_DOOR     = 214634,
    GO_MELJARAK_EX_DOOR    = 214489,
    GO_UNSOK_EN_DOOR       = 214492,
    GO_UNSOK_EX_DOOR       = 214493,
    GO_EMPRESS_COCOON      = 213277,
};

#endif HEARTOFFEAR
