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
namespace SDL {

SDLInputHandler::SDLInputHandler(shared_ptr<Logic::Pacman> handleObject): Logic::InputHandler(handleObject) {

}

SDLInputHandler::~SDLInputHandler() {

}

/**
 * this method handles the input to let pacman move
 * The pacman will keep moving after the key is released
 */
void SDLInputHandler::handleInput(bool& quit,int& direction, int& velocity) {
	SDL_Event e;

	//Handle events on queue
	while(SDL_PollEvent( &e )!=0) {
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
		velocity = 1;
		}
	}

}

void SDLInputHandler::handleEndScreen(bool& quit, bool& repeat) {
	SDL_Event e;

	//Handle events on queue
	while(SDL_PollEvent( &e )!=0) {
		//User requests quit
		if( e.type == SDL_QUIT ) {
			quit = true;
			repeat = false;
		} else if( e.type == SDL_KEYDOWN ) {
			switch( e.key.keysym.sym) {
				case SDLK_SPACE:
					quit = true;
					repeat = true;
				break;

				case SDLK_ESCAPE:
					quit = true;
					repeat = false;
				break;
			}
		}
	}
}
}
