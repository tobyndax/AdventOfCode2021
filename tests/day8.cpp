#include "src/lib/day8solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day8Test, ParseInput) {
  FileReader fileReader("tests/day8/testdata.txt");
  auto data = fileReader.getSignalCodes();
  ASSERT_EQ(data.size(), 10);
  ASSERT_EQ(data[4].signals[1], "fbg");
  ASSERT_EQ(data[4].code[1], "egdcabf");
  ASSERT_EQ(data[4].signals.size(), 10);
  ASSERT_EQ(data[4].code.size(), 4);
}

TEST(Day8Test, Part1) {

  FileReader fileReader("tests/day8/testdata.txt");
  auto data = fileReader.getSignalCodes();
  Day8Solver solver = Day8Solver(data);

  int numUnique = solver.solve();

  ASSERT_EQ(numUnique, 26);
}

TEST(Day8Test, Part2) {

  std::vector<int> gt{8394, 9781, 1197, 9361, 4873,
                      8418, 4548, 1625, 8717, 4315};
  FileReader fileReader("tests/day8/testdata.txt");
  auto data = fileReader.getSignalCodes();
  Day8Solver solver = Day8Solver(data);

  std::vector<int> codes = solver.solvePart2();

  ASSERT_EQ(codes.size(), 10);
  for (int i = 0; i < codes.size(); i++) {
    ASSERT_EQ(codes[i], gt[i]);
  }
}
