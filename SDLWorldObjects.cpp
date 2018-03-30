/*
 * SDLWorldObjects.cpp
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#include "SDLWorldObjects.h"
#include <iostream>
#include "Types.h"
using namespace std;

SDLWorldObjects::SDLWorldObjects(SDL_Renderer* gRenderer) {
	frames = 0;
	this->gRenderer = gRenderer;
}

SDLWorldObjects::~SDLWorldObjects() {

}

void SDLWorldObjects::visualize(const unique_ptr<ScoreHandler>& score) {
	frames = 0;
	while (frames < frameDelay) {
		frames++;
		SDL_RenderClear(gRenderer);
		for(shared_ptr<Entity> entity : objects) {
			entity->visualize(frames);
		}
		score->visualize();
		SDL_RenderPresent(gRenderer);
	}
}