#include "src/lib/util.h"

#include "gtest/gtest.h"

TEST(UtilTest, CanParseSimpleIntegers) {

  std::vector<int> gt = {2, 55, 42, 2500};

  std::string path = "tests/testData/simpleIntegers.txt";
  FileReader fileReader(path);
  std::vector<int> ints = fileReader.getAsIntegers();

  ASSERT_EQ(ints.size(), gt.size())
      << "Vectors ints and gt are of unequal length";

  for (int i = 0; i < ints.size(); ++i) {
    EXPECT_EQ(ints[i], gt[i]) << "Vectors ints and gt differ at index " << i;
  }
}

TEST(UtilTest, CanParseBinaryGrid) {
  std::string path = "tests/day3/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::string> data = fileReader.getAsStrings();

  ASSERT_EQ(data[0], "00100");
  ASSERT_EQ(data[4], "10101");
  ASSERT_EQ(12, data.size());
}
