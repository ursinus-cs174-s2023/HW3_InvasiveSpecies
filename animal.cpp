#include "simulation.h"
#include "animal.h"
#include "randutils.h"
#include <stdio.h>
#include <math.h>
using namespace std;

Animal::Animal(Simulation* simulation){
    this->simulation = simulation;
}