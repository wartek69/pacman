/*
 * SDLDots.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#include "SDLDot.h"
#include <iostream>
#include "Dot.h"
SDLDot::SDLDot(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
Dot(posX, posY), SDLEntity(data, gRenderer, spriteSheet) {
}

SDLDot::~SDLDot() {

}

void SDLDot::visualize(int frame) {
	//TODO param
	SDLX = position.x * 24 + 5;
	SDLY = position.y * 24 + 5;
	SDLEntity::visualize();
}
