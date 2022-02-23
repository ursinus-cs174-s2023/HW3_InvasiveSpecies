#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>

using namespace std;

class Animal;
class SimulationCanvas;

class Simulation {
    private:
        float res;
        list<Animal*> animals;
        SimulationCanvas* canvas;
    
    public:
        /**
         * @brief Construct a new simulation object
         * 
         * @param res The square resolution of the window
         */
        Simulation(int res);
        ~Simulation();

        void circle(float x, float y, int r, int g, int b, float diameter);
        void step(float dt);
        void run();
};

#endif
