
DELETE FROM `creature_text` WHERE Entry= 3513;
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES
	(3513, 7, 0, 'Yes, that is true. Paladins and priests alike train their skills and research great truths behind the walls of the Cathedral.', 12, 7, 100, 1, 0, 0, 1154, 0, 0, 0, 'Miss Danna'),
	(3513, 2, 0, 'Yes, well...let\'s head on to the monument dedicated to the heroes of the two Great Wars, the Valley of Heroes. Follow me.', 12, 7, 100, 0, 0, 0, 1162, 12645, 12645, 0, 'Miss Danna to Miss Danna'),
	(3513, 5, 0, 'Now, take another long look before we make our way to the Holy District and the great Cathedral of Light.', 12, 7, 100, 1, 0, 0, 1166, 0, 0, 0, 'Miss Danna'),
	(3513, 4, 0, 'Breathtaking. Children, when we return to the school, you will each give an oral report on one of these legendary people.', 12, 7, 100, 1, 0, 0, 1165, 0, 0, 0, 'Miss Danna'),
	(3513, 1, 0, 'When the Horde was shattered, men returned here and began to rebuild the once great city as a testament to our own survival.', 12, 7, 100, 1, 0, 0, 1161, 0, 0, 0, 'Miss Danna'),
	(3513, 6, 0, 'Here we have the Cathedral of Light, the center of spiritual enlightenment here in Stormwind.', 12, 7, 100, 1, 0, 0, 1129, 0, 0, 0, 'Miss Danna'),
	(3513, 3, 0, 'Isn\'t it amazing, children? All who enter the city must walk beneath the watchful eyes of the greatest heroes of our lands.', 12, 7, 100, 1, 0, 0, 1163, 0, 0, 0, 'Miss Danna'),
	(3513, 8, 0, 'Children if you would please follow me, we will now be going to see the keep where King Anduin Wrynn himself sits on his throne.', 12, 7, 100, 1, 0, 0, 1155, 0, 0, 0, 'Miss Danna'),
	(3513, 0, 0, 'Here we have Stormwind Keep. Built upon the ruins of Stormwind Castle, which was destroyed by the Horde in the first Great War.', 12, 7, 100, 1, 0, 0, 1140, 0, 0, 0, 'Miss Danna');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3513;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3513);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3513, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3513, 0, 1, 0, 11, 0, 100, 0, 0, 0, 0, 0, 67, 1, 5000, 10000, 0, 0, 100, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Set Timer'),
