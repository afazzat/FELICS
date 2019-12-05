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

#include "test_vectors.h"


/*
 *
 * Test vectors
 *
 */
//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x78, 0xd9, 0xe4, 0xd4, 0xc8, 0x19, 0x16, 0x8b, 0xdc, 0x4b, 0x77, 0x39, 0x28, 0xf6, 0xad, 0xa8};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedKey[KEY_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0xfb, 0xee, 0x91, 0xe2, 0x72, 0x4e, 0xd9, 0xf5, 0x6c, 0xe9, 0xe5, 0xfd, 0xb7, 0x46, 0x22, 0xb6};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x6c, 0x03, 0x66, 0xb5, 0x7a, 0xd2, 0x78, 0x67, 0x46, 0x4d, 0xff, 0x40, 0xa3, 0x9c, 0xfe, 0x60};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedKey[KEY_SIZE] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x25, 0xcd, 0x60, 0x2b, 0x18, 0xba, 0x63, 0xad, 0x48, 0x76, 0x96, 0xf8, 0x08, 0x4c, 0xcc, 0xd3};

//const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};
//const uint8_t expectedKey[KEY_SIZE] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
//const uint8_t expectedCiphertext[BLOCK_SIZE] = {0x99, 0xfc, 0xc9, 0x61, 0x91, 0xaa, 0xcb, 0x46, 0x93, 0x53, 0x17, 0x25, 0x58, 0xa5, 0x6a, 0x6e};

/* paper */
const uint8_t expectedPlaintext[BLOCK_SIZE] = {0x23, 0x01, 0x67, 0x45, 0xab, 0x89, 0xef, 0xcd, 0xdc, 0xfe, 0x98, 0xba, 0x54, 0x76, 0x10, 0x32};
const uint8_t expectedKey[KEY_SIZE] = {0x11, 0x00, 0x33, 0x22, 0x55, 0x44, 0x77, 0x66, 0x99, 0x88, 0xbb, 0xaa, 0xdd, 0xcc, 0xff, 0xee};
const uint8_t expectedCiphertext[BLOCK_SIZE] = {0xee, 0x1c, 0x40, 0x75, 0xbf, 0x7d, 0xd8, 0x23, 0xee, 0xe0, 0x97, 0x15, 0x28, 0xf4, 0xd8, 0x52};
