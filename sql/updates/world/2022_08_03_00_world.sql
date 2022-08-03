-- https://www.wowhead.com/zone=7897/the-underbelly
/* Fixes Log Dalaran Underbelly
- Corregido el bug a la hora de cambiar de mapas
- Ya son visibles varios go que antes no lo eran por problemas de phases
- Removida vieja implementacion de las auras por spell_area, ahora recibes los buffs por playerscript.
- Arreglado el npc 97359 Raethan.
- Arreglado el item 139411 [Festín de los Bajos Fondos].
- Arreglado el item 139412 [Tortugas de guerra mutantes jóvenes]. 
- Arreglado el item 139422 [Cebo vil].
- Arreglada la spell 220273 del item (Varita de maná salvaje) ya solo le casteara la spell a todos los minibosses que tengan mas del 90% de hp (antes solo se lo hacia uno por mala implementacion) y añadido el npc 97589 a la lista.
- Arreglada la spell 220021 Underbelly Banquet ya inicia el evento Kloaka - Banquet
- Arreglada la spell 220236 Young Mutant Warturtles ya inicia el evento Kloaka - Turtle
- Arreglado el spell 220237 ya inicia el evento Kloaka - Shimmering Whorl
- Implementado la spell 223176 Fair Game si el pvp esta activado y vas para la zona segura podras ser atacado por los jugadores por unos 8 segundos
- Arreglado el molesto problema que se te quedaban los 2 buffos encima del jugardor al mismo tiempo
- Implementado el contratar a un guardaespaldas para que te siga por las cloacas que te aplicara el buff 203894 para protegerte de los demas jugadores y arreglado el npc
- Ya al matar a un jugador dentro de esa zona con el evento activo recibes de 15 a 50 ojos videntes.
- Arreglado la cantidad de ojos videntes looteados los bosses 50-90  npcs 1-10 y pesca 1-10
- Ajustado el evento Kloaka - PVP On, ya los guardias al estar el evento activo desaparecen de sus puestos, al terminarse ese evento vuelven.
- Implementado el evento Kloaka - Banquet
- Implementado el evento Kloaka - Turtle
- Implementado el evento Kloaka - Shimmering Whorl he implementado su pool
*/

DELETE FROM `game_event` WHERE `eventEntry` in (200,201,202,203,204,205);

DELETE FROM `game_event_creature` where `eventEntry` in (200,201,202,203,204,205);

DELETE FROM `spell_area` WHERE `spell`=223202;
DELETE FROM `spell_area` WHERE `spell`=223203;


DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=223202;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=223203;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=220273;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 220273, 0, 0, 31, 1, 3, 97387, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 0, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 1, 31, 1, 3, 97587, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 1, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 2, 31, 1, 3, 97381, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 2, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 3, 31, 1, 3, 97380, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 3, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 4, 31, 1, 3, 97388, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 4, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 5, 31, 1, 3, 97384, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 5, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 6, 31, 1, 3, 97390, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 6, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct'),
(17, 0, 220273, 0, 7, 31, 1, 3, 97589, 0, 0, 0, '', 'only rare cre'),
(17, 0, 220273, 0, 7, 38, 1, 90, 3, 0, 0, 0, '', 'only rare cre hp pct');


-- npc 97359 Raethan
DELETE FROM `gossip_menu_option` WHERE `MenuID`=18778;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionType`, `OptionNpcflag`, `OptionNpcflag2`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxCurrency`, `BoxText`, `OptionBroadcastTextID`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(18778, 0, 1, 'I would like to buy from you.', 3, 128, 0, 0, 0, 0, 0, 0, '', 14967, 0, 26972),
(18778, 1, 0, 'Raethan, call off your guards.\n\n[Cost: 50 |TInterface\\Icons\\achievement_reputation_kirintor_offensive.blp:12|t Sightless Eyes]', 1, 1, 0, 0, 0, 0, 0, 0, '', 99085, 0, 26972),
(18778, 2, 0, 'Raethan, call back your guards.\n\n[Cost: 50 |TInterface\\Icons\\achievement_reputation_kirintor_offensive.blp:12|t Sightless Eyes]', 1, 1, 0, 0, 0, 0, 0, 0, NULL, 99086, 0, 26972),
(18778, 3, 0, 'I want to hire a personal bodyguard.', 1, 1, 0, 0, 0, 0, 50000, 0, 'An Underbelly Guard will protect you from other players\' attacks for 5 minutes.\n\nDo you want to hire a bodyguard?', 105615, 105617, 26972);

DELETE FROM `creature_text` WHERE `Entry`=97359;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES 
(97359, 0, 0, 'Sewer guards, time to take a break!', 41, 0, 100, 0, 0, 0, 99082, 0, 0, 0, 'Raethan to Player'),
(97359, 1, 0, 'Sewer guards! Return to your posts!', 41, 0, 100, 0, 0, 0, 99083, 0, 0, 0, 'Raethan to Player');

-- Implementados estos 3 eventos
DELETE FROM `game_event` WHERE `eventEntry` in (200,201,202);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES 
(200, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 2592000, 5, 0, 'Kloaka - Banquet', 0),
(201, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 2592000, 5, 0, 'Kloaka - Turtle', 0),
(202, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 2592000, 5, 0, 'Kloaka - Shimmering Whorl', 0);

DELETE FROM `game_event_creature` WHERE `eventEntry`in (200,201);
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES 
(200, 372379),
(201, 262861),
(201, 272332),
(201, 272335),
(201, 272336);

