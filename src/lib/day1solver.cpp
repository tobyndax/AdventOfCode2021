#include "day1solver.h"
#include <cmath>
#include <iostream>
#include <limits>

Day1Solver::Day1Solver(std::vector<int> inputValues) : values(inputValues) {}

int Day1Solver::countIncreases(int windowSize) {
  int prevValue = std::numeric_limits<int>::max();
  int count = 0;

  int windowRadius = std::floor(windowSize / 2.0);

  for (unsigned int i = windowRadius; i < values.size() - windowRadius; i++) {
    int sum = 0;
    for (int j = -windowRadius; j < windowRadius + 1; j++) {
      sum += values.at(i + j);
    }

    if (sum > prevValue) {
      count++;
    }
    prevValue = sum;
  }
  return count;
}
