#!/bin/bash

#
# University of Luxembourg
# Laboratory of Algorithmics, Cryptology and Security (LACS)
#
# FELICS - Fair Evaluation of Lightweight Cryptographic Systems
#
# Copyright (C) 2015-2019 University of Luxembourg
#
# Author: Luan Cardoso (2019), Virat Shejwalkar (2017),
#         Daniel Dinu (2015), and Yann Le Corre (2015)
#
# This file is part of FELICS.
#
# FELICS is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# FELICS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#

#
# Constants
#

CONSTANTS_SOURCE_FILE=./../source/constants.h
CIPHER_MAKEFILE=./../../../common/cipher.mk
MAKE_FILE_LOG=make.log

SUCCESS_EXIT_CODE=0

CIPHER_ELF_FILE=cipher.elf
RESULT_FILE=result.out

SKIP_STATE_CHECK_TRUE=SKIP_STATE_CHECK_TRUE
SKIP_STATE_CHECK_FALSE=SKIP_STATE_CHECK_FALSE

WRONG=WRONG!
CORRECT=CORRECT!

EXPECTED_WRONG_COUNT=0
EXPECTED_CORRECT_COUNT=17

ARM_SERIAL_TERMINAL=./../../../../../common/scripts/arm/arm_serial_terminal.py

MSPDEBUG_CHECK_CIPHER_COMMANDS_FILE=./../../../../../common/scripts/msp/check_cipher.cmd
