#include "src/lib/cpplib.h"
#include "src/lib/util.h"
#include "src/lib/day1solver.h"

#include <iostream>

int main() {

  int gtCount = 7;

  std::string path = "src/main/day1/input.txt"; 
  FileReader fileReader(path);
  auto ints = fileReader.getAsIntegers();
  
  Day1Solver solver(ints);
  int count = solver.countIncreases();
  std::cout << count << std::endl;

  return 0;
}
