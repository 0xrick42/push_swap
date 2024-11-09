#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m'

# Check if program exists
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found!${NC}"
    make re
fi

# Check if checker exists
if [ ! -f "./checker_linux" ]; then
    echo -e "${RED}Error: checker_linux not found!${NC}"
    exit 1
fi

chmod +x checker_linux

# Identity test
test_identity() {
    printf "${BLUE}Identity test${NC}\n"
    printf "Test with no args: "
    ./push_swap >output
    if [ -s output ]; then
        printf "${RED}KO${NC}\n"
    else
        printf "${GREEN}OK${NC}\n"
    fi

    printf "Test with empty string: "
    ./push_swap "" >output
    if [ -s output ]; then
        printf "${RED}KO${NC}\n"
    else
        printf "${GREEN}OK${NC}\n"
    fi

    printf "Test with already sorted list: "
    ./push_swap 1 2 3 4 5 >output
    if [ -s output ]; then
        printf "${RED}KO${NC}\n"
    else
        printf "${GREEN}OK${NC}\n"
    fi
}

# Error handling
test_errors() {
    printf "\n${BLUE}Error handling${NC}\n"
    printf "Non numeric input: "
    ./push_swap 1 2 3 a b >output 2>error
    if grep -q "Error" error; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi

    printf "Duplicate numbers: "
    ./push_swap 1 2 2 4 5 >output 2>error
    if grep -q "Error" error; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi

    printf "Number bigger than INT_MAX: "
    ./push_swap 1 2 2147483648 4 >output 2>error
    if grep -q "Error" error; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi

    printf "Number smaller than INT_MIN: "
    ./push_swap 1 2 -2147483649 4 >output 2>error
    if grep -q "Error" error; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi
}

# Simple tests
test_simple() {
    printf "\n${BLUE}Simple tests${NC}\n"

    # Test arrays
    TESTS=(
        "2 1"
        "1 3 2"
        "2 3 1"
        "3 2 1"
        "4 3 2 1"
        "1 5 2 4 3"
        "5 4 3 2 1"
    )

    for ARG in "${TESTS[@]}"; do
        printf "Testing with: $ARG\n"
        OPERATIONS=$(./push_swap $ARG | wc -l)
        RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
        printf "Operations: $OPERATIONS - Result: "
        if [ "$RESULT" = "OK" ]; then
            printf "${GREEN}OK${NC}\n"
        else
            printf "${RED}KO${NC}\n"
        fi
    done
}

# Random number tests
test_random() {
    printf "\n${BLUE}Random number tests${NC}\n"
    SIZES=(3 5 100 500)
    TESTS=(10 10 5 5)
    MAX_OPS=(3 12 700 5500)

    for i in ${!SIZES[@]}; do
        SIZE=${SIZES[$i]}
        NUM_TESTS=${TESTS[$i]}
        MAX=${MAX_OPS[$i]}

        printf "\nTesting size ${SIZE} (${NUM_TESTS} tests, max ops: ${MAX})\n"
        SUM=0
        MAX_FOUND=0
        MIN_FOUND=999999

        for ((j=1; j<=${NUM_TESTS}; j++)); do
            ARG=$(seq 1 $SIZE | shuf | tr '\n' ' ')
            OPERATIONS=$(./push_swap $ARG | wc -l)
            RESULT=$(./push_swap $ARG | ./checker_linux $ARG)

            # Update statistics
            SUM=$((SUM + OPERATIONS))
            [ $OPERATIONS -gt $MAX_FOUND ] && MAX_FOUND=$OPERATIONS
            [ $OPERATIONS -lt $MIN_FOUND ] && MIN_FOUND=$OPERATIONS

            printf "Test $j: "
            if [ "$RESULT" = "OK" ] && [ $OPERATIONS -le $MAX ]; then
                printf "${GREEN}OK${NC} "
            else
                printf "${RED}KO${NC} "
            fi
            printf "($OPERATIONS ops)\n"
        done

        AVG=$((SUM / NUM_TESTS))
        printf "\nStats for size $SIZE:\n"
        printf "Average: $AVG\n"
        printf "Min: $MIN_FOUND\n"
        printf "Max: $MAX_FOUND\n"
    done
}

# Special cases
test_special() {
    printf "\n${BLUE}Special cases${NC}\n"

    # Test with negative numbers
    printf "Testing with negative numbers:\n"
    ARG="-1 -3 -2"
    OPERATIONS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    printf "ARG=\"$ARG\" - Ops: $OPERATIONS - Result: "
    if [ "$RESULT" = "OK" ]; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi

    # Test with mixed positive and negative
    printf "\nTesting with mixed numbers:\n"
    ARG="-2 1 -3 4 -5 6"
    OPERATIONS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
    printf "ARG=\"$ARG\" - Ops: $OPERATIONS - Result: "
    if [ "$RESULT" = "OK" ]; then
        printf "${GREEN}OK${NC}\n"
    else
        printf "${RED}KO${NC}\n"
    fi
}

# Run all tests
printf "${YELLOW}Starting push_swap tests...${NC}\n\n"
test_identity
test_errors
test_simple
test_random
test_special
rm -f output error

printf "\n${YELLOW}Tests completed!${NC}\n"
