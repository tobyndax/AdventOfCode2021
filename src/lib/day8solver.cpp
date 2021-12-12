#include "day8solver.h"
#include <iostream>

Day8Solver::Day8Solver(std::vector<Day8Entry> input) : input(input) {}

bool isUnique(const std::string &s) {
  size_t length = s.length();
  if (length == 2 || length == 3 || length == 4 || length == 7) {
    return true;
  }
  return false;
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
