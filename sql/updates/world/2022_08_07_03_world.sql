DELETE FROM `creature` WHERE `guid` in (507622,507623);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `dynamicflags`, `AiID`, `MovementID`, `MeleeID`, `isActive`, `skipClone`, `personal_size`, `isTeemingSpawn`, `unit_flags3`) VALUES 
(507622, 91223, 1220, 7558, 7910, 1, 1, '', 0, 0, 1813.04, 6869.26, -14.2647, 1.76829, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(507623, 91223, 1220, 7558, 7910, 1, 1, '', 0, 0, 1813.04, 6869.26, -14.2647, 2.805, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` in (507622,507623);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(507622, 0, 0, 0, 1, 0, '52550'),
(507623, 0, 0, 0, 1, 0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=38377;

DELETE FROM `quest_template_addon` WHERE `ID` in (38719,38724);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RewardMailTitle`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES 
(38719, 0, 0, 0, 38717, 38721, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 0, 0, ''),
(38724, 0, 0, 0, 38717, 38721, 0, 0, 0, '', 0, 0, 0, 0, 0, 0, 1, 0, '');
