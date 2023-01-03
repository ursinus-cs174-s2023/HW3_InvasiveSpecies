/**
 * @file canvas.cpp
 * @author Chris Tralie (ctralie@alumni.princeton.edu)
 * @brief A file for sending drawing events to the browser
 * @version 0.1
 * @date 2023-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "canvas.h"
#include <ws.h>
#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <stdio.h>
using namespace std;


/**
 * @brief Called when a client connects to the server.
 *
 * @param client Client connection. The @p client parameter is used
 * in order to send messages and retrieve informations about the
 * client.
 */
void onopen(ws_cli_conn_t *client) {
    char *cli;
    cli = ws_getaddress(client);
    printf("Connection opened, addr: %s\n", cli);
}

/**
 * @brief Called when a client disconnects to the server.
 *
 * @param client Client connection. The @p client parameter is used
 * in order to send messages and retrieve informations about the
 * client.
 */
void onclose(ws_cli_conn_t *client) {
    char *cli;
    cli = ws_getaddress(client);
    printf("Connection closed, addr: %s\n", cli);
}

/**
 * @brief Called when a client connects to the server.
 *
 * @param client Client connection. The @p client parameter is used
 * in order to send messages and retrieve informations about the
 * client.
 *
 * @param msg Received message, this message can be a text
 * or binary message.
 *
 * @param size Message size (in bytes).
 *
 * @param type Message type.
 */
void onmessage(ws_cli_conn_t *client,
	const unsigned char *msg, uint64_t size, int type) {
	cout << "Received message: " << msg << "\n";
}

/**
 * @brief This is a helper class to wrap around web drawing functionality
 *        and animation timing
 * 
 * This code is using the "pointer to implementation" design pattern 
 * to work in synchrony with the Simulation class
 * https://en.cppreference.com/w/cpp/language/pimpl
 */



/**
 * @brief Construct a new Simulation Canvas:: Simulation Canvas object
 * 
 * @param port Port on which to connect
 */
WebCanvas::WebCanvas(int port) {
    lastTime = Clock::now();
    evs.onopen = &onopen;
    evs.onclose = &onclose;
    evs.onmessage = &onmessage;
    ws_socket(&evs, port, 1, 1000);

}

void WebCanvas::circle(float x, float y, uint8_t r, uint8_t g, uint8_t b, float diameter) {
    
}

void WebCanvas::draw(float dt) {
    // TODO: Draw all objects by sending request
    cout << "dt = " << dt << "\n";
}

/**
 * @brief Return the amount of time elapsed since the last time this
 *        method was called, in milliseconds
 * 
 * @return float Elapsed time
 */
float WebCanvas::getElapsedTime() {
    Clock::time_point now = Clock::now();
    std::chrono::duration<float, std::milli> dt = now-lastTime;
    lastTime = now;
    return (float)(dt.count());
}