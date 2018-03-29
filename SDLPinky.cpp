/*
 * SDLPinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLPinky.h"

namespace SDL {

SDLPinky::SDLPinky(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
	Pinky(posX, posY), SDLGhost(rectX, rectY, rectW, rectH, gRenderer, spriteSheet) {
	// TODO Auto-generated constructor stub

}

SDLPinky::~SDLPinky() {
	// TODO Auto-generated destructor stub
}

void SDLPinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel);
}

void SDLPinky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

} /* namespace SDL */
