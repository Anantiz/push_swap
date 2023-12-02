#!/bin/bash

BOLD="\e[1m"
YELLOW_COLOR="\e[33m"
GREEN_COLOR="\e[32m"
LIGHT_GREEN_COLOR="\e[38;5;46m"
RED_COLOR="\e[31m"
RESET_COLOR="\e[0m"

# To be shure our push_swap is working
CHECK_COUNT=0
MAX_CHECK_COUNT=0

# The number of normal tests
NORMAL_COUNT=0
NORMAL_CHECK_COUNT=0

# The number of 125% tests
SUCCESS_COUNT=0
MAX_SUCCESS_COUNT=0

# The number of strict count
STRICT_COUNT=0
MAX_STRICT_COUNT=0

# How does the tester_data file is formed?
# You'll have the test entry's
# Then you'll have the "strict" value
# The "strict" values are the best move I succeed to do with my brain, or -1 for "no data"
# The "passed" values are to do 100% at the project (hardcoded)
# The "normal" values are just here to verify you do at least 2 points on this category (hardcoded)

function test()
{
	IFS=" " read -ra argv <<< "$2"
	argc=${#argv[@]}

	RES=$(./push_swap $2 | ./checker $2)
	if [[ $RES != "OK" ]]; then
		printf "($1) Result: test$RED_COLOR failed$RESET_COLOR\n\n"
	else
		printf "($1) Result: test$GREEN_COLOR succeed$RESET_COLOR\n"
		((CHECK_COUNT++))

		RES=$(./push_swap $2 | wc -l)
		LEVEL_OF_SUCCESS=-1

		if (( argc <= 3 )) && (( RES <= 3 )); then
			((NORMAL_COUNT++))
			((SUCCESS_COUNT++))
			LEVEL_OF_SUCCESS=1
		elif (( argc > 3 )) && (( argc <= 5 )) && (( RES <= 12 )); then
			((NORMAL_COUNT++))
			((SUCCESS_COUNT++))
			LEVEL_OF_SUCCESS=1
		elif (( argc > 5 )) && (( argc <= 100 )) && (( RES <= 700 )); then
			((SUCCESS_COUNT++))
   			((NORMAL_COUNT++))
			LEVEL_OF_SUCCESS=1
		elif (( argc > 5 )) && (( argc <= 100 )) && (( RES <= 1300 )); then
			((NORMAL_COUNT++))
			LEVEL_OF_SUCCESS=0
		elif (( argc > 100 )) && (( argc <= 500 )) && (( RES <= 5500 )); then
  			((SUCCESS_COUNT++))
     			((NORMAL_COUNT++))
			LEVEL_OF_SUCCESS=1
		elif (( argc > 100 )) && (( argc <= 500 )) && (( RES <= 10000 )); then
			((NORMAL_COUNT++))
			LEVEL_OF_SUCCESS=0
		fi
		((MAX_SUCCESS_COUNT++))
		((NORMAL_CHECK_COUNT++))

		if (( $3 >= 0 )) && (( RES > $3 )); then
			((MAX_STRICT_COUNT++))
			printf "($1) Ops: test$RED_COLOR failed$RESET_COLOR\nReceived: $RED_COLOR$RES$RESET_COLOR\nRequired: $GREEN_COLOR$3$RESET_COLOR\nTest: ./push_swap $2\n\n"
		else
			if (( $3 >= 0 )); then
				printf "($1) Ops: test$LIGHT_GREEN_COLOR succeed$RESET_COLOR\n\n"
    				((MAX_STRICT_COUNT++))
				((STRICT_COUNT++))
			elif (( LEVEL_OF_SUCCESS == 1)); then
				printf "($1) Ops: test$GREEN_COLOR succeed$RESET_COLOR\n\n"
			elif (( LEVEL_OF_SUCCESS == 0)); then
				printf "($1) Ops: test$YELLOW_COLOR succeed$RESET_COLOR\nReceived: $RED_COLOR$RES$RESET_COLOR\nTest: ./push_swap $2\n\n"
			else
				printf "($1) Ops: test$RED_COLOR failed$RED_COLOR\nReceived: $RED_COLOR$RES$RESET_COLOR\nTest: ./push_swap $2\n\n"
			fi
		fi
	fi
	((MAX_CHECK_COUNT++))
}


echo "Test with empty list"
RES=$(./push_swap > /dev/null 2>__errors.txt)
while IFS= read -r line
	do
	if [[ $line != "Error" ]]; then
		printf "(1): test$RED_COLOR failed$RESET_COLOR\n\n"
	else
		printf "(1): test$GREEN_COLOR succeed$RESET_COLOR\n\n"
		((CHECK_COUNT++))
	fi
	((MAX_CHECK_COUNT++))
done < __errors.txt

rm __errors.txt

LAST_ARGC=0
TEST_ID=1
while read line; do
	IFS=" " read -ra argv <<< "$line"
	argc=${#argv[@]}
	argc=$((argc - 1))
	if (( LAST_ARGC != argc )); then
		printf $BOLD 
		printf "Test with $argc elements$RESET_COLOR\n"
		LAST_ARGC=$((argc))
		TEST_ID=1
	fi
	sliced=${argv[@]:0:argc}
	test $TEST_ID "$sliced" ${argv[argc]}
	((TEST_ID++))
done < tester_data

if ((CHECK_COUNT<MAX_CHECK_COUNT)); then
	printf "[VAL]\t$RED_COLOR$CHECK_COUNT/$MAX_CHECK_COUNT$RESET_COLOR tests succedded\n"
else
	printf "[VAL]\t$GREEN_COLOR$CHECK_COUNT/$MAX_CHECK_COUNT$RESET_COLOR tests succedded\n"
fi

if ((STRICT_COUNT<MAX_STRICT_COUNT)); then
	printf "[OPS]\t$RED_COLOR$STRICT_COUNT/$MAX_STRICT_COUNT$RESET_COLOR strict tests succedded\n"
else
	printf "[OPS]\t$GREEN_COLOR$STRICT_COUNT/$MAX_STRICT_COUNT$RESET_COLOR strict tests succedded\n"
fi

if ((SUCCESS_COUNT<MAX_SUCCESS_COUNT)); then
	printf "[OPS]\t$RED_COLOR$SUCCESS_COUNT/$MAX_SUCCESS_COUNT$RESET_COLOR for the 100%% tests succedded\n"
else
	printf "[OPS]\t$GREEN_COLOR$SUCCESS_COUNT/$MAX_SUCCESS_COUNT$RESET_COLOR for the 100%% tests succedded\n"
fi

if ((NORMAL_COUNT<NORMAL_CHECK_COUNT)); then
	printf "[OPS]\t$RED_COLOR$NORMAL_COUNT/$NORMAL_CHECK_COUNT$RESET_COLOR normal tests succedded (2pts)\n"
else
	printf "[OPS]\t$GREEN_COLOR$NORMAL_COUNT/$NORMAL_CHECK_COUNT$RESET_COLOR normal tests succedded (2pts)\n"
fi
