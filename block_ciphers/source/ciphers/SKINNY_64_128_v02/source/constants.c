/*
 * SKINNY-64-128
 * @Time 2018
 * @Author luopeng(lo_robert@126.com)
 */

/*
 *
 * University of Luxembourg
 * Laboratory of Algorithmics, Cryptology and Security (LACS)
 *
 * FELICS - Fair Evaluation of Lightweight Cryptographic Systems
 *
 * Copyright (C) 2015 University of Luxembourg
 *
 * Written in 2015 by Daniel Dinu <dumitru-daniel.dinu@uni.lu>
 *
 * This file is part of FELICS.
 *
 * FELICS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * FELICS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>

#include "constants.h"


/*
 *
 * Cipher constants
 *
 */
/* Replace with the cipher constants definition */
// 0xc, 0x6, 0x9, 0x0, 0x1, 0xa, 0x2, 0xb, 0x3, 0x8, 0x5, 0xd, 0x4, 0xe, 0x7, 0xf
SBOX_BYTE SBOX[256] = {
    0xcc, 0xc6, 0xc9, 0xc0, 0xc1, 0xca, 0xc2, 0xcb, 0xc3, 0xc8, 0xc5, 0xcd, 0xc4, 0xce, 0xc7, 0xcf,
    0x6c, 0x66, 0x69, 0x60, 0x61, 0x6a, 0x62, 0x6b, 0x63, 0x68, 0x65, 0x6d, 0x64, 0x6e, 0x67, 0x6f,
    0x9c, 0x96, 0x99, 0x90, 0x91, 0x9a, 0x92, 0x9b, 0x93, 0x98, 0x95, 0x9d, 0x94, 0x9e, 0x97, 0x9f,
    0x0c, 0x06, 0x09, 0x00, 0x01, 0x0a, 0x02, 0x0b, 0x03, 0x08, 0x05, 0x0d, 0x04, 0x0e, 0x07, 0x0f,
    0x1c, 0x16, 0x19, 0x10, 0x11, 0x1a, 0x12, 0x1b, 0x13, 0x18, 0x15, 0x1d, 0x14, 0x1e, 0x17, 0x1f,
    0xac, 0xa6, 0xa9, 0xa0, 0xa1, 0xaa, 0xa2, 0xab, 0xa3, 0xa8, 0xa5, 0xad, 0xa4, 0xae, 0xa7, 0xaf,
    0x2c, 0x26, 0x29, 0x20, 0x21, 0x2a, 0x22, 0x2b, 0x23, 0x28, 0x25, 0x2d, 0x24, 0x2e, 0x27, 0x2f,
    0xbc, 0xb6, 0xb9, 0xb0, 0xb1, 0xba, 0xb2, 0xbb, 0xb3, 0xb8, 0xb5, 0xbd, 0xb4, 0xbe, 0xb7, 0xbf,
    0x3c, 0x36, 0x39, 0x30, 0x31, 0x3a, 0x32, 0x3b, 0x33, 0x38, 0x35, 0x3d, 0x34, 0x3e, 0x37, 0x3f,
    0x8c, 0x86, 0x89, 0x80, 0x81, 0x8a, 0x82, 0x8b, 0x83, 0x88, 0x85, 0x8d, 0x84, 0x8e, 0x87, 0x8f,
    0x5c, 0x56, 0x59, 0x50, 0x51, 0x5a, 0x52, 0x5b, 0x53, 0x58, 0x55, 0x5d, 0x54, 0x5e, 0x57, 0x5f,
    0xdc, 0xd6, 0xd9, 0xd0, 0xd1, 0xda, 0xd2, 0xdb, 0xd3, 0xd8, 0xd5, 0xdd, 0xd4, 0xde, 0xd7, 0xdf,
    0x4c, 0x46, 0x49, 0x40, 0x41, 0x4a, 0x42, 0x4b, 0x43, 0x48, 0x45, 0x4d, 0x44, 0x4e, 0x47, 0x4f,
    0xec, 0xe6, 0xe9, 0xe0, 0xe1, 0xea, 0xe2, 0xeb, 0xe3, 0xe8, 0xe5, 0xed, 0xe4, 0xee, 0xe7, 0xef,
    0x7c, 0x76, 0x79, 0x70, 0x71, 0x7a, 0x72, 0x7b, 0x73, 0x78, 0x75, 0x7d, 0x74, 0x7e, 0x77, 0x7f,
    0xfc, 0xf6, 0xf9, 0xf0, 0xf1, 0xfa, 0xf2, 0xfb, 0xf3, 0xf8, 0xf5, 0xfd, 0xf4, 0xfe, 0xf7, 0xff,};

