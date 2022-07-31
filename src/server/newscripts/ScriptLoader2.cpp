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

#include "ScriptLoader2.h"

#ifdef SCRIPTS
//legion
void AddSC_Mardum();
void AddSC_warden_prison();
void AddSC_world_bossess_legion();
void AddSC_invasion_point_world_bosses();
void AddSC_invasion_point_argus();
void AddSC_sentinax();
void Addsc_paraxis();

void AddSC_brokenIslands();
void AddSC_instance_broken_islands();

void AddSC_instance_black_rook_hold_dungeon();  //Black Rook Hold Dungeon
void AddSC_boss_the_amalgam_of_souls();
void AddSC_boss_illysanna_ravencrest();
void AddSC_boss_smashspite_the_hateful();
void AddSC_boss_lord_kurtalos_ravencrest();

void AddSC_instance_darkheart_thicket();       //Dark Heart Thicket
void AddSC_boss_arch_druid_glaidalis();
void AddSC_boss_oakheart();
void AddSC_boss_dresaron();
void AddSC_boss_shade_of_xavius();

void AddSC_instance_eye_of_azshara();           //Eye of Azshara
void AddSC_boss_warlord_parjesh();
void AddSC_boss_lady_hatecoil();
void AddSC_boss_king_deepbeard();
void AddSC_boss_serpentrix();
void AddSC_boss_wrath_of_azshara();

void AddSC_instance_halls_of_valor();           //Halls of Valor
void AddSC_boss_odyn();
void AddSC_boss_hyrja();
void AddSC_boss_hymdall();
void AddSC_boss_fenryr();
void AddSC_boss_god_king_skovald();
void AddSC_instance_maw_of_souls();
void AddSC_boss_ymiron_the_fallen_king();
void AddSC_boss_harbaron();
void AddSC_boss_helya();

void AddSC_instance_neltharions_lair();         //Neltharions Lair
void AddSC_boss_naraxas();
void AddSC_boss_rokmora();
void AddSC_boss_ularogg_cragshaper();
void AddSC_boss_dargrul_the_underking();

void AddSC_instance_the_arcway();               //The Arcway
void AddSC_boss_ivanyr();
void AddSC_boss_corstilax();
void AddSC_boss_general_xakal();
void AddSC_boss_naltira();
void AddSC_boss_advisor_vandros();

void AddSC_instance_vault_of_the_wardens();     //Vault of the Wardens
void AddSC_boss_tirathon_saltheril();
void AddSC_boss_inquisitor_tormentorum();
void AddSC_boss_ashgolm();
void AddSC_boss_glazer();
void AddSC_boss_cordana();

void AddSC_instance_violet_hold_legion();       //Violet Hold Legion
void AddSC_boss_mindflayer_kaahrj();
void AddSC_boss_millificent_manastorm();
void AddSC_boss_festerface();
void AddSC_boss_shivermaw();
void AddSC_boss_anubesset();
void AddSC_boss_saelorn();
void AddSC_boss_blood_princess_thalena();
void AddSC_boss_fel_lord_betrug();
void AddSC_violet_hold_legion();

void AddSC_instance_court_of_stars();           //Court of Stars
void AddSC_boss_patrol_captain_gerdo();
void AddSC_boss_talixae_flamewreath();
void AddSC_boss_advisor_melandrus();

void AddSC_instance_return_to_karazhan();       //Return to Karazhan
void AddSC_boss_opera_hall();
void AddSC_boss_maiden_of_virtue_legion();
void AddSC_boss_attumen_the_huntsman();
void AddSC_boss_moroes_legion();
void AddSC_boss_the_curator();
void AddSC_boss_mana_devourer();
void AddSC_boss_shade_of_medivh();
void AddSC_boss_vizaduum_the_watcher();
void AddSC_karazhan_chess();
void AddSC_boss_rtk_nightbane();

void AddSC_instance_cathedral_of_eternal_night(); //Cathedral of Eternal Night
void AddSC_boss_agronox();
void AddSC_boss_thrashbite_the_scornful();
void AddSC_boss_domatrax();
void AddSC_boss_mephistroth();
void AddSC_cathedral_of_eternal_night();

void AddSC_instance_the_emerald_nightmare();      //The Emerald Nightmare
void AddSC_the_emerald_nightmare();
void AddSC_boss_nythendra();
void AddSC_boss_elerethe_renferal();
void AddSC_boss_ilgynoth();
void AddSC_boss_ursoc();
void AddSC_boss_dragons_of_nightmare();
void AddSC_boss_cenarius();
void AddSC_boss_xavius();

void AddSC_trial_of_valor();                      //Trial of Valor
void AddSC_instance_trial_of_valor();
void AddSC_tov_boss_odyn();
void AddSC_boss_garm();
void AddSC_boss_tov_helya();

void AddSC_boss_chronomatic_anomaly();
void AddSC_boss_elisande();
void AddSC_boss_guldan();
void AddSC_boss_high_botanist_telarn();
void AddSC_boss_krosus();
void AddSC_boss_skorpyron();
void AddSC_boss_spellblade_aluriel();
void AddSC_boss_star_augur_etraeus();
void AddSC_boss_tichondrius();
void AddSC_boss_trilliax();
void AddSC_instance_the_nightnold();
void AddSC_the_nighthold();

void AddSC_instance_tomb_of_sargeras();
void AddSC_boss_goroth();
void AddSC_boss_mistress_sasszine();
void AddSC_boss_sisters_of_the_moon();
void AddSC_tomb_of_sargeras();
void AddSC_boss_demonic_inquisition();
void AddSC_boss_harjatan();
void AddSC_boss_maiden_of_vigilance();
void AddSC_boss_fallen_avatar();
void AddSC_boss_the_desolate_host();
void AddSC_boss_tos_kiljaeden();

void AddSC_instance_seat_of_the_triumvirate(); // Seat Of The Triumvirate
void AddSC_boss_zuraal_the_ascended();
void AddSC_boss_saprish();
void AddSC_boss_viceroy_nezhar();
void AddSC_boss_lura();

void AddSC_instance_antorus();
void AddSC_boss_worldbreaker();
void AddSC_boss_felhounds();
void AddSC_boss_antoran();
void AddSC_boss_hasabel();
void AddSC_boss_eonar();
void AddSC_boss_imonar();
void AddSC_boss_kingaroth();
void AddSC_boss_varimathras();
void AddSC_boss_coven_shivarres();
void AddSC_boss_aggramar();
void AddSC_boss_argus();
void AddSC_antorus();

//Draenor
void AddSC_wod_dark_portal();
void AddSC_wod_frostfire_ridge();
void AddSC_wod_shadowmoon_valley();

void AddSC_instance_iron_docks();       // Iron Docks
void AddSC_boss_fleshrender_nokgar();
void AddSC_boss_grimrail_enforcers();
void AddSC_boss_oshir();
void AddSC_boss_skulloc();

void AddSC_instance_upper_blackrock_spire();   // Upper Blackrock Spire
void AddSC_boss_orebender_gorashan();
void AddSC_boss_kyrak();
void AddSC_boss_commander_tharbek();
void AddSC_boss_ragewing_untamed();
void AddSC_boss_warlord_zaela();
void AddSC_upper_blackrock_spire();

