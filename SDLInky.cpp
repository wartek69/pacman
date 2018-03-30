/*
 * SDLInky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLInky.h"

namespace SDL {

SDLInky::SDLInky(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Inky(posX, posY, world), SDLGhost(rectX, rectY, rectW, rectH, gRenderer, spriteSheet){
	// TODO Auto-generated constructor stub

}

SDLInky::~SDLInky() {
	// TODO Auto-generated destructor stub
}

void SDLInky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel);
}

void SDLInky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

} /* namespace SDL */
