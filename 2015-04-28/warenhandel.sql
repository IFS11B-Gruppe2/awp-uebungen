/*!40101 SET NAMES utf8 */;

--
-- Datenbank: `warenhandel`
--
CREATE DATABASE IF NOT EXISTS `warenhandel` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `warenhandel`;

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `customers`
--

DROP TABLE IF EXISTS `customers`;
CREATE TABLE IF NOT EXISTS `customers` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifikationsnummer des Kundes',
  `firstname` varchar(30) NOT NULL COMMENT 'Nachname des Kundes',
  `lastname` varchar(30) NOT NULL COMMENT 'Vorname des Kundes',
  `address` varchar(50) NOT NULL COMMENT 'Straße des Kundes',

  PRIMARY KEY `pk_customers` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Information der Kunden';

-- --------------------------------------------------------

--
-- Tabellenstruktur für Tabelle `orders`
--

DROP TABLE IF EXISTS `orders`;
CREATE TABLE IF NOT EXISTS `orders` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifikationsnummer der Bestellung',
  `customerID` int(10) unsigned NOT NULL COMMENT 'Identifikationsnummer des Kundes',
  `date` date NOT NULL COMMENT 'Datum der Bestellung',

  PRIMARY KEY `pk_orders` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Informationen der Bestellungen';

-- --------------------------------------------------------

--
-- Fremdeschüssel für Tabelle `orders`
--

ALTER TABLE `orders`
ADD FOREIGN KEY `fk_order_customer` (`customerID`)
  REFERENCES `customers` (`id`)
  ON DELETE NO ACTION
  ON UPDATE NO ACTION
;
