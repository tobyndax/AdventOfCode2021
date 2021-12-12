#pragma once

#include <string>
#include <vector>

class Day8Entry {
public:
  Day8Entry(std::vector<std::string> signals, std::vector<std::string> code)
      : signals(signals), code(code){

                          };
  std::vector<std::string> signals;
  std::vector<std::string> code;
};

class Day8Solver {
public:
  Day8Solver(std::vector<Day8Entry> input);
  int solve();
  std::vector<int> solvePart2();

private:
  std::vector<Day8Entry> input;
};
