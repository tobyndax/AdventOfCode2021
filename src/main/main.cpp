#include "src/lib/cpplib.h"
#include "src/lib/day1solver.h"
#include "src/lib/day2solver.h"
#include "src/lib/day3solver.h"
#include "src/lib/day4solver.h"
#include "src/lib/day5solver.h"
#include "src/lib/util.h"

#include <iostream>

int main() {

  int day = 5;
  if (day == 5) {

    std::string path = "src/main/day5/input.txt";
    FileReader fileReader(path);

    std::vector<std::pair<Point3D, Point3D>> data =
        fileReader.getAsLineCoordinates();
    Day5Solver solver(data);
    int dangerSum = solver.solve(true);
    std::cout << dangerSum << std::endl;
  } else if (day == 4) {
    std::string path = "src/main/day4/input.txt";
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

    std::cout << winnerScore << std::endl;

  } else if (day == 3) {
    std::string path = "src/main/day3/input.txt";
    FileReader fileReader(path);

    std::vector<std::string> data = fileReader.getAsStrings();

    Day3Solver solver(data);
    int gamma = 0;
    int epsilon = 0;
    int ogr = 0;
    int csr = 0;
    solver.solve(gamma, epsilon, ogr, csr);

    int multGE = gamma * epsilon;
    std::cout << multGE << std::endl;

    int multOC = ogr * csr;
    std::cout << multOC << std::endl;

  } else if (day == 2) {

    std::string path = "src/main/day2/input.txt";
    FileReader fileReader(path);
    std::vector<std::pair<Point3D, int>> data = fileReader.getDirectionValue();

    Day2Solver solver(data);
    Point3D position = solver.solveWithAim();

    int res = position.x * position.z;
    std::cout << res << std::endl;
  } else if (day == 1) {
    std::string path = "src/main/day1/input.txt";
    FileReader fileReader(path);
    auto ints = fileReader.getAsIntegers();

    Day1Solver solver(ints);
    int count = solver.countIncreases(3);
    std::cout << count << std::endl;
  }
  return 0;
}
