#include "day2solver.h"

Point3D Day2Solver::solve() {

  Point3D accum(0, 0, 0);
  for (auto val : data) {
    accum += val.first * val.second;
  }
  return accum;
}

Point3D Day2Solver::solveWithAim() {

  double aim = 0.0;

  Point3D accum(0, 0, 0);
  for (auto val : data) {
    aim += val.first.z * val.second;
    accum.x += val.first.x * val.second;
    accum.z += val.first.x * val.second * aim;
  }
  return accum;
}
