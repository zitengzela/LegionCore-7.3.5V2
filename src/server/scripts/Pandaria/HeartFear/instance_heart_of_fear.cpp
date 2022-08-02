//UWoWCore
//Heart of Fear

#include "VMapFactory.h"
#include "heart_of_fear.h"

const DoorData doorData[] =
{
    {GO_VIZIER_EX_DOOR,   DATA_VIZIER_ZORLOK, DOOR_TYPE_PASSAGE, 0},
    {GO_TAYAK_EX_DOOR,    DATA_LORD_TAYAK,    DOOR_TYPE_PASSAGE, 0},
    {GO_GARALON_ENT_DOOR, DATA_LORD_TAYAK,    DOOR_TYPE_PASSAGE, 0},
    {GO_GARALON_EX_DOOR,  DATA_GARALON,       DOOR_TYPE_PASSAGE, 0},
    {GO_MELJARAK_EX_DOOR, DATA_MELJARAK,      DOOR_TYPE_PASSAGE, 0},
    {GO_UNSOK_EN_DOOR,    DATA_MELJARAK,      DOOR_TYPE_PASSAGE, 0},
    {GO_UNSOK_EX_DOOR,    DATA_UNSOK,         DOOR_TYPE_PASSAGE, 0},
    {0,                   0,                  DOOR_TYPE_PASSAGE, 0}
};

