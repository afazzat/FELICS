/*
 *
 * University of Luxembourg
 * Laboratory of Algorithmics, Cryptology and Security (LACS)
 *
 * FELICS - Fair Evaluation of Lightweight Cryptographic Systems
 *
 * Copyright (C) 2016 University of Luxembourg
 *
 * Written in 2016 by Daniel Dinu <dumitru-daniel.dinu@uni.lu>
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
/*const uint8_t expectedKey[KEY_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedIV[IV_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0x76, 0xb8, 0xe0, 0xad, 0xa0, 0xf1, 0x3d, 0x90, 
	0x40, 0x5d, 0x6a, 0xe5, 0x53, 0x86, 0xbd, 0x28, 
	0xbd, 0xd2, 0x19, 0xb8, 0xa0, 0x8d, 0xed, 0x1a, 
	0xa8, 0x36, 0xef, 0xcc, 0x8b, 0x77, 0x0d, 0xc7, 
	0xda, 0x41, 0x59, 0x7c, 0x51, 0x57, 0x48, 0x8d, 
	0x77, 0x24, 0xe0, 0x3f, 0xb8, 0xd8, 0x4a, 0x37, 
	0x6a, 0x43, 0xb8, 0xf4, 0x15, 0x18, 0xa1, 0x1c, 
	0xc3, 0x87, 0xb6, 0x69, 0xb2, 0xee, 0x65, 0x86};*/

/*const uint8_t expectedKey[KEY_SIZE] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const uint8_t expectedIV[IV_SIZE] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0xd9, 0xbf, 0x3f, 0x6b, 0xce, 0x6e, 0xd0, 0xb5, 
	0x42, 0x54, 0x55, 0x77, 0x67, 0xfb, 0x57, 0x44, 
	0x3d, 0xd4, 0x77, 0x89, 0x11, 0xb6, 0x06, 0x05, 
	0x5c, 0x39, 0xcc, 0x25, 0xe6, 0x74, 0xb8, 0x36, 
	0x3f, 0xea, 0xbc, 0x57, 0xfd, 0xe5, 0x4f, 0x79, 
	0x0c, 0x52, 0xc8, 0xae, 0x43, 0x24, 0x0b, 0x79, 
	0xd4, 0x90, 0x42, 0xb7, 0x77, 0xbf, 0xd6, 0xcb, 
	0x80, 0xe9, 0x31, 0x27, 0x0b, 0x7f, 0x50, 0xeb};*/

/*const uint8_t expectedKey[KEY_SIZE] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const uint8_t expectedIV[IV_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0xf6, 0xb8, 0x98, 0x41, 0x2f, 0x4a, 0xb0, 0x61, 
	0x94, 0x31, 0x67, 0xc1, 0xe2, 0x3e, 0xfa, 0xa2, 
	0xba, 0x98, 0xe3, 0x45, 0xa0, 0x93, 0xf0, 0xb0, 
	0x6d, 0xa1, 0x3b, 0xff, 0xdb, 0xd4, 0xb2, 0xc7, 
	0x66, 0xdd, 0x10, 0x70, 0x34, 0xb4, 0x58, 0x2a, 
	0x2e, 0xf4, 0x2c, 0x5e, 0x1e, 0xa4, 0x75, 0xf2, 
	0xfe, 0xa4, 0x77, 0xa1, 0x0a, 0x9f, 0x1d, 0x75, 
	0xb3, 0x63, 0x52, 0x43, 0xb2, 0x50, 0x6b, 0x32};*/

/*const uint8_t expectedKey[KEY_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedIV[IV_SIZE] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0xe2, 0xf6, 0xbe, 0x72, 0x47, 0x57, 0xb1, 0x09, 
	0x5a, 0x95, 0xbc, 0xd2, 0xb7, 0xb4, 0x37, 0xfe, 
	0xb7, 0x43, 0x27, 0x34, 0x6c, 0xda, 0xe6, 0x3a, 
	0x54, 0x91, 0xc6, 0xe1, 0xaf, 0x2c, 0x2c, 0x3d, 
	0x24, 0x0d, 0x1e, 0xe2, 0xbc, 0x9b, 0x84, 0xff, 
	0xf1, 0x35, 0xbc, 0xc6, 0x94, 0xf5, 0x20, 0x28, 
	0x79, 0x29, 0xce, 0x11, 0xc0, 0x37, 0xdf, 0x20, 
	0xf8, 0xd9, 0x35, 0x3d, 0x03, 0xf4, 0x87, 0xd4};*/

/*const uint8_t expectedKey[KEY_SIZE] = {
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
	0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88,
	0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};
const uint8_t expectedIV[IV_SIZE] = {
	0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0xca, 0x76, 0x42, 0x3d, 0x1a, 0x88, 0xe4, 0x12, 
	0xd2, 0x45, 0xb3, 0xf7, 0x7e, 0x7e, 0x76, 0x2c, 
	0x6c, 0x53, 0x80, 0x5c, 0x3b, 0x3b, 0x82, 0x23, 
	0x8e, 0x44, 0xa5, 0x8a, 0xea, 0x15, 0x49, 0x43, 
	0x5d, 0xb7, 0x38, 0x69, 0x80, 0x6e, 0xd0, 0x05, 
	0xb2, 0x09, 0xcc, 0x5f, 0xa0, 0x8e, 0xb9, 0x89, 
	0x82, 0x0b, 0x17, 0x42, 0x62, 0xd1, 0x85, 0xbf, 
	0xd2, 0xd7, 0xe4, 0x19, 0x5f, 0x99, 0xe0, 0x89};*/

const uint8_t expectedKey[KEY_SIZE] = {
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
	0xff, 0xee, 0xdd, 0xcc, 0xbb, 0xaa, 0x99, 0x88,
	0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00};
const uint8_t expectedIV[IV_SIZE] = {
	0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
const uint8_t expectedPlaintext[TEST_STREAM_SIZE] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const uint8_t expectedCiphertext[TEST_STREAM_SIZE] = {
	0xae, 0x95, 0xde, 0x9a, 0xbc, 0xaf, 0x00, 0x7e, 
	0x91, 0xfc, 0x46, 0xe1, 0x64, 0xfe, 0x5e, 0x15, 
	0xaf, 0xea, 0x0a, 0x24, 0xb4, 0xeb, 0xed, 0xa8, 
	0x88, 0x31, 0xbb, 0xea, 0xac, 0x52, 0x3b, 0x3a, 
	0xd2, 0x00, 0x2d, 0x75, 0x59, 0x6b, 0x0b, 0x35, 
	0x38, 0xd8, 0x1d, 0x9b, 0x7c, 0xbb, 0xa5, 0x3f, 
	0x87, 0xba, 0x30, 0x8b, 0x8d, 0x5a, 0x55, 0x35, 
	0x3d, 0x1f, 0x13, 0x3b, 0xb2, 0x46, 0x53, 0xad};
