#include "src/lib/day5solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day5Test, CalcDangerSum) {

  std::string path = "tests/day5/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::pair<Point3D, Point3D>> data =
      fileReader.getAsLineCoordinates();
  Day5Solver solver(data);
  int dangerSum = solver.solve(true);
  ASSERT_EQ(dangerSum, 5);
}

TEST(Day5Test, CalcDangerSumWithDiagonals) {

  std::string path = "tests/day5/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::pair<Point3D, Point3D>> data =
      fileReader.getAsLineCoordinates();
  Day5Solver solver(data);
  int dangerSum = solver.solve(false);
  ASSERT_EQ(dangerSum, 12);
}
