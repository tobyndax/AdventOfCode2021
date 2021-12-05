#include "day5solver.h"

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

int Day5Solver::solve() {
  int maxX = 0;
  int maxY = 0;
  getRequiredGridSize(maxX, maxY);
  DataGrid grid = DataGrid(maxX + 1, maxY + 1);
  for (auto val : inputData) {
    int x0 = val.first.x;
    int x1 = val.second.x;
    int y0 = val.first.y;
    int y1 = val.second.y;
    if (x0 != x1 && y0 != y1) { // diagonal, ignore for now
      continue;
    }
    if (x0 > x1 || y0 > y1) {
      std::swap(x0, x1);
      std::swap(y0, y1);
    }
    if (x0 != x1) {
      for (int x = x0; x <= x1; x++) {
        grid.set(x, y0, grid.get(x, y0) + 1);
      }
    }
    if (y0 != y1) {
      for (int y = y0; y <= y1; y++) {
        grid.set(x0, y, grid.get(x0, y) + 1);
      }
    }
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
