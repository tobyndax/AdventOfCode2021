#pragma once

#include "util.h"
#include <vector>

class Day4Solver {
public:
  Day4Solver(){};
  void solveWorstTile(std::vector<int> bingoNumbers,
                      std::vector<BingoTile> bingoTiles, int &winnerScore,
                      int &currentNumber, int &tileSum);
};
