ALTER TABLE `creature_template_wdb` 
  MODIFY COLUMN `Name1` text AFTER `Entry`,
  MODIFY COLUMN `Name2` text AFTER `Name1`,
  MODIFY COLUMN `Name3` text AFTER `Name2`,
  MODIFY COLUMN `Name4` text AFTER `Name3`,
  MODIFY COLUMN `NameAlt1` text AFTER `Name4`,
  MODIFY COLUMN `NameAlt2` text AFTER `NameAlt1`,
  MODIFY COLUMN `NameAlt3` text AFTER `NameAlt2`,
  MODIFY COLUMN `NameAlt4` text AFTER `NameAlt3`,  
  MODIFY COLUMN `Title` text AFTER `NameAlt4`,
  MODIFY COLUMN `TitleAlt` text AFTER `Title`,
  MODIFY COLUMN `CursorName` varchar(64) DEFAULT NULL AFTER `TitleAlt`,
  DROP INDEX `idx_name`;
  
ALTER TABLE `creature_template_wdb_locale` 
  MODIFY COLUMN `Title` text AFTER `Locale`,
  MODIFY COLUMN `TitleAlt` text AFTER `Title`,
  MODIFY COLUMN `Name1` text AFTER `TitleAlt`,
  MODIFY COLUMN `Name2` text AFTER `Name1`,
  MODIFY COLUMN `Name3` text AFTER `Name2`,
  MODIFY COLUMN `Name4` text AFTER `Name3`,
  MODIFY COLUMN `NameAlt1` text AFTER `Name4`,
  MODIFY COLUMN `NameAlt2` text AFTER `NameAlt1`,
  MODIFY COLUMN `NameAlt3` text AFTER `NameAlt2`,
  MODIFY COLUMN `NameAlt4` text AFTER `NameAlt3`;