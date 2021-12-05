#!/bin/bash

echo "Creating files for Day $1"
mkdir "src/main/day$1"
git add "src/main/day$1"
touch "src/main/day$1/input.txt"
git add "src/main/day$1/input.txt"
mkdir "tests/day$1"
git add "tests/day$1"
touch "tests/day$1/testdata.txt"
git add "tests/day$1/testdata.txt"
touch "tests/day$1.cpp"
git add "tests/day$1.cpp"
touch "src/lib/day$1solver.h"
git add "src/lib/day$1solver.h"
touch "src/lib/day$1solver.cpp"
git add "src/lib/day$1solver.cpp"

cat <<EOT >> "src/lib/day$1solver.h"
#pragma once

class Day$1Solver{
public:
  Day$1Solver();
private:

};
EOT

cat <<EOT >> "src/lib/day$1solver.cpp"
#include "day$1solver.h"

Day$1Solver::Day$1Solver(){

}

EOT

cat <<EOT >> "tests/day$1.cpp"
#include "src/lib/day$1solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day$1Test, Part1) {
  ASSERT_EQ(false, true);
}
EOT
