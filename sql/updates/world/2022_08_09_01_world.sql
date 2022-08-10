DELETE FROM `spell_script_names` WHERE `spell_id`=192465;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(192465, 'spell_teleport_the_skyfire');

DELETE FROM `smart_scripts` WHERE `entryorguid`=91553 AND `source_type`=0;
update `creature_template` set `AIName`= '' where `entry` = 91553;

DELETE FROM `smart_scripts` WHERE `entryorguid`=97979 AND `source_type`=0;
update `creature_template` set `AIName`= '' where `entry` = 97979;

DELETE FROM `smart_scripts` WHERE `entryorguid`=91743 AND `source_type`=0 AND `id` >=1;
