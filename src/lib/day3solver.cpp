#include "day3solver.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>

#define toDigit(c) (c - '0')

std::vector<int> getCounts(std::vector<std::string> data) {
  int entryLength = data[0].length();
  std::vector<int> counters(entryLength);

  for (auto val : data) {
    std::istringstream is(val);
    for (int i = 0; i < entryLength; i++) {
      char c0;
      is >> c0;
      counters[i] += toDigit(c0);
    }
  }
  return counters;
}

int vectorToDecimal(std::vector<int> number) {
  std::reverse(number.begin(), number.end());
  int dec = 0;
  for (size_t i = 0; i < number.size(); i++) {
    dec += std::pow(2, i) * number[i];
  }
  return dec;
}

int Day3Solver::ogrSolver(std::vector<std::string> recData, int position,
                          bool keepCommon) {

  for (auto val : recData) {
  }

  if (recData.size() == 1) {
    return vectorToDecimal(getCounts(recData));
  } else {
    size_t count = getCounts(recData)[position];
    char toKeep;
    int targetCount = std::ceil(recData.size() / 2.0);
    if (count >= targetCount) { // keep if a 1 at position
      toKeep = keepCommon ? '1' : '0';
    } else { // keep if a 0 at position
      toKeep = keepCommon ? '0' : '1';
    }
    std::vector<std::string> newData;
    for (size_t i = 0; i < recData.size(); i++) {
      if (recData[i].at(position) == toKeep) {
        newData.push_back(recData[i]);
      }
    }
    return ogrSolver(newData, ++position, keepCommon);
  }
}

void Day3Solver::solve(int &gamma, int &epsilon, int &ogr, int &csr) {

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

  for (int i = 0; i < entryLength; i++) {
    gamma = vectorToDecimal(gammaNum);
    epsilon = vectorToDecimal(epsilonNum);
  }

  ogr = ogrSolver(data, 0, true);
  csr = ogrSolver(data, 0, false);
}
