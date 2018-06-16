/*
 * SDLInky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLInky.h"

namespace SDL {

SDLInky::SDLInky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world):
	Logic::Inky(posX, posY, world), SDL::SDLGhost(data, gRenderer, spriteSheet){

}

SDLInky::~SDLInky() {
}

void SDLInky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Logic::Ghost::move(direction, velocity);
	//Do the animation
	SDL::SDLGhost::animation(dir, vel, this->eaten);
}

void SDLInky::visualize(int frame) {
	SDL::SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLInky::findPath(const Logic::MovingEntity& entity) {
	Logic::Inky::findPath(entity);
	SDLInky::move(dir, vel);
}
} /* namespace SDL */
