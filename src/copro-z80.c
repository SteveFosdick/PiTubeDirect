/*
 * Z80 Co Pro Emulation
 *
 * (c) 2016 David Banks
 */
#include <stdio.h>
#include <string.h>
#include "tube-defs.h"
#include "tube.h"
#include "tube-ula.h"
#include "yaze/mem_mmu.h"
#include "yaze/simz80.h"
#include "startup.h"

int overlay_rom = 0;

unsigned char copro_z80_ram[0x10000];

unsigned char copro_z80_rom[0x1000] = {
  0xf3, 0x11, 0x00, 0xf0, 0x21, 0x00, 0x00, 0x01, 0x00, 0x10, 0xed, 0xb0, 0xc3, 0x80, 0xf2, 0x43,
  0x6f, 0x70, 0x79, 0x72, 0x69, 0x67, 0x68, 0x74, 0x20, 0x41, 0x63, 0x6f, 0x72, 0x6e, 0x20, 0x43,
  0x6f, 0x6d, 0x70, 0x75, 0x74, 0x65, 0x72, 0x73, 0x20, 0x4c, 0x74, 0x64, 0x2e, 0x20, 0x31, 0x39,
  0x38, 0x34, 0x0d, 0x48, 0x3a, 0x7d, 0x3c, 0xb7, 0xc4, 0xc0, 0x2c, 0x3a, 0x22, 0x3a, 0xb7, 0xc4,
  0xf1, 0x2c, 0xf1, 0x21, 0x1b, 0x3a, 0x34, 0x7e, 0x3d, 0xc2, 0xab, 0x2b, 0x21, 0xec, 0x3b, 0x7e,
  0xb7, 0xc2, 0x34, 0x2b, 0x21, 0x4a, 0x3b, 0x7e, 0xb7, 0xc2, 0x34, 0x2b, 0x21, 0x58, 0x3d, 0x23,
  0x01, 0x06, 0x00, 0x11, 0xec, 0x3b, 0xc3, 0x61, 0xfc, 0x54, 0x68, 0x65, 0x20, 0x42, 0x75, 0x73,
  0x69, 0x6e, 0x65, 0x73, 0x73, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x73, 0x20, 0x47, 0x72,
  0x6f, 0x75, 0x70, 0x20, 0x77, 0x6f, 0x75, 0x6c, 0x64, 0x20, 0x6c, 0x69, 0x6b, 0x65, 0x20, 0x74,
  0x6f, 0x20, 0x74, 0x68, 0x61, 0x6e, 0x6b, 0x4d, 0x69, 0x6b, 0x65, 0x20, 0x42, 0x6f, 0x6c, 0x6c,
  0x65, 0x79, 0x2c, 0x4d, 0x69, 0x6b, 0x65, 0x20, 0x26, 0x20, 0x41, 0x6c, 0x6c, 0x65, 0x6e, 0x20,
  0x42, 0x6f, 0x6f, 0x74, 0x68, 0x72, 0x6f, 0x79, 0x64, 0x2c, 0x52, 0x69, 0x63, 0x68, 0x61, 0x72,
  0x64, 0x20, 0x43, 0x6c, 0x61, 0x79, 0x74, 0x6f, 0x6e, 0x2c, 0x41, 0x6e, 0x64, 0x72, 0x65, 0x77,
  0x20, 0x47, 0x6f, 0x72, 0x64, 0x6f, 0x6e, 0x2c, 0x43, 0x68, 0x72, 0x69, 0x73, 0x20, 0x48, 0x61,
  0x6c, 0x6c, 0x2c, 0x4b, 0x69, 0x6d, 0x20, 0x53, 0x70, 0x65, 0x6e, 0x63, 0x65, 0x2d, 0x4a, 0x6f,
  0x6e, 0x65, 0x73, 0x2c, 0x50, 0x61, 0x75, 0x6c, 0x20, 0x4f, 0x76, 0x65, 0x72, 0x65, 0x6c, 0x6c,
  0x2c, 0x44, 0x61, 0x76, 0x69, 0x64, 0x20, 0x50, 0x61, 0x72, 0x6b, 0x69, 0x6e, 0x73, 0x6f, 0x6e,
  0x2c, 0x4a, 0x6f, 0x68, 0x6e, 0x20, 0x54, 0x75, 0x74, 0x65, 0x6e, 0x20, 0x61, 0x6e, 0x64, 0x20,
  0x45, 0x72, 0x69, 0x63, 0x20, 0x74, 0x68, 0x65, 0x20, 0x68, 0x61, 0x6c, 0x66, 0x20, 0x54, 0x55,
  0x42, 0x45, 0x54, 0x68, 0x65, 0x20, 0x42, 0x53, 0x47, 0x20, 0x69, 0x73, 0x20, 0x42, 0x69, 0x67,
  0x20, 0x41, 0x72, 0x74, 0x68, 0x75, 0x72, 0x20, 0x54, 0x68, 0x65, 0x20, 0x54, 0x6f, 0x75, 0x63,
  0x61, 0x6e, 0x2c, 0x4a, 0x20, 0x4d, 0x61, 0x72, 0x6b, 0x20, 0x43, 0x61, 0x72, 0x72, 0x69, 0x6e,
  0x67, 0x74, 0x6f, 0x6e, 0x2c, 0x48, 0x6f, 0x77, 0x61, 0x72, 0x64, 0x20, 0x46, 0x69, 0x73, 0x68,
  0x65, 0x72, 0x2c, 0x49, 0x61, 0x6e, 0x20, 0x47, 0x20, 0x4a, 0x61, 0x63, 0x6b, 0x2c, 0x4e, 0x65,
  0x69, 0x6c, 0x20, 0x52, 0x6f, 0x62, 0x69, 0x6e, 0x73, 0x6f, 0x6e, 0x2c, 0x53, 0x69, 0x6d, 0x6f,
  0x6e, 0x20, 0x57, 0x6f, 0x6f, 0x64, 0x77, 0x61, 0x72, 0x64, 0x2c, 0x4a, 0x6f, 0x68, 0x6e, 0x20,
  0x43, 0x6f, 0x72, 0x72, 0x61, 0x6c, 0x6c, 0x2c, 0x54, 0x6f, 0x62, 0x79, 0x20, 0x43, 0x72, 0x6f,
  0x73, 0x73, 0x2c, 0x49, 0x61, 0x6e, 0x20, 0x4d, 0x69, 0x6c, 0x6c, 0x65, 0x72, 0x2c, 0x42, 0x6f,
  0x72, 0x69, 0x73, 0x20, 0x53, 0x6f, 0x75, 0x74, 0x68, 0x65, 0x61, 0x72, 0x73, 0x72, 0x6f, 0x72,
  0x28, 0x73, 0x29, 0x00, 0x20, 0x57, 0x61, 0x72, 0x6e, 0x69, 0x6e, 0x67, 0x28, 0x73, 0x29, 0x00,
  0x0e, 0x00, 0x3a, 0x00, 0x3b, 0x47, 0xcd, 0x48, 0x1a, 0xc3, 0x6b, 0x2b, 0xcd, 0x16, 0x2d, 0x21,
  0xcf, 0x2c, 0xcd, 0x19, 0x2d, 0xcd, 0xca, 0x19, 0xc3, 0xfd, 0x2c, 0x52, 0x45, 0x50, 0x54, 0x2f,
  0x49, 0x52, 0x50, 0x2f, 0x49, 0x52, 0x50, 0x43, 0x2f, 0x4d, 0x41, 0x43, 0x52, 0x4f, 0x00, 0x55,
  0x6e, 0x74, 0x65, 0x72, 0x6d, 0x69, 0x6e, 0x61, 0x74, 0x65, 0x64, 0x20, 0x00, 0xcd, 0x16, 0x2d,
  0x21, 0x26, 0x2d, 0xcd, 0x19, 0x2d, 0xcd, 0xca, 0x19, 0x3e, 0x0d, 0xcd, 0xfc, 0x18, 0x3e, 0x0a,
  0xcd, 0xfc, 0x18, 0x3a, 0x37, 0x3d, 0x3c, 0xc8, 0x3e, 0x0d, 0xcd, 0x4e, 0x47, 0x3e, 0x0a, 0xc3,
  0x4e, 0x47, 0x21, 0xe3, 0x2c, 0xe5, 0xcd, 0x77, 0x19, 0xe1, 0x3a, 0x37, 0x3d, 0x3c, 0xc8, 0xc3,
  0x4f, 0x43, 0x43, 0x6f, 0x6e, 0x64, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x61, 0x6c, 0x00, 0x53, 0x79,
  0x6d, 0x62, 0x6f, 0x6c, 0x73, 0x3a, 0x0d, 0x0a, 0x00, 0x4d, 0x61, 0x63, 0x72, 0x6f, 0x73, 0x3a,
  0x0d, 0x0a, 0x00, 0x21, 0xe2, 0xff, 0x39, 0xeb, 0x2a, 0xac, 0x3c, 0xcd, 0x82, 0x0d, 0xd2, 0x5d,
  0x31, 0x80, 0xff, 0xcd, 0x5e, 0xf6, 0x3e, 0xff, 0xed, 0x47, 0xed, 0x5e, 0xfb, 0xcd, 0x0e, 0xf6,
  0x16, 0x08, 0x0d, 0x41, 0x63, 0x6f, 0x72, 0x6e, 0x20, 0x54, 0x55, 0x42, 0x45, 0x20, 0x5a, 0x38,
  0x30, 0x20, 0x36, 0x34, 0x4b, 0x20, 0x31, 0x2e, 0x32, 0x31, 0x0d, 0x0d, 0x00, 0xcd, 0x9a, 0xf6,
  0xcd, 0xae, 0xf5, 0x3e, 0xfd, 0x21, 0x00, 0xff, 0xcd, 0x8e, 0xf8, 0x7d, 0xb7, 0xca, 0xce, 0xf2,
  0x3e, 0x0f, 0x21, 0x01, 0x00, 0xcd, 0x8e, 0xf8, 0xc3, 0xeb, 0xf7, 0xcd, 0xe7, 0xff, 0x31, 0x80,
  0xff, 0x3a, 0x80, 0xff, 0xcb, 0x7f, 0x28, 0x08, 0x3e, 0x7e, 0x21, 0x00, 0x00, 0xcd, 0x8e, 0xf8,
  0x3e, 0x2a, 0xcd, 0x71, 0xf6, 0x21, 0x9d, 0xfc, 0xaf, 0xcd, 0xef, 0xf8, 0xda, 0xfa, 0xf2, 0x21,
  0xb0, 0xfc, 0xcd, 0xb7, 0xf6, 0x18, 0xd7, 0xcd, 0xe7, 0xff, 0x3e, 0x7e, 0xcd, 0x8e, 0xf8, 0xff,
  0x11, 0x45, 0x73, 0x63, 0x61, 0x70, 0x65, 0x00, 0x13, 0x1a, 0xe6, 0xdf, 0xfe, 0x4f, 0xc2, 0xcc,
  0xf7, 0xcd, 0x76, 0xf8, 0x06, 0x00, 0xcd, 0x39, 0xf4, 0xcd, 0x77, 0xf8, 0xfe, 0x0d, 0xc2, 0xcc,
  0xf7, 0x3a, 0xaa, 0xfc, 0x32, 0xa8, 0xfc, 0x3a, 0xab, 0xfc, 0x32, 0xa9, 0xfc, 0xc3, 0xdf, 0xf7,
  0xcd, 0x76, 0xf8, 0x06, 0x00, 0xcd, 0x39, 0xf4, 0xcd, 0x77, 0xf8, 0xfe, 0x0d, 0xc2, 0xcc, 0xf7,
  0x3e, 0x04, 0x21, 0x01, 0x00, 0xcd, 0xf4, 0xff, 0x7d, 0x32, 0xae, 0xfc, 0x2a, 0xaa, 0xfc, 0xcd,
  0xe7, 0xff, 0xcd, 0x71, 0xf4, 0xcd, 0x1d, 0xf4, 0x7e, 0xcd, 0x0d, 0xf4, 0xcd, 0x1d, 0xf4, 0x7e,
  0xcd, 0x76, 0xf4, 0xe5, 0x06, 0x01, 0x21, 0x00, 0x00, 0xcd, 0xe0, 0xff, 0xcd, 0x40, 0xf4, 0x06,
  0x00, 0x5d, 0xe1, 0xfe, 0x8a, 0x28, 0x27, 0xfe, 0x8b, 0x28, 0x20, 0xfe, 0x01, 0xc2, 0xa1, 0xf3,
  0x7e, 0xcb, 0x27, 0xcb, 0x27, 0xcb, 0x27, 0xcb, 0x27, 0x83, 0x77, 0x3e, 0x08, 0xcd, 0x71, 0xf6,
  0xcd, 0x71, 0xf6, 0xcd, 0x71, 0xf6, 0xcd, 0x71, 0xf6, 0x18, 0xbd, 0x23, 0x18, 0xb1, 0x2b, 0x18,
  0xae, 0x3a, 0xae, 0xfc, 0x6f, 0x26, 0x00, 0x3e, 0x04, 0xcd, 0xf4, 0xff, 0xcd, 0xe7, 0xff, 0xd1,
  0xc1, 0xf1, 0xc9, 0xcd, 0x76, 0xf8, 0x06, 0x00, 0xcd, 0x39, 0xf4, 0xfe, 0x0d, 0x28, 0x10, 0xfe,
  0x20, 0xc2, 0xcc, 0xf7, 0x2a, 0xaa, 0xfc, 0xcd, 0x77, 0xf8, 0xcd, 0x39, 0xf4, 0x18, 0x03, 0x2a,
  0xaa, 0xfc, 0xed, 0x5b, 0xaa, 0xfc, 0x3a, 0x80, 0xff, 0xcb, 0x7f, 0xc2, 0xf7, 0xf2, 0xcd, 0xe7,
  0xff, 0xcd, 0x71, 0xf4, 0x06, 0x08, 0xe5, 0xcd, 0x1d, 0xf4, 0x7e, 0xcd, 0x76, 0xf4, 0x23, 0x10,
  0xf6, 0x06, 0x08, 0xe1, 0xcd, 0x1d, 0xf4, 0x7e, 0xcd, 0x0d, 0xf4, 0x23, 0x10, 0xf9, 0xcd, 0x23,
  0xf4, 0xd2, 0x06, 0xf4, 0x18, 0xd0, 0xcd, 0xe7, 0xff, 0xd1, 0xc1, 0xf1, 0xc9, 0xfe, 0x20, 0x38,
  0x06, 0xfe, 0x7f, 0x30, 0x02, 0x18, 0x02, 0x3e, 0x2e, 0xcd, 0x71, 0xf6, 0xc9, 0x3e, 0x20, 0xcd,
  0x71, 0xf6, 0xc9, 0xe5, 0x01, 0x08, 0x00, 0xbf, 0xed, 0x42, 0x30, 0x06, 0x21, 0x00, 0x00, 0xbf,
  0x18, 0x02, 0xe1, 0xe5, 0x2b, 0xed, 0x52, 0xe1, 0xc9, 0x22, 0xac, 0xfc, 0x21, 0x00, 0x00, 0x1a,
  0xcb, 0x77, 0x28, 0x02, 0xe6, 0xdf, 0xfe, 0x30, 0xfa, 0x6d, 0xf4, 0xfe, 0x47, 0xf2, 0x6d, 0xf4,
  0xfe, 0x3a, 0x38, 0x07, 0xfe, 0x41, 0xfa, 0x6d, 0xf4, 0xc6, 0x09, 0xe6, 0x0f, 0x29, 0x29, 0x29,
  0x29, 0xb5, 0x6f, 0x3e, 0x01, 0xb8, 0xc8, 0x13, 0x22, 0xaa, 0xfc, 0x18, 0xd2, 0x2a, 0xac, 0xfc,
  0xc9, 0x7c, 0xcd, 0x76, 0xf4, 0x7d, 0xf5, 0x0f, 0x0f, 0x0f, 0x0f, 0xcd, 0x7f, 0xf4, 0xf1, 0xe6,
  0x0f, 0xc6, 0x30, 0xfe, 0x3a, 0xfa, 0x71, 0xf6, 0xc6, 0x07, 0xc3, 0x71, 0xf6, 0x13, 0x1a, 0xe6,
  0xdf, 0xfe, 0x50, 0xc2, 0xcc, 0xf7, 0x13, 0x1a, 0xe6, 0xdf, 0xfe, 0x4d, 0xc2, 0xcc, 0xf7, 0xcd,
  0x76, 0xf8, 0xfe, 0x0d, 0xc2, 0xcc, 0xf7, 0x18, 0x26, 0xcd, 0x0e, 0xf6, 0x49, 0x6e, 0x73, 0x65,
  0x72, 0x74, 0x20, 0x43, 0x50, 0x2f, 0x4d, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x64,
  0x69, 0x73, 0x63, 0x20, 0x69, 0x6e, 0x20, 0x64, 0x72, 0x69, 0x76, 0x65, 0x20, 0x41, 0x00, 0x3e,
  0xe5, 0x21, 0x01, 0x00, 0xcd, 0x8e, 0xf8, 0x21, 0x82, 0xf5, 0xcd, 0x4a, 0xf5, 0x21, 0x00, 0xeb,
  0x11, 0xf0, 0xea, 0x01, 0xf0, 0x00, 0xed, 0xb0, 0x21, 0xf0, 0xeb, 0x11, 0xe0, 0xeb, 0x01, 0x00,
  0x06, 0xed, 0xb0, 0xcd, 0x3b, 0xf5, 0x3a, 0x00, 0xd4, 0xfe, 0xc3, 0xca, 0x22, 0xf5, 0x3e, 0xe5,
  0x21, 0x00, 0x00, 0xcd, 0x8e, 0xf8, 0xcd, 0xe7, 0xff, 0xff, 0xc8, 0x4e, 0x6f, 0x74, 0x20, 0x61,
  0x20, 0x43, 0x50, 0x2f, 0x4d, 0x20, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x20, 0x64, 0x69, 0x73,
  0x63, 0x00, 0x21, 0xb2, 0xfa, 0x22, 0xfa, 0xff, 0x3e, 0x90, 0x32, 0xa3, 0xfc, 0x21, 0x00, 0x01,
  0xcd, 0x8e, 0xf8, 0xcd, 0x0e, 0xf6, 0x16, 0x00, 0xc3, 0x00, 0xea, 0x21, 0x8d, 0xf5, 0xcd, 0x4a,
  0xf5, 0x21, 0x98, 0xf5, 0xcd, 0x4a, 0xf5, 0x21, 0xa3, 0xf5, 0xcd, 0x5c, 0xf5, 0xb7, 0xc8, 0xff,
  0xc7, 0x44, 0x69, 0x73, 0x63, 0x20, 0x66, 0x61, 0x75, 0x6c, 0x74, 0x00, 0x06, 0x04, 0x48, 0x06,
  0x0a, 0x3e, 0x7f, 0xcd, 0xef, 0xf8, 0x11, 0x0a, 0x00, 0xeb, 0x19, 0x7e, 0x32, 0xa7, 0xfc, 0xeb,
  0xfe, 0x12, 0xc8, 0xb7, 0xc8, 0x10, 0xea, 0x7e, 0xcd, 0x1b, 0xf6, 0x41, 0x10, 0xe0, 0x3a, 0xa7,
  0xfc, 0xc9, 0x00, 0xf0, 0xe9, 0x00, 0x00, 0x03, 0x53, 0x00, 0x00, 0x28, 0xff, 0x00, 0x00, 0xd4,
  0x00, 0x00, 0x03, 0x53, 0x00, 0x08, 0x22, 0xff, 0x00, 0x00, 0xd6, 0x00, 0x00, 0x03, 0x53, 0x01,
  0x00, 0x2a, 0xff, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x03, 0x53, 0x02, 0x00, 0x2a, 0xff, 0xf3, 0x21,
  0x00, 0x25, 0x11, 0xf7, 0xfc, 0x06, 0xe3, 0xcd, 0xf3, 0xf5, 0x21, 0x00, 0x02, 0x11, 0xdc, 0xfd,
  0x06, 0x02, 0xcd, 0xdd, 0xf5, 0x21, 0x03, 0x25, 0x11, 0xdc, 0xfd, 0x06, 0x02, 0xcd, 0xf3, 0xf5,
  0x21, 0x00, 0x02, 0x11, 0xda, 0xfd, 0x06, 0x02, 0xcd, 0xf3, 0xf5, 0xfb, 0xc9, 0x22, 0x09, 0xf6,
  0xe5, 0x21, 0x09, 0xf6, 0x3e, 0x05, 0xcd, 0xf1, 0xff, 0x3a, 0x0d, 0xf6, 0x12, 0x13, 0xe1, 0x23,
  0x10, 0xeb, 0xc9, 0x22, 0x09, 0xf6, 0x1a, 0x32, 0x0d, 0xf6, 0xe5, 0x21, 0x09, 0xf6, 0x3e, 0x06,
  0xcd, 0xf1, 0xff, 0x13, 0xe1, 0x23, 0x10, 0xeb, 0xc9, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xf5,
  0x7e, 0xcd, 0xe3, 0xff, 0x23, 0xb7, 0x20, 0xf8, 0xf1, 0xe3, 0xc9, 0xf5, 0xe5, 0x32, 0x36, 0xf6,
  0x21, 0x36, 0xf6, 0x3e, 0x7f, 0xed, 0x73, 0xa5, 0xfc, 0x00, 0x00, 0x00, 0xcd, 0xef, 0xf8, 0xed,
  0x7b, 0xa5, 0xfc, 0xe1, 0xf1, 0xc9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x69, 0x00, 0x00, 0xe5,
  0x21, 0xff, 0xff, 0x3e, 0x80, 0xcd, 0x8e, 0xf8, 0x7d, 0xb7, 0x28, 0x02, 0x18, 0x0c, 0x3e, 0xd8,
  0x21, 0x00, 0xff, 0xcd, 0x8e, 0xf8, 0x7d, 0xb7, 0x28, 0x02, 0x3e, 0xff, 0xe1, 0xc9, 0xc5, 0xd5,
  0xe5, 0x21, 0xbc, 0xff, 0x11, 0x38, 0x00, 0x01, 0x03, 0x00, 0xed, 0xb0, 0xe1, 0xd1, 0xc1, 0xc9,
  0xc9, 0xf5, 0xdb, 0x00, 0xcb, 0x77, 0x28, 0xfa, 0xf1, 0xd3, 0x01, 0xc9, 0xdb, 0x00, 0xcb, 0x7f,
  0x20, 0x0b, 0xdb, 0x06, 0xcb, 0x7f, 0x28, 0xf4, 0xcd, 0x0b, 0xfb, 0x18, 0xef, 0xdb, 0x01, 0xc9,
  0x3e, 0x00, 0xcd, 0xa3, 0xf6, 0xcd, 0x9a, 0xf6, 0xcb, 0x27, 0xdb, 0x02, 0xcb, 0x7f, 0x28, 0xfa,
  0xdb, 0x03, 0xc9, 0xf5, 0xdb, 0x02, 0xcb, 0x77, 0x28, 0xfa, 0xf1, 0xd3, 0x03, 0xc9, 0xdb, 0x06,
  0xcb, 0x7f, 0x28, 0xfa, 0xdb, 0x07, 0xc9, 0xf5, 0xc5, 0xd5, 0x54, 0x5d, 0xcd, 0x7e, 0xf8, 0xcd,
  0x77, 0xf8, 0xfe, 0x2a, 0x28, 0xf6, 0xe6, 0xdf, 0xfe, 0x48, 0x28, 0x20, 0x4f, 0x3a, 0xa3, 0xfc,
  0xb7, 0x79, 0xc2, 0xcc, 0xf7, 0xfe, 0x47, 0xca, 0x08, 0xf3, 0xfe, 0x44, 0xca, 0xb3, 0xf3, 0xfe,
  0x53, 0xca, 0x30, 0xf3, 0xfe, 0x43, 0xca, 0x8d, 0xf4, 0xc3, 0xcc, 0xf7, 0x13, 0x1a, 0xfe, 0x2e,
  0x28, 0x2e, 0xe6, 0xdf, 0xfe, 0x45, 0xc2, 0xcc, 0xf7, 0x13, 0x1a, 0xfe, 0x2e, 0x28, 0x21, 0xe6,
  0xdf, 0xfe, 0x4c, 0xc2, 0xcc, 0xf7, 0x13, 0x1a, 0xfe, 0x2e, 0x28, 0x14, 0xe6, 0xdf, 0xfe, 0x50,
  0xc2, 0xcc, 0xf7, 0x13, 0x1a, 0xcd, 0x6d, 0xf8, 0xd2, 0xcc, 0xf7, 0xcd, 0x77, 0xf8, 0x18, 0x03,
  0xcd, 0x76, 0xf8, 0xcd, 0xb3, 0xff, 0x0d, 0x5a, 0x38, 0x30, 0x20, 0x54, 0x55, 0x42, 0x45, 0x20,
  0x31, 0x2e, 0x32, 0x31, 0x0d, 0x00, 0x4f, 0x3a, 0xa3, 0xfc, 0xb7, 0x79, 0xc2, 0xcc, 0xf7, 0xfe,
  0x0d, 0x28, 0x29, 0xe6, 0xdf, 0xfe, 0x4d, 0x28, 0x09, 0xfe, 0x0d, 0xca, 0xcc, 0xf7, 0x13, 0x1a,
  0x18, 0xf1, 0x13, 0x1a, 0xe6, 0xdf, 0xfe, 0x4f, 0x20, 0xf4, 0x13, 0x1a, 0xe6, 0xdf, 0xfe, 0x4e,
  0x20, 0xec, 0x13, 0x1a, 0xcd, 0x6d, 0xf8, 0xd2, 0x4e, 0xf7, 0x18, 0x0c, 0xcd, 0x0e, 0xf6, 0x20,
  0x20, 0x4d, 0x4f, 0x4e, 0x0d, 0x00, 0x18, 0x54, 0xcd, 0x0e, 0xf6, 0x20, 0x20, 0x43, 0x50, 0x4d,
  0x0d, 0x20, 0x20, 0x44, 0x75, 0x6d, 0x70, 0x20, 0x3c, 0x73, 0x74, 0x61, 0x72, 0x74, 0x20, 0x61,
  0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x3e, 0x20, 0x3c, 0x65, 0x6e, 0x64, 0x20, 0x61, 0x64, 0x64,
  0x72, 0x65, 0x73, 0x73, 0x3e, 0x0d, 0x20, 0x20, 0x47, 0x4f, 0x20, 0x3c, 0x61, 0x64, 0x64, 0x72,
  0x65, 0x73, 0x73, 0x3e, 0x0d, 0x20, 0x20, 0x53, 0x65, 0x74, 0x20, 0x3c, 0x73, 0x74, 0x61, 0x72,
  0x74, 0x20, 0x61, 0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x3e, 0x0d, 0x00, 0x3e, 0x02, 0xcd, 0xa3,
  0xf6, 0xcd, 0x84, 0xf8, 0xcd, 0x9a, 0xf6, 0xfe, 0x80, 0x28, 0x04, 0xd1, 0xc1, 0xf1, 0xc9, 0x3e,
  0x01, 0x32, 0xaf, 0xfc, 0xcd, 0xeb, 0xf7, 0xd1, 0xc1, 0xf1, 0xc9, 0x2a, 0xa8, 0xfc, 0x11, 0x07,
  0x00, 0x19, 0xe5, 0x7e, 0x2a, 0xa8, 0xfc, 0x5f, 0x19, 0x22, 0x82, 0xff, 0x7e, 0x11, 0x22, 0xff,
  0x06, 0x04, 0x1a, 0xbe, 0x20, 0x20, 0x23, 0x13, 0x10, 0xf8, 0xe1, 0x2b, 0x3a, 0xaf, 0xfc, 0xb7,
  0x20, 0x17, 0x7e, 0xe6, 0x4f, 0xfe, 0x40, 0x38, 0x09, 0xfe, 0x48, 0x20, 0x05, 0xbf, 0x2a, 0xa8,
  0xfc, 0xe9, 0xbf, 0xc3, 0xa9, 0xf4, 0xe1, 0x18, 0xf4, 0xaf, 0x32, 0xaf, 0xfc, 0x7e, 0xe6, 0x4f,
  0xfe, 0x40, 0x38, 0x09, 0xfe, 0x48, 0x20, 0x1e, 0x3e, 0x01, 0x18, 0xe1, 0x00, 0xff, 0xf9, 0x54,
  0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x61, 0x20, 0x6c, 0x61, 0x6e,
  0x67, 0x75, 0x61, 0x67, 0x65, 0x00, 0xff, 0xf9, 0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20,
  0x6e, 0x6f, 0x74, 0x20, 0x5a, 0x38, 0x30, 0x20, 0x63, 0x6f, 0x64, 0x65, 0x00, 0xe6, 0xdf, 0xfe,
  0x41, 0xd8, 0xfe, 0x5b, 0x3f, 0xc9, 0x13, 0x1a, 0xfe, 0x20, 0x28, 0xfa, 0xc9, 0x13, 0x1a, 0xfe,
  0x2a, 0x28, 0xfa, 0xc9, 0x7e, 0xcd, 0xa3, 0xf6, 0x23, 0xfe, 0x0d, 0x20, 0xf7, 0xc9, 0xfe, 0x80,
  0x30, 0x15, 0xf5, 0x3e, 0x04, 0xcd, 0xa3, 0xf6, 0x7d, 0xcd, 0xa3, 0xf6, 0xf1, 0xf5, 0xcd, 0xa3,
  0xf6, 0xcd, 0x9a, 0xf6, 0x6f, 0xf1, 0xc9, 0xfe, 0x82, 0x28, 0x31, 0xfe, 0x83, 0x28, 0x31, 0xfe,
  0x84, 0x28, 0x31, 0xf5, 0x3e, 0x06, 0xcd, 0xa3, 0xf6, 0x7d, 0xcd, 0xa3, 0xf6, 0x7c, 0xcd, 0xa3,
  0xf6, 0xf1, 0xf5, 0xcd, 0xa3, 0xf6, 0xfe, 0x9d, 0x28, 0x10, 0xcd, 0x9a, 0xf6, 0x6f, 0xf1, 0xcb,
  0x25, 0xf5, 0xcd, 0x9a, 0xf6, 0x67, 0xcd, 0x9a, 0xf6, 0x6f, 0xf1, 0xc9, 0x21, 0x00, 0x00, 0xc9,
  0x21, 0x03, 0x3b, 0xc9, 0x21, 0x00, 0xdc, 0xc9, 0xf5, 0x3e, 0x01, 0x32, 0xa4, 0xfc, 0xf1, 0xb7,
  0x28, 0x6b, 0xc5, 0xe5, 0xdd, 0xe5, 0xf5, 0x3e, 0x08, 0xcd, 0xa3, 0xf6, 0xf1, 0xf5, 0xcd, 0xa3,
  0xf6, 0x06, 0x00, 0x4f, 0xfe, 0x80, 0x38, 0x06, 0x46, 0x23, 0x4e, 0x2b, 0x18, 0x15, 0xfe, 0x15,
  0x38, 0x05, 0x01, 0x10, 0x10, 0x18, 0x0c, 0xdd, 0x21, 0x75, 0xfc, 0xdd, 0x09, 0xdd, 0x46, 0xff,
  0xdd, 0x4e, 0x13, 0xe5, 0xc5, 0x48, 0x06, 0x00, 0x09, 0xc1, 0x78, 0xcd, 0xa3, 0xf6, 0xb7, 0x28,
  0x07, 0x2b, 0x7e, 0xcd, 0xa3, 0xf6, 0x10, 0xf9, 0x79, 0xcd, 0xa3, 0xf6, 0xe1, 0xf5, 0x3a, 0xa4,
  0xfc, 0xb7, 0x28, 0x06, 0x62, 0x6b, 0xaf, 0x32, 0xa4, 0xfc, 0xf1, 0xb7, 0x28, 0x09, 0x09, 0x41,
  0x2b, 0xcd, 0x9a, 0xf6, 0x77, 0x10, 0xf9, 0xf1, 0xdd, 0xe1, 0xe1, 0xc1, 0xc9, 0xc5, 0xf5, 0x3e,
  0x0a, 0xcd, 0xa3, 0xf6, 0x23, 0x23, 0x23, 0x23, 0x06, 0x03, 0x7e, 0xcd, 0xa3, 0xf6, 0x2b, 0x10,
  0xf9, 0x3e, 0x07, 0xcd, 0xa3, 0xf6, 0x97, 0xcd, 0xa3, 0xf6, 0xcd, 0x9a, 0xf6, 0x07, 0x38, 0x18,
  0x7e, 0x2b, 0x6e, 0x67, 0x06, 0xff, 0xcd, 0x9a, 0xf6, 0x77, 0x23, 0x04, 0xfe, 0x0d, 0x20, 0xf6,
  0x2e, 0x00, 0x60, 0xf1, 0xc1, 0x37, 0x3f, 0xc9, 0x21, 0xff, 0x00, 0xf1, 0xc1, 0x37, 0xc9, 0xe5,
  0xd5, 0xc5, 0xf5, 0x3e, 0x0c, 0xcd, 0xa3, 0xf6, 0x7b, 0xcd, 0xa3, 0xf6, 0x23, 0x23, 0x23, 0x06,
  0x04, 0x7e, 0xcd, 0xa3, 0xf6, 0x2b, 0x10, 0xf9, 0x23, 0xf1, 0xcd, 0xa3, 0xf6, 0xcd, 0x9a, 0xf6,
  0xf5, 0x23, 0x23, 0x23, 0x06, 0x04, 0xcd, 0x9a, 0xf6, 0x77, 0x2b, 0x10, 0xf9, 0xf1, 0xc1, 0xd1,
  0xe1, 0xc9, 0xf5, 0x3e, 0x12, 0xcd, 0xa3, 0xf6, 0xf1, 0xcd, 0xa3, 0xf6, 0xfe, 0x00, 0x20, 0x0a,
  0xf5, 0x7c, 0xcd, 0xa3, 0xf6, 0xcd, 0x9a, 0xf6, 0xf1, 0xc9, 0xcd, 0x84, 0xf8, 0xc3, 0x9a, 0xf6,
  0x3e, 0x0e, 0xcd, 0xa3, 0xf6, 0x7c, 0xcd, 0xa3, 0xf6, 0xc3, 0x95, 0xf6, 0xf5, 0x3e, 0x10, 0xcd,
  0xa3, 0xf6, 0x7c, 0xcd, 0xa3, 0xf6, 0xf1, 0xcd, 0xa3, 0xf6, 0xf5, 0xcd, 0x9a, 0xf6, 0xf1, 0xc9,
  0xc5, 0xf5, 0x22, 0xac, 0xfc, 0x3e, 0x14, 0xcd, 0xa3, 0xf6, 0x01, 0x11, 0x00, 0x09, 0x06, 0x10,
  0x7e, 0xcd, 0xa3, 0xf6, 0x2b, 0x10, 0xf9, 0x7e, 0x2b, 0x6e, 0x67, 0xcd, 0x84, 0xf8, 0xf1, 0xcd,
  0xa3, 0xf6, 0xcd, 0x9a, 0xf6, 0xe6, 0xff, 0xf5, 0x2a, 0xac, 0xfc, 0x01, 0x11, 0x00, 0x09, 0x06,
  0x10, 0xcd, 0x9a, 0xf6, 0x77, 0x2b, 0x10, 0xf9, 0x2a, 0xac, 0xfc, 0xf1, 0xc1, 0xc9, 0xc5, 0xf5,
  0x22, 0xac, 0xfc, 0x3e, 0x16, 0xcd, 0xa3, 0xf6, 0x01, 0x0c, 0x00, 0x09, 0x06, 0x0d, 0x7e, 0xcd,
  0xa3, 0xf6, 0x2b, 0x10, 0xf9, 0xf1, 0xcd, 0xa3, 0xf6, 0x2a, 0xac, 0xfc, 0x01, 0x0c, 0x00, 0x09,
  0x06, 0x0d, 0xcd, 0x9a, 0xf6, 0x77, 0x2b, 0x10, 0xf9, 0x2a, 0xac, 0xfc, 0xc1, 0xc3, 0x95, 0xf6,
  0x00, 0x00, 0xed, 0x73, 0x80, 0xfa, 0x31, 0x60, 0xff, 0xcd, 0x93, 0xfa, 0xed, 0x7b, 0x80, 0xfa,
  0xfb, 0xed, 0x4d, 0xf5, 0xdb, 0x06, 0xcb, 0x7f, 0x20, 0x71, 0xdb, 0x00, 0xcb, 0x7f, 0x20, 0x39,
  0xf1, 0xc3, 0xb0, 0xff, 0xe1, 0x22, 0x82, 0xff, 0x2a, 0xfa, 0xff, 0xe9, 0xcd, 0xc6, 0xfa, 0xc3,
  0xcb, 0xf2, 0x3e, 0x03, 0x2e, 0x00, 0xcd, 0x8e, 0xf8, 0x3e, 0x02, 0x2e, 0x02, 0xcd, 0x8e, 0xf8,
  0xcd, 0xc6, 0xfa, 0xc3, 0x00, 0x00, 0x2a, 0x82, 0xff, 0x3e, 0x0d, 0xcd, 0x71, 0xf6, 0x3e, 0x0a,
  0xcd, 0x71, 0xf6, 0x23, 0x7e, 0xb7, 0x20, 0xf8, 0xc9, 0xdb, 0x01, 0xcb, 0x7f, 0x20, 0x25, 0x3e,
  0x01, 0x32, 0xa2, 0xfc, 0xe5, 0xdd, 0xe5, 0xcd, 0x7c, 0xf6, 0x67, 0xcd, 0x7c, 0xf6, 0x6f, 0xcd,
  0x7c, 0xf6, 0xcd, 0xfe, 0xfa, 0xaf, 0x32, 0xa2, 0xfc, 0xdd, 0xe1, 0xe1, 0xf1, 0xc9, 0xdd, 0x2a,
  0xfc, 0xff, 0xdd, 0xe9, 0xcb, 0x27, 0x32, 0x80, 0xff, 0xf1, 0xc9, 0xdb, 0x07, 0xcb, 0x7f, 0x28,
  0x45, 0xdb, 0x02, 0xcb, 0x7f, 0x28, 0xfa, 0xdb, 0x03, 0xfb, 0x21, 0xb0, 0xfc, 0x36, 0xcd, 0x23,
  0x3a, 0xbd, 0xff, 0x77, 0x23, 0x3a, 0xbe, 0xff, 0x77, 0x23, 0xcd, 0x9a, 0xf6, 0x77, 0xb7, 0x20,
  0x1a, 0xcd, 0x0e, 0xf6, 0x0d, 0x46, 0x61, 0x74, 0x61, 0x6c, 0x20, 0x65, 0x72, 0x72, 0x6f, 0x72,
  0x00, 0x3a, 0xa3, 0xfc, 0xb7, 0xc2, 0x00, 0x00, 0xc3, 0xcb, 0xf2, 0x23, 0xcd, 0x9a, 0xf6, 0x77,
  0xb7, 0x20, 0xf8, 0xc3, 0xb0, 0xfc, 0xc5, 0xd5, 0xe5, 0xf5, 0x07, 0x5f, 0x07, 0x07, 0x83, 0x07,
  0x5f, 0x16, 0x00, 0x21, 0xc1, 0xfb, 0x19, 0x11, 0x61, 0xfc, 0x01, 0x14, 0x00, 0xed, 0xb0, 0xcd,
  0xae, 0xf6, 0xf1, 0xfe, 0x05, 0x28, 0x33, 0xf5, 0xcd, 0xae, 0xf6, 0xcd, 0xae, 0xf6, 0xcd, 0xae,
  0xf6, 0x67, 0xcd, 0xae, 0xf6, 0x6f, 0x22, 0xa8, 0xfc, 0x0e, 0x05, 0x06, 0x00, 0xcd, 0xae, 0xf6,
  0xf1, 0xfe, 0x06, 0x38, 0x15, 0x20, 0x1d, 0xdb, 0x04, 0xb7, 0xf2, 0x97, 0xfb, 0xed, 0xa3, 0xc2,
  0x97, 0xfb, 0xdb, 0x04, 0xb7, 0xf2, 0xa2, 0xfb, 0xd3, 0x05, 0xe1, 0xd1, 0xc1, 0x3a, 0xa2, 0xfc,
  0xb7, 0xc0, 0xf1, 0xc9, 0xdb, 0x04, 0xb7, 0xf2, 0xb4, 0xfb, 0xed, 0xa2, 0xc2, 0xb4, 0xfb, 0x18,
  0xe9, 0xe5, 0xf5, 0x2a, 0xa8, 0xfc, 0x7e, 0xd3, 0x05, 0x23, 0x22, 0xa8, 0xfc, 0xf1, 0xe1, 0xed,
  0x45, 0x3a, 0x12, 0x3b, 0xb7, 0xe5, 0xf5, 0xdb, 0x05, 0x2a, 0xa8, 0xfc, 0x77, 0x23, 0x22, 0xa8,
  0xfc, 0xf1, 0xe1, 0xed, 0x45, 0x01, 0x3b, 0xeb, 0xcd, 0xe5, 0xf5, 0x2a, 0xa8, 0xfc, 0x7e, 0xd3,
  0x05, 0x23, 0x7e, 0xd3, 0x05, 0x23, 0x22, 0xa8, 0xfc, 0xf1, 0xe1, 0xed, 0x45, 0xe5, 0xf5, 0xdb,
  0x05, 0x2a, 0xa8, 0xfc, 0x77, 0x23, 0xdb, 0x05, 0x77, 0x23, 0x22, 0xa8, 0xfc, 0xf1, 0xe1, 0xed,
  0x45, 0xd3, 0x05, 0xed, 0x45, 0x23, 0x56, 0x2b, 0xc9, 0x2a, 0xa0, 0x3c, 0x19, 0x23, 0x23, 0x5e,
  0x23, 0x56, 0x2b, 0xc9, 0x2a, 0xd3, 0x05, 0xed, 0x45, 0xca, 0x0d, 0x37, 0xeb, 0xd5, 0xcd, 0xed,
  0x36, 0xeb, 0x22, 0xa4, 0x3c, 0xd1, 0xc3, 0x39, 0x37, 0xd3, 0x05, 0xed, 0x45, 0x20, 0x00, 0xeb,
  0x19, 0x22, 0xa2, 0x3c, 0xd5, 0xeb, 0x2a, 0xac, 0x3c, 0xcd, 0x82, 0x0d, 0xd1, 0xd3, 0x05, 0xed,
  0x45, 0x7b, 0x3c, 0x25, 0x3a, 0x7d, 0x3c, 0xb7, 0xcd, 0x82, 0x0d, 0xda, 0x87, 0x38, 0x2a, 0xa0,
  0x3c, 0xd3, 0x05, 0xed, 0x45, 0xd5, 0xcd, 0xe4, 0x36, 0xeb, 0x2a, 0xa8, 0x3c, 0xeb, 0x7b, 0xe6,
  0xe0, 0x5f, 0x7b, 0xb2, 0xc2, 0x00, 0x05, 0x00, 0x05, 0x04, 0x05, 0x08, 0x0e, 0x04, 0x01, 0x01,
  0x05, 0x00, 0x20, 0x20, 0x10, 0x0d, 0x00, 0x08, 0x80, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x00,
  0x00, 0x05, 0x09, 0x05, 0x00, 0x08, 0x20, 0x10, 0x01, 0x0d, 0x80, 0x08, 0x80, 0xb0, 0xfc, 0x80,
  0x20, 0xff, 0x00, 0x00, 0x00, 0xd5, 0xf5, 0x2a, 0xa8, 0xfc, 0x00, 0x00, 0xb0, 0xfc, 0x00, 0x00,
  0x36, 0x2a, 0xa0, 0x3c, 0x19, 0xf1, 0xf5, 0x77, 0x7b, 0xe6, 0x1f, 0xfe, 0x1f, 0xca, 0x95, 0x37,
  0x13, 0xcc, 0x9f, 0x37, 0xeb, 0x22, 0xa8, 0x3c, 0xf1, 0xd1, 0xc9, 0x7b, 0xe6, 0xe0, 0x5f, 0xcd,
  0xed, 0x36, 0x7a, 0xb3, 0xca, 0xf8, 0x36, 0x13, 0x13, 0x13, 0x13, 0xc9, 0xd5, 0xeb, 0x2a, 0xa0,
  0x3c, 0xeb, 0x7d, 0xe6, 0x1f, 0xc2, 0xc0, 0x37, 0x7d, 0xf6, 0x04, 0x6f, 0xeb, 0x19, 0x7e, 0xeb,
  0xd1, 0xc9, 0xcd, 0xb0, 0x37, 0xf5, 0xd5, 0x4c, 0x05, 0x25, 0x00, 0x25, 0xc9, 0xff, 0xf0, 0x03,
  0x6c, 0x03, 0x25, 0x86, 0x70, 0x84, 0x71, 0x85, 0x72, 0xa0, 0x02, 0xb1, 0x70, 0x85, 0x74, 0xc8,
  0xb1, 0x70, 0x85, 0x75, 0xa5, 0xf4, 0x48, 0xc8, 0xb1, 0x70, 0xaa, 0x18, 0x69, 0x40, 0x85, 0xf4,
  0x8d, 0x30, 0xfe, 0xe8, 0xf0, 0x15, 0xe8, 0xf0, 0x05, 0xe8, 0xf0, 0x0a, 0xd0, 0x0d, 0xa9, 0x84,
  0x20, 0xf4, 0xff, 0x98, 0x10, 0x05, 0xa9, 0x01, 0x20, 0xd0, 0x25, 0x20, 0xc3, 0x25, 0xa0, 0x0c,
  0xb1, 0x70, 0x48, 0xa5, 0x70, 0x18, 0x69, 0x06, 0xaa, 0xa9, 0x00, 0x65, 0x71, 0xa8, 0x68, 0x48,
  0x20, 0x06, 0x04, 0xa0, 0x0a, 0xb1, 0x70, 0xaa, 0xc8, 0xb1, 0x70, 0x85, 0x76, 0xd0, 0x03, 0x8a,
  0xf0, 0x43, 0x8a, 0xf0, 0x02, 0xe6, 0x76, 0xa0, 0x00, 0x68, 0x6a, 0xb0, 0x1d, 0x20, 0xc2, 0x25,
  0x20, 0xc2, 0x25, 0x20, 0xc2, 0x25, 0xad, 0xe5, 0xfe, 0x91, 0x74, 0xe6, 0x74, 0xd0, 0x02, 0xe6,
  0x75, 0xca, 0xd0, 0xe9, 0xc6, 0x76, 0xd0, 0xe5, 0xf0, 0x1b, 0xb1, 0x74, 0x8d, 0xe5, 0xfe, 0x20,
  0xc2, 0x25, 0x20, 0xc2, 0x25, 0x20, 0xc2, 0x25, 0xe6, 0x74, 0xd0, 0x02, 0xe6, 0x75, 0xca, 0xd0,
  0xe9, 0xc6, 0x76, 0xd0, 0xe5, 0x20, 0xcb, 0x25, 0xa9, 0x00, 0x20, 0xd0, 0x25, 0x68, 0x85, 0xf4,
  0x8d, 0x30, 0xfe, 0xa6, 0x70, 0xa4, 0x71, 0xa5, 0x72, 0x60, 0xa9, 0xc7, 0x20, 0x06, 0x04, 0x90,
  0xf9, 0x60, 0xa9, 0x87, 0x4c, 0x06, 0x04, 0x48, 0xaa, 0xa9, 0x6c, 0x20, 0xf4, 0xff, 0x68, 0xe8,
  0xd0, 0xef, 0x49, 0x01, 0xaa, 0xa9, 0x6f, 0x4c, 0xf4, 0xff, 0x00, 0x25, 0x36, 0x42, 0xfe, 0x02,
  0x30, 0x22, 0xf5, 0x3a, 0x81, 0xff, 0xe6, 0x01, 0x32, 0xaa, 0xfc, 0xf1, 0x32, 0x81, 0xff, 0xb7,
  0x20, 0x08, 0x21, 0x71, 0xf6, 0x22, 0x9f, 0xff, 0x18, 0x06, 0x21, 0x0d, 0xfe, 0x22, 0x9f, 0xff,
  0x3a, 0xaa, 0xfc, 0xc9, 0xfe, 0xff, 0xc0, 0x3a, 0x81, 0xff, 0xe6, 0x01, 0xc9, 0x4f, 0x3a, 0x81,
  0xff, 0xcb, 0x7f, 0x20, 0x12, 0x79, 0xfe, 0x1b, 0x28, 0x04, 0xcd, 0x71, 0xf6, 0xc9, 0x3a, 0x81,
  0xff, 0xcb, 0xff, 0x32, 0x81, 0xff, 0xc9, 0xcb, 0x77, 0xc2, 0xa6, 0xfe, 0xcb, 0x6f, 0xc2, 0xd9,
  0xfe, 0x79, 0xfe, 0x3d, 0x28, 0x15, 0xfe, 0x3e, 0x28, 0x1a, 0xfe, 0x3f, 0x28, 0x1f, 0xfe, 0x40,
  0x28, 0x3e, 0x3a, 0x81, 0xff, 0xcb, 0xbf, 0x32, 0x81, 0xff, 0xc9, 0x3a, 0x81, 0xff, 0xcb, 0xf7,
  0x32, 0x81, 0xff, 0xc9, 0x3a, 0x81, 0xff, 0xcb, 0xef, 0x32, 0x81, 0xff, 0xc9, 0xcd, 0xec, 0xfe,
  0x28, 0x08, 0xfe, 0x00, 0x20, 0xdc, 0x3e, 0x1f, 0x18, 0x02, 0x3e, 0x18, 0x32, 0x18, 0xff, 0xcd,
  0xf5, 0xfe, 0x06, 0x10, 0x21, 0x10, 0xff, 0x7e, 0xcd, 0x71, 0xf6, 0x23, 0x10, 0xf9, 0x18, 0xc2,
  0xcd, 0xec, 0xfe, 0x28, 0x04, 0xfe, 0x00, 0x20, 0xb9, 0xcd, 0xf5, 0xfe, 0x06, 0x06, 0x21, 0x10,
  0xff, 0x7e, 0xcd, 0x71, 0xf6, 0x23, 0x10, 0xf9, 0x06, 0x05, 0x21, 0x1b, 0xff, 0x7e, 0xcd, 0x71,
  0xf6, 0x23, 0x10, 0xf9, 0x18, 0x9c, 0xcb, 0x67, 0x20, 0x0f, 0x79, 0xd6, 0x20, 0x32, 0x21, 0xff,
  0x3a, 0x81, 0xff, 0xcb, 0xe7, 0x32, 0x81, 0xff, 0xc9, 0x79, 0xd6, 0x20, 0x32, 0x20, 0xff, 0x3e,
  0x1f, 0xcd, 0x71, 0xf6, 0x3a, 0x20, 0xff, 0xcd, 0x71, 0xf6, 0x3a, 0x21, 0xff, 0xcd, 0x71, 0xf6,
  0x3a, 0x81, 0xff, 0xe6, 0x01, 0x32, 0x81, 0xff, 0xc9, 0x79, 0xb7, 0x28, 0x06, 0xd6, 0x20, 0xcd,
  0x71, 0xf6, 0xc9, 0x3a, 0x81, 0xff, 0xe6, 0x01, 0x32, 0x81, 0xff, 0xc9, 0x3e, 0x87, 0xcd, 0x8e,
  0xf8, 0x7c, 0xfe, 0x03, 0xc9, 0x3e, 0x86, 0xcd, 0x8e, 0xf8, 0x7d, 0x32, 0x11, 0xff, 0x32, 0x1e,
  0xff, 0x7c, 0x32, 0x12, 0xff, 0x32, 0x14, 0xff, 0x32, 0x1f, 0xff, 0x3c, 0x32, 0x1a, 0xff, 0xc9,
  0x1c, 0xc4, 0x48, 0x4f, 0xc1, 0x0c, 0x1c, 0x00, 0x1f, 0x4f, 0x48, 0x0c, 0x1a, 0x1f, 0x22, 0x28,
  0x00, 0x00, 0x00, 0x28, 0x43, 0x29, 0x3b, 0x36, 0x00, 0x21, 0x2a, 0x3b, 0xc3, 0x77, 0x19, 0xc5,
  0xe5, 0x7e, 0xe6, 0x03, 0x47, 0x0e, 0x06, 0x23, 0x5e, 0x23, 0x56, 0xcd, 0x48, 0x1a, 0xe1, 0xc1,
  0xc9, 0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x01, 0xb2, 0xfa, 0x02, 0x14, 0x95, 0x00, 0x01, 0x00, 0x00, 0x3c, 0x1a, 0xff,
  0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x4c, 0xd6, 0x5e, 0xc3, 0x71,
  0xf6, 0xc3, 0xae, 0xf5, 0xc3, 0x5c, 0xf5, 0xc3, 0x3b, 0xf5, 0xc3, 0x76, 0xf4, 0xc3, 0x71, 0xf4,
  0xc3, 0xfd, 0xfa, 0xc3, 0x0e, 0xf6, 0xc3, 0x0e, 0xfe, 0xc3, 0xce, 0xf2, 0xc3, 0xa4, 0xfa, 0xc3,
  0x5e, 0xf6, 0xc3, 0x1b, 0xf6, 0xc3, 0x3f, 0xf6, 0xc3, 0xde, 0xfd, 0xc3, 0xe8, 0xf8, 0xc3, 0xd2,
  0xf9, 0xc3, 0x4e, 0xfa, 0xc3, 0xfc, 0xf9, 0xc3, 0xf0, 0xf9, 0xc3, 0x9f, 0xf9, 0xc3, 0x10, 0xfa,
  0xc3, 0x90, 0xf6, 0xfe, 0x0d, 0x20, 0x07, 0x3e, 0x0a, 0xcd, 0xee, 0xff, 0x3e, 0x0d, 0xc3, 0x71,
  0xf6, 0xc3, 0xef, 0xf8, 0xc3, 0x8e, 0xf8, 0xc3, 0xb7, 0xf6, 0xac, 0xfa, 0x70, 0xf6, 0x82, 0xfa
};

