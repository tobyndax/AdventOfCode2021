#pragma once

#include <cstdint>
#include <vector>

class Day6Solver {
public:
  Day6Solver(std::vector<int> inputData);
  long long int solve(int numDays);

private:
  std::vector<int> startState;
};
