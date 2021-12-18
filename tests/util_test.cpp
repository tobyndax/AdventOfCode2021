#include "src/lib/util.h"

#include "gtest/gtest.h"

TEST(UtilTest, CanParseSimpleIntegers) {

  std::vector<int> gt = {2, 55, 42, 2500};

  std::string path = "tests/testData/simpleIntegers.txt";
  FileReader fileReader(path);
  std::vector<int> ints = fileReader.getAsIntegers();

  ASSERT_EQ(ints.size(), gt.size())
      << "Vectors ints and gt are of unequal length";

  for (size_t i = 0; i < ints.size(); ++i) {
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

TEST(UtilTest, CanParseBingo) {
  std::string path = "tests/day4/testdata.txt";
  FileReader fileReader(path);

  std::vector<int> bingoNumbers;
  std::vector<BingoTile> bingoTiles;

  fileReader.getBingoTiles(bingoNumbers, bingoTiles);

  ASSERT_EQ(bingoNumbers.size(), 27);
  ASSERT_EQ(bingoTiles.size(), 3);
}

TEST(UtilTest, CanParseLineCoordinates) {

  std::string path = "tests/day5/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::pair<Point3D, Point3D>> data =
      fileReader.getAsLineCoordinates();
  int numEntries = data.size();

  ASSERT_EQ(numEntries, 10);

  Point3D p0Start(0, 9, 0);
  Point3D p0End(5, 9, 0);
  ASSERT_EQ(data[0].first, p0Start);
  ASSERT_EQ(data[0].second, p0End);

  Point3D p4Start(7, 0, 0);
  Point3D p4End(7, 4, 0);
  ASSERT_EQ(data[4].first, p4Start);
  ASSERT_EQ(data[4].second, p4End);

  Point3D p9Start(5, 5, 0);
  Point3D p9End(8, 2, 0);
  ASSERT_EQ(data[9].first, p9Start);
  ASSERT_EQ(data[9].second, p9End);

  int maxX = 0;
  int maxY = 0;

  for (auto val : data) {
    int x0 = val.first.x;
    int x1 = val.first.x;
    int y0 = val.second.y;
    int y1 = val.second.y;

    maxX = std::max(maxX, std::max(x0, x1));
    maxY = std::max(maxY, std::max(y0, y1));
  }

  ASSERT_EQ(maxX, 9);
  ASSERT_EQ(maxY, 9);
}

TEST(UtilTest, CanSplitText) {
  std::string first, second;
  FileReader::splitStringSingle("128 | 132", " | ", first, second);

  ASSERT_EQ("128", first);
  ASSERT_EQ("132", second);
}
