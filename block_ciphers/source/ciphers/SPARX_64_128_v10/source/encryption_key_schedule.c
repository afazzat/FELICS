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

#include "cipher.h"
#include "constants.h"

#include "speckey.h"


void RunEncryptionKeySchedule(uint8_t *key, uint8_t *roundKeys)
{
    uint8_t i;
    uint16_t temp[2];
    uint16_t reg[8];

    uint16_t *Key = (uint16_t *)key;
    uint16_t *RoundKeys = (uint16_t *)roundKeys;


    reg[0] = Key[0];
    reg[1] = Key[1];

    reg[2] = Key[2];
    reg[3] = Key[3];

    reg[4] = Key[4];
    reg[5] = Key[5];

    reg[6] = Key[6];
    reg[7] = Key[7];

    /* set round key */
    RoundKeys[0] = reg[0];
    RoundKeys[1] = reg[1];
    RoundKeys[2] = reg[2];
    RoundKeys[3] = reg[3];
    RoundKeys[4] = reg[4];
    RoundKeys[5] = reg[5];


    for(i = 1; i < 2 * NUMBER_OF_ROUNDS; i++)
    {
        temp[1] = reg[7] + i;
        temp[0] = reg[6];

        reg[7] = reg[5];
        reg[6] = reg[4];

        speckey(reg + 0, reg + 1);

        reg[5] = reg[3] + reg[1];
        reg[4] = reg[2] + reg[0]; 

        reg[3] = reg[1];
        reg[2] = reg[0];
        
        reg[1] = temp[1];
        reg[0] = temp[0];
        
        /* set round key */
        RoundKeys[6 * i + 0] = reg[0];
        RoundKeys[6 * i + 1] = reg[1];
        RoundKeys[6 * i + 2] = reg[2];
        RoundKeys[6 * i + 3] = reg[3];
        RoundKeys[6 * i + 4] = reg[4];
        RoundKeys[6 * i + 5] = reg[5];
    }


    RoundKeys[6 * 2 * NUMBER_OF_ROUNDS + 0] = reg[6];
    RoundKeys[6 * 2 * NUMBER_OF_ROUNDS + 1] = reg[7] + 2 * NUMBER_OF_ROUNDS;

    speckey(&reg[0], &reg[1]);

    RoundKeys[6 * 2 * NUMBER_OF_ROUNDS + 2] = reg[0];
    RoundKeys[6 * 2 * NUMBER_OF_ROUNDS + 3] = reg[1];
}