// 0x3, 0x4, 0x6, 0x8, 0xc, 0xa, 0x1, 0xe, 0x9, 0x2, 0x5, 0x7, 0x0, 0xb, 0xd, 0xf
SBOX_BYTE INV_SBOX[256] = {
    0x33, 0x34, 0x36, 0x38, 0x3c, 0x3a, 0x31, 0x3e, 0x39, 0x32, 0x35, 0x37, 0x30, 0x3b, 0x3d, 0x3f,
    0x43, 0x44, 0x46, 0x48, 0x4c, 0x4a, 0x41, 0x4e, 0x49, 0x42, 0x45, 0x47, 0x40, 0x4b, 0x4d, 0x4f,
    0x63, 0x64, 0x66, 0x68, 0x6c, 0x6a, 0x61, 0x6e, 0x69, 0x62, 0x65, 0x67, 0x60, 0x6b, 0x6d, 0x6f,
    0x83, 0x84, 0x86, 0x88, 0x8c, 0x8a, 0x81, 0x8e, 0x89, 0x82, 0x85, 0x87, 0x80, 0x8b, 0x8d, 0x8f,
    0xc3, 0xc4, 0xc6, 0xc8, 0xcc, 0xca, 0xc1, 0xce, 0xc9, 0xc2, 0xc5, 0xc7, 0xc0, 0xcb, 0xcd, 0xcf,
    0xa3, 0xa4, 0xa6, 0xa8, 0xac, 0xaa, 0xa1, 0xae, 0xa9, 0xa2, 0xa5, 0xa7, 0xa0, 0xab, 0xad, 0xaf,
    0x13, 0x14, 0x16, 0x18, 0x1c, 0x1a, 0x11, 0x1e, 0x19, 0x12, 0x15, 0x17, 0x10, 0x1b, 0x1d, 0x1f,
    0xe3, 0xe4, 0xe6, 0xe8, 0xec, 0xea, 0xe1, 0xee, 0xe9, 0xe2, 0xe5, 0xe7, 0xe0, 0xeb, 0xed, 0xef,
    0x93, 0x94, 0x96, 0x98, 0x9c, 0x9a, 0x91, 0x9e, 0x99, 0x92, 0x95, 0x97, 0x90, 0x9b, 0x9d, 0x9f,
    0x23, 0x24, 0x26, 0x28, 0x2c, 0x2a, 0x21, 0x2e, 0x29, 0x22, 0x25, 0x27, 0x20, 0x2b, 0x2d, 0x2f,
    0x53, 0x54, 0x56, 0x58, 0x5c, 0x5a, 0x51, 0x5e, 0x59, 0x52, 0x55, 0x57, 0x50, 0x5b, 0x5d, 0x5f,
    0x73, 0x74, 0x76, 0x78, 0x7c, 0x7a, 0x71, 0x7e, 0x79, 0x72, 0x75, 0x77, 0x70, 0x7b, 0x7d, 0x7f,
    0x03, 0x04, 0x06, 0x08, 0x0c, 0x0a, 0x01, 0x0e, 0x09, 0x02, 0x05, 0x07, 0x00, 0x0b, 0x0d, 0x0f,
    0xb3, 0xb4, 0xb6, 0xb8, 0xbc, 0xba, 0xb1, 0xbe, 0xb9, 0xb2, 0xb5, 0xb7, 0xb0, 0xbb, 0xbd, 0xbf,
    0xd3, 0xd4, 0xd6, 0xd8, 0xdc, 0xda, 0xd1, 0xde, 0xd9, 0xd2, 0xd5, 0xd7, 0xd0, 0xdb, 0xdd, 0xdf,
	0xf3, 0xf4, 0xf6, 0xf8, 0xfc, 0xfa, 0xf1, 0xfe, 0xf9, 0xf2, 0xf5, 0xf7, 0xf0, 0xfb, 0xfd, 0xff,};


ROUND_CONST_BYTE RC[36] = {
	0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3E, 0x3D, 0x3B, 0x37, 0x2F,
	0x1E, 0x3C, 0x39, 0x33, 0x27, 0x0E, 0x1D, 0x3A, 0x35, 0x2B,
	0x16, 0x2C, 0x18, 0x30, 0x21, 0x02, 0x05, 0x0B, 0x17, 0x2E,
	0x1C, 0x38, 0x31, 0x23, 0x06, 0x0D, };
