#include "src/lib/util.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

DataGrid::DataGrid(const int width, const int height)
    : width(width), height(height) {
  data.resize(width * height, 0);
}

void DataGrid::set(const int x, const int y, const int value) {
  data[x + y * width] = value;
}

int DataGrid::get(const int x, const int y) { return data[x + y * width]; }

void DataGrid::print() {
  for (int j = 0; j < height; j++) {
    for (int i = 0; i < width; i++) {
      std::cout << get(i, j);
    }
    std::cout << std::endl;
  }
}

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

bool operator==(const Point3D &first, const Point3D &second) {
  return first.x == second.x && first.y == second.y && first.z == second.z;
}
bool operator!=(const Point3D &first, const Point3D &second) {
  return !(first == second);
}

FileReader::FileReader(std::string path) {

  std::ifstream file(path);
  std::string str;
  while (std::getline(file, str)) {
    rawText += str;
    rawText += '\n';
  }
}

std::vector<int> FileReader::getAsIntegers(char separator) {

  std::vector<int> result;
  auto ss = std::stringstream{rawText};

  for (std::string line; std::getline(ss, line, separator);) {
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

void FileReader::getBingoTiles(std::vector<int> &bingoNumbers,
                               std::vector<BingoTile> &bingoTiles) {

  std::stringstream fullStream(rawText);
  std::string firstLine;
  std::getline(fullStream, firstLine, '\n');
  // first line is the numbers to draw
  std::stringstream ss(firstLine);
  while (ss.good()) {
    std::string substr;
    getline(ss, substr, ',');
    bingoNumbers.push_back(std::stoi(substr));
  }

  std::getline(fullStream, firstLine, '\n');
  std::vector<int> tileNumbers;
  int width = 0;
  for (std::string line; std::getline(fullStream, line, '\n');) {
    if (line == "") {
      // create a bingoTile
      bingoTiles.push_back(BingoTile(tileNumbers, width));
      tileNumbers.clear();
      std::getline(fullStream, line, '\n');
    }

    std::istringstream ss_(line);
    width = 0;
    while (ss_.good()) {
      std::string substr;
      int val;
      ss_ >> val;
      tileNumbers.push_back(val);
      width++;
    }
  }
  bingoTiles.push_back(BingoTile(tileNumbers, width));
}

std::string FileReader::replaceSubString(const std::string &input,
                                         const std::string &substr,
                                         const std::string &replacement) {
  return std::regex_replace(input, std::regex(substr), replacement);
}

std::vector<std::pair<Point3D, Point3D>> FileReader::getAsLineCoordinates() {
  std::vector<std::pair<Point3D, Point3D>> result;
  auto ss = std::stringstream{rawText};

  for (std::string line; std::getline(ss, line, '\n');) {
    line = replaceSubString(line, " -> ", ",");
    line = replaceSubString(line, ",", " ");
    int x1, y1, x2, y2;
    std::istringstream is(line);
    is >> x1 >> y1 >> x2 >> y2;
    result.push_back(
        std::pair<Point3D, Point3D>(Point3D(x1, y1, 0), Point3D(x2, y2, 0)));
  }
  return result;
}

std::vector<std::string> FileReader::splitString(const std::string input,
                                                 const std::string separator) {
  std::vector<std::string> results;
  auto start = 0U;
  auto end = input.find(separator);
  while (end != std::string::npos) {
    results.push_back(input.substr(start, end - start));
    start = end + separator.length();
    end = input.find(separator, start);
  }

  results.push_back(input.substr(start, end));
  return results;
}

std::vector<Day8Entry> FileReader::getSignalCodes() {

  std::vector<Day8Entry> results;
  auto ss = std::stringstream{rawText};
  for (std::string line; std::getline(ss, line, '\n');) {
    std::string signals, code;
    splitStringSingle(line, " | ", signals, code);
    results.push_back(
        Day8Entry(splitString(signals, " "), splitString(code, " ")));
  }
  return results;
}

void FileReader::splitStringSingle(const std::string input,
                                   const std::string separator,
                                   std::string &output1, std::string &output2) {
  output1 = input.substr(0, input.find(separator));
  output2 =
      input.substr(input.find(separator) + separator.size(), input.size());
}
