#include "src/lib/cpplib.h"
#include "src/lib/day1solver.h"
#include "src/lib/day2solver.h"
#include "src/lib/util.h"

#include <iostream>

int main() {

  int day = 2;
  if (day == 2) {

    std::string path = "src/main/day2/input.txt";
    FileReader fileReader(path);
    std::vector<std::pair<Point3D, int>> data = fileReader.getDirectionValue();

    Day2Solver solver(data);
    Point3D position = solver.solveWithAim();

    int res = position.x * position.z;
    std::cout << res << std::endl;
  } else if (day == 1) {
    std::string path = "src/main/day1/input.txt";
    FileReader fileReader(path);
    auto ints = fileReader.getAsIntegers();

    Day1Solver solver(ints);
    int count = solver.countIncreases(3);
    std::cout << count << std::endl;
  }
  return 0;
}
