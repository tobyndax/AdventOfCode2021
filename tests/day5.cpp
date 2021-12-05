#include "src/lib/day5solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day5Test, CanConstructGrid) {

  std::string path = "tests/day5/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::pair<Point3D, Point3D>> data =
      fileReader.getAsLineCoordinates();
  Day5Solver solver(data);
  int dangerSum = solver.solve();
  ASSERT_EQ(dangerSum, 5);
}
