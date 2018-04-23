/*
 * SDLPinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLPinky.h"

namespace SDL {

SDLPinky::SDLPinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Pinky(posX, posY, world), SDLGhost(data, gRenderer, spriteSheet) {
	// TODO Auto-generated constructor stub

}

SDLPinky::~SDLPinky() {
	// TODO Auto-generated destructor stub
}

void SDLPinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel, this->eaten);
}

void SDLPinky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLPinky::findPath(const MovingEntity& entity) {
	Logic::Pinky::findPath(entity);
	SDLPinky::move(dir, vel);

}

} /* namespace SDL */
