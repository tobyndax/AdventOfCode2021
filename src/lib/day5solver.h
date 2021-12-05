#pragma once
#include "util.h"

class Day5Solver {
public:
  Day5Solver(std::vector<std::pair<Point3D, Point3D>> inputData);
  int solve();

private:
  void getRequiredGridSize(int &maxX, int &maxY);
  std::vector<std::pair<Point3D, Point3D>> inputData;
};
