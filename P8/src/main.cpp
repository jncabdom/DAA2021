#include <chrono>
#include <fstream>
#include <iostream>

#include "../include/gravityGreedy.h"
#include "../include/gravityParser.h"

std::ifstream inputFile;

auto start = std::chrono::steady_clock::now();
auto end = std::chrono::steady_clock::now();

std::vector<std::chrono::microseconds> times;
std::vector<float> results;
pointSpace points;
std::string aux;

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    return 0;
  }

  inputFile.open(argv[1]);
  if (!inputFile) {
    return 0;
  }
  /* GREEDY 
  gravityParser parser(inputFile);
  gravityGreedy gr(parser.getCoord());
  for (int i = 2; i <= 5; i++) {
    aux = "";
    start = std::chrono::steady_clock::now();
    points = gr.run(i);
    results.push_back(gr.getZ(points));
    end = std::chrono::steady_clock::now();
    times.push_back(
        std::chrono::duration_cast<std::chrono::microseconds>(end - start));
    for (auto point : points) {
      aux += "{ ";
      for (auto coord : point) {
        aux += std::to_string(coord) + ", ";
      }
      aux.pop_back();
      aux.pop_back();
      aux += " }, ";
    }
      aux.pop_back();
      aux.pop_back();
    std::cout << aux << std::endl;
  }
  std::cout << std::endl;
  for(auto z: results) {
    std::cout << z << std::endl;
  }
  std::cout << std::endl;
  for(auto time: times) {
    std::cout << time.count() << "μs" << std::endl;
  }
  times.clear();
  points.clear();
  /* END OF GREEDY */

  /* GREEDY LOCAL SEARCH */
  gravityParser parser(inputFile);
  gravityGreedy gr(parser.getCoord());
  for (int i = 2; i <= 5; i++) {
    aux = "";
    start = std::chrono::steady_clock::now();
    points = gr.run(i);
    points = gr.neighborExplore(points);
    results.push_back(gr.getZ(points));
    end = std::chrono::steady_clock::now();
    times.push_back(
        std::chrono::duration_cast<std::chrono::microseconds>(end - start));
    for (auto point : points) {
      aux += "{ ";
      for (auto coord : point) {
        aux += std::to_string(coord) + ", ";
      }
      aux.pop_back();
      aux.pop_back();
      aux += " }, ";
    }
      aux.pop_back();
      aux.pop_back();
    std::cout << aux << std::endl;
  }
  std::cout << std::endl;
  for(auto z: results) {
    std::cout << z << std::endl;
  }
  std::cout << std::endl;
  for(auto time: times) {
    std::cout << time.count() << "μs" << std::endl;
  }
  times.clear();
  points.clear();
  /* END OF GREEDY LOCAL SEARCH */
}