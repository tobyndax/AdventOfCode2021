#pragma once

#include "day4solver.h"

#include <iostream>
#include <string>
#include <vector>

class Point3D {
public:
  Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

  double x;
  double y;
  double z;

  Point3D &operator+=(const Point3D &other);
  const Point3D operator*(const Point3D &other) const;
  const Point3D operator*(const int &other) const;
  friend bool operator==(const Point3D &first, const Point3D &second);
  friend bool operator!=(const Point3D &first, const Point3D &second);
};

class FileReader {
public:
  FileReader(std::string path);
  std::vector<int> getAsIntegers();
  std::vector<std::pair<Point3D, int>> getDirectionValue();
  std::vector<std::string> getAsStrings();
  void getBingoTiles(std::vector<int> &bingoNumbers,
                     std::vector<BingoTile> &bingoTiles);
  std::vector<std::pair<Point3D, Point3D>> getAsLineCoordinates();

private:
  std::string rawText = "";
  std::string replaceSubString(const std::string &input,
                               const std::string &substr,
                               const std::string &replacement);
};
