-- insertCustomer.sql
-- Adminer 4.7.8 MySQL dump

SET NAMES utf8;
SET time_zone = '+00:00';
SET foreign_key_checks = 0;
SET sql_mode = 'NO_AUTO_VALUE_ON_ZERO';

delete from `Customer`;
INSERT INTO `Customer` (`custNr`, `name`, `baseLoc`, `birthDt`, `gender`) VALUES
(111,	'Ava Kashun',	'TX',	'2000-04-01',	'M'),
(222,	'Cam Aruh',	'CA',	'1990-09-11',	'M'),
(333,	'Pete Moss',	'FL',	'1992-03-03',	'M'),
(444,	'Bill Board',	'CA',	'1985-04-04',	'M'),
(480,	'Anita Vacay',	'TX',	'1975-06-01',	'F'),
(555,	'Perry Scope',	'OK',	'1927-04-15',	'M'),
(601,	'E Race',	'OK',	'1986-10-01',	'M'),
(666,	'Tom E Gunn',	NULL,	NULL,	'M'),
(755,	'Ray Mee',	'CA',	'1965-04-01',	'M'),
(777,	'Bob Wire',	'OK',	'1973-07-07',	'M'),
(855,	'T Doh',	'CA',	'1975-04-15',	'F'),
(888,	'Penny Lane',	'CA',	'1990-08-08',	'F'),
(890,	'Anita Break',	'CA',	'1992-08-09',	'F'),
(901,	'Peg Board',	'NY',	'1987-04-04',	'F'),
(902,	'Al B Tross',	'CA',	'1957-07-12',	'M'),
(903,	'B B Gunn',	NULL,	NULL,	'F'),
(904,	'Sally Mander',	'NY',	NULL,	'F'),
(999,	'Marcus Absent',	'NY',	'1999-09-09',	'M');