int copro_z80_read_mem(unsigned int addr) {
   if (addr >= 0x8000) {
      overlay_rom = 0;
   }
   if (overlay_rom) {
      return copro_z80_rom[addr & 0xfff];
   } else {
      return copro_z80_ram[addr & 0xffff];
   }
}

void copro_z80_write_mem(unsigned int addr, unsigned char data) {
   copro_z80_ram[addr & 0xffff] = data;
}

int copro_z80_read_io(unsigned int addr) {
   return tube_parasite_read(addr & 7);
}

void copro_z80_write_io(unsigned int addr, unsigned char data) {
   tube_parasite_write(addr & 7, data);
}

static void copro_z80_poweron_reset() {
   // Wipe memory
   memset(copro_z80_ram, 0, 0x10000);
}

static void copro_z80_reset() {
  // Log ARM performance counters
  tube_log_performance_counters();

  // Re-instate the Tube ROM on reset
  overlay_rom = 1;

  // Reset the processor
  simz80_reset();

  // Wait for rst become inactive before continuing to execute
  tube_wait_for_rst_release();

  // Reset ARM performance counters
  tube_reset_performance_counters();
}

void copro_z80_emulator()
{
   static unsigned int last_rst = 0;

   // Remember the current copro so we can exit if it changes
   int last_copro = copro;

   copro_z80_poweron_reset(); 
   copro_z80_reset();
  
   while (1)
   {
      // Execute emulator for one instruction
      simz80_execute(1);

#ifdef USE_GPU
      // temp hack to get around coherency issues
      // _invalidate_dcache_mva((void*) tube_mailbox);
#endif
      if (*tube_mailbox & ATTN_MASK) {
         unsigned int tube_mailbox_copy = *tube_mailbox;
         *tube_mailbox &= ~(ATTN_MASK | OVERRUN_MASK);
#ifdef USE_GPU
         // temp hack to get around coherency issues
         // _clean_invalidate_dcache_mva((void *) tube_mailbox);
#endif
         unsigned int intr = tube_io_handler(tube_mailbox_copy);
         unsigned int nmi = intr & 2;
         unsigned int rst = intr & 4;
         // Reset the processor on active edge of rst
         if (rst && !last_rst) {
            // Exit if the copro has changed
            if (copro != last_copro) {
               break;
            }
            copro_z80_reset();
         }
         // NMI is edge sensitive, so only check after mailbox activity
         if (nmi) {
            overlay_rom = 1;
            simz80_NMI();
         }
         last_rst = rst;
      }
      // IRQ is level sensitive, so check between every instruction
      if (tube_irq & 1) {
         // check if the emulator IRQ is enabled
         if (simz80_is_IRQ_enabled()) {
            simz80_IRQ();
         }
      }
   }
}