
#include "ScriptMgr.h"

class test_commandscript : public CommandScript
{
public:
    test_commandscript() : CommandScript("test_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand TestTable[] =
        {
            { "summon",             SEC_GAMEMASTER,         true,  &HandleTestSummon,                   "", NULL },
            { "",                   SEC_GAMEMASTER,         true,  &HandleTestSummon,                   "", NULL },
            { NULL,                 0,                      false, NULL,                                "", NULL }
        };

        static ChatCommand CommandTable[] =
        {
             { "test",                  SEC_ADMINISTRATOR,  true,   nullptr,                        "", TestTable },
             { "sizeof",                SEC_GAMEMASTER,     false,  &HandleSizeofCommand,           "", nullptr },
             { nullptr,                 0,                  false,  nullptr,                        "", nullptr }
        };

        return CommandTable;
    }

    static bool HandleTestSummon(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* countStr = strtok((char*)args, " ");
        uint32 count = (uint32)atoi(countStr);
        uint32 summoned = 0;

        for (int i = 0; i <= count; ++i)
            if (handler->GetSession()->GetPlayer()->SummonCreature(44548, 16226.2f, 16257.0f, 13.20f, 1.65f))
                summoned++;

        handler->PSendSysMessage("TestSummon count %u summoned %u", count, summoned);
        return true;
    }

    static bool HandleSizeofCommand(ChatHandler* handler, char const* args)
    {
        Player* _player = handler->GetSession()->GetPlayer();
        _player->PrintPlayerSize();

        if (Unit* target = handler->getSelectedUnit())
            if (Creature* creature = target->ToCreature())
                creature->PrintCreatureSize(_player);

        handler->PSendSysMessage("Object size %u", sizeof(Object));
        handler->PSendSysMessage("WorldObject size %u", sizeof(WorldObject));
        handler->PSendSysMessage("Unit size %u", sizeof(Unit));
        handler->PSendSysMessage("Player size %u", sizeof(Player));
        handler->PSendSysMessage("Pet size %u", sizeof(Pet));
        handler->PSendSysMessage("Creature size %u", sizeof(Creature));
        handler->PSendSysMessage("Corpse size %u", sizeof(Corpse));
        handler->PSendSysMessage("GameObject size %u", sizeof(GameObject));
        handler->PSendSysMessage("DynamicObject size %u", sizeof(DynamicObject));
        handler->PSendSysMessage("Transport size %u", sizeof(Transport));
        handler->PSendSysMessage("AreaTrigger size %u", sizeof(AreaTrigger));
        handler->PSendSysMessage("Conversation size %u", sizeof(Conversation));
        handler->PSendSysMessage("EventObject size %u", sizeof(EventObject));
        handler->PSendSysMessage("LootItem size %u", sizeof(LootItem));
        handler->PSendSysMessage("Loot size %u", sizeof(Loot));
        handler->PSendSysMessage("Vehicle size %u", sizeof(Vehicle));
        handler->PSendSysMessage("Item size %u", sizeof(Item));
        handler->PSendSysMessage("Vector for Unit size %u", sizeof(std::vector<Unit*>));
        handler->PSendSysMessage("Vector for Unit size %u", sizeof(std::vector<uint32>));
        std::vector<Unit*> testList;
        testList.resize(1000);
        handler->PSendSysMessage("Vector for Unit size %u", sizeof(testList));

        return true;
    }
};

void AddSC_test_commandscript()
{
    new test_commandscript();
}
