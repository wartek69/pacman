/*
 * SDLClyde.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLClyde.h"

namespace SDL {

SDLClyde::SDLClyde(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Clyde(posX, posY, world), SDLGhost(rectX, rectY, rectW, rectH, gRenderer, spriteSheet) {
	// TODO Auto-generated constructor stub

}

SDLClyde::~SDLClyde() {
	// TODO Auto-generated destructor stub
}

void SDLClyde::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel);
}

void SDLClyde::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

} /* namespace SDL */