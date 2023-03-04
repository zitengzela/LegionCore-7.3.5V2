SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for version
-- ----------------------------
DROP TABLE IF EXISTS `version`;
CREATE TABLE `version`  (
  `core_version` varchar(120) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Core revision dumped at startup.',
  `core_revision` varchar(120) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `db_version` varchar(120) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'Version of characters DB.'
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_general_ci COMMENT = 'Version Notes' ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of version
-- ----------------------------
INSERT INTO `version` VALUES ('TrinityCore rev. Archived 0000-00-00 00:00:00 +0000 ( branch) (Unix, debug)', '', 'LegionCore Characters Database 2020-04-03');

SET FOREIGN_KEY_CHECKS = 1;
