#######
## 2 ##
#######
DROP DATABASE IF EXISTS `rentalap`;
CREATE DATABASE IF NOT EXISTS `rentalap` CHARACTER SET utf8 COLLATE utf8_general_ci;
USE rentalap;

#######
## 3 ##
#######
DROP TABLE IF EXISTS `processor_types`;
CREATE TABLE IF NOT EXISTS `processor_types` (
	`id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'ID-Nummer',
	`define_name` varchar(40) NOT NULL COMMENT 'Kurze Beschreibung',
	`description` varchar(400) DEFAULT NULL COMMENT 'Lange Beschreibung',

	CONSTRAINT `pk_processor_types` PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='Prozessortypen';

DROP TABLE IF EXISTS `battery_types`;
CREATE TABLE IF NOT EXISTS `battery_types` (
	`id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'ID-Nummer',
	`define_name` varchar(40) NOT NULL COMMENT 'Kurze Beschreibung',
	`description` varchar(400) DEFAULT NULL COMMENT 'Lange Beschreibung',

	CONSTRAINT `pk_battery_types` PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='Akkustypen';

DROP TABLE IF EXISTS `laptops`;
CREATE TABLE IF NOT EXISTS `laptops` (
	`inventar_number` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Inventarnummer',
	`processor_type_id` int(10) unsigned DEFAULT NULL COMMENT 'Fremdschlüssel processor_types',
	`battery_type_id` int(10) unsigned DEFAULT NULL COMMENT 'Fremdschlüssel battery_type',

	CONSTRAINT `pk_laptops` PRIMARY KEY (inventar_number),
	CONSTRAINT `fk_laptops_processor_types` FOREIGN KEY (`processor_type_id`)
		REFERENCES `processor_types` (`id`)
		ON DELETE NO ACTION ON UPDATE NO ACTION,
	CONSTRAINT `fk_laptops_battery_types` FOREIGN KEY (`battery_type_id`)
		REFERENCES `battery_types` (`id`)
		ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='Daten der Laptops';

DROP TABLE IF EXISTS `customers`;
CREATE TABLE IF NOT EXISTS `customers` (
	`id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Ausweissnummer',
	`name` varchar(40) NOT NULL COMMENT 'Name',
	`credit_card` varchar(16) DEFAULT NULL COMMENT 'Kreditkarte',

	CONSTRAINT `pk_customers` PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='Daten der Kunden';

DROP TABLE IF EXISTS `rents`;
CREATE TABLE IF NOT EXISTS `rents` (
	`id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'ID-Nummer',
	`customer_id` int(10) unsigned DEFAULT NULL COMMENT 'Fremdschlüssel customers',
	`laptop_id` int(10) unsigned DEFAULT NULL COMMENT 'Fremdschlüssel laptops',
	`paid` decimal(6,2) NOT NULL COMMENT 'Mietgebühr',

	CONSTRAINT `pk_rents` PRIMARY KEY (`id`),
	CONSTRAINT `fk_rents_customer` FOREIGN KEY (`customer_id`)
		REFERENCES `customers` (`id`)
		ON DELETE NO ACTION ON UPDATE NO ACTION,
	CONSTRAINT `fk_rents_laptops` FOREIGN KEY (`laptop_id`)
		REFERENCES `laptops` (`inventar_number`)
		ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='Daten der Mieten';

#######
## 4 ##
#######
INSERT INTO `processor_types`
	(`define_name`, `description`)
VALUES
	('i3', 'Intel Core i3'),
	('i7', 'Intel Core i7')
;

INSERT INTO `battery_types`
	(`define_name`, `description`)
VALUES
	('Li-ion', 'Lithium-ion battery'),
	('LiPo', 'Lithium-Polymer-Akkumulator')
;

INSERT INTO `customers`
	(`name`, `credit_card`)
VALUES
	('Pepe', '5555444433338888'),
	('Antonio', '1111222233334444'),
	('Anacleto', '7777333311114444')
;

SET @i3 = (SELECT id FROM processor_types WHERE define_name = 'i3');
SET @i7 = (SELECT id FROM processor_types WHERE define_name = 'i7');
SET @li_ion = (SELECT id FROM battery_types WHERE define_name = 'Li-ion');
SET @lipo = (SELECT id FROM battery_types WHERE define_name = 'LiPo');

INSERT INTO `laptops`
	(`processor_type_id`, `battery_type_id`)
VALUES
	(@i3, @lipo),
	(@i7, @li_ion)
;

#######
## 5 ##
#######
DROP TABLE IF EXISTS `old_customers`;
CREATE TABLE IF NOT EXISTS `old_customers`
	AS SELECT * FROM customers WHERE id IS NULL
;
ALTER TABLE `old_customers`
	COMMENT='Daten der alten Kunden'
;

#######
## 6 ##
#######
INSERT INTO `old_customers`
	(`name`, `credit_card`)
VALUES
	('Alberto', '111222333444'),
	('Manuel', '5555444433338888')
;

#######
## 7 ##
#######
UPDATE `old_customers`
SET `credit_card` = '1111222233334444'
WHERE id = 1
;

#######
## 8 ##
#######
INSERT INTO `rents`
	(`customer_id`, `laptop_id`, `paid`)
VALUES
	(1, 1, 40.99),
	(1, 2, 20.99)
;

#######
## 9 ##
#######
# ??
INSERT INTO `customers`
	(`name`, `credit_card`)
VALUES
	('Alberto', '1111222233334444'),
	('Manuel', '5555444433338888')
;
# ??

########
## 10 ##
########
DROP TABLE IF EXISTS `old_customers`;

########
## 11 ##
########
ALTER TABLE `laptops`
ADD COLUMN `notes` text DEFAULT NULL COMMENT 'Bemerkungen'
;

########
## 12 ##
########
UPDATE `laptops`
SET notes = 'Rechner hat Kratzer'
WHERE inventar_number = 1
;
