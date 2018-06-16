/*
 * SDLCherry.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "SDLCherry.h"


namespace SDL {

SDLCherry::SDLCherry(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, std::shared_ptr<Logic::ScoreHandler> score):
	Logic::Cherry(posX, posY, score), SDL::SDLEntity(data, gRenderer, spriteSheet) {

}

SDLCherry::~SDLCherry() {
}

void SDLCherry::visualize(int frame) {
	SDLX = position.x * tileDimensions.width;
	SDLY = position.y * tileDimensions.height;
	SDL::SDLEntity::visualize();
}

} /* namespace SDL */
