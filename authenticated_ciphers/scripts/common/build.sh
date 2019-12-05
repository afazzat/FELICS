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
# Call this script to build the cipher with the given parameters
#     ./build.sh [{-h|--help}] [--version] [{-a|--architecture}=[PC|AVR|MSP|ARM]] [{-s|--scenario}=[0|1|2|3|4|5|6]] [{-v|--verbose}=[0|1]] [{-co|--compiler_options}='...']
#
#    To call from a cipher build folder use:
#        ./../../../../scripts/common/build.sh [options]
#
#    Options:
#        -h, --help
#            Display help information
#        --version
#            Display version information
#        -s, --scenario
#            Specifies which scenario is used
#                0 - cipher and debug scenario
#                1 - scenario 1a (scenario 1)
#                2 - scenario 1b (scenario 2)
#                3 - scenario 1c (scenario 3)
#                4 - scenario 2a (scenario 4)
#                5 - scenario 2b (scenario 5)
#                6 - scenario 2c (scenario 6)
#                Default: 0
#        -a, --architecture
#            Specifies which architecture is used
#                PC - binary files are build for PC
#                AVR - binary files are build for AVR device
#                MSP - binary file are build for MSP device
#                ARM - binary files are build for ARM device
#                Default: PC
#        -v, --verbose
#            Specifies if information are diplayed
#                0 - no information is diplayed
#                1 - information is diplayed
#                Default: 1
#        -co,--compiler_options
#            Specifies the compiler options
#                List of values: '-O3 --param max-unroll-times=5 --param max-unrolled-insns=100 ...'
#                Default: -O3
#
#    Examples:
#        ./../../../../scripts/common/build.sh -a=PC
#        ./../../../../scripts/common/build.sh --architecture=MSP -s=0
#         ./../../../../scripts/common/build.sh --scenario=1 -v=0
#


# Get current script path
script_path=$(dirname $0)

# Include constants files
source $script_path/../constants/constants.sh
source $script_path/../constants/common/build.sh

# Include help file
source $script_path/../help/common/build.sh

# Include validation functions
source $script_path/validate.sh

# Include check status function
source $script_path/check_status.sh

# Include version file
source $script_path/../common/version.sh


# Default values
SCRIPT_ARCHITECTURE=$SCRIPT_ARCHITECTURE_PC
SCRIPT_SCENARIO=$SCRIPT_SCENARIO_0
SCRIPT_VERBOSE=$SCRIPT_VERBOSE_ENABLED
SCRIPT_COMPILER_OPTIONS=$SCRIPT_COMPILER_OPTION_OPTIMIZE_3


# Parse script arguments
for i in "$@"
do
    case $i in
        -h|--help)
            display_help
            shift
            ;;
        --version)
            display_version
            shift
            ;;
        -a=*|--architecture=*)
            SCRIPT_ARCHITECTURE="${i#*=}"
            shift
            ;;
        -s=*|--scenario=*)
            SCRIPT_SCENARIO="${i#*=}"
            shift
            ;;
        -v=*|--verbose=*)
            SCRIPT_VERBOSE="${i#*=}"
            shift
            ;;
        -co=*|--compiler_options=*)
            SCRIPT_COMPILER_OPTIONS="${i#*=}"
            shift
            ;;
        *)
            # Unknown option
            ;;
    esac
done


if [ $SCRIPT_VERBOSE_ENABLED -eq $SCRIPT_VERBOSE ] ; then
    echo "Script settings:"
    echo -e "\t SCRIPT_ARCHITECTURE \t\t = $SCRIPT_ARCHITECTURE"
    echo -e "\t SCRIPT_SCENARIO \t\t = $SCRIPT_SCENARIO"
    echo -e "\t SCRIPT_VERBOSE \t\t = $SCRIPT_VERBOSE"
    echo -e "\t SCRIPT_COMPILER_OPTIONS \t = $SCRIPT_COMPILER_OPTIONS"
fi


# Validate inputs
validate_architecture $SCRIPT_ARCHITECTURE
validate_scenario $SCRIPT_SCENARIO


make_log_file=$SCRIPT_ARCHITECTURE$SCENARIO_NAME_PART$SCRIPT_SCENARIO$FILE_NAME_SEPARATOR$SCRIPT_MAKE_LOG

# Clean
make -f $CIPHER_MAKEFILE $MAKE_CLEAN_TARGET &> $make_log_file
check_status $? $(pwd)/$make_log_file

# Build
make -f $CIPHER_MAKEFILE ARCHITECTURE=$SCRIPT_ARCHITECTURE SCENARIO=$SCRIPT_SCENARIO COMPILER_OPTIONS="$SCRIPT_COMPILER_OPTIONS" &> $make_log_file
check_status $? $(pwd)/$make_log_file

if [ $FALSE -eq $KEEP_GENERATED_FILES ] ; then
    # Remove the log file
    rm -f $make_log_file
fi
