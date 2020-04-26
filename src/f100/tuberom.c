#include "tuberom.h"
uint16_t tuberom_f100[0x800] = {
0x8000,0x7C01,0x4800,0x0000,0x8000,0x7800,0x4800,0x0001,0x8000,0xFFCB,0x4002,0x8000,0x0BC6,0x4003,0x8000,0x061F,
0x4004,0x8903,0x4904,0x7002,0x0811,0x8000,0x0B9E,0x2800,0x0965,0x8000,0x0000,0x2800,0x7FEE,0x2800,0x0B69,0x8000,
0x002A,0x2800,0x7FEE,0x8000,0x0000,0x4003,0x8000,0x0A5C,0x4004,0x2800,0x7FF1,0x0194,0x0834,0x8000,0x0660,0x4003,
0x2800,0x7FF7,0xF800,0x081F,0x8000,0x007E,0x2800,0x7FF4,0x8000,0x0BBF,0x2800,0x0965,0xF800,0x081F,0x047B,0x3000,
0x3000,0x8000,0x7C01,0x4800,0x0000,0x2800,0x0974,0x8000,0x07FA,0x4002,0x8802,0x9000,0x0001,0x2800,0x0965,0x2800,
0x0974,0xF800,0x081F,0x3000,0x3000,0x3000,0x8003,0xC000,0x0080,0x0181,0x086F,0x8003,0x4901,0x8000,0x0004,0x2800,
0x0B72,0x8004,0x2800,0x0B72,0x8B01,0x4003,0x8901,0x2800,0x0B72,0x2800,0x0B69,0x4004,0x8B01,0x4003,0x3000,0x8000,
0x0000,0x4002,0x8003,0xB000,0x0082,0x0191,0x08A7,0xB000,0x0083,0x0191,0x08A3,0xB000,0x0084,0x0191,0x089F,0x8000,
0x0006,0x2800,0x0B72,0x8004,0x2800,0x0B72,0x8005,0x2800,0x0B72,0x8003,0x2800,0x0B72,0x8003,0xB000,0x009D,0x0191,
0x089C,0x2800,0x0B69,0x4901,0x2800,0x0B69,0x4005,0x2800,0x0B69,0x4004,0x8B01,0x4002,0x8B01,0x4003,0x3000,0x8000,
0x77FF,0x4003,0x3000,0x8000,0x1000,0x4003,0x3000,0x8000,0x0000,0x4003,0x3000,0x8004,0x4901,0x8003,0x4901,0x2800,
0x090D,0x8002,0x0191,0x08C8,0x8000,0x0002,0x2800,0x0B72,0x8B01,0x2800,0x0B7D,0x2800,0x0B69,0xC000,0x0080,0x0191,
0x08C8,0x8B01,0x4003,0x4901,0x2800,0x08CF,0x2800,0x08CD,0x8B01,0x4003,0x8B01,0x4004,0x3000,0xF800,0x07EC,0x8000,
0x0001,0x6003,0x8000,0x0001,0x5003,0x2800,0x095C,0x4004,0xB000,0x002A,0x0191,0x08D2,0xB000,0x002F,0x0191,0x0902,
0x8000,0x0908,0x4004,0x8000,0x0001,0xA003,0x4005,0x8000,0x0001,0x5004,0x8804,0x4006,0x0191,0x0900,0x8000,0x0001,
0x5005,0x8805,0x4007,0xB000,0x002E,0x0191,0x0900,0x8000,0x00DF,0xC007,0x4007,0xB006,0x0181,0x0905,0xF800,0x08E7,
0x8005,0x4003,0x8000,0x0001,0x5003,0x2800,0x095C,0x4004,0x3000,0x0052,0x0055,0x004E,0x0000,0x8000,0x00FF,0x4002,
0x3000,0x3000,0x3000,0x3000,0x8003,0x0191,0x0A0C,0x4901,0x8004,0x4901,0x8005,0x4901,0x8006,0x4901,0x8003,0x4005,
0x8004,0x4006,0x8000,0x0008,0x2800,0x0B72,0x8005,0x2800,0x0B72,0x8005,0xB000,0x0015,0x0184,0x0931,0x8000,0x0000,
0x4005,0x8005,0x9000,0x09E2,0x4002,0x8802,0x2800,0x0B72,0x8005,0x9000,0x09E2,0x4002,0x8802,0x4003,0x8006,0x4004,
0x2800,0x097D,0x8005,0x9000,0x09F7,0x4002,0x8802,0x2800,0x0B72,0x8005,0x9000,0x09F7,0x4002,0x8802,0x4003,0x8006,
0x4004,0x2800,0x09AF,0x8B01,0x4006,0x8B01,0x4005,0x8B01,0x4004,0x8B01,0x4003,0x3000,0x8000,0x0001,0x6003,0x8903,
0xB000,0x0020,0x0191,0x095F,0x3000,0x4002,0x8000,0x0001,0xA002,0x4003,0x8903,0xC000,0x00FF,0x0191,0x0973,0x2800,
0x7FEE,0xF800,0x096A,0x3000,0x8000,0x000A,0x2800,0x7FEE,0x8000,0x000D,0x2800,0x7FEE,0x3000,0x8005,0x4901,0x8006,
0x4901,0x8000,0xFFFF,0x9003,0x4006,0x0193,0x09AA,0x0321,0x0006,0x9004,0x4004,0x8804,0x4005,0x8006,0xC000,0x0001,
0x4003,0x0194,0x099C,0x0378,0x0005,0x2800,0x0B72,0x8000,0x0001,0x6006,0x0193,0x09AA,0x2800,0x0B72,0x8000,0x0001,
0x6006,0x0193,0x09AA,0x8000,0x0001,0x6004,0x8804,0x4005,0xF800,0x0993,0x8B01,0x4006,0x8B01,0x4005,0x3000,0x8005,
0x4901,0x8006,0x4901,0x8000,0x0001,0x6006,0x0193,0x09DD,0x0321,0x0006,0x5004,0x8000,0x0000,0x4005,0x8000,0x0001,
0xC006,0x0191,0x09CC,0x2800,0x0B69,0x0078,0xC000,0xFF00,0x5005,0x8000,0x0001,0x6006,0x0193,0x09D3,0x2800,0x0B69,
0xC000,0x00FF,0x5005,0x8005,0x4B04,0x8000,0x0000,0x4005,0x8000,0x0001,0x6006,0x0183,0x09C3,0x8B01,0x4006,0x8B01,
0x4005,0x3000,0x0010,0x0000,0x0005,0x0000,0x0005,0x0004,0x0005,0x0008,0x000E,0x0004,0x0001,0x0001,0x0005,0x0000,
0x0008,0x0019,0x0010,0x000D,0x0000,0x0008,0x0080,0x0010,0x0005,0x0000,0x0005,0x0000,0x0005,0x0000,0x0000,0x0000,
0x0005,0x0009,0x0005,0x0000,0x0008,0x0019,0x0001,0x000D,0x000D,0x0080,0x0008,0x0080,0x8004,0x4901,0x8000,0x000A,
0x2800,0x0B72,0x8004,0x9000,0x0003,0x4002,0x8802,0x2800,0x0B72,0x8004,0x9000,0x0002,0x4002,0x8802,0x2800,0x0B72,
0x8004,0x9000,0x0001,0x4002,0x8802,0x2800,0x0B72,0x8000,0x0007,0x2800,0x0B72,0x8000,0x0000,0x2800,0x0B72,0x2800,
0x0B69,0xC000,0x0080,0x0191,0x0A3A,0x8000,0x0010,0x4003,0xF800,0x0A51,0x8000,0x0000,0x4005,0x8804,0x4004,0x2800,
0x0B69,0x4002,0x4804,0x8000,0x0001,0x5004,0x8000,0x0001,0x5005,0x8002,0xB000,0x000D,0x0181,0x0A3F,0x8000,0x0000,
0x4003,0x8800,0x0000,0x4002,0x8003,0x4802,0x8B01,0x4004,0x8000,0x0000,0x4003,0x3000,0x0660,0x018C,0x0020,0x00FF,
0x9000,0x0030,0x4002,0x8800,0x7EF8,0xC000,0x0040,0x0191,0x0A63,0x8002,0x4800,0x7EF9,0x3000,0x8000,0x0000,0x2800,
0x0B72,0x2800,0x0B69,0x2800,0x0B69,0x3000,0x8003,0x4800,0x07F8,0xF800,0x0624,0x8800,0x7EFE,0xC000,0x0080,0x0181,
0x0AAF,0x8800,0x7EF8,0xC000,0x0080,0x0181,0x0A89,0xF800,0x0626,0x8800,0x7EF9,0x4003,0xB000,0x0080,0x0184,0x0AA8,
0x8004,0x4901,0x8005,0x4901,0x2800,0x0B5B,0x4005,0x2800,0x0B5B,0x4004,0x2800,0x0B5B,0x4003,0x2800,0x0AA6,0x8B01,
0x4005,0x8B01,0x4004,0x8800,0x07F8,0x3800,0xF800,0x0640,0x8003,0x5003,0x4800,0x07FE,0x8800,0x07F8,0x3800,0x8800,
0x7EFF,0x4003,0xC000,0x0080,0x0191,0x0ACF,0x8004,0x4901,0x2800,0x0B69,0x8000,0x0660,0x4004,0x2800,0x0B69,0x4804,
0x8000,0x0001,0x5004,0x2800,0x0B69,0x4003,0x4804,0x8000,0x0001,0x5004,0x8003,0x0181,0x0AC3,0xF800,0x0841,0x8004,
0x4901,0x8005,0x4901,0x8003,0x4004,0x2800,0x0B8A,0x4004,0xB000,0x0005,0x0191,0x0AF3,0x2800,0x0B8A,0x2800,0x0B8A,
0x2800,0x0B8A,0x0078,0xC000,0xFF00,0x4005,0x2800,0x0B8A,0x5005,0x8800,0x7EFD,0x8800,0x7EFD,0x2800,0x0B8A,0x8000,
0x0AFA,0x5004,0xF004,0x8B01,0x4005,0x8B01,0x4004,0x8800,0x07F8,0x3800,0x0B02,0x0B2C,0x0B59,0x0B59,0x0B56,0x0AF3,
0x0B59,0x0B59,0x8000,0x0000,0x4004,0x8800,0x7EFE,0x4003,0xC000,0x0080,0x0181,0x0AF3,0x8800,0x7EFC,0x4003,0xC000,
0x0040,0x0191,0x0B05,0x8000,0x0000,0xA004,0x0193,0x0B28,0x8805,0x4004,0x4800,0x7EFD,0x8000,0x0001,0x5005,0x0378,
0x0004,0xC000,0x00FF,0x9000,0x8000,0x4004,0xF800,0x0B05,0x4800,0x7EFD,0xF800,0x0B02,0x8000,0x0000,0x4004,0x8800,
0x7EFE,0x4003,0xC000,0x0080,0x0181,0x0AF3,0x8800,0x7EFC,0x4003,0xC000,0x0080,0x0191,0x0B2F,0x8000,0x0000,0xA004,
0x0193,0x0B49,0x8800,0x7EFD,0x9000,0x8000,0x4004,0xF800,0x0B2F,0x8004,0xC0FF,0x4004,0x8800,0x7EFD,0x0068,0x5004,
0x4805,0x8000,0x0001,0x5005,0xF800,0x0B2C,0x8005,0x4000,0x07EC,0xF800,0x0AF3,0x8800,0x7EF8,0xC000,0x0080,0x0181,
0x0B66,0x8800,0x7EFE,0xC080,0x0191,0x0B5B,0x8800,0x7EF9,0x3000,0x8800,0x7EFA,0xC000,0x0080,0x0191,0x0B69,0x8800,
0x7EFB,0x3000,0x4002,0x8800,0x7EFA,0xC000,0x0040,0x0191,0x0B73,0x8002,0x4800,0x7EFB,0x3000,0x4002,0x8000,0x0001,
0xA002,0x4003,0x8903,0x2800,0x0B72,0xB000,0x000D,0x0181,0x0B82,0x3000,0x8800,0x7EFE,0xC000,0x0080,0x0191,0x0B8A,
0x8800,0x7EFF,0x3000,0x4002,0x8800,0x7EFE,0xC000,0x0040,0x0191,0x0B94,0x8002,0x4800,0x7EFF,0x3000,0x000A,0x0046,
0x0065,0x0072,0x0072,0x0061,0x006E,0x0074,0x0069,0x0020,0x0046,0x0031,0x0030,0x0030,0x002D,0x004C,0x0020,0x0028,
0x0033,0x0032,0x004B,0x0020,0x0077,0x006F,0x0072,0x0064,0x0073,0x0029,0x000A,0x000A,0x000D,0x0000,0x0011,0x000A,
0x0045,0x0073,0x0063,0x0061,0x0070,0x0065,0x0000,0xF800,0x0840,0xF800,0x0841,0xF800,0x0A7B,0xF800,0x0840,0xF800,
0x08AB,0xF800,0x0856,0xF800,0x0914,0xF800,0x0A62,0xF800,0x0A6D,0xF800,0x0911,0xF800,0x0853,0xF800,0x0854,0xF800,
0x0855,0xF800,0x0913,0xF800,0x0912,0xF800,0x0840,0xF800,0x083F,0xF800,0x0840,0xF800,0x0840,0xF800,0x0840,0xF800,
0x0840,0xF800,0x0840,0xF800,0x0840,0xF800,0x0840,0xF800,0x083F,0xF800,0x083F,0xF800,0x083F,0x8000,0x0FFF,0x4003,
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
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF800,0x0A6D,0x0000,0xF800,0x0A62,0x0000,0xF800,0x063C,
0x0000,0xF800,0x063A,0x0000,0xF800,0x0638,0x0000,0xF800,0x0636,0x0000,0xF800,0x0634,0x0000,0xF800,0x0632,0x0000,
0xF800,0x0630,0x0000,0xB00D,0x0181,0x7FEE,0x0000,0xF800,0x0974,0x0000,0x0000,0x0000,0x800D,0x0000,0xF800,0x062E,
0x0000,0xF800,0x062C,0x0000,0xF800,0x062A,0x0000,0xF800,0x0628,0x0000,0x0000,0x0000,0x0000,0x0000,0xF800,0x0A76,
};
