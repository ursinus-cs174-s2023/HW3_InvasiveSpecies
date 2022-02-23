#include "simulation.h"
#include "animal.h"
#include "tinygl-cpp.h"
#include <list>
#include <iterator>
using namespace std;
using namespace tinygl;


// Use the "pointer to implementation" design pattern for 
// internal drawing details
// https://en.cppreference.com/w/cpp/language/pimpl
class SimulationCanvas: public Window {
    private:
        int res;
        Simulation* simulation;
        float lastTime;
    public:
        SimulationCanvas(Simulation* simulation, int res):Window(res, res) {
            this->simulation = simulation;
            this->res = res;
            lastTime = elapsedTime();
        }
        void circle(float x, float y, int r, int g, int b, float diameter) {
            color(r, g, b);
            ellipsoid((int)(res*x), (int)(res*y), res*diameter, res*diameter);
        }
        void draw() {
            background(0.8f, 0.8f, 0.8f);
            float time = elapsedTime();
            float dt = time - lastTime;
            lastTime = time;
            simulation->step(dt);
        }
};



/**
 * @brief Construct a new simulation object
 * 
 * @param res The square resolution of the window
 */
Simulation::Simulation(int res) {
    canvas = new SimulationCanvas(this, res);
    this->res = (float)res;
}

Simulation::~Simulation() {
    // TODO: Cleanup dynamically allocated stuff here
}

/**
 * @brief Wrapper around tinygl run method for continuous animation
 * 
 */
void Simulation::run() {
    canvas->run();
}

/**
 * @brief Wrapper around tinygl circle method for drawing dots
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

void Simulation::step(float dt) {
    circle(0.5, 0.5, 255, 0, 0, 0.01);
}
