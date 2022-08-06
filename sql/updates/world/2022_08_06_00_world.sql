-- Kloaka things
DELETE FROM `smart_scripts` WHERE `entryorguid`=97359 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=97359;


-- Pandaria Intro
DELETE FROM `phase_definitions` WHERE `zoneId`=12 AND `entry`=1;
DELETE FROM `phase_definitions` WHERE `zoneId`=14 AND `entry`=5;
DELETE FROM `phase_definitions` WHERE `zoneId`=16 AND `entry`=5;
DELETE FROM `phase_definitions` WHERE `zoneId`=1637 AND `entry`=9;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES 
(12, 1, 0, '', 1066, 0, 0, 'Stormwind Gunship (Pandaria Start Area)'),
(14, 5, 0, '', 1074, 0, 0, 'Orgrimmar Gunship (Pandaria Start Area)'),
(16, 5, 0, '', 1074, 0, 0, 'Orgrimmar Gunship (Pandaria Start Area)'),
(1637, 9, 0, '', 1074, 0, 0, 'Orgrimmar Gunship (Pandaria Start Area)');

DELETE FROM `gossip_menu_option` WHERE `MenuID`=61022;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionNPC`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcflag`) VALUES 
(61022, 0, 0, 'I am ready to depart.',                            67429, 1, 1),
(61022, 1, 0, 'You really have it in for the Horde, don\'t you?', 68469, 1, 1);

DELETE FROM `smart_scripts` WHERE `entryorguid`=66292 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(66292, 0, 0, 0, 62, 0, 100, 0, 61022, 0, 0, 0, 62, 870, 0, 0, 0, 0, 0, 7, 0, 0, 0, -755, -1384, 81, 0, ''),
(66292, 0, 1, 0, 19, 0, 100, 0, 31732, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 54615, 15, 0, 0, 0, 0, 0, '');

DELETE FROM `phase_definitions` WHERE `zoneId`=5785 AND `entry`=14;
DELETE FROM `phase_definitions` WHERE `zoneId`=5785 AND `entry`=15;
DELETE FROM `phase_definitions` WHERE `zoneId`=5785 AND `entry`=16;
DELETE FROM `phase_definitions` WHERE `zoneId`=5785 AND `entry`=17;
DELETE FROM `phase_definitions` WHERE `zoneId`=5785 AND `entry`=18;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES 
(5785, 14, 0, 0, 1076, 0, 0, 'Jade Forest Horde Starting Area'),
(5785, 15, 0, 0, 972, 0, 0, 'Jade Forest Battlefield Phase'),
(5785, 16, 0, 0, 971, 0, 0, 'Jade Forest Alliance Hub Phase'),
(5785, 17, 0, 0, 1061, 0, 0, 'Krasarang Wilds: Horde Beach Daily Area'),
(5785, 18, 0, 0, 1062, 0, 0, 'Krasarang Wilds: Alliance Beach Daily Area');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=5785 AND `SourceEntry`=17;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=5785 AND `SourceEntry`=18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(23, 5785, 18, 0, 1, 8, 0, 32109, 0, 0, 0, 0, '', ''),
(23, 5785, 18, 0, 0, 8, 0, 32108, 0, 0, 0, 0, '', ''),
(23, 5785, 17, 0, 1, 8, 0, 32109, 0, 0, 0, 0, '', ''),
(23, 5785, 17, 0, 0, 8, 0, 32108, 0, 0, 0, 0, '', '');


