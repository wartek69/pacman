/*
 * SDLDots.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#include "SDLDot.h"

#include "Dot.h"
SDLDot::SDLDot(SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
Dot(posX, posY), SDLEntity(216, 0, collisionWidth, collisionHeight, gRenderer, spriteSheet) {
	// TODO Auto-generated constructor stub

}

SDLDot::~SDLDot() {
	// TODO Auto-generated destructor stub
}

void SDLDot::visualize() {
	SDLEntity::visualize(position.x, position.y);
}
