#include "day6solver.h"
#include <iostream>
#include <numeric>

Day6Solver::Day6Solver(std::vector<int> inputData) : startState(inputData) {}

long long int Day6Solver::solve(int numDays) {
  std::vector<long long int> fishCounters(9);
  for (auto val : startState) {
    fishCounters[val]++;
  }

  for (int d = 0; d < numDays; d++) {
    long long int fishesToSpawn = fishCounters.at(0);
    fishCounters.erase(fishCounters.begin());
    fishCounters.at(6) += fishesToSpawn;
    fishCounters.push_back(fishesToSpawn);
  }

  return std::accumulate(fishCounters.begin(), fishCounters.end(), 0LL);
}
