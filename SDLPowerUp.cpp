/*
 * SDLPowerUp.cpp
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#include "SDLPowerUp.h"
#include <limits>

namespace SDL {

SDLPowerUp::SDLPowerUp(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, std::shared_ptr<Logic::Timer> timer) :
	Logic::PowerUp(posX, posY, timer), SDL::SDLEntity(data, gRenderer, spriteSheet){
	frameCounter = 0;
	toggle = 0;
}

SDLPowerUp::~SDLPowerUp() {
}

void SDLPowerUp::visualize(int frame) {
	//TODO param the 24 and 5, do same in dot
	SDLX = position.x * tileDimensions.width;
	SDLY = position.y * tileDimensions.height;

	//Blinking of the dot
	if(frameCounter%16 == 0) {
		if (toggle == 0)
			toggle = 1;
		else
			toggle = 0;
	}
	if(toggle == 1)
		SDL::SDLEntity::visualize();

	frameCounter++;
	//prevent overflow
	if(frameCounter == std::numeric_limits<int>::max())
		frameCounter = 0;

}
} /* namespace SDL */
