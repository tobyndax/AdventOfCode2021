#pragma once

#include <iostream>
#include <string>
#include <vector>

#define RST "\x1B[0m"
#define KRED "\x1B[31m"
#define FRED(x) KRED x RST

class BingoTile {
public:
  BingoTile(const std::vector<int> &data, const int width)
      : data(data), width(width) {
    checked.clear();
    checked.resize(width * width, 0);
  }

  int getValue(int x, int y) { return data[x + y * width]; }
  void markHit(int value) {
    for (size_t i = 0; i < data.size(); i++) {
      if (data[i] == value) {
        checked[i] = 1;
      }
    }
  }
  int winnerScore(int drawnNumber) {
    int sum = 0;
    for (size_t i = 0; i < data.size(); i++) {
      sum += checked[i] == 0 ? data[i] : 0;
    }
    return sum * drawnNumber;
  }
  void printTile() {
    for (int j = 0; j < width; j++) {
      for (int i = 0; i < width; i++) {
        if (checked[i + j * width] == 1) {
          std::cout << KRED << data[i + j * width] << RST << " ";
        } else {
          std::cout << data[i + j * width] << " ";
        }
      }
      std::cout << std::endl;
    }
    std::cout << "========" << std::endl;
  }

  bool checkWin() {
    // check for each row
    for (int j = 0; j < width; j++) {
      int rowSum = 0;
      for (int i = 0; i < width; i++) {
        rowSum += checked[i + j * width];
      }
      if (rowSum == width) {
        return true;
      }
    }
    for (int i = 0; i < width; i++) {
      int colSum = 0;
      for (int j = 0; j < width; j++) {
        colSum += checked[i + j * width];
      }
      if (colSum == width) {
        return true;
      }
    }
    return false;
  }

private:
  std::vector<int> data;
  std::vector<int> checked;
  int width = 0;
};
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
