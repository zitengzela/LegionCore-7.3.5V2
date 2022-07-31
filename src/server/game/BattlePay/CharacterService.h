
#ifndef _sCharService
#define _sCharService

class CharacterService
{
	CharacterService() = default;
	~CharacterService() = default;
	
public:
    void SetRename(Player* player);
    void ChangeFaction(Player* player);
    void ChangeRace(Player* player);
    void Customize(Player* player);
    void Boost(Player* player);
    void RestoreDeletedCharacter(WorldSession* session);
	void Promo(Player* player);
	void PremadePve(Player* player);
	void PremadePvp(Player* player);
	void Level(Player* player);
	void AppareanceArtifac(Player* player);
	void Gold20k(Player* player);
	void Gold50k(Player* player);
	void Gold100k(Player* player);
	void Gold250k(Player* player);
	void Gold500k(Player* player);
	void Gold1000k(Player* player);
	void Currency1(Player* player);
	void Currency2(Player* player);
	// Profesiones Primarias
	void ProfPriAlchemy(Player* player);
	void ProfPriSastre(Player* player);
	void ProfPriJoye(Player* player);
	void ProfPriHerre(Player* player);
	void ProfPriPele(Player* player);
	void ProfPriInge(Player* player);
	void ProfPriInsc(Player* player);
	void ProfPriEncha(Player* player);
	void ProfPriDesu(Player* player);
	void ProfPriMing(Player* player);
	void ProfPriHerb(Player* player, WorldSession* session);
	// Profesiones Secundarias
	void ProfSecCoci(Player* player);
	void ProfSecPrau(Player* player);
	void ProfSecArque(Player* player);
	void ProfSecFish(Player* player);
	void VueloDL(Player* player);
	void Unbinall(Player* player);
	// Reputaciones
	void RepClassic(Player* player);
	void RepBurnig(Player* player);
	void RepTLK(Player* player);
	void RepCata(Player* player);
	void RepPanda(Player* player);
	void RepDraenor(Player* player);
	void RepLegion(Player* player);
	void RacesAlliedNightborne(Player* player);
	void RacesAlliedHighmountainTauren(Player* player);
	void RacesAlliedVoidElf(Player* player);
	void RacesAlliedLighForgedDraenei(Player* player);
	void ArtifactLevel(Player* player);
	void ArtifactPower101(Player* player);
	void GuildRename(Player* player);
	void HonorLvl(Player* target);

	static CharacterService* instance();
};

#define sCharacterService CharacterService::instance()

#endif