void AddSC_instance_shadowmoon_burial_grounds();   // Shadowmoon Burial Grounds
void AddSC_boss_sadana_bloodfury();
void AddSC_boss_nhallish();
void AddSC_boss_bonemaw();
void AddSC_boss_nerzhul();

void AddSC_instance_bloodmaul_slag_mines(); // Bloodmaul Slag Mines
void AddSC_boss_slave_watcher_crushto();
void AddSC_boss_forgemaster_gogduh();
void AddSC_boss_roltall();
void AddSC_boss_gugrokk();
void AddSC_bloodmaul_slag_mines();

void AddSC_instance_skyreach(); // Skyreach
void AddSC_boss_ranjit();
void AddSC_boss_araknath();
void AddSC_boss_rukhran();
void AddSC_boss_high_sage_viryx();

void AddSC_instance_the_everbloom(); // The Everbloom
void AddSC_boss_witherbark();
void AddSC_boss_ancient_protectors();
void AddSC_boss_xeritac();
void AddSC_boss_archmage_sol();
void AddSC_boss_yalnu();

void AddSC_instance_auchindoun();
void AddSC_auchindoun();
void AddSC_boss_azzakel();
void AddSC_boss_teronogor();
void AddSC_boss_nyami();
void AddSC_boss_kaathar();

void AddSC_instance_highmaul(); // Raid: Highmaul
void AddSC_boss_twin_ogron();
void AddSC_boss_brackenspore();
void AddSC_boss_imperator_margok();
void AddSC_boss_kargath_bladefist();
void AddSC_boss_koragh();
void AddSC_boss_tectus();
void AddSC_boss_the_butcher();
void AddSC_highmaul();

void AddSC_instance_blackrock_foundry(); // Raid: Blackrock Foundry

void AddSC_instance_hellfire_citadel();  // Raid: Hellfire Citadel

void AddSC_world_bossess_draenor();
void AddSC_edge_of_reality();

//maelstorm
void AddSC_kezan();
void AddSC_lost_isle();

//eastern kingdoms
void AddSC_alterac_valley();                 //Alterac Valley
void AddSC_boss_balinda();
void AddSC_boss_drekthar();
void AddSC_boss_galvangar();
void AddSC_boss_vanndar();
void AddSC_boss_alizabal();                  //Baradin Hold
void AddSC_boss_argaloth();
void AddSC_boss_occuthar();
void AddSC_instance_baradin_hold();

void AddSC_instance_bastion_of_twilight();//Bastion of Twilight
void AddSC_boss_theralion_and_valiona();
void AddSC_boss_sinestra();
void AddSC_bastion_of_twilight();
void AddSC_boss_halfus_wyrmbreaker();
void AddSC_boss_chogall();
void AddSC_boss_ascendant_council();
void AddSC_blackrock_depths();               //Blackrock Depths
void AddSC_boss_ambassador_flamelash();
void AddSC_boss_anubshiah();
void AddSC_boss_draganthaurissan();
void AddSC_boss_general_angerforge();
void AddSC_boss_gorosh_the_dervish();
void AddSC_boss_grizzle();
void AddSC_boss_high_interrogator_gerstahn();
void AddSC_boss_magmus();
void AddSC_boss_moira_bronzebeard();
void AddSC_boss_tomb_of_seven();
void AddSC_instance_blackrock_depths();
void AddSC_boss_drakkisath();                //Blackrock Spire
void AddSC_boss_halycon();
void AddSC_boss_highlordomokk();
void AddSC_boss_mothersmolderweb();
void AddSC_boss_overlordwyrmthalak();
void AddSC_boss_shadowvosh();
void AddSC_boss_thebeast();
void AddSC_boss_warmastervoone();
void AddSC_boss_quatermasterzigris();
void AddSC_boss_pyroguard_emberseer();
void AddSC_boss_gyth();
void AddSC_boss_rend_blackhand();
void AddSC_instance_blackrock_spire();
void AddSC_boss_atramedes();                 //BlackwingDescent
void AddSC_boss_chimaeron();
void AddSC_boss_magmaw();
void AddSC_boss_maloriak();
void AddSC_boss_bwd_nefarian();
void AddSC_boss_omnotron_defence_system();
void AddSC_instance_blackwing_descent();
void AddSC_blackwing_descent();
void AddSC_boss_razorgore();                 //Blackwing lair
void AddSC_boss_vaelastrasz();
void AddSC_boss_broodlord();
void AddSC_boss_firemaw();
void AddSC_boss_ebonroc();
void AddSC_boss_flamegor();
void AddSC_boss_chromaggus();
void AddSC_boss_nefarian();
void AddSC_instance_blackwing_lair();
void AddSC_instance_deadmines(); // Deadmines
void AddSC_deadmines();
void AddSC_boss_glubtok();
void AddSC_boss_helix_gearbreaker();
void AddSC_boss_foereaper5000();
void AddSC_boss_admiral_ripsnarl();
void AddSC_boss_captain_cookie();
void AddSC_boss_vanessa_vancleef();
void AddSC_gilneas();
void AddSC_gnomeregan();                     //Gnomeregan
void AddSC_instance_gnomeregan();
void AddSC_boss_attumen();                   //Karazhan
void AddSC_boss_curator();
void AddSC_boss_maiden_of_virtue();
void AddSC_boss_shade_of_aran();
void AddSC_boss_malchezaar();
void AddSC_boss_terestian_illhoof();
void AddSC_boss_moroes();
void AddSC_bosses_opera();
void AddSC_boss_netherspite();
void AddSC_instance_karazhan();
void AddSC_karazhan();
void AddSC_boss_nightbane();
void AddSC_boss_felblood_kaelthas();         // Magister's Terrace
void AddSC_boss_selin_fireheart();
void AddSC_boss_vexallus();
void AddSC_boss_priestess_delrissa();
void AddSC_instance_magisters_terrace();
void AddSC_magisters_terrace();
void AddSC_boss_lucifron();                  //Molten core
void AddSC_boss_magmadar();
void AddSC_boss_gehennas();
void AddSC_boss_garr();
void AddSC_boss_baron_geddon();
void AddSC_boss_shazzrah();
void AddSC_boss_golemagg();
void AddSC_boss_sulfuron();
void AddSC_boss_majordomo();
void AddSC_boss_ragnaros();
void AddSC_instance_molten_core();
void AddSC_the_scarlet_enclave();            //Scarlet Enclave
void AddSC_the_scarlet_enclave_c1();
void AddSC_the_scarlet_enclave_c2();
void AddSC_the_scarlet_enclave_c5();
void AddSC_boss_thalnos_the_soulrender();    //Scarlet Monastery
void AddSC_boss_brother_korloff();
void AddSC_boss_high_inquisitor_whitemane();
void AddSC_boss_headless_horseman();
void AddSC_instance_scarlet_monastery();
void AddSC_boss_armsmaster_harlan();         //Scarlet Halls
void AddSC_boss_houndmaster_braun();
void AddSC_boss_flameweaver_koegler();
void AddSC_instance_scarlet_halls();
void AddSC_instance_scholomance();           // Update in Mist of Pandaria
void AddSC_scholomance();
void AddSC_boss_instructor_chillheart();
void AddSC_boss_jandice_barov();
void AddSC_boss_rattlegore();
void AddSC_boss_lilian_voss();
void AddSC_boss_darkmaster_gandling();
void AddSC_boss_baron_ashbury();            //Shadowfang keep
void AddSC_boss_baron_silverlaine();
void AddSC_boss_commander_springvale();
void AddSC_boss_lord_valden();
void AddSC_boss_lord_godfrey();
void AddSC_shadowfang_keep();                
void AddSC_instance_shadowfang_keep();
void AddSC_boss_magistrate_barthilas();      //Stratholme
void AddSC_boss_maleki_the_pallid();
void AddSC_boss_nerubenkan();
void AddSC_boss_cannon_master_willey();
void AddSC_boss_baroness_anastari();
void AddSC_boss_ramstein_the_gorger();
void AddSC_boss_timmy_the_cruel();
void AddSC_boss_postmaster_malown();
void AddSC_boss_baron_rivendare();
void AddSC_boss_dathrohan_balnazzar();
void AddSC_boss_order_of_silver_hand();
void AddSC_instance_stratholme();
void AddSC_stratholme();
void AddSC_sunken_temple();                  // Sunken Temple
void AddSC_instance_sunken_temple();
void AddSC_instance_sunwell_plateau();       //Sunwell Plateau
void AddSC_boss_kalecgos();
void AddSC_boss_brutallus();
void AddSC_boss_felmyst();
void AddSC_boss_eredar_twins();
void AddSC_boss_muru();
void AddSC_boss_kiljaeden();
void AddSC_sunwell_plateau();

