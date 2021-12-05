#include "src/lib/day5solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day5Test, CanConstructGrid) {

  std::string path = "tests/day5/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::pair<Point3D, Point3D>> data =
      fileReader.getAsLineCoordinates();

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
}
