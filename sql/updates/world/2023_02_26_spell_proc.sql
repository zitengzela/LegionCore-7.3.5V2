SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `spell_proc`
-- ----------------------------
DROP TABLE IF EXISTS `spell_proc`;
CREATE TABLE `spell_proc` (
  `spellId` mediumint(8) NOT NULL DEFAULT 0,
  `schoolMask` tinyint(4) NOT NULL DEFAULT 0,
  `spellFamilyName` smallint(5) unsigned NOT NULL DEFAULT 0,
  `spellFamilyMask0` int(10) unsigned NOT NULL DEFAULT 0,
  `spellFamilyMask1` int(10) unsigned NOT NULL DEFAULT 0,
  `spellFamilyMask2` int(10) unsigned NOT NULL DEFAULT 0,
  `spellFamilyMask3` int(10) unsigned NOT NULL DEFAULT 0,
  `typeMask` int(10) unsigned NOT NULL DEFAULT 0,
  `spellTypeMask` int(10) unsigned NOT NULL DEFAULT 0,
  `spellPhaseMask` int(11) NOT NULL DEFAULT 0,
  `hitMask` int(11) NOT NULL DEFAULT 0,
  `attributesMask` int(10) unsigned NOT NULL DEFAULT 0,
  `ratePerMinute` float NOT NULL DEFAULT 0,
  `chance` float NOT NULL DEFAULT 0,
  `cooldown` float unsigned NOT NULL DEFAULT 0,
  `charges` int(10) unsigned NOT NULL DEFAULT 0,
  `modcharges` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`spellId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci;

-- ----------------------------
-- Records of spell_proc
-- ----------------------------
INSERT INTO `spell_proc` VALUES ('209493', '0', '0', '0', '0', '0', '0', '16', '0', '1', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `spell_proc` VALUES ('204140', '0', '0', '0', '0', '0', '0', '16', '0', '1', '0', '0', '0', '0', '0', '4', '0');
INSERT INTO `spell_proc` VALUES ('206333', '0', '0', '0', '0', '0', '0', '16', '0', '1', '0', '0', '0', '0', '0', '1', '0');
INSERT INTO `spell_proc` VALUES ('209706', '0', '0', '0', '0', '0', '0', '16', '0', '1', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `spell_proc` VALUES ('216974', '0', '0', '0', '0', '0', '0', '16', '0', '1', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `spell_proc` VALUES ('208081', '0', '0', '0', '0', '0', '0', '331776', '0', '1', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `spell_proc` VALUES ('198300', '0', '0', '0', '0', '0', '0', '69648', '0', '1', '0', '0', '0', '0', '0', '1', '1');
INSERT INTO `spell_proc` VALUES ('164545', '0', '0', '0', '0', '0', '0', '65536', '0', '1', '0', '0', '0', '0', '0', '0', '3');
INSERT INTO `spell_proc` VALUES ('164547', '0', '0', '0', '0', '0', '0', '65536', '0', '1', '0', '0', '0', '0', '0', '0', '3');