void AddSC_instance_the_stonecore(); // The Stonecore
void AddSC_the_stonecore();
void AddSC_boss_corborus();
void AddSC_boss_slabhide();
void AddSC_boss_ozruk();
void AddSC_boss_high_priestess_azil();

void AddSC_instance_throne_of_the_tides(); // Throne of the Tides
void AddSC_throne_of_the_tides();
void AddSC_boss_lady_nazjar();
void AddSC_boss_commander_ulthok();
void AddSC_boss_erunak_stonespeaker();
void AddSC_boss_ozumat();

void AddSC_instance_blackrock_caverns(); // Blackrock Caverns
void AddSC_boss_romogg_bonecrusher();
void AddSC_boss_corla_herald_of_twilight();
void AddSC_boss_karsh_steelbender();
void AddSC_boss_beauty();
void AddSC_boss_ascendant_lord_obsidius();

void AddSC_boss_archaedas();                 //Uldaman
void AddSC_boss_ironaya();
void AddSC_uldaman();
void AddSC_instance_uldaman();
void AddSC_boss_akilzon();                   //Zul'Aman
void AddSC_boss_halazzi();
void AddSC_boss_hex_lord_malacrass();
void AddSC_boss_janalai();
void AddSC_boss_nalorakk();
void AddSC_boss_daakara();
void AddSC_instance_zulaman();
void AddSC_zulaman();
void AddSC_instance_grim_batol(); // Grim Batol
void AddSC_grim_batol();
void AddSC_boss_general_umbriss();
void AddSC_boss_forgemaster_throngus();
void AddSC_boss_drahga_shadowburner();
void AddSC_boss_erudax();
void AddSC_boss_grilek();                   // Zul'Gurub
void AddSC_boss_hazzarah();
void AddSC_boss_jindo_the_godbreaker();
void AddSC_boss_kilnara();
void AddSC_boss_mandokir();
void AddSC_boss_renataki();
void AddSC_boss_venoxis();
void AddSC_boss_wushoolay();
void AddSC_boss_zanzil();
void AddSC_instance_zulgurub();
//void AddSC_alterac_mountains();
void AddSC_arathi_highlands();
void AddSC_burning_steppes();
void AddSC_duskwood();
void AddSC_eastern_plaguelands();
void AddSC_eversong_woods();
void AddSC_ghostlands();
void AddSC_hinterlands();
void AddSC_ironforge();
void AddSC_isle_of_queldanas();
void AddSC_loch_modan();
void AddSC_redridge_mountains();
void AddSC_silvermoon_city();
void AddSC_silverpine_forest();
void AddSC_stormwind_city();
void AddSC_stranglethorn_vale();
void AddSC_swamp_of_sorrows();
void AddSC_tirisfal_glades();
void AddSC_undercity();
void AddSC_western_plaguelands();
void AddSC_westfall();
void AddSC_wetlands();

// Pandaria
void AddSC_instance_temple_of_jade_serpent();       // Temple of Jade Serpent
void AddSC_boss_wise_mari();
void AddSC_boss_lorewalker_stonestep();
void AddSC_boss_liu_flameheat();
void AddSC_boss_sha_of_doubt();
void AddSC_instance_stormstout_brewery();           // The Stormstout Brewery
void AddSC_stormstout_brewery();
void AddSC_boss_ook_ook();
void AddSC_boss_hoptallus();
void AddSC_boss_yan_zhu();
void AddSC_instance_gate_setting_sun();             // Gate of the Setting Sun
void AddSC_gate_setting_sun();
void AddSC_boss_saboteur_kiptilak();
void AddSC_boss_striker_gadok();
void AddSC_boss_commander_rimok();
void AddSC_boss_raigonn();
void AddSC_boss_sha_of_anger();                     // Pandaria World Bosses
void AddSC_boss_galion();
void AddSC_boss_oondasta();
void AddSC_boss_nalak();
void AddSC_instance_mogu_shan_palace();             // Mogu'Shan Palace
void AddSC_mogu_shan_palace();
void AddSC_boss_trial_of_the_king();
void AddSC_boss_gekkan();
void AddSC_boss_xin_the_weaponmaster();
void AddSC_instance_shadopan_monastery();           // Shadopan Monastery
void AddSC_shadopan_monastery();
void AddSC_boss_gu_cloudstrike();
void AddSC_boss_master_snowdrift();
void AddSC_boss_sha_of_violence();
void AddSC_boss_taran_zhu();
void AddSC_instance_siege_of_the_niuzoa_temple();   // Siege of the Niuzoa Temple
void AddSC_siege_of_the_niuzoa_temple();
void AddSC_boss_jinbak();
void AddSC_boss_commander_vojak();
void AddSC_boss_general_pavalak();
void AddSC_boss_wing_leader_neronok();
void AddSC_instance_mogu_shan_vault();              // Mogu'Shan Vault
void AddSC_mogu_shan_vault();
void AddSC_boss_stone_guard();
void AddSC_boss_feng();
void AddSC_boss_garajal();
void AddSC_boss_spirit_kings();
void AddSC_boss_elegon();
void AddSC_boss_will_of_emperor();
void AddSC_instance_heart_of_fear();                // Heart of Fear
void AddSC_boss_vizier_zorlok();
void AddSC_boss_lord_tayak();
void AddSC_boss_garalon();
void AddSC_boss_lord_meljarak();
void AddSC_boss_unsok();
void AddSC_boss_empress_shekzeer();
void AddSC_instance_terrace_of_endless_spring();    // Terrace of Endless Spring
//void AddSC_terrace_of_endless_spring();
void AddSC_boss_protectors_of_the_endless();
void AddSC_boss_tsulong();
void AddSC_boss_lei_shi();
void AddSC_boss_sha_of_fear();
void AddSC_instance_throne_of_thunder();            // Throne of Thunder
void AddSC_boss_jinrokh();
void AddSC_boss_horridon();
void AddSC_boss_council_of_elders();
void AddSC_boss_tortos();
void AddSC_boss_megaera();
void AddSC_boss_jikun();
void AddSC_boss_durumu();
void AddSC_boss_primordius();
void AddSC_boss_dark_animus();
void AddSC_boss_iron_qon();
void AddSC_boss_twin_consorts();
void AddSC_boss_lei_shen();
void AddSC_boss_ra_den();
void AddSC_instance_siege_of_orgrimmar();           // Siege of Orgrimmar 
void AddSC_siege_of_orgrimmar();
void AddSC_boss_immerseus();
void AddSC_boss_fallen_protectors();
void AddSC_boss_norushen();
void AddSC_boss_sha_of_pride();
void AddSC_boss_galakras();
void AddSC_boss_iron_juggernaut();
void AddSC_boss_korkron_dark_shaman();
void AddSC_boss_general_nazgrim();
void AddSC_boss_malkorok();
void AddSC_boss_spoils_of_pandaria();
void AddSC_boss_thok_the_bloodthirsty();
void AddSC_boss_siegecrafter_blackfuse();
void AddSC_boss_paragons_of_the_klaxxi();
void AddSC_boss_garrosh_hellscream();

