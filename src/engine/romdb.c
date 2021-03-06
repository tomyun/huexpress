/*
 * Copyright 2013, Alexander von Gluck, All Rights Reserved.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Alexander von Gluck IV <kallisti5@unixzen.com>
 */


#include "romdb.h"

#if defined(__linux__)
#include <limits.h>
#endif
#include <stdlib.h>

#include "utils.h"

// Known NEC PC-Engine HuCards: 323
// Known NEC PC-Engine CD-ROMs: 438
// Known NEC TurboGrafx-16 HuCards: 96
// Knwon NEC TurboGrafx-16 CD-ROMs: 51

#define __ID		"Unknown"
#define __DATE		"Unknown"
#define __PUBLISHER	"Unknown"


struct rom_database kKnownRoms[KNOWN_ROM_COUNT] = {
{0x3F9F95A4, "[BIOS] CD-ROM System (v1.0)", "NEC", __ID, __DATE, JAP | CD_SYSTEM},
{0x52520BC6, "[BIOS] CD-ROM System (v2.0)", "NEC", __ID, __DATE, JAP | CD_SYSTEM},
{0x283B74E0, "[BIOS] CD-ROM System (v2.1)", "NEC", __ID, __DATE, JAP | CD_SYSTEM},
{0x51A12D90, "[BIOS] Games Express CD Card", "Games Express", __ID, __DATE, JAP | CD_SYSTEM},
{0x6D9A73EF, "[BIOS] Super CD-ROM System (v3.0)", "NEC", "PCE-SC1", __DATE, JAP | CD_SYSTEM},
{0x2B5B75FE, "[BIOS] TurboGrafx CD Super System Card (v3.0)", "NEC", __ID, __DATE, USA | CD_SYSTEM},
{0xFF2A5EC3, "[BIOS] TurboGrafx CD System Card (v2.0)", "NEC", __ID, __DATE, USA | CD_SYSTEM},
{0xFDE08D6D, "1943 Kai", "CAPCOM", "NX91002", "03-22-1991", JAP},
{0x73614660, "21 Emon - Mezase Hotel Ou!!", "NEC", __ID, __DATE, JAP},
{0x8E71D4F3, "Adventure Island", "Hudson", __ID, __DATE, JAP},
{0x25BE2B81, "Aero Blasters", "KANEKO", "TGX040051", __DATE, JAP},
{0xB03E0B32, "Aero Blasters", __PUBLISHER, __ID, __DATE, USA},
{0xCA72A828, "After Burner II", "SEGA", "NAPH-1011", "09-28-1990", JAP},
{0x933D5BCC, "Air Zonk", "Hudson", "TGX040084", __DATE, USA},
{0x60EDF4E1, "Alien Crush", "Naxat", "NX63001", "09-14-1988", JAP},
{0xEA488494, "Alien Crush", __PUBLISHER, __ID, __DATE, USA},
{0xCACC06FB, "Ankoku Densetsu", __PUBLISHER, __ID, __DATE, JAP},
{0x08A09B9A, "Aoi Blink", "Hudson", "HC90030", "04-27-1990", JAP},
{0x2B54CBA2, "Appare Gateball", __PUBLISHER, __ID, __DATE, JAP},
{0x20EF87FD, "Armed Formation F", __PUBLISHER, __ID, __DATE, JAP},
{0x5E4FA713, "Artist Tool", "Hudson", __ID, __DATE, JAP},
{0xDD175EFD, "Atomic Robo-Kid Special", __PUBLISHER, __ID, __DATE, JAP},
{0xB866D282, "AV Poker", __PUBLISHER, __ID, __DATE, JAP},
{0x8ACFC8AA, "Ballistix", "PSYGNOSIS", "CJ0001", "12-13-1991", JAP},
{0x420FA189, "Ballistix", __PUBLISHER, __ID, __DATE, USA},
{0xC267E25D, "Bari Bari Densetsu", "Taito", "TP01003", "11-29-1989", JAP},
{0x4A3DF3CA, "Barunba", "Namco", "NC90003", "04-27-1990", JAP},
{0x106BB7B2, "Batman", "SUNSOFT", "SS90003", "10-12-1990", JAP},
{0x59E44F45, "Battle Lode Runner", "Hudson", "HS93054", "02-10-1993", JAP},
{0xE70B01AF, "Battle Royale", __PUBLISHER, __ID, __DATE, USA | US_ENCODED},
{0xE439F299, "Be Ball", "Hudson", "HC90028", "03-30-1990", JAP},
{0xE1A73797, "Benkei Gaiden", "SUNSOFT", "SS89002", "12-22-1989", JAP},
{0xC9626A43, "Benkei Gaiden", __PUBLISHER, __ID, __DATE, JAP},
{0x34893891, "Bikkuriman World", __PUBLISHER, __ID, __DATE, JAP},
{0x2841FD1E, "Bikkuriman World", __PUBLISHER, __ID, __DATE, JAP},
{0xB4A1B0F6, "Blazing Lazers", "Hudson", "TGX030010", __DATE, USA | US_ENCODED | TWO_PART_ROM},
{0x958BCD09, "Blodia", "Hudson", "HC90027", "03-23-1990", JAP},
{0x37BAF6BC, "Bloody Wolf", "DATA EAST", "TGX040037", __DATE, USA},
{0xFFD92458, "Bodycon Quest II", __PUBLISHER, __ID, __DATE, JAP},
{0x5F6F3C2A, "Bomberman", "Hudson", "HC90036", "12-07-1990", USA},
{0x9ABB4D1F, "Bomberman", "Hudson", __ID, __DATE, JAP},
{0x02309AA0, "Bomberman '93 (Special Version)", __PUBLISHER, __ID, __DATE, JAP},
{0x56171C1C, "Bomberman '93", "Hudson", "HC92061", "12-11-1992", USA},
{0xB300C5D0, "Bomberman '93", "Hudson", __ID, __DATE, JAP},
{0x05362516, "Bomberman '94", "Hudson", "HC93065", "12-10-1993", JAP},
{0x1489FA51, "Bomberman - Users Battle", __PUBLISHER, __ID, __DATE, JAP},
{0x5A3F76D8, "Bonk III - Bonk's Big Adventure", "Hudson", "TGX080097", __DATE, USA},
{0x599EAD9B, "Bonk's Adventure", "Hudson", __ID, __DATE, USA},
{0x14250F9A, "Bonk's Revenge", "Hudson", "TGX040058", __DATE, USA},
{0x8F4D9F94, "Bouken Danshaku Don", __PUBLISHER, __ID, __DATE, JAP},
{0x605BE213, "Boxyboy", __PUBLISHER, __ID, __DATE, USA},
{0xCCA08B02, "Bravoman", __PUBLISHER, __ID, __DATE, USA},
{0xC9D7426A, "Break In", "Naxat", "NX89002", "08-10-1989", JAP},
{0x0D766139, "Bubblegum Crash!", "ARTMIC", "NX91005", "12-06-1991", JAP},
{0x5C4D1991, "Bull Fight - Ring no Haja", __PUBLISHER, __ID, __DATE, JAP},
{0xD233C05A, "Burning Angels", "Naxat", "NX90008", "12-07-1990", JAP},
{0xD0C250CA, "Busou Keiji - Cyber Cross", "FACE", "FA01-002", "06-23-1989", JAP},
{0x8DC0D85F, "Cadash", "Taito", "TP02015", "01-18-1991", JAP},
{0xBB0B3AEF, "Cadash", __PUBLISHER, __ID, __DATE, USA | US_ENCODED},
{0x9EDC0AEA, "Champion Wrestler", "Taito", "TPO2014", "12-14-1990", JAP},
{0x15EE889A, "Champions Forever Boxing", "NEC", "TGX040077", __DATE, USA},
{0x8CD13E9A, "Chew Man Fu", "Hudson", "TGX020035", __DATE, USA},
{0x951ED380, "Chibi Maruko-chan - Quiz de Piihyara", __PUBLISHER, __ID, __DATE, JAP},
{0xCAB21B2E, "Chikudenya Toubei", __PUBLISHER, __ID, __DATE, JAP},
{0x84098884, "Chikudenya Toubei", __PUBLISHER, __ID, __DATE, JAP},
{0xA2EE361D, "China Warrior", "Hudson", "TGX020008", __DATE, USA},
{0x0DF57C90, "Chouzetsu Rinjin - Bravoman", __PUBLISHER, __ID, __DATE, JAP},
{0xC3212C24, "Circus Lido", "UNI POST", "PJ91001", "04-06-1991", JAP},
{0xF91B055F, "City Hunter", "SUNSOFT", "SS90001", "03-02-1990", JAP},
{0x99F7A572, "Columns", "LASER SOFT", "TJ03002", "03-29-1991", JAP},
{0xB4D29E3B, "Coryoon", __PUBLISHER, __ID, __DATE, JAP},
{0xD5389889, "Coryoon", __PUBLISHER, __ID, __DATE, JAP},
{0x9033E83A, "Cratermaze", "Hudson", "TGX020027", __DATE, USA},
{0x2DF97BD0, "Cross Wiber", "FACE", __ID, __DATE, JAP},
{0x4CFB6E3E, "Cyber Core", "IGS", "TGX030030", "03-09-1990", USA},
{0xA98D276A, "Cyber Core", __PUBLISHER, __ID, __DATE, JAP},
{0xC1139BD3, "Cyber Dodge", __PUBLISHER, __ID, __DATE, JAP},
{0xA594FAC0, "Cyber Knight", "TONKIN HOUSE", "TON90003", "10-12-1990", JAP},
{0x61A2935F, "Daichi-kun Crisis", __PUBLISHER, __ID, __DATE, JAP},
{0x9107BCC8, "Daisenpuu", __PUBLISHER, __ID, __DATE, JAP},
{0xB0BA689F, "Darius Alpha", "Taito", __ID, __DATE, JAP},
{0xBEBFE042, "Darius Plus", "Taito", "NAPH-1009", __DATE, JAP},
{0x4AC97606, "Darkwing Duck", "Disney", "TGX040066", __DATE, USA},
{0x4A135429, "Darkwing Duck", "Disney", "TGX040066", __DATE, USA},
{0x9EDAB596, "Davis Cup Tennis", "LORICIEL", "TGX040061", __DATE, USA},
{0x56739BC7, "Dead Moon", "Natsume", __ID, __DATE, JAP},
{0xF5D98B0B, "Dead Moon", "Natsume", __ID, __DATE, USA},
{0x16B40B44, "Deep Blue", "PACK-IN-VIDEO", __ID, __DATE, USA},
{0x053A0F83, "Deep Blue - Kaitei Shinwa", __PUBLISHER, __ID, __DATE, JAP},
{0x5CF59D80, "Detana!! TwinBee", "KONAMI", "KM92004", "02-28-1992", JAP},
{0x4EC81A80, "Devil Crash", "Naxat", "NX90004", "07-20-1990", JAP},
{0x157B4492, "Devil's Crush", "Naxat", "TGX030038", __DATE, USA},
{0x1B5B1CB1, "Die Hard", "Nichibutsu", "NB90003", "09-28-1990", JAP},
{0x17BA3032, "Digital Champ", "Naxat", "NX89003", "10-13-1989", JAP},
{0xF42AA73E, "Don Doko Don!", "Taito", "TP02010", "05-31-1990", JAP},
{0xDC760A07, "Doraemon - Meikyuu Daisakusen", __PUBLISHER, __ID, __DATE, JAP},
{0x013A747F, "Doraemon - Nobita no Dorabian Night", __PUBLISHER, __ID, __DATE, JAP},
{0x86087B39, "Double Dungeons", "Masynya", "NCS89006", "09-29-1989", JAP},
{0x4A1A8C60, "Double Dungeons", "Masynya", "NCS89006", "09-29-1989", USA},
{0x85101C20, "Download", "NEC", "NAPH-1007", "06-22-1990", JAP},
{0x4E0DE488, "Download", "NEC", "NAPH-1007", "06-22-1990", JAP},
{0x442405D5, "Dragon Egg!", "Masynya", "NCS91003", "09-27-1991", JAP},
{0xC89CE75A, "Dragon Saber", "Namco", "NC91005", "12-27-1991", JAP},
{0x3219849C, "Dragon Saber", "Namco", "NC91005", "12-27-1991", JAP},
{0x01A76935, "Dragon Spirit", __PUBLISHER, __ID, __DATE, JAP},
{0x086F148C, "Dragon Spirit", __PUBLISHER, __ID, __DATE, USA},
{0x7D2C4B09, "Dragon's Curse", "Hudson", "TGX020039", __DATE, USA},
{0x8E81FCAC, "Drop Rock Hora Hora ", "DATA EAST", "DE90005", "03-30-1990", JAP},
{0x67EC5EC4, "Drop Rock Hora Hora", "DATA EAST", __ID, __DATE, JAP},
{0xFEA27B32, "Drop.Off", __PUBLISHER, __ID, __DATE, USA},
{0x72E00BC4, "Druaga no Tou", __PUBLISHER, __ID, __DATE, JAP},
{0x4FF01515, "Dungeon Explorer", "ATLUS", "HC63015", "03-04-1989", USA},
{0x1B1A80A2, "Dungeon Explorer", __PUBLISHER, __ID, __DATE, JAP},
{0xCA68FF21, "Energy", "Masynya", "NCS89005", "04-19-1989", JAP},
{0xD50FF730, "F-1 Dream", __PUBLISHER, __ID, __DATE, JAP},
{0x09048174, "F-1 Pilot", __PUBLISHER, __ID, __DATE, JAP},
{0x79705779, "F1 Circus", "Nichibutsu", "NB89002", "09-14-1990", JAP},
{0xE14DEE08, "F1 Circus", "Nichibutsu", "NB89002", "09-14-1990", JAP},
{0xD7CFD70F, "F1 Circus '91", "Nichibutsu", "NB91004", "07-12-1991", JAP},
{0xB268F2A2, "F1 Circus '92", "Nichibutsu", __ID, "06-14-05", JAP},
{0x13BF0409, "F1 Triple Battle", "HUMAN", "HM89002", "12-23-1989", JAP},
{0x0BC0A12B, "Falcon", "SPECTRUM HOLOBYTE", "TGX040067", __DATE, USA},
{0xE8C3573D, "Fantasy Zone", "SEGA", "H49G-1001", "10-14-1988", USA},
{0x72CB0F9D, "Fantasy Zone", __PUBLISHER, __ID, __DATE, JAP},
{0x1828D2E5, "Fighting Run", "Nichibutsu", "NB91005", "11-29-1991", JAP},
{0xC90971BA, "Final Blaster", "Namco", "NC90007", "09-28-1990", JAP},
{0xC8C084E3, "Final Lap Twin", "Namco", "NC89003", "07-07-1989", JAP},
{0x26408EA3, "Final Lap Twin", __PUBLISHER, __ID, __DATE, USA},
{0x560D2305, "Final Match Tennis", "HUMAN", "HM91004", "03-01-1991", JAP},
{0x02A578C5, "Final Soldier (Special)", "Hudson", "HC91045", "07-05-1991", JAP},
{0xAF2DD2AF, "Final Soldier", "Hudson", __ID, __DATE, JAP},
{0x90ED6575, "Fire Pro Wrestling", "HUMAN", "HM89001", "06-22-1989", JAP},
{0xE88987BB, "Fire Pro Wrestling 2", __PUBLISHER, __ID, __DATE, JAP},
{0x534E8808, "Fire Pro Wrestling 3", __PUBLISHER, __ID, __DATE, JAP},
{0x85A1E7B6, "Formation Soccer - Human Cup '90", __PUBLISHER, __ID, __DATE, JAP},
{0x7146027C, "Formation Soccer - On J. League", __PUBLISHER, __ID, __DATE, JAP},
{0x12C4E6FD, "Fushigi no Yume no Alice", __PUBLISHER, __ID, __DATE, JAP},
{0x95F90DEC, "Gai Flame", "Masynya", "NCS90001", "01-26-1990", JAP},
{0x6FD6827C, "Gaia no Monshou", "NCS", "NCS63001", "09-23-1988", JAP},
{0x1A8393C6, "Galaga '88", "Namco", "NC63002", "7/15/1988", JAP},
{0x2909DEC6, "Galaga '90", "Namco", "TGX020018", __DATE, USA},
{0xEC42622E, "Galaga '90", "Tai Sang", __ID, __DATE, JAP},
{0x27A4D11A, "Ganbare! Golf Boys", "Masynya", "NCS89003", "03-28-1989", JAP},
{0xE8702D51, "Gekisha Boy", __PUBLISHER, __ID, __DATE, JAP},
{0xAD450DFC, "Genji Tsuushin Agedama", __PUBLISHER, __ID, __DATE, JAP},
{0xB926C682, "Genpei Toumaden", __PUBLISHER, __ID, __DATE, JAP},
{0x8793758C, "Genpei Toumaden Ni no Maki", __PUBLISHER, __ID, __DATE, JAP},
{0x2DB4C1FD, "Ghost Manor", "ICOM", "TGX040076", __DATE, USA},
{0xE749A22C, "Gokuraku! Chuuka Taisen", __PUBLISHER, __ID, __DATE, JAP},
{0x9A353AFD, "Gomola Speed", "UPL", "UP02002", "09-28-1990", JAP},
{0x0517DA65, "Gradius", "KONAMI", "KM91001", "11-15-1991", JAP},
{0xF370B58E, "Gunboat", "NEC", "TGX040060", __DATE, USA},
{0xA17D4D7E, "Gunhed", "Hudson", "HC89019", "07-07-1989", JAP},
{0x57F183AE, "Gunhed - Hudson Gunhed Taikai", __PUBLISHER, __ID, __DATE, JAP},
{0xBA4D0DD4, "Hana Taka Daka!", "Natsume", __ID, "08-09-1991", JAP},
{0xBF3E2CC7, "Hanii in the Sky", "Face", "FA64-0001", "03-01-1989", JAP},
{0x9897FA86, "Hanii on the Road", "Face", "FA02-006", "09-07-1990", JAP},
{0x44E7DF53, "Hatris", "Bullet Proof", "MC91002", "05-24-1991", JAP},
{0xEB923DE5, "Heavy Unit", "Taito", "TP01004", "12-22-1989", JAP},
{0x5565A973, "Hisou Kihei - Xserd", __PUBLISHER, __ID, __DATE, JAP},
{0x7ACB60C8, "Hit the Ice - VHL", "Taito", "TP03019", "09-20-1991", JAP},
{0x8B29C3AA, "Hit the Ice - VHL", "Taito", __ID, __DATE, USA},
{0xB01EE703, "Honoo no Toukyuuji - Dodge Danpei", __PUBLISHER, __ID, __DATE, JAP},
{0x9EC6FC6C, "Idol Hanafuda Fan Club", "GAMES EXPRESS", __ID, __DATE, JAP},
{0xA80C565F, "Image Fight", "IREM", "IC02003", "07-27-1990", JAP},
{0xE2470F5F, "Impossamole", "NEC", "TGX040062", __DATE, USA},
{0x0AD97B04, "J. League Greatest Eleven", __PUBLISHER, __ID, __DATE, JAP},
{0xE01C5127, "J.J. & Jeff", __PUBLISHER, "TGX020014", __DATE, USA},
{0xEA751E82, "Jack Nicklaus' Major Championship Golf", __PUBLISHER, __ID, __DATE, JAP},
{0x83384572, "Jack Nicklaus' Turbo Golf", __PUBLISHER, __ID, __DATE, USA},
{0xC6FA6373, "Jackie Chan", "Hudson", __ID, __DATE, JAP},
{0x9D2F6193, "Jackie Chan's Action Kung Fu", __PUBLISHER, "TGX040079", __DATE, USA},
{0xCC7D3EEB, "Jigoku Meguri", "Taito", "TP02013", "08-03-1990", JAP},
{0x84240EF9, "Jinmu Denshou", __PUBLISHER, __ID, __DATE, JAP},
{0xC150637A, "Jinmu Denshou", __PUBLISHER, __ID, __DATE, JAP},
{0xC8C7D63E, "Juuouki", __PUBLISHER, __ID, __DATE, JAP},
{0x6A628982, "Juuouki", __PUBLISHER, __ID, __DATE, JAP},
{0xA9084D6E, "Kaizou Choujin Shubibinman", __PUBLISHER, __ID, __DATE, JAP},
{0x109BA474, "Kaizou Choujin Shubibinman 2", __PUBLISHER, __ID, __DATE, JAP},
{0x6069C5E7, "Kato-chan & Ken-chan", "Hudson", "HC62006", "11-30-1987", JAP},
{0x4F2844B0, "Kattobi! Takuhai-kun", "TONKIN HOUSE", "TON90004", "11-09-1990", JAP},
{0x474D7A72, "Keith Courage in Alpha Zones", "SUNRISE", "TGX020001", __DATE, USA},
{0x7E3C367B, "KickBall", "NCS", __ID, "'90", JAP},
{0xC0CB5ADD, "Kikikai-kai", __PUBLISHER, __ID, __DATE, JAP},
{0x2F2E2240, "King of Casino", "VICTOR", "JC63006", "03-30-1990", USA},
{0xBF52788E, "King of Casino", __PUBLISHER, __ID, __DATE, JAP},
{0x0F1B59B4, "Klax", "TENGEN", "TTGX20001", "08-10-1990", USA},
{0xC74FFBC9, "Klax", __PUBLISHER, __ID, __DATE, JAP},
{0xC614116C, "Knight Rider Special", "PACK-IN-VIDEO", "PV1003", "12-22-1989", JAP},
{0x44F60137, "Kore ga Pro Yakyuu '89", __PUBLISHER, __ID, __DATE, JAP},
{0x1772B229, "Kore ga Pro Yakyuu '90", __PUBLISHER, __ID, __DATE, JAP},
{0xB552C906, "Kung Fu, The", __PUBLISHER, __ID, __DATE, JAP},
{0x02DDE03E, "Kyuukyoku Mahjong", __PUBLISHER, __ID, __DATE, JAP},
{0xE5B6B3E5, "Kyuukyoku Mahjong II", __PUBLISHER, __ID, __DATE, JAP},
{0x09509315, "Kyuukyoku Tiger", __PUBLISHER, __ID, __DATE, JAP},
{0xC6F764EC, "Lady Sword", "GAMES EXPRESS", "T4955754200922", __DATE, JAP},
{0xEB833D15, "Lady Sword", "GAMES EXPRESS", "T4955754200922", __DATE, JAP},
{0x3C131486, "Legend of Hero Tonma", __PUBLISHER, __ID, "03-13-1991", USA},
{0xC28B0D8A, "Legend of Hero Tonma", __PUBLISHER, __ID, __DATE, JAP},
{0x220EBF91, "Legendary Axe II, The", __PUBLISHER, __ID, __DATE, USA},
{0x2D211007, "Legendary Axe, The", __PUBLISHER, __ID, __DATE, USA},
{0xE6EE1468, "Lode Runner - Lost Labyrinth", __PUBLISHER, __ID, __DATE, JAP},
{0xA15A1F37, "Maerchen Maze", __PUBLISHER, __ID, __DATE, JAP},
{0x95CD2979, "Magical Chase", "PALSOFT", "PL91001", "11-15-1991", USA},
{0xDD0EBF8C, "Magical Chase", __PUBLISHER, __ID, __DATE, JAP},
{0xF5B90D55, "Mahjong Gakuen", __PUBLISHER, __ID, __DATE, JAP},
{0xF4148600, "Mahjong Gakuen Mild", "FACE", "FA02-004", "06-29-1990", JAP},
{0x3E4D432A, "Mahjong Gakuen Mild", __PUBLISHER, __ID, __DATE, JAP},
{0xF8861456, "Mahjong Gokuu Special", __PUBLISHER, __ID, __DATE, JAP},
{0xDF10C895, "Mahjong Haouden", __PUBLISHER, __ID, __DATE, JAP},
{0x6C34AAEA, "Mahjong Shikaku Retsuden - Mahjong Wars", __PUBLISHER, __ID, __DATE, JAP},
{0x5C78FEE1, "Maison Ikkoku", "FUJI TV", "MC66680", "08-04-1989", JAP},
{0xBE62EEF5, "Makai Hakkenden Shada", "DATA EAST", "DE89002", "04-01-1989", JAP},
{0xB101B333, "Makai Prince Dorabocchan", __PUBLISHER, __ID, __DATE, JAP},
{0xD4C5AF46, "Makyou Densetsu", __PUBLISHER, __ID, __DATE, JAP},
{0x99F2865C, "Maniac Puroresu - Asu e no Tatakai", __PUBLISHER, __ID, __DATE, JAP},
{0x2F8935AA, "Mashin Eiyuu Den Wataru", __PUBLISHER, __ID, __DATE, JAP},
{0xE87190F1, "Mesopotamia", "ATLUS", "AT03001", "10-04-1991", JAP},
{0x25A02BEE, "Metal Stoker", "FACE", "FA03-009", "07-12-1991", JAP},
{0x93F316F7, "Military Madness", "Hudson", "TGX030015", __DATE, USA},
{0xB2EF558D, "Mizubaku Adventure", __PUBLISHER, __ID, __DATE, JAP},
{0xF860455C, "Momotarou Densetsu Gaiden - Dai-1-shuu", __PUBLISHER, __ID, __DATE, JAP},
{0xD9E1549A, "Momotarou Densetsu II", __PUBLISHER, __ID, __DATE, JAP},
{0x625221A6, "Momotarou Densetsu Turbo", __PUBLISHER, __ID, __DATE, JAP},
{0x345F43E9, "Momotarou Katsugeki", __PUBLISHER, __ID, __DATE, JAP},
{0xF2E46D25, "Monster Puroresu", __PUBLISHER, __ID, __DATE, JAP},
{0x2546EFE0, "Morita Shougi PC", __PUBLISHER, __ID, __DATE, JAP},
{0x428F36CD, "Moto Roader", "Masynya", "NCS89002", "02-23-1989", JAP},
{0xE2B0D544, "Moto Roader", __PUBLISHER, __ID, __DATE, USA},
{0x4BA525BA, "Moto Roader II", "Masynya", "NCS91002", "03-29-1991", JAP},
{0x0B7F6E5F, "Moto Roader II", __PUBLISHER, __ID, __DATE, JAP},
{0x2CB92290, "Mr. Heli no Daibouken", __PUBLISHER, __ID, __DATE, JAP},
{0xAC0CD796, "Mr. Heli no Daibouken", __PUBLISHER, __ID, __DATE, JAP},
{0xB01F70C2, "Narazumono Sentai Butai - Bloody Wolf", __PUBLISHER, __ID, __DATE, JAP},
{0x60ECAE22, "Naxat Open", "Naxat", "NX89001", "05-30-1989", JAP},
{0x20A7D128, "Naxat Stadium", "Naxat", "NX90006", "10-26-1990", JAP},
{0x0441D85A, "Nazo no Mascarade", __PUBLISHER, __ID, __DATE, JAP},
{0x53109AE6, "Necromancer", __PUBLISHER, __ID, __DATE, JAP},
{0xFB0FDCFE, "Necros no Yousai", "ASK KODANSHA", "AK90001", "04-20-1990", JAP},
{0x0243453B, "Nectaris", "Hudson", "HC63016", "02-09-1989", JAP},
{0x65FDB863, "Nekketsu Koukou Dodgeball-bu - PC Bangai Hen", __PUBLISHER, __ID, __DATE, JAP},
{0xF2285C6D, "Nekketsu Koukou Dodgeball-bu - Soccer PC Hen", __PUBLISHER, __ID, __DATE, JAP},
{0xA9A94E1B, "Neutopia", "Hudson", "HC89022", "11-17-1989", USA},
{0x9C49EF11, "Neutopia", "Hudson", "TGX030029", __DATE, JAP},
{0x2B94AEDC, "Neutopia II", "Hudson", "HC91047", "09-27-1991", JAP},
{0xC4ED4307, "Neutopia II", "Hudson", "TGX060078", __DATE, USA},
{0x756A1802, "New Adventure Island", "Hudson", "TGX040080", __DATE, USA},
{0x8E4D75A8, "New Zealand Story, The", "Taito", "TP02007", "02-23-1990", JAP},
{0x20A7D128, "Nexat Stadium", "Nexat", __ID, __DATE, JAP},
{0xFBA3A1A4, "Nexat Stadium", "Tai Sang", __ID, __DATE, JAP},
{0xA32430D5, "NHK Taiga Drama - Taiheiki", __PUBLISHER, __ID, __DATE, JAP},
{0xC159761B, "Night Creatures", "MANLEY __PUBLISHER ASSOCIATES", "TGX040069", __DATE, USA},
{0x82DEF9EE, "Niko Niko Pun", "KSS", "NV91001", "12-13-1991", JAP},
{0x67573BAC, "Ninja Ryuuken Den", __PUBLISHER, __ID, __DATE, JAP},
{0xDE8AF1C1, "Ninja Spirit", "IREM", "TGX040050", "07-06-1990", USA},
{0x96E0CD9D, "Ninja Warriors, The", __PUBLISHER, __ID, "06-30-1989", JAP},
{0x4D3B0BC9, "Obocchama-kun", __PUBLISHER, __ID, __DATE, JAP},
{0xFF898F87, "Operation Wolf", "NEC", "NAPH-1010", "08-31-1990", JAP},
{0xFAE0FC60, "Order of the Griffon", "SSL", "TGX040072", __DATE, USA},
{0xE7BF2A74, "Ordyne", "Namco", "NC89004", "09-08-1989", USA},
{0x8C565CB6, "Ordyne", "Namco", __ID, __DATE, JAP},
{0x5CDB3F5B, "Out Live", __PUBLISHER, __ID, __DATE, JAP},
{0xE203F223, "Out Run", "SEGA", "NAPH-1016", "12-21-1990", JAP},
{0xB74EC562, "Override", "DEKA", "DE90006", "01-08-1991", JAP},
{0x7632DB90, "P-47 - The Freedom Fighter", __PUBLISHER, __ID, "03-20-1989", JAP},
{0x14FAD3BA, "Pac-Land", "Namco", __ID, __DATE, JAP},
{0xD6E30CCD, "Pac-Land", "Namco", __ID, __DATE, USA},
{0x4148FD7C, "Pachio-kun - Juuban Shoubu", __PUBLISHER, __ID, __DATE, JAP},
{0xA980E0E9, "Panza Kick Boxing", __PUBLISHER, __ID, __DATE, USA},
{0xBB4429B6, "Paranoia", "Naxat", "NX90001", "03-01-1990", JAP},
{0x9893E0E6, "Paranoia", "Naxat", "NX90001", "03-01-1990", JAP},
{0x51E86451, "Parasol Stars - The Story of Bubble Bobble 3", "Taito", __ID, __DATE, JAP},
{0xE6458212, "Parasol Stars - The Story of Bubble Bobble III", __PUBLISHER, __ID, __DATE, USA},
{0x647718F9, "Parodius Da! - Shinwa kara Owarai e", "KONAMI", "KM92003", "02-21-1992", JAP},
{0x740491C2, "PC Denjin - Punkic Cyborgs", "Hudson", "HC92053", "11-20-1992", JAP},
{0x8FB4F228, "PC Denjin - Punkic Cyborgs", "Hudson", __ID, __DATE, JAP},
{0x2CB5CD55, "PC Genjin - Pithecanthropus Computerurus", "Hudson", "HC89024", "12-15-1989", JAP},
{0x67B35E6E, "PC Genjin - Pithecanthropus Computerurus", "Hudson", "HC89024", "12-15-1989", JAP},
{0x3028F7CA, "PC Genjin 2 - Pithecanthropus Computerurus", "Hudson", "HC91043", "07-19-1991", JAP},
{0x6F6ED301, "PC Genjin 3 - Pithecanthropus Computerurus (Demo)", "Hudson", "HC93063", "04-02-1993", JAP},
{0xA170B60E, "PC Genjin 3 - Pithecanthropus Computerurus", "Hudson", "HC93063", __DATE, JAP},
{0x0AA88F33, "PC Pachi-Slot Idol Gambler", __PUBLISHER, __ID, __DATE, JAP},
{0x083C956A, "Populous", "Hudson", "HC91041", "04-05-1991", JAP | POPULOUS},
{0x0A9ADE99, "Populous", "Hudson", "HC91041", "04-05-1991", JAP | POPULOUS},
{0x99E6D988, "Power Drift", "Asmik", "AS02002", "04-13-1990", JAP},
{0x25E0F6E9, "Power Drift", "Asmik", "AS02002", "04-13-1990", JAP},
{0x3E647D8B, "Power Eleven", "Hudson", "HC91039", "06-21-1991", JAP},
{0xBE8B6E3B, "Power Gate", "PACK-IN-VIDEO", "PV-1008", __DATE, JAP},
{0xEA324F07, "Power Golf", "Hudson", "HC89018", "05-25-1989", JAP},
{0xED1D3843, "Power Golf", "Hudson", __ID, __DATE, USA},
{0x69180984, "Power League", "Hudson", __ID, __DATE, JAP},
{0x04A85769, "Power League  (All Star Version)", __PUBLISHER, __ID, __DATE, JAP},
{0x7D3E6F33, "Power League '93", "Hudson", __ID, __DATE, JAP},
{0xC5FDFA89, "Power League II", "Hudson", "HC89020", "08-08-1989", JAP},
{0x8AA4B220, "Power League III", "Hudson", "HC90037", "08-10-1990", JAP},
{0x30CC3563, "Power League IV", "Hudson", "HC91046", "08-09-1991", JAP},
{0x8B61E029, "Power League V", "Hudson", "HC92057", "08-07-1992", JAP},
{0x29EEC024, "Power Sports", "Hudson", "HC92058", "10-10-1992", JAP},
{0x8DEF5AA1, "Power Tennis", "Hudson", "HC93062", "06-25-1993", JAP},
{0x11A36745, "Pro Tennis World Court", __PUBLISHER, __ID, __DATE, JAP},
{0x34E089A9, "Pro Yakyuu World Stadium", "Namco", "NC63001", "05-20-1988", JAP},
{0x66B167A9, "Pro Yakyuu World Stadium '91", __PUBLISHER, __ID, __DATE, JAP},
{0x03883EE8, "Psycho Chaser", "Naxat", "NX90003", "04-06-1990", JAP},
{0x6CC10824, "Psychosis", "Naxat", __ID, __DATE, USA},
{0xFAA6E187, "Puzzle Boy", "TELENET", __ID, __DATE, JAP},
{0x965C95B3, "Puzznic", "Taito", "TP02011", "06-29-1990", JAP},
{0xF2E6856D, "Quiz Toukou Shashin", __PUBLISHER, __ID, __DATE, JAP},
{0x91CE5156, "R-Type", "Hudson", __ID, __DATE, USA | US_ENCODED},
{0x45FC8CB9, "R-Type", "Tai Sang", __ID, __DATE, JAP},
{0xCEC3D28A, "R-Type Part-1", "Hudson", __ID, __DATE, JAP},
{0xF207ECAE, "R-Type Part-2", "Hudson", __ID, __DATE, JAP},
{0xCE4FBEFE, "R-Type Part-2", "Tai Sang", __ID, __DATE, JAP},
{0xD8373DE6, "Rabio Lepus Special", __PUBLISHER, __ID, __DATE, JAP},
{0x3E79734C, "Racing Damashii", __PUBLISHER, __ID, __DATE, JAP},
{0x850829F2, "Raiden", "SEIBU KAIHATSU", "HC91049", "11-22-1991", JAP},
{0xBC59C31E, "Raiden", __PUBLISHER, __ID, __DATE, USA},
{0x00C38E69, "Rastan Saga II", "Taito", "TP02012", "07-06-1990", JAP},
{0x2FD65312, "Rock-On", __PUBLISHER, __ID, __DATE, JAP},
{0x91E6896F, "Ryuukyuu", __PUBLISHER, __ID, __DATE, JAP},
{0xF999356F, "Sadakichi 7 Series - Hideyoshi no Ougon", __PUBLISHER, __ID, __DATE, JAP},
{0x0590A156, "Saigo no Nindou - Ninja Spirit", __PUBLISHER, __ID, __DATE, JAP},
{0xFAECCE20, "Salamander", "KONAMI", "KM91002", "12-06-1991", JAP},
{0x77A924B7, "Samurai-Ghost", "Namco", "TGX040085", __DATE, USA},
{0x2E955051, "Sekigahara", __PUBLISHER, __ID, __DATE, JAP},
{0x90E6BF49, "Sengoku Mahjong", "Hudson", "HC63010", "07-08-1988", JAP},
{0x6923D736, "Shanghai", "Hudson", "HC62004", "10-30-1987", JAP},
{0xBC655CF3, "Shinobi", "ASMIK", "AS01001", "12-08-1989", JAP},
{0x469A0FDF, "Shiryou Sensen", "FUN PROJECT", "JC63002", "03-24-1989", JAP},
{0x2774462C, "Shockman", "NCS", "TGX040087", __DATE, USA},
{0x23EC8970, "Shougi Shodan Icchokusen", __PUBLISHER, __ID, __DATE, JAP},
{0x457F2BC4, "Shougi Shoshinsha Muyou", __PUBLISHER, __ID, __DATE, JAP},
{0xE5E7B8B7, "SideArms - Hyper Dyne", "CAPCOM", __ID, __DATE, JAP},
{0xD1993C9F, "SideArms - Hyper Dyne", "CAPCOM", __ID, __DATE, USA},
{0xFA7E5D66, "Silent Debuggers", "DATA EAST", "DE90004", "03-29-1991", USA},
{0x616EA179, "Silent Debuggers", __PUBLISHER, __ID, __DATE, JAP},
{0xB5C4EEBD, "Sindibad - Chitei no Daimakyuu", __PUBLISHER, __ID, __DATE, JAP},
{0x4F6E2DBD, "Sinistron", "IGS", "ITGX10007", __DATE, USA},
{0x4D539C9F, "Skweek", "VICTOR", "JC63011", "08-02-1991", JAP},
{0x4BB68B13, "Soldier Blade", "Hudson", "HC92056", "07-10-1992", USA},
{0x8420B12B, "Soldier Blade", __PUBLISHER, __ID, __DATE, JAP},
{0xF39F38ED, "Soldier Blade Special - Caravan Stage", __PUBLISHER, __ID, __DATE, JAP},
{0x8FCAF2E9, "Somer Assault", "ATLUS", "TGX040089", __DATE, USA},
{0xD7921DF2, "Son Son II", "NEC", "H54G-1003", "01-27-1989", JAP},
{0xF74E5EB3, "Sonic Spike - World Championship Beach Volleyball", "IGS", "ITGX10001", __DATE, USA},
{0xFB37DDC4, "Soukoban World", __PUBLISHER, __ID, __DATE, JAP},
{0x43B05EB8, "Space Harrier", "NEC", "H67G-1002", "12-09-1988", USA},
{0x64580427, "Space Harrier", __PUBLISHER, __ID, __DATE, JAP},
{0x99496DB3, "Space Invaders - Fukkatsu no Hi", __PUBLISHER, __ID, __DATE, JAP},
{0x09A0BFCC, "Special Criminal Investigation", __PUBLISHER, __ID, __DATE, JAP},
{0x1C6FF459, "Spin Pair", "MEDIA RINGS", "MR90002", "12-14-1990", JAP},
{0xA5290DD0, "Spiral Wave", "MEDIA RINGS", "MR91004", "12-13-1991", JAP},
{0xD00CA74F, "Splatterhouse", "Namco", "TGX040041", __DATE, USA},
{0x6B319457, "Splatterhouse", "Namco", "NC90002", "04-03-1990", JAP},
{0x727F4656, "Stratego", "ACCOLADE", "JC63012", "07-24-1992", JAP},
{0xD15CB6BB, "Street Fighter II' - Champion Edition", "Capcom", "HE93002", "06/12/93", JAP},
{0xD6FC51CE, "Strip Fighter II", "GAMES EXPRESS", "T4955754200984", __DATE, JAP},
{0x56488B36, "Super Metal Crusher", "PACK-IN-VIDEO", "PV-1007", "11-29-1991", JAP},
{0x3EB5304A, "Super Momotarou Dentetsu", __PUBLISHER, __ID, __DATE, JAP},
{0x2BC023FC, "Super Momotarou Dentetsu II", __PUBLISHER, __ID, __DATE, JAP},
{0xDB29486F, "Super Star Soldier", "Hudson", "HE-1097", "07-06-1990", USA},
{0x5D0E3105, "Super Star Soldier", __PUBLISHER, __ID, __DATE, JAP},
{0xCE2E4F9F, "Super Volleyball", __PUBLISHER, __ID, __DATE, JAP},
{0x245040B3, "Super Volleyball", __PUBLISHER, __ID, __DATE, USA},
{0xCF73D8FC, "Susanoo Densetsu", __PUBLISHER, __ID, __DATE, JAP},
{0x6F4FD790, "Taito Chase H.Q.", __PUBLISHER, __ID, __DATE, JAP},
{0x9298254C, "Taito Chase H.Q.", __PUBLISHER, __ID, __DATE, USA},
{0xE415EA19, "Takahashi Meijin no Shin Bouken-jima", __PUBLISHER, __ID, __DATE, JAP},
{0xF022BE13, "Takeda Shingen", "AICOM", "AC89002", "07-28-1989", JAP},
{0xDF7AF71C, "Takeda Shingen", __PUBLISHER, __ID, __DATE, JAP},
{0xE9D51797, "Takin' It to the Hoop", __PUBLISHER, __ID, __DATE, USA},
{0xBAE9CECC, "TaleSpin", "NEC", "TGX040056", __DATE, USA},
{0xC1B26659, "Tatsujin  (Proto)", "Taito", "...", __DATE, JAP},
{0xA6088275, "Tatsujin", __PUBLISHER, __ID, __DATE, JAP},
{0xEEB6DD43, "Tatsunoko Fighter", __PUBLISHER, __ID, __DATE, JAP},
{0x3B3808BD, "Ten no Koe Bank", __PUBLISHER, __ID, __DATE, JAP},
{0x2E278CCB, "Tenseiryuu - Saint Dragon", __PUBLISHER, __ID, __DATE, JAP},
{0x1B2D0077, "Terra Cresta II - Mandoraa no Gyakushuu", "NIHON BUSSAN", "NB96002", "11-27-1992", JAP},
{0xDDC3E809, "Thunder Blade", "SEGA", "NAPH-1015", "12-07-1990", JAP},
{0x985D492D, "Tiger Road", "CAPCOM", __ID, __DATE, USA},
{0x02C39660, "Time Cruise", "FACE", "TGX040090", __DATE, USA},
{0xCFEC1D6A, "Time Cruise II", __PUBLISHER, __ID, __DATE, JAP},
{0x5D395019, "Timeball", "Hudson", __ID, __DATE, USA},
{0xD20F382F, "Titan", "TITUS", "NX91001", "03-15-1991", JAP},
{0x53B7784B, "Toilet Kids", "MEDIA RINGS", "MR92005", "03-06-1992", JAP},
{0x82AE3B16, "Tora e no Michi", "CAPCOM", "JC63004", "02-23-1990", JAP},
{0xB18D102D, "Toshi Tensou Keikaku - Eternal City", __PUBLISHER, __ID, __DATE, JAP},
{0x97C5EE9A, "Toy Shop Boys", "VICTOR", "JC63009", "12-14-1990", JAP},
{0x3AEA2F8F, "Tricky", "IGS", "AI-03004", "07-06-1991", JAP},
{0x48E6FD34, "Tricky Kick", "IGS", __ID, __DATE, USA},
{0x61A6E210, "Tsuppari Oozumou - Heisei Ban", __PUBLISHER, __ID, __DATE, JAP},
{0xF70112E5, "Tsuru Teruhito no Jissen Kabushiki Bai Bai Game", __PUBLISHER, __ID, __DATE, JAP},
{0x34DC65C4, "Tsushin Tool (Prototype)", "NEC", __ID, "00-00-1990", JAP},
{0xB77F559E, "Tsushin Tool (Prototype, Emu patched)", "NEC", __ID, "00-00-1990", JAP},
{0xEB045EDF, "Turrican", "ACCOLADE", "ATGX04TUTG", __DATE, USA},
{0x10B60601, "TV Sports Basketball", "CINEMAWARE", __ID, "04-29-1993", JAP},
{0xEA54D653, "TV Sports Basketball", __PUBLISHER, __ID, __DATE, USA},
{0x968D908A, "TV Sports Football", "VICTOR", "JC63008", "03-29-1991", JAP},
{0x5E25B557, "TV Sports Football", __PUBLISHER, __ID, __DATE, USA},
{0x97FE5BCF, "TV Sports Hockey", "NEC", "TGX030064", __DATE, USA},
{0xE7529890, "TV Sports Hockey", __PUBLISHER, __ID, __DATE, JAP},
{0x1CAD4B7F, "USA Pro Basketball", "AICOM", "AC89003", "12-01-1989", USA},
{0xA3303978, "Valkyrie no Densetsu", "Namco", "NC90006", "09-09-1990", JAP},
{0x04188C5C, "Veigues - Tactical Gladiator", __PUBLISHER, __ID, __DATE, JAP},
{0x99D14FB7, "Veigues - Tactical Gladiator", __PUBLISHER, __ID, __DATE, USA},
{0x85CBD045, "Victory Run", "Hudson", "HC62003", "12-28-1987", USA},
{0x03E28CFF, "Victory Run", __PUBLISHER, __ID, __DATE, JAP},
{0xE4124FE0, "Vigilante", "IREM", "IC63001", "01-14-1989", JAP},
{0x79D49A0D, "Vigilante", __PUBLISHER, __ID, __DATE, USA},
{0x1BC36B36, "Violent Soldier", "IGS", "AI02005", "12-14-1990", JAP},
{0xAD226F30, "Volfied", "Taito", "TP01005", "12-27-1989", JAP},
{0xBE990010, "W-Ring - The Double Rings", __PUBLISHER, __ID, __DATE, JAP},
{0xA2A0776E, "Wai Wai Mahjong - Yukai na Janyuu-tachi", "VIDEO SYSTEM", "VS-89001", "06-19-1989", JAP},
{0x0112D0C7, "Wallaby!! - Usagi no Kuni no Kangaroo Race", "Masynya", "NCS90005", "12-14-1990", JAP},
{0x9B5EBC58, "Winning Shot", "DATA EAST", "DE64001", "03-03-1989", JAP},
{0x59D07314, "Wonder Momo", "Namco", "NC64001", "04-21-1989", JAP},
{0xBE850530, "World Beach Volley", "IGS", __ID, "07-27-1990", JAP},
{0xB3EEEA2E, "World Circuit", "Namco", "NC91004", "10-18-1991", JAP},
{0x4186D0C0, "World Class Baseball", "Hudson", __ID, __DATE, USA},
{0xA4457DF0, "World Court Tennis", "Namco", "TGX020019", "08-11-1988", USA},
{0xA9AB2954, "World Jockey", "Namco", __ID, __DATE, JAP},
{0x4B93F0AC, "World Sports Competition", __PUBLISHER, __ID, __DATE, USA},
{0xF8F85EEC, "Xevious - Fardraut Densetsu", "Namco", "NC90004", "06-29-1990", JAP},
{0x3CA7DB48, "Yo, Bro", __PUBLISHER, __ID, __DATE, USA},
{0xF131B706, "Youkai Douchuuki", __PUBLISHER, __ID, __DATE, JAP},
{0xC0905CA9, "Yuu Yuu Jinsei - Victory Life", "TAKARA", "HC63008", "04-22-1988", JAP},
{0xEE156721, "Zero 4 Champ", "Media Rings", "MR91003", "03-08-1991", JAP},
{0xB77F2E2F, "Zero 4 Champ  (v1.5)", "Media Rings", __ID, __DATE, JAP},
{0x67AAB7A1, "Zipang", "PACK-IN-VIDEO", "PV-1005", "12-14-1990", JAP},
};