(3513, 0, 2, 0, 59, 0, 100, 0, 1, 0, 0, 0, 53, 0, 3513, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Timer Trigger - Start WP'),
(3513, 0, 3, 4, 40, 0, 100, 0, 1, 0, 0, 0, 80, 351300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WP Reached - Actionlist for Conversation @ Keep'),
(3513, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 18000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Pause WP'),
(3513, 0, 5, 6, 40, 0, 100, 0, 50, 0, 0, 0, 80, 351301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WP Reached - Actionlist for Conversation @ Valley'),
(3513, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 20000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Pause WP'),
(3513, 0, 7, 0, 40, 0, 100, 0, 113, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WP Reached - Speech before Cathedral'),
(3513, 0, 8, 9, 40, 0, 100, 0, 125, 0, 0, 0, 80, 351302, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'WP Reached - Actionlist for Conversation @ Cathedral'),
(3513, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 54, 22000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Pause WP'),
(3513, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3513, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3513, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3513, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3513, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3513, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3513, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3513, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3513, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3513, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3513, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3513, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3513, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3513, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3513, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3513, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3513, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3513, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3513, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3513, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3513, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3513, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3513, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3513, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');


DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 351300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(351300, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351300, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351300, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 84, 0, 0, 0, 0, 0, 0, 11, 3511, 15, 0, 0, 0, 0, 0, 'Simple Talk - Steven'),
(351300, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 351300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(351300, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351300, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351300, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 84, 0, 0, 0, 0, 0, 0, 11, 3511, 15, 0, 0, 0, 0, 0, 'Simple Talk - Steven'),
(351300, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech');

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 351302);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(351302, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351302, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 84, 0, 0, 0, 0, 0, 0, 11, 3512, 15, 0, 0, 0, 0, 0, 'Simple Talk - Jimmy'),
(351302, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech'),
(351302, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Speech');

DELETE FROM `waypoints` WHERE `entry`=3513;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(3513, 1, -8548.27, 468.184, 104.58, 'Miss Danna and children'),
(3513, 2, -8548.93, 466.572, 104.628, 'Miss Danna and children'),
(3513, 3, -8550.23, 465.412, 104.645, 'Miss Danna and children'),
(3513, 4, -8551.96, 465.091, 104.616, 'Miss Danna and children'),
(3513, 5, -8564.49, 466.245, 104.615, 'Miss Danna and children'),
(3513, 6, -8568.83, 469.128, 104.595, 'Miss Danna and children'),
(3513, 7, -8576.92, 475.723, 104.322, 'Miss Danna and children'),
(3513, 8, -8591.79, 493.755, 104.061, 'Miss Danna and children'),
(3513, 9, -8604.07, 505.364, 103.799, 'Miss Danna and children'),
(3513, 10, -8614.31, 514.71, 103.432, 'Miss Danna and children'),
(3513, 11, -8643.73, 545.41, 98.6766, 'Miss Danna and children'),
(3513, 12, -8652.04, 552.076, 96.9428, 'Miss Danna and children'),
(3513, 13, -8658.58, 554.212, 97.0891, 'Miss Danna and children'),
(3513, 14, -8673.96, 553.51, 97.3619, 'Miss Danna and children'),
(3513, 15, -8682.32, 549.425, 97.6111, 'Miss Danna and children'),
(3513, 16, -8697.67, 535.503, 97.7366, 'Miss Danna and children'),
(3513, 17, -8708.73, 524.24, 97.6432, 'Miss Danna and children'),
(3513, 18, -8710.78, 523.077, 97.4831, 'Miss Danna and children'),
(3513, 19, -8713.86, 522.867, 97.5569, 'Miss Danna and children'),
(3513, 20, -8716.29, 523.879, 97.8977, 'Miss Danna and children'),
(3513, 21, -8727.4, 537.344, 100.798, 'Miss Danna and children'),
(3513, 22, -8736.36, 547.42, 100.762, 'Miss Danna and children'),
(3513, 23, -8744.46, 556.427, 97.9314, 'Miss Danna and children'),
(3513, 24, -8745.14, 559.952, 97.537, 'Miss Danna and children'),
(3513, 25, -8744.52, 562.955, 97.4552, 'Miss Danna and children'),
(3513, 26, -8743.21, 565.35, 97.4219, 'Miss Danna and children'),
(3513, 27, -8740.4, 570.129, 97.3708, 'Miss Danna and children'),
(3513, 28, -8739.76, 572.369, 97.4931, 'Miss Danna and children'),
(3513, 29, -8739.58, 576.754, 97.5811, 'Miss Danna and children'),
(3513, 30, -8740.64, 578.422, 97.5733, 'Miss Danna and children'),
(3513, 31, -8766.8, 605.176, 97.0261, 'Miss Danna and children'),
(3513, 32, -8769.12, 606.096, 97.0521, 'Miss Danna and children'),
(3513, 33, -8772.22, 606.255, 97.2372, 'Miss Danna and children'),
(3513, 34, -8776.49, 603.929, 97.4016, 'Miss Danna and children'),
(3513, 35, -8794.51, 591.053, 97.7582, 'Miss Danna and children'),
(3513, 36, -8796.43, 591.321, 97.759, 'Miss Danna and children'),
(3513, 37, -8799.78, 592.351, 97.6749, 'Miss Danna and children'),
(3513, 38, -8806, 596.001, 97.1189, 'Miss Danna and children'),
(3513, 39, -8810.39, 601.331, 96.6809, 'Miss Danna and children'),
(3513, 40, -8827.08, 617.833, 94.4598, 'Miss Danna and children'),
(3513, 41, -8833, 618.537, 93.7779, 'Miss Danna and children'),
(3513, 42, -8837.84, 616.341, 93.0874, 'Miss Danna and children'),
(3513, 43, -8887.64, 573.871, 93.1856, 'Miss Danna and children'),
(3513, 44, -8922.67, 543.923, 94.6837, 'Miss Danna and children'),
(3513, 45, -8924.46, 538.5, 94.7037, 'Miss Danna and children'),
(3513, 46, -8923.44, 533.908, 94.6629, 'Miss Danna and children'),
(3513, 47, -8914.19, 517.33, 93.8169, 'Miss Danna and children'),
(3513, 48, -8913, 511.086, 93.8177, 'Miss Danna and children'),
(3513, 49, -8916.76, 501.446, 93.8821, 'Miss Danna and children'),
(3513, 50, -8935.77, 485.708, 94.1447, 'Miss Danna and children'),
(3513, 51, -8917.57, 500.238, 93.8908, 'Miss Danna and children'),
(3513, 52, -8913.6, 506.938, 93.8488, 'Miss Danna and children'),
(3513, 53, -8912.85, 516.821, 93.8176, 'Miss Danna and children'),
(3513, 54, -8919.76, 529.199, 94.4184, 'Miss Danna and children'),
(3513, 55, -8923.98, 539.137, 94.7103, 'Miss Danna and children'),
(3513, 56, -8921.7, 546.451, 94.6896, 'Miss Danna and children'),
(3513, 57, -8914.13, 553.777, 94.2676, 'Miss Danna and children'),
(3513, 58, -8875.17, 584.23, 93.1569, 'Miss Danna and children'),
(3513, 59, -8840.05, 614.217, 92.8922, 'Miss Danna and children'),
(3513, 60, -8837.91, 621.883, 93.5347, 'Miss Danna and children'),
(3513, 61, -8838.66, 627.504, 94.1886, 'Miss Danna and children'),
(3513, 62, -8846.33, 641.894, 96.4534, 'Miss Danna and children'),
(3513, 63, -8851.14, 652.949, 96.6759, 'Miss Danna and children'),
(3513, 64, -8850.4, 657.573, 96.9944, 'Miss Danna and children'),
(3513, 65, -8847.37, 662.483, 97.5074, 'Miss Danna and children'),
(3513, 66, -8833.01, 674.137, 98.4962, 'Miss Danna and children'),
(3513, 67, -8828.45, 677.468, 97.72, 'Miss Danna and children'),
(3513, 68, -8827.07, 681.7, 97.2116, 'Miss Danna and children'),
(3513, 69, -8841.53, 714.566, 97.6569, 'Miss Danna and children'),
(3513, 70, -8842.46, 718.973, 97.5845, 'Miss Danna and children'),
(3513, 71, -8841.63, 722.51, 97.5469, 'Miss Danna and children'),
(3513, 72, -8837.06, 727.47, 97.8624, 'Miss Danna and children'),
(3513, 73, -8821.52, 736.546, 98.155, 'Miss Danna and children'),
(3513, 74, -8804.36, 744.102, 97.7195, 'Miss Danna and children'),
(3513, 75, -8790.34, 745.516, 98.3826, 'Miss Danna and children'),
(3513, 76, -8779.73, 744.113, 99.279, 'Miss Danna and children'),
(3513, 77, -8771.79, 739.936, 99.4639, 'Miss Danna and children'),
(3513, 78, -8754.28, 723.926, 98.2419, 'Miss Danna and children'),
(3513, 79, -8749.09, 716.946, 98.1788, 'Miss Danna and children'),
(3513, 80, -8746.88, 715.528, 98.0988, 'Miss Danna and children'),
(3513, 81, -8742.79, 714.058, 98.3354, 'Miss Danna and children'),
(3513, 82, -8738.99, 715.585, 99.8817, 'Miss Danna and children'),
(3513, 83, -8734.19, 719.332, 101.612, 'Miss Danna and children'),
(3513, 84, -8726.55, 726.071, 100.916, 'Miss Danna and children'),
(3513, 85, -8720.52, 731.1, 98.8576, 'Miss Danna and children'),
(3513, 86, -8717.12, 732.328, 97.9582, 'Miss Danna and children'),
(3513, 87, -8713.87, 731.695, 97.8571, 'Miss Danna and children'),
(3513, 88, -8701.44, 718.188, 97.0845, 'Miss Danna and children'),
(3513, 89, -8698.87, 717.931, 97.056, 'Miss Danna and children'),
(3513, 90, -8696.45, 718.359, 97.079, 'Miss Danna and children'),
(3513, 91, -8691.13, 721.164, 97.0606, 'Miss Danna and children'),
(3513, 92, -8664.74, 742.016, 96.9616, 'Miss Danna and children'),
(3513, 93, -8661.78, 744.779, 96.8513, 'Miss Danna and children'),
(3513, 94, -8660.74, 747.841, 96.83, 'Miss Danna and children'),
(3513, 95, -8660.41, 753.099, 96.941, 'Miss Danna and children'),
(3513, 96, -8661.32, 760.476, 97.0777, 'Miss Danna and children'),
(3513, 97, -8659.51, 765.088, 96.9838, 'Miss Danna and children'),
(3513, 98, -8656.77, 769.142, 96.7888, 'Miss Danna and children'),
(3513, 99, -8638.61, 783.421, 97.0783, 'Miss Danna and children'),
(3513, 100, -8636.8, 785.949, 97.0824, 'Miss Danna and children'),
(3513, 101, -8636.04, 789.948, 96.9959, 'Miss Danna and children'),
(3513, 102, -8638.53, 793.411, 96.9091, 'Miss Danna and children'),
(3513, 103, -8657.77, 814.974, 96.9152, 'Miss Danna and children'),
(3513, 104, -8658.98, 818.576, 96.8741, 'Miss Danna and children'),
(3513, 105, -8659.19, 822.476, 96.87, 'Miss Danna and children'),
(3513, 106, -8657.27, 825.576, 96.8886, 'Miss Danna and children'),
(3513, 107, -8626.48, 848.032, 96.883, 'Miss Danna and children'),
(3513, 108, -8613.57, 856.703, 96.9606, 'Miss Danna and children'),
(3513, 109, -8610.13, 856.724, 96.9606, 'Miss Danna and children'),
(3513, 110, -8607.06, 855.198, 96.8832, 'Miss Danna and children'),
(3513, 111, -8604.92, 853.151, 96.887, 'Miss Danna and children'),
(3513, 112, -8604.77, 850.972, 96.8834, 'Miss Danna and children'),
(3513, 113, -8606.21, 847.546, 96.8659, 'Miss Danna and children'),
(3513, 114, -8607.73, 845.354, 96.8584, 'Miss Danna and children'),
(3513, 115, -8629.72, 823.935, 96.7455, 'Miss Danna and children'),
(3513, 116, -8632.42, 818.756, 96.7605, 'Miss Danna and children'),
(3513, 117, -8634.7, 810.87, 96.8638, 'Miss Danna and children'),
(3513, 118, -8634.83, 804.468, 96.8329, 'Miss Danna and children'),
(3513, 119, -8633.66, 795.159, 96.8915, 'Miss Danna and children'),
(3513, 120, -8632.29, 790.398, 96.86, 'Miss Danna and children'),
(3513, 121, -8628.96, 783.286, 96.9338, 'Miss Danna and children'),
(3513, 122, -8625.14, 778.093, 96.8276, 'Miss Danna and children'),
(3513, 123, -8623.4, 776.638, 96.7829, 'Miss Danna and children'),
(3513, 124, -8621.37, 776.737, 96.7475, 'Miss Danna and children'),
(3513, 125, -8619.98, 777.857, 96.7115, 'Miss Danna and children'),
(3513, 126, -8616, 772.206, 96.736, 'Miss Danna and children'),
(3513, 127, -8610.52, 766.333, 96.8316, 'Miss Danna and children'),
(3513, 128, -8604.59, 762.507, 96.9382, 'Miss Danna and children'),
(3513, 129, -8595.01, 756.969, 96.9399, 'Miss Danna and children'),
(3513, 130, -8590.8, 752.568, 96.8915, 'Miss Danna and children'),
(3513, 131, -8583.83, 744.026, 96.957, 'Miss Danna and children'),
(3513, 132, -8581.69, 738.466, 96.8724, 'Miss Danna and children'),
(3513, 133, -8582.83, 732.984, 96.8434, 'Miss Danna and children'),
(3513, 134, -8591.72, 718.902, 96.8038, 'Miss Danna and children'),
(3513, 135, -8592.36, 714.622, 96.8427, 'Miss Danna and children'),
(3513, 136, -8590.59, 709.969, 96.8856, 'Miss Danna and children'),
(3513, 137, -8564.76, 677.169, 97.0302, 'Miss Danna and children'),
(3513, 138, -8562.4, 676.285, 97.0307, 'Miss Danna and children'),
(3513, 139, -8558.73, 676.229, 97.0531, 'Miss Danna and children'),
(3513, 140, -8543.79, 684.424, 97.6691, 'Miss Danna and children'),
(3513, 141, -8538.22, 685.529, 97.7184, 'Miss Danna and children'),
(3513, 142, -8533.7, 684.408, 97.835, 'Miss Danna and children'),
(3513, 143, -8525.26, 674.301, 102.385, 'Miss Danna and children'),
(3513, 144, -8517.83, 663.737, 102.237, 'Miss Danna and children'),
(3513, 145, -8513.29, 656.849, 100.966, 'Miss Danna and children'),
(3513, 146, -8513.38, 652.064, 100.581, 'Miss Danna and children'),
(3513, 147, -8515.92, 648.132, 100.445, 'Miss Danna and children'),
(3513, 148, -8530.75, 637.029, 100.242, 'Miss Danna and children'),
(3513, 149, -8565.23, 612.941, 102.673, 'Miss Danna and children'),
(3513, 150, -8575.88, 602.362, 103.393, 'Miss Danna and children'),
(3513, 151, -8582.08, 592.856, 103.691, 'Miss Danna and children'),
(3513, 152, -8585.57, 583.2, 103.507, 'Miss Danna and children'),
(3513, 153, -8586.52, 573.333, 102.997, 'Miss Danna and children'),
(3513, 154, -8584.76, 561.493, 101.994, 'Miss Danna and children'),
(3513, 155, -8582.2, 550.296, 102.1, 'Miss Danna and children'),
(3513, 156, -8577.28, 542.722, 102.064, 'Miss Danna and children'),
(3513, 157, -8565.64, 527.541, 101.163, 'Miss Danna and children'),
(3513, 158, -8551.2, 508.892, 98.4646, 'Miss Danna and children'),
(3513, 159, -8536.86, 490.785, 100.425, 'Miss Danna and children'),
(3513, 160, -8537.16, 485.543, 101.347, 'Miss Danna and children'),
(3513, 161, -8538.81, 481.7, 102.098, 'Miss Danna and children'),
(3513, 162, -8541.32, 478.345, 102.811, 'Miss Danna and children'),
(3513, 163, -8545.32, 474.881, 103.737, 'Miss Danna and children'),
(3513, 164, -8548.46, 472.552, 104.279, 'Miss Danna and children'),
(3513, 165, -8549.38, 469.871, 104.532, 'Miss Danna and children'),
(3513, 166, -8548.71, 468.899, 104.56, 'Miss Danna and children');

DELETE FROM creature WHERE guid IN (265896,265895,265894,265893,265892,265891,265890,265889);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265896, 3513, 0, 1519, 5390, 1, 1, '', 0, 0, -8548.69, 468.778, 104.59, 5.35816, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265895, 3512, 0, 1519, 5390, 1, 1, '', 0, 0, -8546.83, 470.687, 104.59, 5.56069, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265894, 3511, 0, 1519, 5390, 1, 1, '', 0, 0, -8548.94, 471.396, 104.46, 5.51202, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265893, 3510, 0, 1519, 5390, 1, 1, '', 0, 0, -8550.98, 470.712, 104.59, 5.17707, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265892, 3509, 0, 1519, 5390, 1, 1, '', 0, 0, -8546.22, 469.739, 104.623, 5.43977, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265891, 3508, 0, 1519, 5390, 1, 1, '', 0, 0, -8547.81, 471.286, 104.473, 5.51627, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265890, 3507, 0, 1519, 5390, 1, 1, '', 0, 0, -8551.59, 469.525, 104.59, 5.36628, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES (265889, 3505, 0, 1519, 5390, 1, 1, '', 0, 0, -8551.53, 468.627, 104.593, 5.26744, 180, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM creature_template_addon WHERE entry IN (3505,3507,3508,3509,3510,3511,3512,3513);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3505, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3507, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3508, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3509, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3510, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3511, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3512, 0, 0, 0, 1, 0, '');
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (3513, 0, 0, 0, 1, 0, '');


DELETE FROM `creature_text` WHERE `Entry`=3511 AND `Text`='I wanna see the dragon skeleton in the great library.';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (3511, 0, 0, 'I wanna see the dragon skeleton in the great library.', 12, 7, 100, 1, 0, 0, 1132, 0, 0, 0, 'Steven to Miss Danna');
DELETE FROM `creature_text` WHERE `Entry`=3511 AND `Text`='Teacher, he keeps poking me!';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (3511, 3, 0, 'Teacher, he keeps poking me!', 12, 7, 100, 0, 0, 0, 1139, 5370, 5370, 0, 'Steven to Miss Danna');
DELETE FROM `creature_text` WHERE `Entry`=3512 AND `Text`='Is it true that the paladins train here?';
INSERT INTO `creature_text` (`Entry`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `MinTimer`, `MaxTimer`, `SpellID`, `comment`) VALUES (3512, 0, 0, 'Is it true that the paladins train here?', 12, 7, 100, 1, 0, 0, 1153, 0, 0, 0, 'Jimmy to Miss Danna');


UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3505;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3505);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3505, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3505, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 1, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3505, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3505, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3505, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3505, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3505, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3505, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3505, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3505, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3505, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3505, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3505, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3505, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3505, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3505, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3505, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3505, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3505, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3505, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3505, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3505, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3505, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3505, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3505, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3505, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3507;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3507);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3507, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3507, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 5, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3507, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3507, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3507, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3507, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3507, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3507, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3507, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3507, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3507, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3507, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3507, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3507, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3507, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3507, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3507, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3507, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3507, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3507, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3507, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3507, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3507, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3507, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3507, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3507, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3508;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3508);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3508, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 5, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3508, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 20, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3508, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3508, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3508, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3508, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3508, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3508, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3508, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3508, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3508, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3508, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3508, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3508, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3508, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3508, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3508, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3508, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3508, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3508, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3508, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3508, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3508, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3508, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3508, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3508, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3509;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3509);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3509, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 7, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3509, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 30, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3509, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3509, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3509, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3509, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3509, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3509, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3509, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3509, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3509, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3509, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3509, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3509, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3509, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3509, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3509, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3509, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3509, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3509, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3509, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3509, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3509, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3509, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3509, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3509, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3510;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3510);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3510, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3510, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 10, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3510, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3510, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3510, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3510, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3510, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3510, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3510, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3510, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3510, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3510, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3510, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3510, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3510, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3510, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3510, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3510, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3510, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3510, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3510, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3510, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3510, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3510, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3510, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3510, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3511;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3511);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3511, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3511, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 15, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3511, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3511, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3511, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3511, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3511, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3511, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3511, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3511, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3511, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3511, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3511, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3511, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3511, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3511, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3511, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3511, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3511, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3511, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3511, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3511, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3511, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3511, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3511, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3511, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 3512;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 3512);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3512, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 219, 1, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Disable Pathing'),
(3512, 0, 1, 0, 1, 0, 100, 0, 2000, 2000, 20000, 20000, 29, 0, 25, 0, 0, 0, 0, 11, 3513, 10, 0, 0, 0, 0, 0, 'OOC - Follow Miss Danna'),
(3512, 0, 100, 0, 22, 0, 100, 0, 101, 2000, 2000, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Wave Emote - Wave'),
(3512, 0, 101, 0, 22, 0, 100, 0, 41, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Flex Emote - Laugh'),
(3512, 0, 102, 0, 22, 0, 100, 0, 39, 2000, 2000, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Fart Emote - Laugh'),
(3512, 0, 103, 0, 22, 0, 100, 0, 5, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Applaud Emote - Bow'),
(3512, 0, 104, 0, 22, 0, 100, 0, 24, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Clap Emote - Bow'),
(3512, 0, 105, 0, 22, 0, 100, 0, 21, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cheer Emote - Bow'),
(3512, 0, 106, 0, 22, 0, 100, 0, 33, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Curtsey Emote - Bow'),
(3512, 0, 107, 0, 22, 0, 100, 0, 26, 2000, 2000, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Congrat Emote - Bow'),
(3512, 0, 108, 0, 22, 0, 100, 0, 8, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Beg Emote - \'No\''),
(3512, 0, 109, 0, 22, 0, 100, 0, 31, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cry Emote - \'No\''),
(3512, 0, 110, 0, 22, 0, 100, 0, 35, 2000, 2000, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Drink Emote - \'Yes\''),
(3512, 0, 111, 0, 22, 0, 100, 0, 28, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Cower Emote - Flex'),
(3512, 0, 112, 0, 22, 0, 100, 0, 60, 2000, 2000, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Laugh Emote - Question'),
(3512, 0, 113, 0, 22, 0, 100, 0, 75, 2000, 2000, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Roar Emote - Roar'),
(3512, 0, 114, 0, 22, 0, 100, 0, 98, 2000, 2000, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Threaten Emote - \'No\''),
(3512, 0, 115, 0, 22, 0, 100, 0, 100, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Victory Emote - Flex'),
(3512, 0, 116, 0, 22, 0, 100, 0, 80, 2000, 2000, 0, 5, 94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Sexy Emote - Dance'),
(3512, 0, 117, 0, 22, 0, 100, 0, 104, 2000, 2000, 0, 5, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Receive Whistle Emote - Flex'),
(3512, 0, 122, 123, 22, 0, 30, 0, 89, 2000, 2000, 0, 11, 58519, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Spit Emote - Chance to Cast Spit on invoker'),
(3512, 0, 123, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3512, 0, 124, 125, 22, 0, 30, 0, 77, 2000, 2000, 0, 11, 58511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Rude Emote - Chance to Cast Rotten Apple on invoker'),
(3512, 0, 125, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote'),
(3512, 0, 126, 127, 22, 0, 30, 0, 68, 2000, 2000, 0, 11, 58514, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Receive Nosepick Emote - Chance to Cast Rotten Banana on invoker'),
(3512, 0, 127, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - \'No\' Emote');
