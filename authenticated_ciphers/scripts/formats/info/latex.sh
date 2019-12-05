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
# Functions to generate LaTeX data table
#


# Add LaTeX table header
# Parameters:
#     $1 - the output file
function add_latex_table_header()
{
    local output_file=$1


    # Clear output
    echo -n "" > $output_file
}


# Add LaTeX table row
# Parameters:
#     $1 - the output file
#     $2 - the cipher name
#     $3 - the cipher block size
#     $4 - the cipher key size
#     $5 - the cipher implementation version
#     $6 - the cipher implementation info
#     $7 - the cipher implementation authors
function add_latex_table_row()
{
    local output_file=$1
    local cipher_name=$2
    local cipher_block_size=$3
    local cipher_key_size=$4
    local cipher_nonce_size=$5
    local cipher_state_size=$6
    local cipher_tag_size=$7
    local cipher_implementation_version=$8
    local cipher_implementation_info=$9
    local cipher_implementation_authors=${10}


    printf "%s" "$cipher_name" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_block_size" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_key_size" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_nonce_size" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_state_size" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_tag_size" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_implementation_version" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_implementation_info" >> $output_file
    printf " " >> $output_file
    printf "%s" "$cipher_implementation_authors" >> $output_file
    printf " " >> $output_file
    printf "\n" >> $output_file
}


# Add LaTeX table footer
# Parameters:
#     $1 - the output file
function add_latex_table_footer()
{
    local output_file=$1
}
