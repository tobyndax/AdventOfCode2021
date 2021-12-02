#include "src/lib/cpplib.h"
#include "src/lib/day1solver.h"
#include "src/lib/util.h"

#include <iostream>

int main() {

  std::string path = "src/main/day1/input.txt";
  FileReader fileReader(path);
  auto ints = fileReader.getAsIntegers();

  Day1Solver solver(ints);
  int count = solver.countIncreases(3);
  std::cout << count << std::endl;

  return 0;
}
