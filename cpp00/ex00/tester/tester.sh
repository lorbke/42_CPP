# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 18:09:22 by lorbke            #+#    #+#              #
#    Updated: 2023/04/17 20:10:20 by lorbke           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# __________________________________________________________________ VARIABLES #

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
RESET='\033[0m'

NEXT_CASE="./"
FILE_CASES="tester/testcases.txt"
FILE_OUT_TEST="tester/test_out"
FILE_OUT_TRUE="tester/true_out"


# ______________________________________________________________________ UTILS #

print_header()
{
	echo -e "$YELLOW# ---------------------------------------------------------------------------- #"
	echo "| TESTER                                                                       |"
	echo -e "# ---------------------------------------------------------------------------- #$RESET"
}

# takes 3 arguments:
# 1. number of the test
# 2. result of the test (0 if OK, 1 if KO)
# 3. error message or incorrect output by the program (if KO)
echo_result()
{
	echo -n -e "$BLUE $1. $RESET"
	if [ $2 -eq 0 ]
	then
		echo -e "$GREEN [OK]$RESET"
	else
		echo -n -e "$RED [KO]:$RESET"
		echo -e "$RED $3$RESET"
	fi
}

clean_files()
{
	rm -f $FILE_OUT_TEST
	rm -f $FILE_OUT_TRUE
}

# _____________________________________________________________________ TESTS #

test_cflags()
{
	make re | grep -q "c++ -Wall -Wextra -Werror -std=c++98"
	echo_result 0 $? "Flags are not correct"
}

test_cases()
{
	i=0
	while read line; do
		if [ "${line:0:2}" = "$NEXT_CASE" ]
		then
			((i++))
			eval $line > $FILE_OUT_TEST
			read line
			echo "$line" > $FILE_OUT_TRUE
			diff $FILE_OUT_TEST $FILE_OUT_TRUE > /dev/null
			echo_result $i $? "$line"
		fi
	done < "$FILE_CASES"
}

print_header
test_cflags
test_cases
#clean_files
