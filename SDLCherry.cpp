/*
 * SDLCherry.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "SDLCherry.h"


namespace SDL {

SDLCherry::SDLCherry(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, std::shared_ptr<ScoreHandler> score):
	Logic::Cherry(posX, posY, score), SDLEntity(data, gRenderer, spriteSheet) {
	// TODO Auto-generated constructor stub

}

SDLCherry::~SDLCherry() {
	// TODO Auto-generated destructor stub
}

void SDLCherry::visualize(int frame) {
	SDLX = position.x * 24;
	SDLY = position.y * 24;
	SDLEntity::visualize();
}

} /* namespace SDL */
