#include "src/lib/util.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Point3D &Point3D::operator+=(const Point3D &other) {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
}

const Point3D Point3D::operator*(const Point3D &other) const {
  Point3D result = *this;
  result.x *= other.x;
  result.y *= other.y;
  result.z *= other.z;
  return result;
}

const Point3D Point3D::operator*(const int &other) const {
  Point3D result = *this;
  result.x *= other;
  result.y *= other;
  result.z *= other;
  return result;
}

FileReader::FileReader(std::string path) {

  std::ifstream file(path);
  std::string str;
  while (std::getline(file, str)) {
    rawText += str;
    rawText += '\n';
  }
}

std::vector<int> FileReader::getAsIntegers() {

  std::vector<int> result;
  auto ss = std::stringstream{rawText};

  for (std::string line; std::getline(ss, line, '\n');) {
    result.push_back(std::stoi(line));
  }
  return result;
}

std::vector<std::pair<Point3D, int>> FileReader::getDirectionValue() {

  std::vector<std::pair<Point3D, int>> result;
  auto ss = std::stringstream{rawText};

  for (std::string line; std::getline(ss, line, '\n');) {
    std::string dir;
    int value;
    std::istringstream is(line);
    is >> dir >> value;

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    if (dir == "left") {
      y += 1.0;
    } else if (dir == "right") {
      y -= 1.0;
    } else if (dir == "up") {
      z -= 1.0; // note removes depth
    } else if (dir == "down") {
      z += 1.0;
    } else if (dir == "forward") {
      x += 1.0;
    } else if (dir == "backward") {
      x -= 1.0;
    }
    result.push_back(std::pair<Point3D, int>(Point3D(x, y, z), value));
  }
  return result;
}

std::vector<std::string> FileReader::getAsStrings() {

  std::vector<std::string> results;
  auto ss = std::stringstream{rawText};

  for (std::string line; std::getline(ss, line, '\n');) {
    results.push_back(line);
  }
  return results;
}
