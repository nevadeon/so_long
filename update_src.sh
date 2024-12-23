#!/bin/bash

SRC_DIR="./src"
TEST_DIR="./tests"

SRC_FILES=$(find "$SRC_DIR" -type f -name "*.c")
TEST_FILES=$(find "$TEST_DIR" -type f -name "*.c")

SRC_LINE="SRC := $(echo "$SRC_FILES" | sed 's|^\./||' | tr '\n' ' ')"
TEST_SRC_LINE="TEST_SRC := $(echo "$TEST_FILES" | sed 's|^\./||' | tr '\n' ' ')"

printf "$SRC_LINE\n"
printf "$TEST_SRC_LINE\n"

# Remplacer la ligne SRC dans le Makefile
sed -i "/^SRC :=/c\\$SRC_LINE" "Makefile"
sed -i "/^TEST_SRC :=/c\\$TEST_SRC_LINE" "Makefile"
