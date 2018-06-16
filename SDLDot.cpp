/*
 * SDLDots.cpp
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#include "SDLDot.h"
#include <iostream>
#include "Dot.h"
namespace SDL {
SDLDot::SDLDot(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
Logic::Dot(posX, posY), SDL::SDLEntity(data, gRenderer, spriteSheet) {
}

SDLDot::~SDLDot() {

}

void SDLDot::visualize(int frame) {
	//TODO param
	SDLX = position.x * tileDimensions.width;
	SDLY = position.y * tileDimensions.height;
	SDL::SDLEntity::visualize();
}
}
