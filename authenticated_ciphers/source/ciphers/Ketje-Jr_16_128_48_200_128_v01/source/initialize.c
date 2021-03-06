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
#include <stdio.h>

#include "cipher.h"
#include "constants.h"
#include "keccak_round.h"
#include "ketje_state_add_byte.h"
#include "ketje_state_overwrite.h"


void Initialize(uint8_t *state, const uint8_t *key, const uint8_t *nonce) {
    /* Add initialization code here */
    uint8_t smallData[1];
    uint8_t keyPackSizeInBits;

    keyPackSizeInBits = 8 * (KEY_SIZE + 2);

    if ((keyPackSizeInBits + 8 * NONCE_SIZE + 2) < 8 * STATE_SIZE) {
        /* Key pack */
        smallData[0] = KEY_SIZE + 2;

        KetJr_StateOverwrite(state, 0, smallData, 1);
        KetJr_StateOverwrite(state, 1, (uint8_t *)key, KEY_SIZE);

        /* Key size in FELICS must be a multiple of 8 */
        smallData[0] = 0x01;

        KetJr_StateOverwrite(state, 1 + KEY_SIZE, smallData, 1);

        KetJr_StateOverwrite(state, 1 + KEY_SIZE + 1, (uint8_t *)nonce,
                NONCE_SIZE);

        KetJr_StateOverwrite(state, 1 + KEY_SIZE + 1 + NONCE_SIZE, smallData,
                1);

        KetJr_StateAddByte(state, 0x80, STATE_SIZE - 1);

        KeccakP200_Permute_Nrounds(state, Ket_StartRounds);
    }
}
