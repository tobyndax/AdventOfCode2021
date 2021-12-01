#include "src/lib/util.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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
