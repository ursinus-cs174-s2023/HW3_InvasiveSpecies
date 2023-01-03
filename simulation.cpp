#include "simulation.h"
#include "animal.h"
#include <ws.h>
#include <list>
#include <iterator>
#include <iostream>
#include <chrono>
#include <stdio.h>
using namespace std;

typedef std::chrono::high_resolution_clock Clock;

///////////////////////////////////////////////////////////////////////////
/**
 * @brief This is a helper class to wrap around web drawing functionality
 *        and animation timing
 * DO NOT TOUCH THIS CLASS
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

    public:
        SimulationCanvas(Simulation* simulation) {
            this->simulation = simulation;
            lastTime = Clock::now();
        }

        void circle(float x, float y, int r, int g, int b, float diameter) {
            // TODO: Fill this in
        }

        void draw() {
            // TODO: Draw all objects by sending request
            
        }

        float getElapsedTime() {
            Clock::time_point now = Clock::now();
            std::chrono::duration<float, std::milli> dt = now-lastTime;
            lastTime = now;
            return (float)(dt.count());
        }
};

/**
 * @brief Start off a continuous animation loop
 * 
 */
void Simulation::run() {
    while (true) {
        // Step 1: Determine elapsed time
        float dt = canvas->getElapsedTime();
        // Step 2: Do a step of the simulation
        step(dt);
        // Step 3: Draw the results
        canvas->draw();
    }
}

/**
 * @brief Wrapper around canvas circle method for drawing dots
 * 
 * @param x Location of dot in [0, 1]
 * @param y Location of dot in [0, 1]
 * @param r Red component in [0, 255]
 * @param g Green component in [0, 255]
 * @param b Blue component in [0, 255]
 * @param diameter Diameter of dot, in [0, 1]
 */
void Simulation::circle(float x, float y, int r, int g, int b, float diameter) {
    canvas->circle(x, y, r, g, b, diameter);
}

///////////////////////////////////////////////////////////////////////////
//                         BEGIN STUDENT CODE                            //
///////////////////////////////////////////////////////////////////////////



/**
 * @brief Construct a new simulation object
 * 
 */
Simulation::Simulation() {
    canvas = new SimulationCanvas(this);
}

/**
 * @brief Destroy the Simulation:: Simulation object
 * 
 */
Simulation::~Simulation() {
    delete canvas;
    // TODO: Cleanup dynamically allocated stuff here
}

/**
 * @brief Do a step of the simulation.  Every animal should
 * move and take its action
 * 
 * @param dt The amount of time elapsed since the last step
 */
void Simulation::step(float dt) {
    cout << "dt = " << dt << "\n";
    // TODO: You should loop through the animals here
    // and take steps and draw them
    //circle(0.5, 0.5, 255, 0, 0, 0.01);

    canvas->draw();
}
