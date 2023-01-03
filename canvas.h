#ifndef CANVAS_H
#define CANVAS_H

#include "simulation.h"
#include <ws.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <stdio.h>
using namespace std;

typedef std::chrono::high_resolution_clock Clock;

/**
 * @brief This is a helper class to wrap around web drawing functionality
 *        and animation timing
 * 
 * This code is using the "pointer to implementation" design pattern 
 * to work in synchrony with the Simulation class
 * https://en.cppreference.com/w/cpp/language/pimpl
 */
class SimulationCanvas {
    private:
        Simulation* simulation;
        Clock::time_point lastTime;
        struct ws_events evs;
        stringstream shapes;

    public:
        SimulationCanvas(Simulation* simulation, int port);

        void circle(float x, float y, uint8_t r, uint8_t g, uint8_t b, float diameter);
        void draw(float dt);
        float getElapsedTime();
};

#endif