-- Дамп структуры для таблица battlepay_product_group_locales
CREATE TABLE IF NOT EXISTS `battlepay_product_group_locales` (
  `GroupID` mediumint(8) unsigned NOT NULL DEFAULT '0',
  `Locale` text,
  `Name` text,
  PRIMARY KEY (`GroupID`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- Дамп данных таблицы battlepay_product_group_locales: 13 rows
REPLACE INTO `battlepay_product_group_locales` (`GroupID`, `Locale`, `Name`) VALUES
	(1, 'ruRU', 'Транспорт'),
	(2, 'ruRU', 'Питомцы'),
	(3, 'ruRU', 'Услуги'),
	(4, 'ruRU', 'Золото'),
	(5, 'ruRU', 'Профессии'),
	(7, 'ruRU', '|cffa335eeБроня'),
	(8, 'ruRU', 'Рекомендуем'),
	(9, 'ruRU', 'Игрушки'),
	(11, 'ruRU', 'Сумки'),
	(12, 'ruRU', 'Реликвии'),
	(6, 'ruRU', '|cffff8000Легендарные'),
	(16, 'ruRU', '|cffff8000Внешний вид'),
	(10, 'ruRU', 'Улучшения');