unsigned long
filesize(FILE * fp)
{
	int prev = ftell(fp);
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, prev, SEEK_SET);
	return size;
}

#if 0
unsigned long pack_filesize(PACKFILE *F)
  {
   unsigned long old_pos,end;
   pack_ftell(F,(long*)&old_pos);

   end=old_pos;

   while (!pack_feof(F))
     {
      pack_getc(F);
      end++;
      }


   fseek(F,0,SEEK_END);
   fgetpos(F,(long*)&end);
   fseek(F,old_pos,SEEK_SET);
   return end;
   }
#endif

uint32
CRC_file(char *name)
{
	FILE *F = fopen(name, "rb");
	uchar *tmp_data;
	uint32 taille, index, CRC = -1, true_size;

	if (!F)
		return -1;

	taille = filesize(F);
	true_size = taille & 0xFFFFF000;
	if (taille & 0x0FFF) {
		//fprintf(stderr,"HEADER OF 0X%X BYTES\n",taille & 0x0FFF);
		fseek(F, taille & 0x0FFF, SEEK_SET);
	}
	if (!(tmp_data = (uchar *) (malloc(true_size))))
		exit(-1);
	fread(tmp_data, true_size, 1, F);
	for (index = 0; index < true_size; index++) {
		tmp_data[index] ^= CRC;
		CRC >>= 8;
		CRC ^= TAB_CONST[tmp_data[index]];
	}
	free(tmp_data);
	CRC = ~CRC;
//      fprintf(stderr,"CRC = 0X%lX\n",CRC);
	fclose(F);
	return CRC;
}
