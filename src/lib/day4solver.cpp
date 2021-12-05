#include "day4solver.h"

void Day4Solver::solveWorstTile(std::vector<int> bingoNumbers,
                                std::vector<BingoTile> bingoTiles,
                                int &winnerScore, int &currentNumber,
                                int &tileSum) {
  bool win = false;
  for (auto &val : bingoNumbers) {
    currentNumber = val;
    for (auto it = bingoTiles.begin(); it != bingoTiles.end();) {
      auto &tile = *it;
      tile.markHit(val);
      win = tile.checkWin();
      if (win) {
        tileSum = tile.winnerScore(1);
        winnerScore = tile.winnerScore(val);
        it = bingoTiles.erase(it);
      } else {
        it++;
      }
    }
    if (bingoTiles.size() == 0) {
      break;
    }
  }
}
