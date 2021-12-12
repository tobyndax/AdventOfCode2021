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
  Day8Solver(std::vector<int> input);
  int solve();

private:
  std::vector<int> input;
};
