#ifndef SIMULATION_H
#define SIMULATION_H

#include <list>
#include <stdint.h>

using namespace std;

class Animal;
class WebCanvas;

class Simulation {
    private:
        list<Animal*> animals;
        WebCanvas* canvas;
    
    public:
        Simulation(int port);
        ~Simulation();

        void circle(float x, float y, uint8_t r, uint8_t g, uint8_t b, float diameter);
        void step(float dt);
        void run();
};

#endif
