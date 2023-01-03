#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>

using namespace std;

class Animal;
class SimulationCanvas;

class Simulation {
    private:
        list<Animal*> animals;
        SimulationCanvas* canvas;
    
    public:
        Simulation();
        ~Simulation();

        void circle(float x, float y, int r, int g, int b, float diameter);
        void step(float dt);
        void run();
};

#endif
