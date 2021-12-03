#include "day3solver.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

#define toDigit(c) (c - '0')

void Day3Solver::solve(int &gamma, int &epsilon) {

  int entryLength = data[0].length();
  std::vector<int> counters(data[0].length());

  for (auto val : data) {
    std::istringstream is(val);
    for (int i = 0; i < entryLength; i++) {
      char c0;
      is >> c0;
      counters[i] += toDigit(c0);
    }
  }

  int N = data.size();
  std::vector<int> gammaNum(data[0].length());
  std::vector<int> epsilonNum(data[0].length());
  for (int i = 0; i < entryLength; i++) {
    gammaNum[i] = counters[i] > N / 2 ? 1 : 0;
    epsilonNum[i] = counters[i] > N / 2 ? 0 : 1;
  }

  std::reverse(gammaNum.begin(), gammaNum.end());
  std::reverse(epsilonNum.begin(), epsilonNum.end());
  for (int i = 0; i < entryLength; i++) {
    gamma += std::pow(2, i) * gammaNum[i];
    epsilon += std::pow(2, i) * epsilonNum[i];
  }
}
