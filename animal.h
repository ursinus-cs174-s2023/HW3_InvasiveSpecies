#include "simulation.h"
#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
    protected:
        Simulation* simulation;
    
    public:
        Animal(Simulation* simulation);
        virtual ~Animal(){};

};

#endif