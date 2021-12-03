#pragma once

#include <string>
#include <vector>

class Day3Solver {
public:
  Day3Solver(std::vector<std::string> data) : data(data) {}
  void solve(int &gamma, int &epsilon, int &ogr, int &csr);

private:
  int ogrSolver(std::vector<std::string> recData, int position,
                bool keepCommon);
  std::vector<std::string> data;
};
