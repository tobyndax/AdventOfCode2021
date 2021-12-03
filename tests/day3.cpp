#include "src/lib/day3solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day3Test, Day3Example) {
  int gtGamma = 22;
  int gtEpsilon = 9;
  int gtMult = 198;

  std::string path = "tests/day3/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::string> data = fileReader.getAsStrings();

  Day3Solver solver(data);
  int gamma = 0;
  int epsilon = 0;
  solver.solve(gamma, epsilon);

  int mult = gamma * epsilon;

  ASSERT_EQ(gamma, gtGamma);
  ASSERT_EQ(epsilon, gtEpsilon);
  ASSERT_EQ(mult, gtMult);
}
