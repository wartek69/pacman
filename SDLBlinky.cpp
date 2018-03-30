/*
 * SDLBlinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "SDLBlinky.h"
#include "SDLGhost.h"

namespace SDL {

SDLBlinky::SDLBlinky(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world):
	Blinky(posX, posY, world), SDLGhost(rectX, rectY, rectW, rectH, gRenderer, spriteSheet) {

}

SDLBlinky::~SDLBlinky() {

}

void SDLBlinky::move(int direction, int velocity) {
	//first replace the ghost in the game
	Ghost::move(direction, velocity);
	//Do the animation
	SDLGhost::animation(dir, vel);
}

void SDLBlinky::visualize(int frame) {
	SDLGhost::showOnScreen(position.x, position.y, vel, dir, frame);
}

void SDLBlinky::findPath(const Entity& entity) {
	Logic::Blinky::findPath(entity);
	SDLBlinky::move(dir, vel);

}

} /* namespace SDL */
