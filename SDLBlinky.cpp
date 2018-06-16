/*
 * SDLBlinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLBlinky.h"
#include "SDLGhost.h"

namespace SDL {

SDLBlinky::SDLBlinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world):
	Logic::Blinky(posX, posY, world), SDL::SDLGhost(data, gRenderer, spriteSheet) {

}

SDLBlinky::~SDLBlinky() {

}

void SDLBlinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Logic::Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel, this->eaten);
}

void SDLBlinky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLBlinky::findPath(const Logic::MovingEntity& entity) {
	Logic::Blinky::findPath(entity);
	SDLBlinky::move(dir, vel);

}

} /* namespace SDL */
