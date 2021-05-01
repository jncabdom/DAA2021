#include <chrono>
#include <iostream>
#include <fstream>
#include "../include/gravityGreedy.h"
#include "../include/gravityParser.h"

std::ifstream inputFile;

/* Faltan funciones de la clase gravity.h
 *
 * float getDist(int, int);
 * int getCenter();
 * std::vector<int> getBetterK(int);
 *
 * y run del gravity.
 *
 * También objeto localsearch igual que la pr anterior?
 */

int main(int argc, char* argv[]) {
  if(argc <= 1) {
    return 0;
  }

  inputFile.open(argv[1]);
  if(!inputFile) {
    return 0;
  }

  gravityParser parser(inputFile);
  gravityGreedy gr(parser.getCoord());
  gr.print(std::cout);
}