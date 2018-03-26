/*
 * SDLDots.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#include "SDLDot.h"
#include <iostream>
#include "Dot.h"
SDLDot::SDLDot(SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
Dot(posX, posY), SDLEntity(216, 0, 10, 10, gRenderer, spriteSheet, posX*24+5, posY*24+5) {

	// TODO config file

}

SDLDot::~SDLDot() {
	// TODO Auto-generated destructor stub
}

void SDLDot::visualize(int frame) {
	SDLEntity::visualize();
}
