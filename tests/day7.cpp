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

TEST(Day7Test, Part1) {}