void AddSC_valley_of_the_four_winds();
void AddSC_krasarang_wilds();
void AddSC_kun_lai_summit();
void AddSC_jade_forest();
void AddSC_WanderingIsland();
void AddSC_timeless_isle();

// Micro-Holidays
void AddSC_CallOfTheScarab();
void AddSC_GlowcapFestival();
void AddSC_HatchingOfTheHippogryphs();
void AddSC_KirinTorTavernCrawl();
void AddSC_MarchOfTheTadpoles();
void AddSC_SpringBalloonFestival();
void AddSC_ThousandBoatBash();
void AddSC_UnGoroMadness();
void AddSC_VolunteerGuardDay();
void AddSC_TrialofStyle();
void AddSC_AuctionHouseDanceParty();
void AddSC_DarkMoonConcertBlightBoar();
void AddSC_TheGreatGromereganRun();
void AddSC_MoonkinFestival();

// Scenarios

//< Arena of Annihilation
void AddSC_instance_arena_of_annihilation();
void AddSC_boss_scar_shell();
void AddSC_boss_jolgrum();
void AddSC_boss_little_liuyang();
void AddSC_boss_chagan_firehoof();
void AddSC_arena_of_annihilation();

//< Fall of Shan'bu
void AddSC_fall_of_shan_bu();
void AddSC_instance_fall_of_shan_bu();

//< Pursuing the Black Harvest
void AddSC_pursing_the_black_harvest();
void AddSC_instance_pursuing_the_black_harvest();

//< Thunder Forge
void AddSC_thunder_forge();
void AddSC_instance_thunder_forge();

//< Troves of the Thunder King
void AddSC_troves_of_the_thunder_king();
void AddSC_instance_troves_of_the_thunder_king();

//< A Brewing Storm
void AddSC_a_brewing_storm();
void AddSC_instance_a_brewing_storm();

//< A Little Patience
void AddSC_a_little_patience();
void AddSC_instance_a_little_patience();

//< Assault on Zan'vess
void AddSC_assault_on_zanvess();
void AddSC_instance_assault_on_zanvess();

//< Battle on the High Seas
void AddSC_battle_on_the_high_seas();
void AddSC_instance_battle_on_the_high_seas();

//< Blood in the Snow
void AddSC_blood_in_the_snow();
void AddSC_instance_blood_in_the_snow();

//< Brewmoon Festival
void AddSC_brewmoon_festival();
void AddSC_instance_brewmoon_festival();

//< Celestial Tournament
void AddSC_celestial_tournament();
void AddSC_instance_celestial_tournament();

//< Crypt of Forgotten Kings
void AddSC_crypt_of_forgotten_kings();
void AddSC_instance_crypt_of_forgotten_kings();

//< Dagger in the Dark
void AddSC_dagger_in_the_dark();
void AddSC_instance_dagger_in_the_dark();

//< Dark Heart of Pandaria
void AddSC_dark_heart_of_pandaria();
void AddSC_instance_dark_heart_of_pandaria();

//< Domination Point
void AddSC_domination_point();
void AddSC_instance_domination_point();

//< Greenstone Village
void AddSC_greenstone_village();
void AddSC_instance_greenstone_village();

//< Lion's Landing
void AddSC_lions_landing();
void AddSC_instance_lions_landing();

//< The Secrets of Ragefire
void AddSC_the_secrets_of_ragefire();
void AddSC_instance_the_secrets_of_ragefire();

//< Unga Ingoo
void AddSC_unga_ingoo();
void AddSC_instance_unga_ingoo();

//< Proving Grounds
void AddSC_instance_proving_grounds();
void AddSC_proving_grounds();

//< Broken Shore
void AddSC_instance_broken_shore();
void AddSC_broken_shore();

//< Shield's Reset
void AddSC_instance_shields_rest();
void AddSC_shields_rest();

//< Vengeance Art
void AddSC_DH_vengeance_art_scenario();

// Rogue Arts
void AddSC_Dreadblades();

void AddSC_Kingslayers();
void AddSC_instance_kingslayers();

void AddSC_Devourer();
void AddSC_instance_devourer();

// Warrior scenarios
void AddSC_wars_intro_scenario();

void AddSC_Warswords();
void AddSC_instance_warswords();

void AddSC_EarthWarder();

//priest art
void AddSC_Tuure();
void AddSC_instance_tuure();

// Paladin Art
void AddSC_SilverHand();
void AddSC_instance_silver_hand();

// Shaman Art
void AddSC_Sharasdal();
void AddSC_instance_sharasdal();

// Monk Art
void AddSC_monk_intro_scenario();

void AddSC_Sheylun();

// Arts common
void AddSC_instance_class_art_scenarios();

void AddSC_AssaultBrokenShore();
void AddSC_instance_AssaultBrokenShore();

void AddSC_InvasionAzsuna();
void AddSC_instance_InvasionAzsuna();

void AddSC_InvasionHM();
void AddSC_instance_invasion_HM();

void AddSC_InvasionValshara();
void AddSC_instance_invasion_valshara();

void AddSC_InvasionStormheim();
void AddSC_instance_invasion_stormheim();

void AddSC_instance_walling_caverns_pet();
void AddSC_instance_dead_mines_per();

void AddSC_army_training();
void AddSC_instance_army_training();

void AddSC_instance_temple_of_the_jade_serpent();

void AddSC_the_brawlers_guild();
void AddSC_the_brawlers_guild_bosses_rank_one();
void AddSC_the_brawlers_guild_bosses_rank_two();
void AddSC_the_brawlers_guild_bosses_rank_three();
void AddSC_the_brawlers_guild_bosses_rank_four();
void AddSC_the_brawlers_guild_bosses_rank_five();
void AddSC_the_brawlers_guild_bosses_rank_six();
void AddSC_the_brawlers_guild_bosses_rank_seven();

// battlegrounds

// outdoor pvp
void AddSC_outdoorpvp_hp();
void AddSC_outdoorpvp_na();
void AddSC_outdoorpvp_tf();
void AddSC_outdoorpvp_zm();
void AddSC_outdoorpvp_rg();

void AddSC_Kloaka();

// player
void AddSC_chat_log();
#endif

