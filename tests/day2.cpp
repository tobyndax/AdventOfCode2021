#include "src/lib/day2solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(UtilTest, Day2Example) {

  int gtRes = 150;

  std::string path = "tests/day2/testdata.txt";
  FileReader fileReader(path);
  std::vector<std::pair<Point3D, int>> data = fileReader.getDirectionValue();

  Day2Solver solver(data);
  Point3D position = solver.solve();

  int res = position.x * position.z;

  ASSERT_EQ(res, gtRes) << "Day2 doesn't count increases correctly";
}

TEST(UtilTest, Day2ExampleWithAim) {

  int gtRes = 900;

  std::string path = "tests/day2/testdata.txt";
  FileReader fileReader(path);
  std::vector<std::pair<Point3D, int>> data = fileReader.getDirectionValue();

  Day2Solver solver(data);
  Point3D position = solver.solveWithAim();

  int res = position.x * position.z;

  ASSERT_EQ(res, gtRes) << "Day2 doesn't count increases correctly";
}
