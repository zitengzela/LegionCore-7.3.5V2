-- Дамп структуры для таблица creature_formations
CREATE TABLE IF NOT EXISTS `creature_formations` (
  `leaderGUID` bigint(20) unsigned NOT NULL DEFAULT '0',
  `memberGUID` bigint(20) unsigned NOT NULL DEFAULT '0',
  `dist` float unsigned NOT NULL,
  `angle` float unsigned NOT NULL,
  `groupAI` int(10) unsigned NOT NULL,
  PRIMARY KEY (`memberGUID`),
  KEY `leaderGUID` (`leaderGUID`),
  KEY `memberGUID` (`memberGUID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- Дамп данных таблицы creature_formations: 4 rows
REPLACE INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
	(102827, 102816, 7, 45, 515),
	(102827, 102815, 5, 360, 515),
	(102827, 102817, 5, 90, 515),
	(102827, 102827, 0, 0, 515);

