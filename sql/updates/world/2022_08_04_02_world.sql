DELETE FROM `phase_definitions` WHERE `zoneId`=7004 AND `entry`=1;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `PreloadMapID`, `VisibleMapID`, `UiWorldMapAreaID`, `flags`, `comment`) VALUES 
(7004, 1, 0, '4177', 0, 0, 0, 24, 'Base-Phase FrostFireRidge. Garrison lvl.1');

-- QUEST 34822
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`= -100 WHERE `entry`=80174 AND `item`=111907;

