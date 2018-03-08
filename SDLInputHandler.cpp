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
	lastInput = 0;

}

SDLInputHandler::~SDLInputHandler() {
	// TODO Auto-generated destructor stub
}

/**
 * this method handles the input to let pacman move
 * The commented part can be used to let pacman stand still by every button release
 * Be aware because there is some input lag so the controls feel laggy sometimes
 * if the part stays commented then pacman will keep moving after the key is released
 * Lastinput variable is needed so that when no button is pressed the pacman will still move
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
			lastInput = FORWARD;
			break;
		case SDLK_DOWN:
			lastInput = BACKWARD;
			break;
		case SDLK_LEFT:
			lastInput = LEFT;
			break;
		case SDLK_RIGHT:
			lastInput = RIGHT;
			break;
		}
		cout << "event" << endl;
	velocity = 1;
	} else {
		//this is needed to make sure that when a button is pressed in
		//a direction that isn't possible that pacman won't go in that direction
		lastInput = direction;
	}
	/*else if(e.type == SDL_KEYUP) {
		//KEY IS RELEASED
		if(e.key.keysym.sym == SDLK_UP || e.key.keysym.sym == SDLK_DOWN|| e.key.keysym.sym == SDLK_LEFT || e.key.keysym.sym == SDLK_RIGHT) {
			//-1 is used to identify the default value
			cout << "test key released" << endl;
			//handleObject->move(lastInput,-1);
			velocity = 1;
		}
	}*/
	direction = lastInput;
}

