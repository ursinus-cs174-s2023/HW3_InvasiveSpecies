#include <vector>
#include <iostream>
#include "simulation.h"

using namespace std;


int main() {
  Simulation simulation(8080);
  simulation.run();
  return 0;
}