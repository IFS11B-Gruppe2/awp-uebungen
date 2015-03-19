USE test;
DROP TABLE IF EXISTS delivery_men;

#######
## 1 ##
#######
CREATE TABLE IF NOT EXISTS `delivery_men` (
	`id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Lieferantennummer',
	`name` varchar(40) COMMENT 'Name',
	`city` varchar(40) COMMENT 'Ort',
	`zip_code` varchar(5) COMMENT 'PLZ',
	`contact_person` varchar(40) COMMENT 'Ansprechpartner',
	`delivery_time` tinyint(3) unsigned COMMENT 'Lieferdauer in Wochen',

	CONSTRAINT PRIMARY KEY pk_delivery_man (id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_general_ci COMMENT='tblLieferanten';

#######
## 2 ##
#######
INSERT INTO delivery_men
VALUES
  (125, 'Berghaus', 'Remscheid', '52336', 'Herr Günther', 4),
  (166, 'Däubler', 'Fürth', '90765', 'Frau Lot', 5),
  (321, 'Rietle', 'Nürnberg', '90405', 'Herr Kern', 4)
;

#######
## 3 ##
#######
UPDATE delivery_men
SET name = 'Riedel'
WHERE id = 321
;

#######
## 4 ##
#######
DELETE FROM delivery_men
WHERE id = 166
;

#######
## 5 ##
#######
UPDATE delivery_men
SET delivery_time = 2
WHERE delivery_time = 4
;

#######
## 6 ##
#######
INSERT INTO delivery_men
  (id, name, city)
VALUES
  (554, 'König', 'Darmstadt')
;

#######
## 7 ##
#######
