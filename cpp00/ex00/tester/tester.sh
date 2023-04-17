# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorbke <lorbke@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 18:09:22 by lorbke            #+#    #+#              #
#    Updated: 2023/04/17 22:02:20 by lorbke           ###   ########.fr        #
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

# takes 4 arguments:
# 1. number of the test
# 2. result of the test (0 if OK, 1 if KO)
# 3. expected output (if KO)
# 4. error message or incorrect output by the program (if KO)
echo_result()
{
	echo -n -e "$BLUE $1. $RESET"
	if [ $2 -eq 0 ]
	then
		echo -e "$GREEN [OK]$RESET"
	else
		echo -e "$RED [KO]$RESET"
		echo -e "$BLUE |$YELLOW Expected output: '$3'$RESET"
		echo -e "$BLUE |$YELLOW Actual output:   '$4'$RESET"
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
	make re > $FILE_OUT_TEST
	grep -q "c++ -Wall -Wextra -Werror -std=c++98" $FILE_OUT_TEST
	echo_result 0 $? "Check Makefile." "Flags are not correct"
}

# @note files technically not necessary, the two strings can be compared directly
test_file_cases()
{
	i=0
	while read test_str; do
		if [ "${test_str:0:2}" = "$NEXT_CASE" ]
		then
			((i++))
			eval $test_str > $FILE_OUT_TEST
			test_str=$(cat $FILE_OUT_TEST)
			read true_str
			echo "$true_str" > $FILE_OUT_TRUE
			diff $FILE_OUT_TEST $FILE_OUT_TRUE > /dev/null
			echo_result $i $? "$true_str" "$test_str"
		fi
	done < "$FILE_CASES"
}

# ______________________________________________________________________ MAIN #

print_header
test_cflags
test_file_cases
clean_files
