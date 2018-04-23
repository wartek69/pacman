/*
 * SDLInky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLInky.h"

namespace SDL {

SDLInky::SDLInky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Inky(posX, posY, world), SDLGhost(data, gRenderer, spriteSheet){
	// TODO Auto-generated constructor stub

}

SDLInky::~SDLInky() {
	// TODO Auto-generated destructor stub
}

void SDLInky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel, this->eaten);
}

void SDLInky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLInky::findPath(const MovingEntity& entity) {
	Logic::Inky::findPath(entity);
	SDLInky::move(dir, vel);
}
} /* namespace SDL */