void AddScripts2()
{
#ifdef SCRIPTS
    AddLegionScripts();
    AddDraenorScripts();
    AddEasternKingdomsScripts();
    AddPandarieScripts();
#endif
}

void AddLegionScripts()
{
#ifdef SCRIPTS
    AddSC_Mardum();
    AddSC_warden_prison();
    AddSC_world_bossess_legion();
    AddSC_invasion_point_world_bosses();
    AddSC_invasion_point_argus();
    AddSC_sentinax();
    Addsc_paraxis();

    AddSC_brokenIslands();
    AddSC_instance_broken_islands();

    AddSC_instance_black_rook_hold_dungeon();  //Black Rook Hold Dungeon
    AddSC_boss_the_amalgam_of_souls();
    AddSC_boss_illysanna_ravencrest();
    AddSC_boss_smashspite_the_hateful();
    AddSC_boss_lord_kurtalos_ravencrest();

    AddSC_instance_darkheart_thicket();       //Dark Heart Thicket
    AddSC_boss_arch_druid_glaidalis();
    AddSC_boss_oakheart();
    AddSC_boss_dresaron();
    AddSC_boss_shade_of_xavius();

    AddSC_instance_eye_of_azshara();           //Eye of Azshara
    AddSC_boss_warlord_parjesh();
    AddSC_boss_lady_hatecoil();
    AddSC_boss_king_deepbeard();
    AddSC_boss_serpentrix();
    AddSC_boss_wrath_of_azshara();

    AddSC_instance_halls_of_valor();           //Halls of Valor
    AddSC_boss_odyn();
    AddSC_boss_hyrja();
    AddSC_boss_hymdall();
    AddSC_boss_fenryr();
    AddSC_boss_god_king_skovald();
    AddSC_instance_maw_of_souls();
    AddSC_boss_ymiron_the_fallen_king();
    AddSC_boss_harbaron();
    AddSC_boss_helya();

    AddSC_instance_tomb_of_sargeras();
    AddSC_boss_goroth();
    AddSC_boss_mistress_sasszine();
    AddSC_boss_sisters_of_the_moon();
    AddSC_tomb_of_sargeras();
    AddSC_boss_demonic_inquisition();
    AddSC_boss_harjatan();
    AddSC_boss_maiden_of_vigilance();
    AddSC_boss_fallen_avatar();
    AddSC_boss_the_desolate_host();
    AddSC_boss_tos_kiljaeden();
    
    AddSC_instance_neltharions_lair();         //Neltharions Lair
    AddSC_boss_naraxas();
    AddSC_boss_rokmora();
    AddSC_boss_ularogg_cragshaper();
    AddSC_boss_dargrul_the_underking();

    AddSC_instance_the_arcway();               //The Arcway
    AddSC_boss_ivanyr();
    AddSC_boss_corstilax();
    AddSC_boss_general_xakal();
    AddSC_boss_naltira();
    AddSC_boss_advisor_vandros();

    AddSC_instance_vault_of_the_wardens();     //Vault of the Wardens
    AddSC_boss_tirathon_saltheril();
    AddSC_boss_inquisitor_tormentorum();
    AddSC_boss_ashgolm();
    AddSC_boss_glazer();
    AddSC_boss_cordana();

    AddSC_instance_violet_hold_legion();       //Violet Hold Legion
    AddSC_boss_mindflayer_kaahrj();
    AddSC_boss_millificent_manastorm();
    AddSC_boss_festerface();
    AddSC_boss_shivermaw();
    AddSC_boss_anubesset();
    AddSC_boss_saelorn();
    AddSC_boss_blood_princess_thalena();
    AddSC_boss_fel_lord_betrug();
    AddSC_violet_hold_legion();

    AddSC_instance_court_of_stars();           //Court of Stars
    AddSC_boss_patrol_captain_gerdo();
    AddSC_boss_talixae_flamewreath();
    AddSC_boss_advisor_melandrus();

    AddSC_instance_return_to_karazhan();       //Return to Karazhan
    AddSC_boss_opera_hall();
    AddSC_boss_maiden_of_virtue_legion();
    AddSC_boss_attumen_the_huntsman();
    AddSC_boss_moroes_legion();
    AddSC_boss_the_curator();
    AddSC_boss_mana_devourer();
    AddSC_boss_shade_of_medivh();
    AddSC_boss_vizaduum_the_watcher();
    AddSC_karazhan_chess();
    AddSC_boss_rtk_nightbane();

    AddSC_instance_cathedral_of_eternal_night(); //Cathedral of Eternal Night
    AddSC_boss_agronox();
    AddSC_boss_thrashbite_the_scornful();
    AddSC_boss_domatrax();
    AddSC_boss_mephistroth();
    AddSC_cathedral_of_eternal_night();

    AddSC_instance_the_emerald_nightmare();     //The Emerald Nightmare
    AddSC_the_emerald_nightmare();
    AddSC_boss_nythendra();
    AddSC_boss_elerethe_renferal();
    AddSC_boss_ilgynoth();
    AddSC_boss_ursoc();
    AddSC_boss_dragons_of_nightmare();
    AddSC_boss_cenarius();
    AddSC_boss_xavius();

    AddSC_trial_of_valor();                     //Trial of Valor
    AddSC_instance_trial_of_valor();
    AddSC_tov_boss_odyn();
    AddSC_boss_garm();
    AddSC_boss_tov_helya();

    AddSC_boss_chronomatic_anomaly();           //The Nighthold
    AddSC_boss_elisande();
    AddSC_boss_guldan();
    AddSC_boss_high_botanist_telarn();
    AddSC_boss_krosus();
    AddSC_boss_skorpyron();
    AddSC_boss_spellblade_aluriel();
    AddSC_boss_star_augur_etraeus();
    AddSC_boss_tichondrius();
    AddSC_boss_trilliax();
    AddSC_instance_the_nightnold();
    AddSC_the_nighthold();

    AddSC_CallOfTheScarab();
    AddSC_GlowcapFestival();
    AddSC_HatchingOfTheHippogryphs();
    AddSC_KirinTorTavernCrawl();
    AddSC_MarchOfTheTadpoles();
    AddSC_SpringBalloonFestival();
    AddSC_ThousandBoatBash();
    AddSC_UnGoroMadness();
    AddSC_VolunteerGuardDay();
    AddSC_TrialofStyle();
    AddSC_AuctionHouseDanceParty();
    AddSC_DarkMoonConcertBlightBoar();
    AddSC_TheGreatGromereganRun();
    AddSC_MoonkinFestival();

    AddSC_instance_seat_of_the_triumvirate(); // Seat Of The Triumvirate
    AddSC_boss_zuraal_the_ascended();
    AddSC_boss_saprish();
    AddSC_boss_viceroy_nezhar();
    AddSC_boss_lura();
    
    AddSC_instance_antorus();
    AddSC_boss_worldbreaker();
    AddSC_boss_felhounds();
    AddSC_boss_antoran();
    AddSC_boss_hasabel();
    AddSC_boss_eonar();
    AddSC_boss_imonar();
    AddSC_boss_kingaroth();
    AddSC_boss_varimathras();
    AddSC_boss_coven_shivarres();
    AddSC_boss_aggramar();
    AddSC_boss_argus();
    AddSC_antorus();
#endif
}

