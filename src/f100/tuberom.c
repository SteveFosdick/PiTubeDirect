#include "tuberom.h"
uint16_t tuberom_f100[0x800] = {
0x8000,0x7C01,0x4800,0x0000,0x8000,0x7800,0x4800,0x0001,0x8000,0xFFCB,0x4002,0x8000,0x0BD0,0x4003,0x8000,0x061F,
0x4004,0x8903,0x4904,0x7002,0x0811,0x8000,0x0BA9,0x2800,0x096C,0x8000,0x0000,0x2800,0x7FEE,0x2800,0x0B74,0x8000,
0x002A,0x2800,0x7FEE,0x8000,0x0000,0x4003,0x8000,0x0A57,0x4004,0x2800,0x7FF1,0x0194,0x0834,0x8000,0x0660,0x4003,
0x2800,0x7FF7,0xF800,0x081F,0x8000,0x007E,0x4003,0x2800,0x7FF4,0x2800,0x097B,0x8000,0x0BCA,0x2800,0x096C,0x2800,
0x097B,0xF800,0x081F,0x047B,0x3000,0x3000,0x8000,0x7C01,0x4800,0x0000,0x2800,0x097B,0x8000,0x07FA,0x4002,0x8802,
0x9000,0x0001,0x2800,0x096C,0x2800,0x097B,0xF800,0x081F,0x3000,0x3000,0x3000,0x8003,0xC000,0x0080,0x0181,0x0874,
0x8003,0x4901,0x8000,0x0004,0x2800,0x0B7D,0x8004,0x2800,0x0B7D,0x8B01,0x4003,0x8901,0x2800,0x0B7D,0x2800,0x0B74,
0x4004,0x8B01,0x4003,0x3000,0x8000,0x0000,0x4002,0x8003,0xB000,0x0082,0x0191,0x08AC,0xB000,0x0083,0x0191,0x08A8,
0xB000,0x0084,0x0191,0x08A4,0x8000,0x0006,0x2800,0x0B7D,0x8004,0x2800,0x0B7D,0x8005,0x2800,0x0B7D,0x8003,0x2800,
0x0B7D,0x8003,0xB000,0x009D,0x0191,0x08A1,0x2800,0x0B74,0x4901,0x2800,0x0B74,0x4005,0x2800,0x0B74,0x4004,0x8B01,
0x4002,0x8B01,0x4003,0x3000,0x8000,0x77FF,0x4003,0x3000,0x8000,0x1000,0x4003,0x3000,0x8000,0x0000,0x4003,0x3000,
0x8004,0x4901,0x8003,0x4901,0x2800,0x0914,0x8002,0x0191,0x08CD,0x8000,0x0002,0x2800,0x0B7D,0x8B01,0x2800,0x0B88,
0x2800,0x0B74,0xC000,0x0080,0x0191,0x08CD,0x8B01,0x4003,0x4901,0x2800,0x08D6,0x2800,0x08D2,0x8B01,0x4003,0x8B01,
0x4004,0x3000,0x8800,0x07EC,0x4002,0xF802,0x8000,0x0001,0x6003,0x8000,0x0001,0x5003,0x2800,0x0963,0x4004,0xB000,
0x002A,0x0191,0x08D9,0xB000,0x002F,0x0191,0x0909,0x8000,0x090F,0x4004,0x8000,0x0001,0xA003,0x4005,0x8000,0x0001,
0x5004,0x8804,0x4006,0x0191,0x0907,0x8000,0x0001,0x5005,0x8805,0x4007,0xB000,0x002E,0x0191,0x0907,0x8000,0x00DF,
0xC007,0x4007,0xB006,0x0181,0x090C,0xF800,0x08EE,0x8005,0x4003,0x8000,0x0001,0x5003,0x2800,0x0963,0x4004,0x3000,
0x0052,0x0055,0x004E,0x0000,0x8000,0x00FF,0x4002,0x3000,0x3000,0x3000,0x3000,0x8003,0x0191,0x0A13,0x4901,0x8004,
0x4901,0x8005,0x4901,0x8006,0x4901,0x8003,0x4005,0x8004,0x4006,0x8000,0x0008,0x2800,0x0B7D,0x8005,0x2800,0x0B7D,
0x8005,0xB000,0x0015,0x0184,0x0938,0x8000,0x0000,0x4005,0x8005,0x9000,0x09E9,0x4002,0x8802,0x2800,0x0B7D,0x8005,
0x9000,0x09E9,0x4002,0x8802,0x4003,0x8006,0x4004,0x2800,0x0984,0x8005,0x9000,0x09FE,0x4002,0x8802,0x2800,0x0B7D,
0x8005,0x9000,0x09FE,0x4002,0x8802,0x4003,0x8006,0x4004,0x2800,0x09B6,0x8B01,0x4006,0x8B01,0x4005,0x8B01,0x4004,
0x8B01,0x4003,0x3000,0x8000,0x0001,0x6003,0x8903,0xB000,0x0020,0x0191,0x0966,0x3000,0x4002,0x8000,0x0001,0xA002,
0x4003,0x8903,0xC000,0x00FF,0x0191,0x097A,0x2800,0x7FEE,0xF800,0x0971,0x3000,0x8000,0x000A,0x2800,0x7FEE,0x8000,
0x000D,0x2800,0x7FEE,0x3000,0x8005,0x4901,0x8006,0x4901,0x8000,0xFFFF,0x9003,0x4006,0x0193,0x09B1,0x8006,0x0021,
0x9004,0x4004,0x8804,0x4005,0x8006,0xC000,0x0001,0x4003,0x0194,0x09A3,0x8005,0x0078,0x2800,0x0B7D,0x8000,0x0001,
0x6006,0x0193,0x09B1,0x2800,0x0B7D,0x8000,0x0001,0x6006,0x0193,0x09B1,0x8000,0x0001,0x6004,0x8804,0x4005,0xF800,
0x099A,0x8B01,0x4006,0x8B01,0x4005,0x3000,0x8005,0x4901,0x8006,0x4901,0x8000,0x0001,0x6006,0x0193,0x09E4,0x8006,
0x0021,0x5004,0x8000,0x0000,0x4005,0x8000,0x0001,0xC006,0x0191,0x09D3,0x2800,0x0B74,0x0078,0xC000,0xFF00,0x5005,
0x8000,0x0001,0x6006,0x0193,0x09DA,0x2800,0x0B74,0xC000,0x00FF,0x5005,0x8005,0x4B04,0x8000,0x0000,0x4005,0x8000,
0x0001,0x6006,0x0183,0x09CA,0x8B01,0x4006,0x8B01,0x4005,0x3000,0x0010,0x0000,0x0005,0x0000,0x0005,0x0004,0x0005,
0x0008,0x000E,0x0004,0x0001,0x0001,0x0005,0x0000,0x0008,0x0019,0x0010,0x000D,0x0000,0x0008,0x0080,0x0010,0x0005,
0x0000,0x0005,0x0000,0x0005,0x0000,0x0000,0x0000,0x0005,0x0009,0x0005,0x0000,0x0008,0x0019,0x0001,0x000D,0x000D,
0x0080,0x0008,0x0080,0x8004,0x4901,0x8000,0x000A,0x2800,0x0B7D,0x8004,0x9000,0x0003,0x4002,0x8802,0x2800,0x0B7D,
0x8004,0x9000,0x0002,0x4002,0x8802,0x2800,0x0B7D,0x8004,0x9000,0x0001,0x4002,0x8802,0x2800,0x0B7D,0x8000,0x0007,
0x2800,0x0B7D,0x8000,0x0000,0x2800,0x0B7D,0x2800,0x0B74,0xC000,0x0080,0x0181,0x0A51,0x8000,0x0000,0x4005,0x8804,
0x4004,0x2800,0x0B74,0x4002,0x4804,0x8000,0x0001,0x5004,0x8000,0x0001,0x5005,0x8002,0xB000,0x000D,0x0181,0x0A41,
0xD002,0x8B01,0x4004,0x8000,0x0000,0x4003,0x3800,0x0660,0x018C,0x0020,0x00FF,0x9000,0x0030,0x4002,0x8800,0x7EF8,
0xC000,0x0040,0x0191,0x0A5E,0x8002,0x4800,0x7EF9,0x3000,0x8000,0x0000,0x2800,0x0B7D,0x2800,0x0B74,0x2800,0x0B74,
0x3000,0x4901,0x8003,0x4901,0xF800,0x0624,0x8800,0x7EFE,0xC000,0x0080,0x0181,0x0AAD,0x8800,0x7EF8,0xC000,0x0080,
0x0181,0x0A84,0xF800,0x0626,0x8800,0x7EF9,0x4003,0xC000,0x0080,0x0181,0x0AA4,0x8004,0x4901,0x8005,0x4901,0x2800,
0x0B65,0x4005,0x2800,0x0B65,0x4004,0x2800,0x0B65,0x4003,0x2800,0x0AA2,0x8B01,0x4005,0x8B01,0x4004,0x8B01,0x4003,
0x8B01,0x3000,0xF800,0x0640,0x8003,0x5003,0x8003,0x4800,0x07FE,0x8B01,0x4003,0x8B01,0x3000,0x8800,0x7EFF,0x4003,
0xC000,0x0080,0x0191,0x0AD1,0x8004,0x4901,0x2800,0x0B74,0x8000,0x0660,0x4004,0x2800,0x0B74,0x4804,0x8000,0x0001,
0x5004,0x2800,0x0B74,0x4003,0x4804,0x8000,0x0001,0x5004,0x8003,0x0181,0x0AC1,0x8000,0x0660,0x4800,0x07FA,0xF800,
0x0846,0x8004,0x4901,0x8005,0x4901,0x8003,0x4004,0x2800,0x0B95,0x8004,0xB000,0x0005,0x0191,0x0B04,0x2800,0x0B95,
0x2800,0x0B95,0x2800,0x0B95,0x0078,0xC000,0xFF00,0x4005,0x2800,0x0B95,0x5005,0x8800,0x7EFD,0x8800,0x7EFD,0x2800,
0x0B95,0x8004,0x9004,0x1000,0xF800,0x0B0C,0xF800,0x0B34,0xF800,0x0B63,0xF800,0x0B63,0xF800,0x0B60,0xF800,0x0B04,
0xF800,0x0B63,0xF800,0x0B63,0x8B01,0x4005,0x8B01,0x4004,0x8B01,0x4003,0x8B01,0x3000,0x8000,0x0000,0x4004,0x8800,
0x7EFE,0x4003,0xC000,0x0080,0x0181,0x0B04,0x8800,0x7EFC,0x4003,0xC000,0x0040,0x0191,0x0B0F,0x8000,0x0000,0xA004,
0x0193,0x0B30,0x8805,0x4004,0x4800,0x7EFD,0x8000,0x0001,0x5005,0x8004,0x0028,0x9000,0x8000,0x4004,0xF800,0x0B0F,
0x4800,0x7EFD,0xF800,0x0B0C,0x8000,0x0000,0x4004,0x8800,0x7EFE,0x4003,0xC000,0x0080,0x0181,0x0B04,0x8800,0x7EFC,
0x4003,0xC000,0x0080,0x0191,0x0B37,0x8000,0x0000,0xA004,0x0193,0x0B51,0x8800,0x7EFD,0x9000,0x8000,0x4004,0xF800,
0x0B37,0x8004,0xC000,0x00FF,0x4004,0x8800,0x7EFD,0x0068,0x9004,0x4004,0x4805,0x8000,0x0001,0x5005,0xF800,0x0B34,
0x8005,0x4800,0x07EC,0xF800,0x0B04,0x8800,0x7EF8,0xC000,0x0080,0x0181,0x0B71,0x8800,0x7EFE,0xC000,0x0080,0x0191,
0x0B65,0x8800,0x7EF9,0x3000,0x8800,0x7EFA,0xC000,0x0080,0x0191,0x0B74,0x8800,0x7EFB,0x3000,0x4002,0x8800,0x7EFA,
0xC000,0x0040,0x0191,0x0B7E,0x8002,0x4800,0x7EFB,0x3000,0x4002,0x8000,0x0001,0xA002,0x4003,0x8903,0x2800,0x0B7D,
0xB000,0x000D,0x0181,0x0B8D,0x3000,0x8800,0x7EFE,0xC000,0x0080,0x0191,0x0B95,0x8800,0x7EFF,0x3000,0x4002,0x8800,
0x7EFE,0xC000,0x0040,0x0191,0x0B9F,0x8002,0x4800,0x7EFF,0x3000,0x000A,0x0046,0x0065,0x0072,0x0072,0x0061,0x006E,
0x0074,0x0069,0x0020,0x0046,0x0031,0x0030,0x0030,0x002D,0x004C,0x0020,0x0028,0x0033,0x0032,0x004B,0x0020,0x0077,
0x006F,0x0072,0x0064,0x0073,0x0029,0x000A,0x000A,0x000D,0x0000,0x0011,0x0045,0x0073,0x0063,0x0061,0x0070,0x0065,
0x0000,0xF800,0x0845,0xF800,0x0846,0xF800,0x0A76,0xF800,0x0845,0xF800,0x08B0,0xF800,0x085B,0xF800,0x091B,0xF800,
0x0A5D,0xF800,0x0A68,0xF800,0x0918,0xF800,0x0858,0xF800,0x0859,0xF800,0x085A,0xF800,0x091A,0xF800,0x0919,0xF800,
0x0845,0xF800,0x0844,0xF800,0x0845,0xF800,0x0845,0xF800,0x0845,0xF800,0x0845,0xF800,0x0845,0xF800,0x0845,0xF800,
0x0845,0xF800,0x0844,0xF800,0x0844,0xF800,0x0844,0x8000,0x0FFF,0x4003,0x8000,0xFDED,0x4002,0x8000,0x0002,0x4903,
0x7002,0x0C0D,0x8000,0xFF61,0x400A,0x8000,0x0000,0x4005,0x400B,0x4004,0x8000,0x0212,0x4006,0x9000,0x1000,0x4009,
0x8000,0x0000,0x4007,0x8809,0x0043,0x9809,0x9809,0x5007,0x8006,0x0041,0x4011,0x8000,0x0001,0x6011,0x8007,0x4010,
0x2800,0x0C95,0x8010,0x4007,0x8011,0x4809,0x8000,0x0001,0x6006,0x0191,0x0C46,0x8B09,0x8007,0x4010,0x8006,0x4011,
0x2800,0x0CB6,0x8011,0x4007,0xF800,0x0C23,0x8007,0x4010,0x8000,0x000A,0x4011,0x2800,0x0C95,0x8010,0x9005,0x4008,
0x8011,0x4005,0x8008,0xB000,0x0009,0x0181,0x0C5C,0x8000,0x0001,0x6004,0x700A,0x0C1A,0x8008,0xB000,0x000A,0x0181,
0x0C73,0x8000,0x0000,0x4008,0x8000,0x0001,0x500B,0x800B,0x2800,0x0A5B,0x8004,0x0191,0x0C8D,0x8000,0x0000,0x2800,
0x0A5B,0x7004,0x0C6D,0x800A,0xB000,0xFF61,0x0191,0x0C8D,0x800B,0x2800,0x0A5B,0x800A,0xB000,0xFF62,0x0181,0x0C84,
0x8000,0x002E,0x2800,0x7FEE,0x8004,0x0191,0x0C8D,0x8000,0x0009,0x2800,0x0A5B,0x7004,0x0C87,0x8008,0x400B,0x700A,
0x0C1A,0x800B,0x2800,0x0A5B,0x3000,0x8000,0x0000,0x400F,0x400E,0x8000,0xFFF0,0x400D,0x0341,0x000F,0x0341,0x000E,
0x038F,0x0010,0x0CA5,0x03E0,0x000E,0x8011,0xB00E,0x0193,0x0CAD,0x8011,0x600E,0x03E0,0x000F,0x0341,0x0010,0x700D,
0x0C9C,0x800E,0x4011,0x800F,0x4010,0x3000,0x8000,0xFFF1,0x400D,0x8011,0x400F,0x8000,0x0000,0x4011,0x0380,0x000F,
0x0CC3,0x8010,0x5011,0x0301,0x000F,0x0361,0x0010,0x700D,0x0CBE,0x3000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
};
uint16_t tuberom_f100_high[0x100] = {
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF800,0x0A68,0x0000,0xF800,0x0A5D,0x0000,0xF800,0x063C,
0x0000,0xF800,0x063A,0x0000,0xF800,0x0638,0x0000,0xF800,0x0636,0x0000,0xF800,0x0634,0x0000,0xF800,0x0632,0x0000,
0xF800,0x0630,0x0000,0xB000,0x000D,0x0181,0x7FEE,0xF800,0x097B,0x0000,0x0000,0x0000,0x8000,0x000D,0xF800,0x062E,
0x0000,0xF800,0x062C,0x0000,0xF800,0x062A,0x0000,0xF800,0x0628,0x0000,0x0000,0x0000,0x0000,0x0000,0xF800,0x0A71,
};
