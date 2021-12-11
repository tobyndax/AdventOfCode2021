#include "src/lib/day7solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day7Test, Input) {
  FileReader fileReader("tests/day7/testdata.txt");
  std::vector<int> gt = {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
  std::vector<int> data = fileReader.getAsIntegers(',');
  for (size_t i = 0; i < data.size(); i++) {
    ASSERT_EQ(data[i], gt[i]);
  }
}

TEST(Day7Test, Part1) {
  FileReader fileReader("tests/day7/testdata.txt");
  std::vector<int> data = fileReader.getAsIntegers(',');

  int gtResult = 37;
  int gtPosition = 2;

  int pos, fuelCost;
  Day7Solver solver(data);
  solver.solve(pos, fuelCost);

  ASSERT_EQ(fuelCost, gtResult);
  ASSERT_EQ(pos, gtPosition);
}

TEST(Day7Test, Part2) {
  FileReader fileReader("tests/day7/testdata.txt");
  std::vector<int> data = fileReader.getAsIntegers(',');

  int gtResult = 168;
  int gtPosition = 5;

  int pos, fuelCost;
  Day7Solver solver(data);
  solver.solvePart2(pos, fuelCost);

  ASSERT_EQ(fuelCost, gtResult);
  ASSERT_EQ(pos, gtPosition);
}
