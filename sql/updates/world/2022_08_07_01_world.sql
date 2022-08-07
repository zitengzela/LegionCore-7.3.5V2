DELETE FROM `smart_scripts` WHERE `entryorguid`=111109 AND `source_type`=0;
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_emissary_auldbridge' WHERE `entry`=111109;
