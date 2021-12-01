#include "day1solver.h"


Day1Solver::Day1Solver(std::vector<int> inputValues) : values(inputValues){

}

int Day1Solver::countIncreases(){
  int prevValue = values[0];
  int count = 0;
  for (auto val : values){
    if (val > prevValue){
      count++;
    }
    prevValue = val;
  } 
  return count;
}
