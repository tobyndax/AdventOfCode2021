#pragma once

#include <string>
#include <vector>

class Day3Solver {
public:
  Day3Solver(std::vector<std::string> data) : data(data) {}
  void solve(int &gamma, int &epsilon);

private:
  std::vector<std::string> data;
};
