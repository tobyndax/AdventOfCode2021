#pragma once

#include <vector>

class Day7Solver {
public:
  Day7Solver(std::vector<int> input);
  void solve(int &position, int &fuelCost);
  void solvePart2(int &position, int &fuelCost);
  int calcCost(int steps);

private:
  std::vector<int> input;
};
