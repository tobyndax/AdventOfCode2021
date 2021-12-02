#pragma once

#include "util.h"

#include <vector>

class Day2Solver {
public:
  Day2Solver(const std::vector<std::pair<Point3D, int>> &data) : data(data) {}
  Point3D solve();
  Point3D solveWithAim();

private:
  std::vector<std::pair<Point3D, int>> data;
};
