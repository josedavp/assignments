-- createCustomer.sql
-- Adminer 4.7.8 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

drop table if exists Customer;
CREATE TABLE `Customer` (
  `custNr`          smallint    NOT NULL,
  `name`            varchar(30) DEFAULT NULL,
  `baseLoc`         char(2)     DEFAULT NULL, 
  `birthDt`         date        DEFAULT NULL,
  `gender`          char(1)     DEFAULT 'U',  
  PRIMARY KEY (`custNr`)
)  ENGINE=InnoDB DEFAULT CHARSET=latin1;
