#include "day8solver.h"
#include <algorithm>
#include <cassert>
#include <iostream>

Day8Solver::Day8Solver(std::vector<Day8Entry> input) : input(input) {}

bool isUnique(const std::string &s) {
  size_t length = s.length();
  if (length == 2 || length == 3 || length == 4 || length == 7) {
    return true;
  }
  return false;
}

int countPairs(std::string s1, std::string s2) {

  int freq1[26] = {0};
  int freq2[26] = {0};
  int i, count = 0;
  for (i = 0; i < s1.length(); i++)
    freq1[s1[i] - 'a']++;

  for (i = 0; i < s2.length(); i++)
    freq2[s2[i] - 'a']++;

  for (i = 0; i < 26; i++)
    count += (std::min(freq1[i], freq2[i]));

  return count;
}

void sortVectorInternally(std::vector<std::string> &input) {
  for (auto &val : input) {
    sort(val.begin(), val.end());
  }
}

std::string getOne(std::vector<std::string> signals) {
  for (const auto &val : signals) {
    if (val.length() == 2) {
      return val;
    }
  }
  assert(false);
}

std::string getFour(std::vector<std::string> signals) {
  for (const auto &val : signals) {
    if (val.length() == 4) {
      return val;
    }
  }
  assert(false);
}

std::string getSeven(std::vector<std::string> signals) {
  for (const auto &val : signals) {
    if (val.length() == 3) {
      return val;
    }
  }
  assert(false);
}

std::string getEight(std::vector<std::string> signals) {
  for (const auto &val : signals) {
    if (val.length() == 7) {
      return val;
    }
  }
  assert(false);
}

std::string getThree(std::vector<std::string> signals, std::string seven) {
  for (const auto &val : signals) {
    if (countPairs(val, seven) == 3) {
      return val;
    }
  }
  assert(false);
}

std::string getTwo(std::vector<std::string> signals, std::string four) {
  for (const auto &val : signals) {
    if (countPairs(val, four) == 2) {
      return val;
    }
  }
  assert(false);
}

std::string getFive(std::vector<std::string> signals, std::string four,
                    std::string three) {
  for (const auto &val : signals) {
    if (countPairs(val, four) == 3 && countPairs(val, three) != 5) {
      return val;
    }
  }
  assert(false);
}

std::string getSix(std::vector<std::string> signals, std::string one) {
  for (const auto &val : signals) {
    if (countPairs(val, one) == 1) {
      return val;
    }
  }
  assert(false);
}

std::string getNine(std::vector<std::string> signals, std::string four) {
  for (const auto &val : signals) {
    if (countPairs(val, four) == 4) {
      return val;
    }
  }
  assert(false);
}

std::string getZero(std::vector<std::string> signals, std::string five) {
  for (const auto &val : signals) {
    if (countPairs(val, five) == 4) {
      return val;
    }
  }
  assert(false);
}

std::vector<std::string> getSegsOfLength(std::vector<std::string> signals,
                                         int length) {
  std::vector<std::string> lenSegs;
  for (const auto &val : signals) {
    if (val.length() == length) {
      lenSegs.push_back(val);
    }
  }
  return lenSegs;
}

void decode(Day8Entry &entry, std::vector<std::string> &sequences) {
  // find the 1,4, and 7
  // There are three 5 segment numbers, 2,3,5
  // 3 should share all segments of 7. ==> 3
  // 4 and 5 should share exactly 3 segments ==> 5
  // 4 and 2 should share exactly 2 segmentsresize==> 2
  // 5 and 1 should share 1 segment and it should be lower right
  // 2 and 1 should share 1 segment and it should be upper right
  sequences.resize(10);
  for (int i = 0; i < sequences.size(); i++) {
    sequences.at(i) = "notSet";
  }
  sortVectorInternally(entry.signals);
  auto signals = entry.signals;
  sequences[1] = getOne(signals);
  sequences[4] = getFour(signals);
  sequences[7] = getSeven(signals);
  sequences[8] = getEight(signals);

  std::vector<std::string> fiveSegmentSignals = getSegsOfLength(signals, 5);
  sequences[3] = getThree(fiveSegmentSignals, sequences[7]);
  sequences[2] = getTwo(fiveSegmentSignals, sequences[4]);
  sequences[5] = getFive(fiveSegmentSignals, sequences[4], sequences[3]);

  std::vector<std::string> sixSegmentSignals = getSegsOfLength(signals, 6);
  sequences[6] =
      getSix(sixSegmentSignals,
             sequences[1]); // should have exactly one in common with 1
  sequences[9] = getNine(sixSegmentSignals,
                         sequences[4]); // should have all in common with 4
  sequences[0] =
      getZero(sixSegmentSignals,
              sequences[5]); // should have exactly 4 in common with 5.
}

int Day8Solver::solve() {
  int numUnique = 0;
  for (const auto &entry : input) {
    for (const auto &code : entry.code) {
      numUnique += isUnique(code) ? 1 : 0;
    }
  }
  return numUnique;
}

int match(std::string &input, std::vector<std::string> &translation) {
  for (int i = 0; i < translation.size(); i++) {
    if (translation[i] == input) {
      return i;
    }
  }
}

int convert(std::vector<std::string> &code,
            std::vector<std::string> &translation) {
  sortVectorInternally(code);
  int res = 1000 * match(code[0], translation) +
            100 * match(code[1], translation) +
            10 * match(code[2], translation) + match(code[3], translation);
  return res;
}

std::vector<int> Day8Solver::solvePart2() {
  std::vector<int> result;
  for (auto &entry : input) {
    std::vector<std::string> translation;
    decode(entry, translation);
    int value = convert(entry.code, translation);
    result.push_back(value);
  }
  return result;
}
