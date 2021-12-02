#pragma once

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
};

class FileReader {
public:
  FileReader(std::string path);
  std::vector<int> getAsIntegers();
  std::vector<std::pair<Point3D, int>> getDirectionValue();

private:
  std::string rawText = "";
};
