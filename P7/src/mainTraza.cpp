#include <chrono>
#include <iostream>

#include "../include/machines.h"

int stop = 1, iterations = 1000, lrcNumber = 3;

machines machinesTest;

auto start = std::chrono::steady_clock::now();
auto end = std::chrono::steady_clock::now();

int main(int argc, char* argv[]) {
  machinesTest.read(argv[1]);
  std::vector<int> tcts;
  std::vector<float> times;
  /*
  start = std::chrono::steady_clock::now();
  machinesTest.greedy1();
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.greedy2();
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  // GRASP

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 2, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 2, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 2, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 2, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 3, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 3, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 3, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 3, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 4, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 4, 1, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 4, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 4, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  tcts.push_back(machinesTest.getTCT());
  times.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(end -
  start).count());

  // VND

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 1, 1, 100);
  machinesTest.VND(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 1, 1, 100);
  machinesTest.VND(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 1, 1, 100);
  machinesTest.VND(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 1, 1, 100);
  machinesTest.VND(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 2, 1, 100);
  machinesTest.VND(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(2, 1, 2, 1, 100);
  machinesTest.VND(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 2, 1, 100);
  machinesTest.VND(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, 2, 1, 100);
  machinesTest.VND(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  */
  // GVNS

  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

         
  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(1);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());
  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());
  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(2);
  end = std::chrono::steady_clock::now();

  tcts.push_back(machinesTest.getTCT());
  times.push_back(
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count());

  for (int i = 0; i < tcts.size(); i++) {
    std::cout << tcts[i] << std::endl;
  }
  std::cout << std::endl;
  for (int i = 0; i < tcts.size(); i++) {
    std::cout << times[i] << std::endl;
  }
}

/* FORMATO SALIDA:

greedy1
greedy2

grasp(lrc 2, Intra Inter, greedy, parada 1, iter 100)
grasp(lrc 3, Intra Inter, greedy, parada 1, iter 100)
grasp(lrc 2, Intra Inter, ansiosa, parada 1, iter 100)
grasp(lrc 3, Intra Inter, ansiosa, parada 1, iter 100)

grasp(lrc 2, Inter Inter, greedy, parada 1, iter 100)
grasp(lrc 3, Inter Inter, greedy, parada 1, iter 100)
grasp(lrc 2, Inter Inter, ansiosa, parada 1, iter 100)
grasp(lrc 3, Inter Inter, ansiosa, parada 1, iter 100)

grasp(lrc 2, Intra Reinser, greedy, parada 1, iter 100)
grasp(lrc 3, Intra Reinser, greedy, parada 1, iter 100)
grasp(lrc 2, Intra Reinser, ansiosa, parada 1, iter 100)
grasp(lrc 3, Intra Reinser, ansiosa, parada 1, iter 100)

grasp(lrc 2, Inter Reinser, greedy, parada 1, iter 100)
grasp(lrc 3, Inter Reinser, greedy, parada 1, iter 100)
grasp(lrc 2, Inter Reinser, ansiosa, parada 1, iter 100)
grasp(lrc 3, Inter Reinser, ansiosa, parada 1, iter 100)

VND
GVNS
*/