class instance_heart_of_fear : public InstanceMapScript
{
public:
    instance_heart_of_fear() : InstanceMapScript("instance_heart_of_fear", 1009) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_heart_of_fear_InstanceMapScript(map);
    }

    struct instance_heart_of_fear_InstanceMapScript : public InstanceScript
    {
        instance_heart_of_fear_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //GameObjects
        ObjectGuid vizierentdoorGuid;
        ObjectGuid vizierexdoorGuid;
        ObjectGuid tayakexdoorGuid;
        ObjectGuid garalonentdoorGuid;
        ObjectGuid meljarakexdoorGuid;
        ObjectGuid unsokendoorGuid;
        ObjectGuid unsokexdoorGuid;
        ObjectGuid empresscocoonGuid;

        GuidVector vizierarenadoorGuids;
        GuidVector garaloncdoorGuids;
        GuidVector garalonexdoorGuids;

        //Creature
        ObjectGuid zorlokGuid;
        ObjectGuid gascontrollerGuid;
        ObjectGuid tayakGuid;
        ObjectGuid garalonGuid;
        ObjectGuid meljarakGuid;
        ObjectGuid unsokGuid;
        ObjectGuid ambermonsterGuid;
        ObjectGuid shekzeerGuid;

        ObjectGuid srathik[3];
        ObjectGuid zarthik[3];
        ObjectGuid korthik[3];
        GuidVector meljaraksoldiersGuids;
        
        void Initialize() override
        {
            SetBossNumber(7);
            LoadDoorData(doorData);

            //GameObject
            vizierentdoorGuid.Clear();
            vizierexdoorGuid.Clear();
            tayakexdoorGuid.Clear();
            garalonentdoorGuid.Clear();
            meljarakexdoorGuid.Clear();
            unsokendoorGuid.Clear();
            unsokexdoorGuid.Clear();
            empresscocoonGuid.Clear();

            vizierarenadoorGuids.clear();
            garaloncdoorGuids.clear();
            garalonexdoorGuids.clear();

            //Creature
            zorlokGuid.Clear();
            gascontrollerGuid.Clear();
            tayakGuid.Clear();
            garalonGuid.Clear();
            meljarakGuid.Clear();
            unsokGuid.Clear();
            ambermonsterGuid.Clear();
            shekzeerGuid.Clear();

            for (uint8 n = 0; n < 3; n++)
            {
                srathik[n].Clear();
                zarthik[n].Clear();
                korthik[n].Clear();
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            { 
            case NPC_VIZIER_ZORLOK:
                zorlokGuid = creature->GetGUID();
                break;
            case NPC_GAS_CONTROLLER:
                gascontrollerGuid = creature->GetGUID();
                break;
            case NPC_LORD_TAYAK:
                tayakGuid = creature->GetGUID();
                break;
            case NPC_GARALON:
                garalonGuid = creature->GetGUID();
                break;
            case NPC_MELJARAK:
                meljarakGuid = creature->GetGUID();
                break;
            case NPC_SRATHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (!srathik[n])
                    {
                        srathik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(srathik[n]);
                        break;
                    }
                }
                break;
            case NPC_ZARTHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (!zarthik[n])
                    {
                        zarthik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(zarthik[n]);
                        break;
                    }
                }
                break;
            case NPC_KORTHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (!korthik[n])
                    {
                        korthik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(korthik[n]);
                        break;
                    }
                }
                break;
            case NPC_UNSOK:
                unsokGuid = creature->GetGUID();
                break;
            case NPC_AMBER_MONSTER:
                ambermonsterGuid = creature->GetGUID();
                break;
            case NPC_SHEKZEER:
                shekzeerGuid = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_VIZIER_ENT_DOOR:
                vizierentdoorGuid = go->GetGUID();
                break;
            case GO_VIZIER_ARENA_DOOR:
                vizierarenadoorGuids.push_back(go->GetGUID());
                break;
            case GO_VIZIER_EX_DOOR:
                AddDoor(go, true);
                vizierexdoorGuid = go->GetGUID();
                break;
            case GO_TAYAK_EX_DOOR:
                AddDoor(go, true);
                tayakexdoorGuid = go->GetGUID();
                break;
            case GO_GARALON_ENT_DOOR:
                AddDoor(go, true);
                garalonentdoorGuid = go->GetGUID();
                break;
            case GO_GARALON_COMBAT_DOOR:
                garaloncdoorGuids.push_back(go->GetGUID());
                break;
            case GO_GARALON_EX_DOOR:
                AddDoor(go, true);
                garalonexdoorGuids.push_back(go->GetGUID());
                break;
            case GO_MELJARAK_EX_DOOR:
                AddDoor(go, true);
                meljarakexdoorGuid = go->GetGUID();
                break;
            case GO_UNSOK_EN_DOOR:
                AddDoor(go, true);
                unsokendoorGuid = go->GetGUID();
                break;
            case GO_UNSOK_EX_DOOR:
                AddDoor(go, true);
                unsokexdoorGuid = go->GetGUID();
                break;
            case GO_EMPRESS_COCOON:
                empresscocoonGuid = go->GetGUID();
                break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;
            
            switch (id)
            {
            case DATA_VIZIER_ZORLOK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(vizierentdoorGuid, true);
                        for (GuidVector::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case DONE:
                        HandleGameObject(vizierentdoorGuid, true);
                        HandleGameObject(vizierexdoorGuid, true); 
                        for (GuidVector::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(vizierentdoorGuid, false);
                        for (GuidVector::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    }
                    break;
                }
            case DATA_LORD_TAYAK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(vizierexdoorGuid, true);
                        break;
                    case DONE:
                        HandleGameObject(vizierexdoorGuid, true);
                        HandleGameObject(tayakexdoorGuid, true);
                        HandleGameObject(garalonentdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(vizierexdoorGuid, false);
                        break;
                    }
                    break;
                }
            case DATA_GARALON:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (GuidVector::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case DONE:
                        for (GuidVector::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        
                        for (GuidVector::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        break;
                    case IN_PROGRESS:
                        for (GuidVector::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    }
                    break;
                }
            case DATA_MELJARAK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (GuidVector::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);

                        for (GuidVector::const_iterator guid = meljaraksoldiersGuids.begin(); guid != meljaraksoldiersGuids.end(); guid++)
                        {
                            if (Creature* soldier = instance->GetCreature(*guid))
                            {
                                if (!soldier->isAlive())
                                {
                                    soldier->Respawn();
                                    soldier->GetMotionMaster()->MoveTargetedHome();
                                }
                                else if (soldier->isAlive() && soldier->isInCombat())
                                    soldier->AI()->EnterEvadeMode();
                            }
                        }
                        break;
                    case IN_PROGRESS:
                        for (GuidVector::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, false);

                        for (GuidVector::const_iterator guid = meljaraksoldiersGuids.begin(); guid != meljaraksoldiersGuids.end(); guid++)
                        {
                            if (Creature* soldier = instance->GetCreature(*guid))
                            {
                                if (soldier->isAlive() && !soldier->isInCombat())
                                    soldier->AI()->DoZoneInCombat(soldier, 100.0f);
                            }
                        }
                        break;
                    case DONE:
                        HandleGameObject(meljarakexdoorGuid, true);
                        HandleGameObject(unsokendoorGuid, true);
                        for (GuidVector::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        break;
                    }
                    break;
                }
            case DATA_UNSOK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(unsokendoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(unsokendoorGuid, false);
                        break;
                    case DONE:
                        HandleGameObject(unsokendoorGuid, true);
                        HandleGameObject(unsokexdoorGuid, true);
                        break;
                    }
                    break;
                }
            case DATA_SHEKZEER:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case DONE:
                        HandleGameObject(unsokexdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(unsokexdoorGuid, false);
                        break;
                    }
                    break;
                }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override {}

        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_VIZIER_ZORLOK:
                    return zorlokGuid;
                case NPC_GAS_CONTROLLER:
                    return gascontrollerGuid;
                case NPC_LORD_TAYAK:
                    return tayakGuid;
                case NPC_GARALON:
                    return garalonGuid;
                case NPC_MELJARAK:
                    return meljarakGuid;
                //Meljarak Soldiers
                case NPC_SRATHIK_1:
                    return srathik[0];
                case NPC_SRATHIK_2:
                    return srathik[1];
                case NPC_SRATHIK_3:
                    return srathik[2];
                case NPC_ZARTHIK_1:
                    return zarthik[0];
                case NPC_ZARTHIK_2:
                    return zarthik[1];
                case NPC_ZARTHIK_3:
                    return zarthik[2];
                case NPC_KORTHIK_1:
                    return korthik[0];
                case NPC_KORTHIK_2:
                    return korthik[1];
                case NPC_KORTHIK_3:
                    return korthik[2];
                //
                case NPC_UNSOK:
                    return unsokGuid;
                case NPC_SHEKZEER:
                    return shekzeerGuid;
                case GO_EMPRESS_COCOON:
                    return empresscocoonGuid;
            }
            return ObjectGuid::Empty;
        }

        bool IsWipe() const override
        {
            Map::PlayerList const& PlayerList = instance->GetPlayers();

            if (PlayerList.isEmpty())
                return true;

            for (Map::PlayerList::const_iterator Itr = PlayerList.begin(); Itr != PlayerList.end(); ++Itr)
            {
                Player* player = Itr->getSource();

                if (!player)
                    continue;

                if (player->isAlive() && !player->isGameMaster() && !player->HasAura(115877)) // Aura 115877 = Totaly Petrified
                    return false;
            }

            return true;
        }

        std::string GetSaveData() override
        {
            std::ostringstream saveStream;
            saveStream << GetBossSaveData() << " ";
            return saveStream.str();
        }

        void Load(const char* data) override
        {
            std::istringstream loadStream(LoadBossState(data));
            uint32 buff;
            for (uint32 i = 0; i < 7; ++i)
                loadStream >> buff;
        }
    };
};

void AddSC_instance_heart_of_fear()
{
    new instance_heart_of_fear();
}