void AddDraenorScripts()
{
#ifdef SCRIPTS
    AddSC_wod_dark_portal();
    AddSC_wod_frostfire_ridge();
    AddSC_wod_shadowmoon_valley();

    AddSC_instance_iron_docks();       // Iron Docks
    AddSC_boss_fleshrender_nokgar();
    AddSC_boss_grimrail_enforcers();
    AddSC_boss_oshir();
    AddSC_boss_skulloc();

    AddSC_instance_upper_blackrock_spire();   // Upper Blackrock Spire
    AddSC_boss_orebender_gorashan();
    AddSC_boss_kyrak();
    AddSC_boss_commander_tharbek();
    AddSC_boss_ragewing_untamed();
    AddSC_boss_warlord_zaela();
    AddSC_upper_blackrock_spire();

    AddSC_instance_shadowmoon_burial_grounds();   // Shadowmoon Burial Grounds
    AddSC_boss_sadana_bloodfury();
    AddSC_boss_nhallish();
    AddSC_boss_bonemaw();
    AddSC_boss_nerzhul();

    AddSC_instance_bloodmaul_slag_mines(); //< Bloodmaul Slag Mines
    AddSC_boss_slave_watcher_crushto();
    AddSC_boss_forgemaster_gogduh();
    AddSC_boss_roltall();
    AddSC_boss_gugrokk();
    AddSC_bloodmaul_slag_mines();

    AddSC_instance_skyreach(); // Skyreach
    AddSC_boss_ranjit();
    AddSC_boss_araknath();
    AddSC_boss_rukhran();
    AddSC_boss_high_sage_viryx();

    AddSC_instance_the_everbloom(); // The Everbloom
    AddSC_boss_witherbark();
    AddSC_boss_ancient_protectors();
    AddSC_boss_xeritac();
    AddSC_boss_archmage_sol();
    AddSC_boss_yalnu();

    AddSC_instance_auchindoun();
    AddSC_auchindoun();
    AddSC_boss_azzakel();
    AddSC_boss_teronogor();
    AddSC_boss_nyami();
    AddSC_boss_kaathar();

    AddSC_instance_highmaul(); // Raid: Highmaul
    AddSC_boss_twin_ogron();
    AddSC_boss_brackenspore();
    AddSC_boss_imperator_margok();
    AddSC_boss_kargath_bladefist();
    AddSC_boss_koragh();
    AddSC_boss_tectus();
    AddSC_boss_the_butcher();
    AddSC_highmaul();

    AddSC_instance_blackrock_foundry(); // Raid: Blackrock Foundry

    AddSC_instance_hellfire_citadel();  // Raid: Hellfire Citadel

    AddSC_world_bossess_draenor();
    AddSC_edge_of_reality();
#endif
}

