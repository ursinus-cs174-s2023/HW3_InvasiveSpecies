#include "simulation.h"
#include "animal.h"
#include "canvas.h"
#include <list>
#include <stdint.h>
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

///////////////////////////////////////////////////////////////////////////
// DO NOT TOUCH THE CODE IN THIS BLOCK
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
        canvas->draw(dt);
    }
}

/**
 * @brief Wrapper around canvas circle method for drawing dots
 * 
 * @param x Location of dot in [0, 1]
 * @param y Location of dot in [0, 1]
 * @param diameter Diameter of dot, in [0, 1]
 * @param r Red component in [0, 255]
 * @param g Green component in [0, 255]
 * @param b Blue component in [0, 255]
 */
void Simulation::circle(float x, float y, float diameter, uint8_t r, uint8_t g, uint8_t b) {
    canvas->circle(x, y, diameter, r, g, b);
}
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//                         BEGIN STUDENT CODE                            //
///////////////////////////////////////////////////////////////////////////



/**
 * @brief Construct a new simulation object
 * 
 * @param port Port on which to connect to browser
 */
Simulation::Simulation(int port) {
    canvas = new WebCanvas(port);
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
    //cout << "dt = " << dt << "\n";
    // TODO: You should loop through the animals here
    // and take steps and draw them
    circle(0.5, 0.5, 0.01, 255, 0, 0);
}
