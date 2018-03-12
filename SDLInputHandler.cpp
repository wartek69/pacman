/*
 * SDLInputHandler.cpp
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#include "SDLInputHandler.h"
#include <SDL2\SDL.h>
#include "Types.h"
#include <iostream>
using namespace std;


SDLInputHandler::SDLInputHandler(Pacman* handleObject): InputHandler(handleObject) {

}

SDLInputHandler::~SDLInputHandler() {
	// TODO Auto-generated destructor stub
}

/**
 * this method handles the input to let pacman move
 * The pacman will keep moving after the key is released
 */
void SDLInputHandler::handleInput(bool& quit,int& direction, int& velocity) {
	SDL_Event e;

	//Handle events on queue
	SDL_PollEvent( &e );
	//User requests quit
	if( e.type == SDL_QUIT ) {
		quit = true;
	} else if( e.type == SDL_KEYDOWN ) {
		switch( e.key.keysym.sym) {
		case SDLK_UP:
			direction = FORWARD;

			break;
		case SDLK_DOWN:
			direction = BACKWARD;

			break;
		case SDLK_LEFT:
			direction = LEFT;

			break;
		case SDLK_RIGHT:
			direction = RIGHT;
			break;
		}
	velocity = 2;
	}

}

