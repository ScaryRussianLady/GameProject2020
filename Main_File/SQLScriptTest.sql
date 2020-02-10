-- Script Date: 10/02/2020 00:41  - ErikEJ.SqlCeScripting version 3.5.2.85
-- Database information:
-- Database: C:\Users\benny\source\repos\GameProject2020\Main_File\GladiatorDatabase.db
-- ServerVersion: 3.27.2
-- DatabaseSize: 32 KB
-- Created: 09/02/2020 20:04

-- User Table information:
-- Number of tables: 3
-- Attack: -1 row(s)
-- Defence: -1 row(s)
-- User: -1 row(s)

SELECT 1;
PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Mace',1,16,3,12);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Ruyi Jingu Bang',1,6,10,20);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Saggitarius Bow & Arrow',1,13,3,18);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Scissor Knife',1,7,5,20);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Sica',1,8,2,14);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Spiked Gauntlet',1,12,4,8);
INSERT INTO [Defence] ([weapon_name],[quality],[damage],[attack_speed],[block_chance(%)]) VALUES (
'Spiked Hammer',2,20,2,8);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Gladius',1,18,1,8);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Retiarius Trident',1,18,1,12);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Rudis',1,8,2,8);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Sagittarius Bow & Arrow',1,13,3,10);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Scissor Knife',1,7,5,20);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Sica',1,8,2,14);
INSERT INTO [Attack] ([weapon_name],[quality],[damage],[attack_speed],[critical_chance(%)]) VALUES (
'Spear of Carpophorus',2,20,3,18);
COMMIT;

