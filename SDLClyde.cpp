/*
 * SDLClyde.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLClyde.h"

namespace SDL {

SDLClyde::SDLClyde(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world):
	Logic::Clyde(posX, posY, world), SDL::SDLGhost(data, gRenderer, spriteSheet) {

}

SDLClyde::~SDLClyde() {
}

void SDLClyde::move(int direction, int velocity) {
	//first replace the ghost in the game
	Logic::Ghost::move(direction, velocity);
	//Do the animation
	SDL::SDLGhost::animation(dir, vel, this->eaten);
}

void SDLClyde::visualize(int frame) {
	SDL::SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLClyde::findPath(const MovingEntity& entity) {
	Logic::Clyde::findPath(entity);
	SDLClyde::move(dir, vel);
}

} /* namespace SDL */
