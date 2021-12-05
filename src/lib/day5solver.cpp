#include "day5solver.h"

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

Day5Solver::Day5Solver(std::vector<std::pair<Point3D, Point3D>> inputData)
    : inputData(inputData) {}

void Day5Solver::getRequiredGridSize(int &maxX, int &maxY) {

  for (auto val : inputData) {
    int x0 = val.first.x;
    int x1 = val.first.x;
    int y0 = val.second.y;
    int y1 = val.second.y;

    maxX = std::max(maxX, std::max(x0, x1));
    maxY = std::max(maxY, std::max(y0, y1));
  }
}

int Day5Solver::solve(bool skipDiagonals) {
  int maxX = 0;
  int maxY = 0;
  getRequiredGridSize(maxX, maxY);
  DataGrid grid = DataGrid(maxX + 1, maxY + 1);
  for (auto val : inputData) {
    int x0 = val.first.x;
    int x1 = val.second.x;
    int y0 = val.first.y;
    int y1 = val.second.y;
    if (skipDiagonals && x0 != x1 && y0 != y1) {
      continue;
    }
    int dx = sgn(x1 - x0);
    int dy = sgn(y1 - y0);
    int x = x0;
    int y = y0;
    grid.set(x, y, grid.get(x, y) + 1);
    do {
      x += dx;
      y += dy;
      grid.set(x, y, grid.get(x, y) + 1);
    } while (x != x1 || y != y1);
  }
  int dangerSum = 0;
  std::vector<int> rawData = grid.getData();
  for (auto val : rawData) {
    if (val > 1) {
      dangerSum++;
    }
  }
  return dangerSum;
}
