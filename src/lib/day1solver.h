#pragma once

#include <vector>

class Day1Solver{
public:
  Day1Solver(std::vector<int> inputValues);
  int countIncreases();

private:
  std::vector<int> values; 
};
