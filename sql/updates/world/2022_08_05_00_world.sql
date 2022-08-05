DELETE FROM `creature_questender` WHERE `id`=120738 AND `quest`=46842;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES 
(120738, 46842);

update `creature_template` set `flags_extra`= 128 where `entry` in (124903,127036,122272);

-- quest 47890 fix magni visibility
DELETE FROM `smart_scripts` WHERE `entryorguid`=119388 AND `source_type`=0 AND `id`=1 AND `link`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=124595 AND `source_type`=0 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `link`= 0 WHERE `entryorguid`=124595 AND `source_type`=0 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=124595 AND `source_type`=0 AND `id`=3 AND `link`=0;

UPDATE `quest_template_addon` SET `ScriptName`= 'quest_visions_of_torment' WHERE `id`=47890;

-- quest 47220 fix phase
UPDATE `conditions` SET `ConditionTypeOrReference`= 28 WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=8701 AND `SourceEntry`=76 AND `ElseGroup`=0;
