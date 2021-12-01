#pragma once

#include <vector>
#include <string>

class FileReader{
  public:
    FileReader(std::string path);
    std::vector<int> getAsIntegers();

  private:
    std::string rawText = "";

};