void AddEasternKingdomsScripts()
{
#ifdef SCRIPTS
    AddSC_kezan();                          //Maelstrom
    AddSC_lost_isle();
    AddSC_alterac_valley();                 //Alterac Valley
    AddSC_boss_balinda();
    AddSC_boss_drekthar();
    AddSC_boss_galvangar();
    AddSC_boss_vanndar();
    AddSC_boss_alizabal();                  //Baradin Hold
    AddSC_boss_argaloth();
    AddSC_boss_occuthar();
    AddSC_instance_baradin_hold();

    AddSC_instance_bastion_of_twilight();   //BastionOfTwilight
    AddSC_boss_theralion_and_valiona();
    AddSC_boss_sinestra();
    AddSC_bastion_of_twilight();
    AddSC_boss_halfus_wyrmbreaker();
    AddSC_boss_chogall();
    AddSC_boss_ascendant_council();
    AddSC_blackrock_depths();               //Blackrock Depths
    AddSC_boss_ambassador_flamelash();
    AddSC_boss_anubshiah();
    AddSC_boss_draganthaurissan();
    AddSC_boss_general_angerforge();
    AddSC_boss_gorosh_the_dervish();
    AddSC_boss_grizzle();
    AddSC_boss_high_interrogator_gerstahn();
    AddSC_boss_magmus();
    AddSC_boss_moira_bronzebeard();
    AddSC_boss_tomb_of_seven();
    AddSC_instance_blackrock_depths();
    AddSC_boss_drakkisath();                //Blackrock Spire
    AddSC_boss_halycon();
    AddSC_boss_highlordomokk();
    AddSC_boss_mothersmolderweb();
    AddSC_boss_overlordwyrmthalak();
    AddSC_boss_shadowvosh();
    AddSC_boss_thebeast();
    AddSC_boss_warmastervoone();
    AddSC_boss_quatermasterzigris();
    AddSC_boss_pyroguard_emberseer();
    AddSC_boss_gyth();
    AddSC_boss_rend_blackhand();
    AddSC_instance_blackrock_spire();
    AddSC_boss_atramedes();                 //BlackwingDescent
    AddSC_boss_chimaeron();
    AddSC_boss_magmaw();
    AddSC_boss_maloriak();
    AddSC_boss_bwd_nefarian();
    AddSC_boss_omnotron_defence_system();
    AddSC_instance_blackwing_descent();
    AddSC_blackwing_descent();
    AddSC_boss_razorgore();                 //Blackwing lair
    AddSC_boss_vaelastrasz();
    AddSC_boss_broodlord();
    AddSC_boss_firemaw();
    AddSC_boss_ebonroc();
    AddSC_boss_flamegor();
    AddSC_boss_chromaggus();
    AddSC_boss_nefarian();
    AddSC_instance_blackwing_lair();
    AddSC_instance_deadmines(); // Deadmines
    AddSC_deadmines();
    AddSC_boss_glubtok();
    AddSC_boss_helix_gearbreaker();
    AddSC_boss_foereaper5000();
    AddSC_boss_admiral_ripsnarl();
    AddSC_boss_captain_cookie();
    AddSC_boss_vanessa_vancleef();
	AddSC_gilneas();                     //Gilneas
    AddSC_gnomeregan();                     //Gnomeregan
    AddSC_instance_gnomeregan();
    AddSC_boss_attumen();                   //Karazhan
    AddSC_boss_curator();
    AddSC_boss_maiden_of_virtue();
    AddSC_boss_shade_of_aran();
    AddSC_boss_malchezaar();
    AddSC_boss_terestian_illhoof();
    AddSC_boss_moroes();
    AddSC_bosses_opera();
    AddSC_boss_netherspite();
    AddSC_instance_karazhan();
    AddSC_karazhan();
    AddSC_boss_nightbane();
    AddSC_boss_felblood_kaelthas();         // Magister's Terrace
    AddSC_boss_selin_fireheart();
    AddSC_boss_vexallus();
    AddSC_boss_priestess_delrissa();
    AddSC_instance_magisters_terrace();
    AddSC_magisters_terrace();
    AddSC_boss_lucifron();                  //Molten core
    AddSC_boss_magmadar();
    AddSC_boss_gehennas();
    AddSC_boss_garr();
    AddSC_boss_baron_geddon();
    AddSC_boss_shazzrah();
    AddSC_boss_golemagg();
    AddSC_boss_sulfuron();
    AddSC_boss_majordomo();
    AddSC_boss_ragnaros();
    AddSC_instance_molten_core();
    AddSC_the_scarlet_enclave();            //Scarlet Enclave
    AddSC_the_scarlet_enclave_c1();
    AddSC_the_scarlet_enclave_c2();
    AddSC_the_scarlet_enclave_c5();
    AddSC_boss_thalnos_the_soulrender();    //Scarlet Monastery
    AddSC_boss_brother_korloff();
    AddSC_boss_high_inquisitor_whitemane();
    AddSC_boss_headless_horseman();
    AddSC_instance_scarlet_monastery();
    AddSC_boss_armsmaster_harlan();         //Scarlet Halls
    AddSC_boss_houndmaster_braun();
    AddSC_boss_flameweaver_koegler();
    AddSC_instance_scarlet_halls();
    AddSC_instance_scholomance();           //Scholomance
    AddSC_boss_instructor_chillheart();     
    AddSC_boss_jandice_barov();
    AddSC_boss_rattlegore();
    AddSC_boss_lilian_voss();
    AddSC_scholomance();
    AddSC_boss_darkmaster_gandling();       
    AddSC_boss_baron_ashbury();             //Shadowfang keep
    AddSC_boss_baron_silverlaine();
    AddSC_boss_commander_springvale();
    AddSC_boss_lord_valden();
    AddSC_boss_lord_godfrey();
    AddSC_shadowfang_keep();                
    AddSC_instance_shadowfang_keep();
    AddSC_boss_magistrate_barthilas();      //Stratholme
    AddSC_boss_maleki_the_pallid();
    AddSC_boss_nerubenkan();
    AddSC_boss_cannon_master_willey();
    AddSC_boss_baroness_anastari();
    AddSC_boss_ramstein_the_gorger();
    AddSC_boss_timmy_the_cruel();
    AddSC_boss_postmaster_malown();
    AddSC_boss_baron_rivendare();
    AddSC_boss_dathrohan_balnazzar();
    AddSC_boss_order_of_silver_hand();
    AddSC_instance_stratholme();
    AddSC_stratholme();
    AddSC_sunken_temple();                  // Sunken Temple
    AddSC_instance_sunken_temple();
    AddSC_instance_sunwell_plateau();       //Sunwell Plateau
    AddSC_boss_kalecgos();
    AddSC_boss_brutallus();
    AddSC_boss_felmyst();
    AddSC_boss_eredar_twins();
    AddSC_boss_muru();
    AddSC_boss_kiljaeden();
    AddSC_sunwell_plateau();

    AddSC_instance_the_stonecore(); // The Stonecore
    AddSC_the_stonecore();
    AddSC_boss_corborus();
    AddSC_boss_slabhide();
    AddSC_boss_ozruk();
    AddSC_boss_high_priestess_azil();

    AddSC_instance_throne_of_the_tides(); // Throne of the Tides
    AddSC_throne_of_the_tides();
    AddSC_boss_lady_nazjar();
    AddSC_boss_commander_ulthok();
    AddSC_boss_erunak_stonespeaker();
    AddSC_boss_ozumat();

    AddSC_instance_blackrock_caverns(); // Blackrock Caverns
    AddSC_boss_romogg_bonecrusher();
    AddSC_boss_corla_herald_of_twilight();
    AddSC_boss_karsh_steelbender();
    AddSC_boss_beauty();
    AddSC_boss_ascendant_lord_obsidius();

    AddSC_boss_archaedas();                 //Uldaman
    AddSC_boss_ironaya();
    AddSC_uldaman();
    AddSC_instance_uldaman();
    AddSC_boss_akilzon();                   //Zul'Aman
    AddSC_boss_halazzi();
    AddSC_boss_hex_lord_malacrass();
    AddSC_boss_janalai();
    AddSC_boss_nalorakk();
    AddSC_boss_daakara();
    AddSC_instance_zulaman();
    AddSC_zulaman();

    AddSC_instance_grim_batol(); // Grim Batol
    AddSC_grim_batol();
    AddSC_boss_general_umbriss();
    AddSC_boss_forgemaster_throngus();
    AddSC_boss_drahga_shadowburner();
    AddSC_boss_erudax();

    AddSC_boss_grilek();                    // Zul'Gurub
    AddSC_boss_hazzarah();
    AddSC_boss_jindo_the_godbreaker();
    AddSC_boss_kilnara();
    AddSC_boss_mandokir();
    AddSC_boss_renataki();
    AddSC_boss_venoxis();
    AddSC_boss_wushoolay();
    AddSC_boss_zanzil();
    AddSC_instance_zulgurub();

    //AddSC_alterac_mountains();
    AddSC_arathi_highlands();
    AddSC_burning_steppes();
    AddSC_duskwood();
    AddSC_eastern_plaguelands();
    AddSC_eversong_woods();
    AddSC_ghostlands();
    AddSC_hinterlands();
    AddSC_ironforge();
    AddSC_isle_of_queldanas();
    AddSC_loch_modan();
    AddSC_redridge_mountains();
    AddSC_silvermoon_city();
    AddSC_silverpine_forest();
    AddSC_stormwind_city();
    AddSC_stranglethorn_vale();
    AddSC_swamp_of_sorrows();
    AddSC_tirisfal_glades();
    AddSC_undercity();
    AddSC_western_plaguelands();
    AddSC_westfall();
    AddSC_wetlands();
#endif
}

