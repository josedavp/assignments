-- createProperty.sql
-- Adminer 4.7.8 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

drop table if exists Property;
CREATE TABLE `Property` (
  `propId`         char(9)     NOT NULL,
  `locDesc`           varchar(31) NOT NULL,
  `state`           char(2) DEFAULT NULL,
  `propType`        char(1) DEFAULT 'T',
  `rating`          int(3)  DEFAULT NULL,
  PRIMARY KEY (`propId`)
)  ENGINE=InnoDB DEFAULT CHARSET=latin1;
