#include <chrono>
#include <fstream>
#include <iostream>

#include "../include/gravityParser.h"

#include "../include/gravityGreedy.h"
#include "../include/gravityGrasp.h"
#include "../include/gravityBnB1.h"
#include "../include/gravityBnB2.h"

std::ifstream inputFile;

auto start = std::chrono::steady_clock::now();
auto end = std::chrono::steady_clock::now();

std::vector<std::chrono::microseconds> times;
std::vector<float> results;
std::vector<int> nodes;
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

  gravityParser parser(inputFile);

  /* GREEDY
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

  /* GREEDY LOCAL SEARCH
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
  for (auto z : results) {
    std::cout << z << std::endl;
  }
  std::cout << std::endl;
  for (auto time : times) {
    std::cout << time.count() << "μs" << std::endl;
  }
  times.clear();
  points.clear();
  /* END OF GREEDY LOCAL SEARCH */

  /* GRASP 
  gravityGrasp gr(parser.getCoord(), 3);
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
  for (auto z : results) {
    std::cout << z << std::endl;
  }
  std::cout << std::endl;
  for (auto time : times) {
    std::cout << time.count() << "μs" << std::endl;
  }
  times.clear();
  points.clear();
  /* END OF GRASP */

  /* BRANCH AND BOUND */
  gravityGrasp grGrasp(parser.getCoord(), 3);
  gravityGreedy grGreedy(parser.getCoord());
  for (int i = 2; i <= 5; i++) {
    gravityBnB1 gr(parser.getCoord(), grGreedy.run(i));
    // Descomentar para exploración por nodo más profundo
    // gravityBnB2 gr(parser.getCoord(), grGreedy.run(i));
    aux = "";
    start = std::chrono::steady_clock::now();
    points = gr.run(i);
    results.push_back(gr.getZ(points));
    end = std::chrono::steady_clock::now();
    times.push_back(
        std::chrono::duration_cast<std::chrono::microseconds>(end - start));
    nodes.push_back(gr.getNodeCount());
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
  for (auto z : results) {
    std::cout << z << std::endl;
  }
  std::cout << std::endl;
  for (auto time : times) {
    std::cout << time.count() << "μs" << std::endl;
  }
std::cout << std::endl;
  for(auto count: nodes) {
    std::cout << count << std::endl;
  }
  times.clear();
  points.clear();
  /* END OF BRANCH AND BOUND */
}