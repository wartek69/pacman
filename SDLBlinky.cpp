/*
 * SDLBlinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLBlinky.h"
#include "SDLGhost.h"

namespace SDL {

SDLBlinky::SDLBlinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Blinky(posX, posY, world), SDLGhost(data, gRenderer, spriteSheet) {

}

SDLBlinky::~SDLBlinky() {

}

void SDLBlinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel, this->eaten);
}

void SDLBlinky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLBlinky::findPath(const MovingEntity& entity) {
	Logic::Blinky::findPath(entity);
	SDLBlinky::move(dir, vel);

}

} /* namespace SDL */