-- 110666
DELETE FROM `creature` WHERE `guid`=262861;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(262861, 110666, 1502, 8392, 7594, 1, 1, '', 0, 0, -833.66, 4451.57, 696.743, 2.93042, 180, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22624);


DELETE FROM `game_event_gameobject` WHERE `eventEntry`=202;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES 
(202, 107065),
(202, 107066),
(202, 107067),
(202, 107068),
(202, 107069),
(202, 107070),
(202, 107071),
(202, 107072),
(202, 107073),
(202, 107074),
(202, 107075),
(202, 107076),
(202, 107077),
(202, 107078),
(202, 107079),
(202, 109912), 
(202, 109920),
(202, 109924),
(202, 109949), -- 250642
(202, 142698), 
(202, 142699),
(202, 142700),
(202, 142701),
(202, 142702),
(202, 142703),
(202, 142704); -- 252110

DELETE FROM `pool_template` WHERE `entry` in (500,501);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES 
(500, 4, 'Kloaka - Shimmering Whorl'),
(501, 4, 'Kloaka - Frenzied Pool');

update `gameobject` set phaseid = '' where `id`= 250642;

delete from `pool_gameobject` where `pool_entry` in (500,501);
INSERT INTO `pool_gameobject` (`guid`, `pool_entry`, `chance`, `description`) VALUES 
(107065, 500, 0, 'Kloaka - Shimmering Whorl'),
(107066, 500, 0, 'Kloaka - Shimmering Whorl'),
(107067, 500, 0, 'Kloaka - Shimmering Whorl'),
(107068, 500, 0, 'Kloaka - Shimmering Whorl'),
(107069, 500, 0, 'Kloaka - Shimmering Whorl'),
(107070, 500, 0, 'Kloaka - Shimmering Whorl'),
(107071, 500, 0, 'Kloaka - Shimmering Whorl'),
(107072, 500, 0, 'Kloaka - Shimmering Whorl'),
(107073, 500, 0, 'Kloaka - Shimmering Whorl'),
(107074, 500, 0, 'Kloaka - Shimmering Whorl'),
(107075, 500, 0, 'Kloaka - Shimmering Whorl'),
(107076, 500, 0, 'Kloaka - Shimmering Whorl'),
(107077, 500, 0, 'Kloaka - Shimmering Whorl'),
(107078, 500, 0, 'Kloaka - Shimmering Whorl'),
(107079, 500, 0, 'Kloaka - Shimmering Whorl'),
(109912, 500, 0, 'Kloaka - Shimmering Whorl'),
(109920, 500, 0, 'Kloaka - Shimmering Whorl'),
(109924, 500, 0, 'Kloaka - Shimmering Whorl'),
(109949, 500, 0, 'Kloaka - Shimmering Whorl'),
(142698, 501, 0, 'Kloaka - Frenzied Pool'),
(142699, 501, 0, 'Kloaka - Frenzied Pool'),
(142700, 501, 0, 'Kloaka - Frenzied Pool'),
(142701, 501, 0, 'Kloaka - Frenzied Pool'),
(142702, 501, 0, 'Kloaka - Frenzied Pool'),
(142703, 501, 0, 'Kloaka - Frenzied Pool'),
(142704, 501, 0, 'Kloaka - Frenzied Pool');

-- 103112
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 103112;

DELETE FROM `smart_scripts` WHERE `entryorguid`=103112 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(103112, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 203894, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'on just spawned - cast spell 203894 on owner'),
(103112, 0, 1, 0, 60, 0, 100, 0, 300000, 300000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'in 5 minutes - despawn');

UPDATE `creature_template_addon` SET `auras` = '203894' WHERE `entry` = 103112;

-- loot
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97387; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97587; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97381; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97380; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97388; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97384; 
update `creature_loot_template` set `mincountOrRef`= 50, `maxcount`= 90 where `item`= -1149 and `entry` = 97390; 
update `creature_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 107778; 
update `creature_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 110719; 
update `creature_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 110737; 
update `creature_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 110721; 
update `creature_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 110729; 

update `gameobject_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 250642; 
update `gameobject_loot_template` set `mincountOrRef`= 1, `maxcount`= 10 where `item`= -1149 and `entry` = 252110; 
  
DELETE FROM `spell_script_names` WHERE `spell_id` in (220021,220236,220237);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(220021, 'spell_kloaka_call_some_adds'),
(220236, 'spell_kloaka_call_some_adds'),
(220237, 'spell_kloaka_call_some_adds');

-- 110661
UPDATE `creature_template` SET `ScriptName` = 'npc_underbelly_banquet' WHERE `entry` = 110661;
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 110661;

DELETE FROM `game_event` WHERE `eventEntry` in (80,81);
INSERT INTO `game_event` (`eventEntry`, `start_time`, `end_time`, `occurence`, `length`, `holiday`, `description`, `world_event`) VALUES 
(80, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 2592000, 0, 0, 'Kloaka - PVP On', 0),
(81, '0000-00-00 00:00:00', '0000-00-00 00:00:00', 2592000, 0, 0, 'Kloaka - PVP Off ', 0);


DELETE FROM `outdoorpvp_template` WHERE `TypeId`=16;
DELETE FROM `world_seamless_teleport` WHERE `ZoneID` in (8392,7502); 
INSERT INTO `world_seamless_teleport` (`ZoneID`, `AreaID`, `FromMapID`, `ToMapID`, `comment`) VALUES 
(8392, 0, 1220, 1502, 'From Dalaran to Kloaka'),
(7502, 0, 1502, 1220, 'From Kloaka to Dalaran');