void AddPandarieScripts()
{
#ifdef SCRIPTS
    AddSC_instance_temple_of_jade_serpent();        // Temple of Jade Serpent
    AddSC_boss_wise_mari();
    AddSC_boss_lorewalker_stonestep();
    AddSC_boss_liu_flameheat();
    AddSC_boss_sha_of_doubt();
    AddSC_instance_stormstout_brewery();            // The Stormstout Brewery
    AddSC_stormstout_brewery();
    AddSC_boss_ook_ook();
    AddSC_boss_hoptallus();
    AddSC_boss_yan_zhu();
    AddSC_instance_mogu_shan_palace();              // The Mogu'Shan Palace
    AddSC_mogu_shan_palace();
    AddSC_boss_trial_of_the_king();
    AddSC_boss_gekkan();
    AddSC_boss_xin_the_weaponmaster();
    AddSC_instance_gate_setting_sun();              // Gate of the Setting Sun
    AddSC_gate_setting_sun();
    AddSC_boss_saboteur_kiptilak();
    AddSC_boss_striker_gadok();
    AddSC_boss_commander_rimok();
    AddSC_boss_raigonn();
    AddSC_boss_sha_of_anger();                      // Pandaria World Bosses
    AddSC_boss_galion();
    AddSC_boss_oondasta();
    AddSC_boss_nalak();
    AddSC_instance_shadopan_monastery();            // Shadopan Monastery
    AddSC_shadopan_monastery();
    AddSC_boss_gu_cloudstrike();
    AddSC_boss_master_snowdrift();
    AddSC_boss_sha_of_violence();
    AddSC_boss_taran_zhu();
    AddSC_instance_siege_of_the_niuzoa_temple();    // Siege of the Niuzoa Temple
    AddSC_siege_of_the_niuzoa_temple();
    AddSC_boss_jinbak();
    AddSC_boss_commander_vojak();
    AddSC_boss_general_pavalak();
    AddSC_boss_wing_leader_neronok();
    AddSC_instance_mogu_shan_vault();               // Mogu'Shan Vault
    AddSC_mogu_shan_vault();
    AddSC_boss_stone_guard();
    AddSC_boss_feng();
    AddSC_boss_garajal();
    AddSC_boss_spirit_kings();
    AddSC_boss_elegon();
    AddSC_boss_will_of_emperor();
    AddSC_instance_heart_of_fear();                //Heart of Fear
    AddSC_boss_vizier_zorlok();
    AddSC_boss_lord_tayak();
    AddSC_boss_garalon();
    AddSC_boss_lord_meljarak();
    AddSC_boss_unsok();
    AddSC_boss_empress_shekzeer();
    AddSC_instance_terrace_of_endless_spring();    //Terrace of Endless Spring
	//AddSC_terrace_of_endless_spring();
	AddSC_boss_protectors_of_the_endless();
	AddSC_boss_tsulong();
    AddSC_boss_lei_shi();
    AddSC_boss_sha_of_fear();
    AddSC_instance_throne_of_thunder();            // Throne of Thunder
    AddSC_boss_jinrokh();
    AddSC_boss_horridon();
    AddSC_boss_council_of_elders();
    AddSC_boss_tortos();
    AddSC_boss_megaera();
    AddSC_boss_jikun();
    AddSC_boss_durumu();
    AddSC_boss_primordius();
    AddSC_boss_dark_animus();
    AddSC_boss_iron_qon();
    AddSC_boss_twin_consorts();
    AddSC_boss_lei_shen();
    AddSC_boss_ra_den();
    AddSC_instance_siege_of_orgrimmar();           // Siege of Orgrimmar 
    AddSC_siege_of_orgrimmar();
    AddSC_boss_immerseus();
    AddSC_boss_fallen_protectors();
    AddSC_boss_norushen();
    AddSC_boss_sha_of_pride();
    AddSC_boss_galakras();
    AddSC_boss_iron_juggernaut();
    AddSC_boss_korkron_dark_shaman();
    AddSC_boss_general_nazgrim();
    AddSC_boss_malkorok();
    AddSC_boss_spoils_of_pandaria();
    AddSC_boss_thok_the_bloodthirsty();
    AddSC_boss_siegecrafter_blackfuse();
    AddSC_boss_paragons_of_the_klaxxi();
    AddSC_boss_garrosh_hellscream();

    AddSC_valley_of_the_four_winds();
    AddSC_krasarang_wilds();
    AddSC_kun_lai_summit();
	AddSC_jade_forest();
    AddSC_WanderingIsland();
    AddSC_timeless_isle();

    // Scenarios
    //< Arena of Annihilation
    AddSC_instance_arena_of_annihilation();
    AddSC_boss_scar_shell();
    AddSC_boss_jolgrum();
    AddSC_boss_little_liuyang();
    AddSC_boss_chagan_firehoof();
    AddSC_arena_of_annihilation();

    //< Fall of Shan'bu
    AddSC_fall_of_shan_bu();
    AddSC_instance_fall_of_shan_bu();

    //< Pursuing the Black Harvest
    AddSC_pursing_the_black_harvest();
    AddSC_instance_pursuing_the_black_harvest();

    //< Thunder Forge
    AddSC_thunder_forge();
    AddSC_instance_thunder_forge();

    //< Troves of the Thunder King
    AddSC_troves_of_the_thunder_king();
    AddSC_instance_troves_of_the_thunder_king();

    //< A Brewing Storm
    AddSC_a_brewing_storm();
    AddSC_instance_a_brewing_storm();

    //< A Little Patience
    AddSC_a_little_patience();
    AddSC_instance_a_little_patience();

    //< Assault on Zan'vess
    AddSC_assault_on_zanvess();
    AddSC_instance_assault_on_zanvess();

    //< Battle on the High Seas
    AddSC_battle_on_the_high_seas();
    AddSC_instance_battle_on_the_high_seas();

    //< Blood in the Snow
    AddSC_blood_in_the_snow();
    AddSC_instance_blood_in_the_snow();

    //< Brewmoon Festival
    AddSC_brewmoon_festival();
    AddSC_instance_brewmoon_festival();

    //< Celestial Tournament
    AddSC_celestial_tournament();
    AddSC_instance_celestial_tournament();

    //< Crypt of Forgotten Kings
    AddSC_crypt_of_forgotten_kings();
    AddSC_instance_crypt_of_forgotten_kings();

    //< Dagger in the Dark
    AddSC_dagger_in_the_dark();
    AddSC_instance_dagger_in_the_dark();

    //< Dark Heart of Pandaria
    AddSC_dark_heart_of_pandaria();
    AddSC_instance_dark_heart_of_pandaria();

    //< Domination Point
    AddSC_domination_point();
    AddSC_instance_domination_point();

    //< Greenstone Village
    AddSC_greenstone_village();
    AddSC_instance_greenstone_village();

    //< Lion's Landing
    AddSC_lions_landing();
    AddSC_instance_lions_landing();

    //< The Secrets of Ragefire
    AddSC_the_secrets_of_ragefire();
    AddSC_instance_the_secrets_of_ragefire();

    //< Unga Ingoo
    AddSC_unga_ingoo();
    AddSC_instance_unga_ingoo();

    //< Proving Grounds
    AddSC_instance_proving_grounds();
    AddSC_proving_grounds();
    
    //< Broken Shore
    AddSC_instance_broken_shore();
    AddSC_broken_shore();

    //< Shield's Reset
    AddSC_instance_shields_rest();
    AddSC_shields_rest();

    //< Vengeance Art
    AddSC_DH_vengeance_art_scenario();
    
    // Rogue Art
    AddSC_Dreadblades();
    
    AddSC_Kingslayers();
    AddSC_instance_kingslayers();
    
    AddSC_Devourer();
    AddSC_instance_devourer();
    
    // Warrior scenarios
    AddSC_wars_intro_scenario();
    
    AddSC_Warswords();
    AddSC_instance_warswords();
    
    AddSC_EarthWarder();
    
    // Priest Art
    AddSC_Tuure();
    AddSC_instance_tuure();
    
    // Pdladin Art
    AddSC_SilverHand();
    AddSC_instance_silver_hand();
    
    // Shaman Art
    AddSC_Sharasdal();
    AddSC_instance_sharasdal();
    
    // Monk Art
    AddSC_monk_intro_scenario();
    
    AddSC_Sheylun();

    // Art Common
    AddSC_instance_class_art_scenarios();
    
    AddSC_AssaultBrokenShore();
    AddSC_instance_AssaultBrokenShore();
    
    AddSC_InvasionAzsuna();
    AddSC_instance_InvasionAzsuna();
    
    AddSC_InvasionHM();
    AddSC_instance_invasion_HM();
    
    AddSC_InvasionValshara();
    AddSC_instance_invasion_valshara();
    
    AddSC_InvasionStormheim();
    AddSC_instance_invasion_stormheim();

    AddSC_instance_walling_caverns_pet();
    AddSC_instance_dead_mines_per();
    
    AddSC_army_training();
    AddSC_instance_army_training();
    
    AddSC_instance_temple_of_the_jade_serpent();
    
    AddSC_the_brawlers_guild();
    AddSC_the_brawlers_guild_bosses_rank_one();
    AddSC_the_brawlers_guild_bosses_rank_two();
    AddSC_the_brawlers_guild_bosses_rank_three();
    AddSC_the_brawlers_guild_bosses_rank_four();
    AddSC_the_brawlers_guild_bosses_rank_five();
    AddSC_the_brawlers_guild_bosses_rank_six();
    AddSC_the_brawlers_guild_bosses_rank_seven();
#endif
}
