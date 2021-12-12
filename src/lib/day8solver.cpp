#include "day8solver.h"
#include <algorithm>
#include <iostream>

Day8Solver::Day8Solver(std::vector<Day8Entry> input) : input(input) {}

bool isUnique(const std::string &s) {
  size_t length = s.length();
  if (length == 2 || length == 3 || length == 4 || length == 7) {
    return true;
  }
  return false;
}

void sortVectorInternally(std::vector<std::string> &input) {
  for (auto &val : input) {
    sort(val.begin(), val.end());
  }
}

std::vector<std::string> decode() {
  // find the 1,4, and 7
  // There are three 5 segment numbers, 2,3,5
  // 3 should share all segments of 7. ==> 3
  // 4 and 5 should share exactly 3 segments ==> 5
  // 4 and 2 should share exactly 2 segments  ==> 2
  // 5 and 1 should share 1 segment and it should be lower right
  // 2 and 1 should share 1 segment and it should be upper right

  return std::vector<std::string>();
}

int Day8Solver::solve() {
  int numUnique = 0;
  for (const auto &entry : input) {
    for (const auto &code : entry.code) {
      numUnique += isUnique(code) ? 1 : 0;
    }
  }
  return numUnique;
}

std::vector<int> Day8Solver::solvePart2() { return std::vector<int>(); }
