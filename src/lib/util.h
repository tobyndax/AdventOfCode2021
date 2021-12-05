#pragma once

#include "day4solver.h"

#include <iostream>
#include <string>
#include <vector>

#define RST "\x1B[0m"
#define KRED "\x1B[31m"
#define FRED(x) KRED x RST

class Point3D {
public:
  Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

  double x;
  double y;
  double z;

  Point3D &operator+=(const Point3D &other);
  const Point3D operator*(const Point3D &other) const;
  const Point3D operator*(const int &other) const;
};

class FileReader {
public:
  FileReader(std::string path);
  std::vector<int> getAsIntegers();
  std::vector<std::pair<Point3D, int>> getDirectionValue();
  std::vector<std::string> getAsStrings();
  void getBingoTiles(std::vector<int> &bingoNumbers,
                     std::vector<BingoTile> &bingoTiles);

private:
  std::string rawText = "";
};
