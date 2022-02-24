#include "simulation.h"
#ifndef ANIMAL_H
#define ANIMAL_H

/**
 * TODO: You will need to extend this quite a bit the full 
 * functionality in this assignment.  This includes adding
 * variables and methods to the Animal class, as well as 
 * defining subclasses for Female, Male, and SuperMale
 * 
 */
class Animal {
    protected:
        Simulation* simulation;
    
    public:
        Animal(Simulation* simulation);
        virtual ~Animal(){};

};

#endif