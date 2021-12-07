#include "src/lib/day6solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day6Test, Input) {
  FileReader fileReader("tests/day6/testdata.txt");
  std::vector<int> gt = {3, 4, 3, 1, 2};
  std::vector<int> data = fileReader.getAsIntegers(',');
  for (size_t i = 0; i < data.size(); i++) {
    ASSERT_EQ(data[i], gt[i]);
  }
}

TEST(Day6Test, Part1) {
  FileReader fileReader("tests/day6/testdata.txt");

  auto data = fileReader.getAsIntegers(',');
  Day6Solver solver(data);
  long long int numFish = solver.solve(18);
  ASSERT_EQ(numFish, 26);
  numFish = solver.solve(80);
  ASSERT_EQ(numFish, 5934);
}

TEST(Day6Test, Part2) {
  FileReader fileReader("tests/day6/testdata.txt");

  auto data = fileReader.getAsIntegers(',');
  Day6Solver solver(data);
  long long int numFish = solver.solve(256);
  ASSERT_EQ(numFish, 26984457539);
}
