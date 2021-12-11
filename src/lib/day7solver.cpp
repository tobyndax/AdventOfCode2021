#include "day7solver.h"
#include <algorithm>
#include <iostream>
#include <limits>

Day7Solver::Day7Solver(std::vector<int> input) : input(input) {}

int median(std::vector<int> v) {
  if (v.empty()) {
    return 0.0;
  }
  auto n = v.size() / 2;
  nth_element(v.begin(), v.begin() + n, v.end());
  auto med = v[n];
  if (!(v.size() & 1)) { // If the set size is even
    auto max_it = max_element(v.begin(), v.begin() + n);
    med = (*max_it + med) / 2.0;
  }
  return med;
}

int Day7Solver::calcCost(int steps) { return steps * (steps + 1) / 2; }

void Day7Solver::solvePart2(int &position, int &fuelCost) {

  position = 0;
  fuelCost = std::numeric_limits<int>::max();
  int minPos = *std::min_element(input.begin(), input.end());
  int maxPos = *std::max_element(input.begin(), input.end());
  for (int i = minPos; i < maxPos; i++) {
    int localFuelCost = 0;
    for (const auto &val : input) {
      int cost = calcCost(abs(val - i));
      localFuelCost += abs(cost);
    }
    position = localFuelCost < fuelCost ? i : position;
    fuelCost = localFuelCost < fuelCost ? localFuelCost : fuelCost;
  }
}

void Day7Solver::solve(int &position, int &fuelCost) {
  position = 0;
  fuelCost = 0;
  position = median(input);

  for (const auto &val : input) {
    fuelCost += abs(position - val);
  }
}
