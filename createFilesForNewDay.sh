#!/bin/bash

echo "Creating files for Day $1"
mkdir "src/main/day$1"
touch "src/main/day$1/input.txt"
mkdir "tests/day$1"
touch "tests/day$1/testdata.txt"
touch "tests/day$1.cpp"
touch "src/lib/day$1solver.h"
touch "src/lib/day$1solver.cpp"
