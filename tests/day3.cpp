#include "src/lib/day3solver.h"
#include "src/lib/util.h"
#include "gtest/gtest.h"

TEST(Day3Test, Day3Example) {
  int gtGamma = 22;
  int gtEpsilon = 9;
  int gtOgr = 23;
  int gtCsr = 10;
  int gtMultGE = 198;
  int gtMultOC = 230;

  std::string path = "tests/day3/testdata.txt";
  FileReader fileReader(path);

  std::vector<std::string> data = fileReader.getAsStrings();

  Day3Solver solver(data);
  int gamma = 0;
  int epsilon = 0;
  int ogr = 0;
  int csr = 0;
  solver.solve(gamma, epsilon, ogr, csr);

  int multGE = gamma * epsilon;
  int multOC = ogr * csr;

  ASSERT_EQ(gamma, gtGamma);
  ASSERT_EQ(epsilon, gtEpsilon);
  ASSERT_EQ(ogr, gtOgr);
  ASSERT_EQ(csr, gtCsr);
  ASSERT_EQ(multGE, gtMultGE);
  ASSERT_EQ(multOC, gtMultOC);
}
