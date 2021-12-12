#pragma once

#include <string>
#include <vector>

class Day8Entry {
public:
  Day8Entry(std::vector<std::string> signalSequences,
            std::vector<std::string> code)
      : signalSequences(signalSequences), code(code){

                                          };
  std::vector<std::string> signalSequences;
  std::vector<std::string> code;
};

class Day8Solver {
public:
  Day8Solver(std::vector<int> input);
  int solve();

private:
  std::vector<int> input;
};
