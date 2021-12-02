#pragma once

#include <string>
#include <vector>

class FileReader {
public:
  FileReader(std::string path);
  std::vector<int> getAsIntegers();

private:
  std::string rawText = "";
};