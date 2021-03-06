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


#include "constants.h"
#include "stdint.h"

KETJE_CONST_BYTE KeccakRhoOffsets[nrLanes] = {
    0, 1, 6, 4, 3, 4, 4, 6, 7, 4, 3, 2, 3, 1, 7, 1, 5, 7, 5, 0, 2, 2, 5, 0, 6
};

KETJE_CONST_BYTE KeccakRoundConstants[maxNrRounds] = {
    0x01,
    0x82,
    0x8a,
    0x00,
    0x8b,
    0x01,
    0x81,
    0x09,
    0x8a,
    0x88,
    0x09,
    0x0a,
    0x8b,
    0x8b,
    0x89,
    0x03,
    0x02,
    0x80,
};

KETJE_CONST_BYTE KetJr_StateTwistIndexes[25] = {
    0, 6, 12, 18, 24,
    3, 9, 10, 16, 22,
    1, 7, 13, 19, 20,
    4, 5, 11, 17, 23,
    2, 8, 14, 15, 21
};
