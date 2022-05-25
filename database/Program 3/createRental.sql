-- createRental.sql
-- Adminer 4.7.8 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

drop table if exists `Rental`;
CREATE TABLE `Rental` (
  `custNr`         smallint    NOT NULL,
  `propId`         char(9)     NOT NULL,
  `startDt`        date        DEFAULT NULL,
  `totalCost`      double      NOT NULL,
  PRIMARY KEY (`custNr`,`propId`)
)  ENGINE=InnoDB DEFAULT CHARSET=latin1;
