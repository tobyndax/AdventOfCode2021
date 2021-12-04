#include "src/lib/day4solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day4Test, ExampleInput) {
  std::string path = "tests/day4/testdata.txt";
  FileReader fileReader(path);

  std::vector<int> bingoNumbers;
  std::vector<BingoTile> bingoTiles;

  fileReader.getBingoTiles(bingoNumbers, bingoTiles);

  ASSERT_EQ(bingoNumbers.size(), 27);
  ASSERT_EQ(bingoTiles.size(), 3);
  int numbersDrawn = 0;
  int winnerScore = 0;
  bool win = false;
  for (auto &val : bingoNumbers) {
    numbersDrawn++;
    for (auto &tile : bingoTiles) {
      tile.markHit(val);
      win = tile.checkWin();
      if (win) {
        winnerScore = tile.winnerScore(val);
        break;
      }
    }
    if (win) {
      break;
    }
  }

  // Someone has to win
  ASSERT_EQ(win, true);
  ASSERT_EQ(numbersDrawn, 12);
  ASSERT_EQ(winnerScore, 4512);
}

TEST(Day4Test, Part2) {
  std::string path = "tests/day4/testdata.txt";
  FileReader fileReader(path);

  std::vector<int> bingoNumbers;
  std::vector<BingoTile> bingoTiles;

  fileReader.getBingoTiles(bingoNumbers, bingoTiles);
  Day4Solver solver;

  int winnerScore;
  int currentNumber;
  int tileSum;
  solver.solveWorstTile(bingoNumbers, bingoTiles, winnerScore, currentNumber,
                        tileSum);

  ASSERT_EQ(currentNumber, 13);
  ASSERT_EQ(tileSum, 148);
  ASSERT_EQ(winnerScore, 1924);
}
