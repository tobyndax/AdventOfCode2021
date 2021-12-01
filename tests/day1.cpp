#include "src/lib/day1solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(UtilTest, Day1Example) {

  int gtCount = 7;

  std::string path = "tests/day1/testdata.txt"; 
  FileReader fileReader(path);
  auto ints = fileReader.getAsIntegers();
  
  Day1Solver solver(ints);
  int count = solver.countIncreases();

  ASSERT_EQ(count, gtCount) << "Day1 doesn't count increases correctly";
  

}
