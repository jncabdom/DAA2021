#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

class gravityParser {
 private:
  std::vector<std::vector<float>> coordinates;

 public:
  inline gravityParser(std::istream& is) { readFromFile(is); }
  ~gravityParser() {}
  void readFromFile(std::istream&);
  inline std::vector<std::vector<float>> getCoord() { return coordinates; }
};

void gravityParser::readFromFile(std::istream& is) {
  std::string aux;
  std::string coord;
  std::vector<float> auxPoint;

  while (std::getline(is, aux)) {
    std::stringstream iss(aux);
    while (iss >> coord) {
      auxPoint.push_back(std::stof(coord));
    }
    coordinates.push_back(auxPoint);
    auxPoint.clear();
  }
}