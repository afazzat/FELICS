/*
 *
 * University of Luxembourg
 * Laboratory of Algorithmics, Cryptology and Security (LACS)
 *
 * FELICS - Fair Evaluation of Lightweight Cryptographic Systems
 *
 * Copyright (C) 2017 University of Luxembourg
 *
 * Written in 2017 by Virat Shejwalkar <virat.shejwalkar@uni.lu>
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

#define TEST 0
/*
 *
 * Test vectors
 *
 */

#if(TEST == 0)
/* Test vectors for normal testing  */
const uint8_t expectedMessage[TEST_MESSAGE_SIZE] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07}; /* Initial message value */
const uint8_t expectedDigest[DIGEST_SIZE] = {0x62, 0x24, 0x93, 0x9a, 0x79, 0xf5, 0xf5, 0x93}; /* Digest value after finalization */

/* Expected state values */

const uint8_t expectedPostInitializationState[STATE_SIZE] = {0x75, 0x64, 0x71, 0x73, 0x61, 0x68, 0x69, 0x74, 0x65, 0x66, 0x6e, 0x65, 0x6d, 0x7f, 0x61, 0x6b, 0x61, 0x73, 0x67, 0x6d, 0x61, 0x62, 0x7f, 0x6b, 0x7b, 0x6c, 0x7e, 0x72, 0x6e, 0x69, 0x6b, 0x7b}; /* State value after initialization */
const uint8_t expectedPostUpdateState[STATE_SIZE] = {0x0f, 0xa5, 0xd9, 0x23, 0x40, 0x12, 0xd9, 0x89, 0x52, 0x70, 0x18, 0xfb, 0xa5, 0x1b, 0xd6, 0xb1, 0xad, 0xbc, 0x76, 0xa4, 0xdb, 0x25, 0x3c, 0x92, 0x0d, 0x86, 0x93, 0xa5, 0x26, 0x93, 0xb6, 0x2d}; /* State value after Update */
const uint8_t expectedPostFinalizationState[STATE_SIZE] = {0x68, 0x52, 0x5c, 0xfc, 0xf6, 0x90, 0x8e, 0xad, 0x02, 0x89, 0xaa, 0xc8, 0xcc, 0xe1, 0xc7, 0x45, 0x26, 0x92, 0xe8, 0x5a, 0x24, 0xcd, 0xfe, 0x51, 0x2e, 0x6d, 0x8d, 0xf4, 0x67, 0x49, 0x42, 0x2a}; /* State value after finalization */

#elif(TEST == 1)
/* Test vectors for padding testing */
const uint8_t expectedMessage[TEST_MESSAGE_SIZE] = {0x00, 0x11, 0x0f, 0xa3, 0xcc}; /* Initial message value */
const uint8_t expectedDigest[DIGEST_SIZE] = {0x83, 0xb6, 0x9a, 0xca, 0x47, 0xdd, 0x95, 0xf6}; /* Digest value after finalization */

/* Expected state values */

const uint8_t expectedPostInitializationState[STATE_SIZE] = {0x75, 0x64, 0x71, 0x73, 0x61, 0x68, 0x69, 0x74, 0x65, 0x66, 0x6e, 0x65, 0x6d, 0x7f, 0x61, 0x6b, 0x61, 0x73, 0x67, 0x6d, 0x61, 0x62, 0x7f, 0x6b, 0x7b, 0x6c, 0x7e, 0x72, 0x6e, 0x69, 0x6b, 0x7b}; /* State value after initialization */
const uint8_t expectedPostUpdateState[STATE_SIZE] = {0xf3, 0x99, 0x3d, 0xf5, 0x40, 0x30, 0x4a, 0x92, 0xc0, 0x79, 0x6a, 0x8a, 0x01, 0xe7, 0xd3, 0x44, 0xd6, 0x08, 0x90, 0x6c, 0xe8, 0x3d, 0x9c, 0xc7, 0xb3, 0x43, 0x68, 0x7a, 0x40, 0x36, 0x1c, 0xb2}; /* State value after Update */
const uint8_t expectedPostFinalizationState[STATE_SIZE] = {0x9f, 0xda, 0x82, 0x97, 0xe5, 0xd4, 0xe7, 0x42, 0x0d, 0xa9, 0x9c, 0x65, 0xa3, 0xa8, 0x1a, 0xac, 0x21, 0x64, 0xe0, 0x32, 0xa3, 0x13, 0x14, 0x36, 0x30, 0xa1, 0x64, 0x0a, 0xa2, 0xb2, 0x7c, 0x2e}; /* State value after finalization */

#endif