/*
 * SDLPinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLPinky.h"

namespace SDL {

SDLPinky::SDLPinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world):
	Logic::Pinky(posX, posY, world), SDL::SDLGhost(data, gRenderer, spriteSheet) {

}

SDLPinky::~SDLPinky() {
}

void SDLPinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Logic::Ghost::move(direction, velocity);
	//Do the animation
	SDL::SDLGhost::animation(dir, vel, this->eaten);
}

void SDLPinky::visualize(int frame) {
	SDL::SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLPinky::findPath(const Logic::MovingEntity& entity) {
	Logic::Pinky::findPath(entity);
	SDL::SDLPinky::move(dir, vel);

}

} /* namespace SDL */
