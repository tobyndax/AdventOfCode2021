#include "src/lib/day6solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day6Test, Input) {
  FileReader fileReader("tests/day6/testdata.txt");
  std::vector<int> gt = {3, 4, 3, 1, 2};
  std::vector<int> data = fileReader.getAsIntegers(',');
  for (int i = 0; i < data.size(); i++) {
    ASSERT_EQ(data[i], gt[i]);
  }
}

TEST(Day6Test, Part1) {
  FileReader fileReader("tests/day6/testdata.txt");

  fileReader.getAsIntegers(',');
  ASSERT_EQ(false, true);
}
