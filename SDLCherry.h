/*
 * SDLCherry.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef SDLCHERRY_H_
#define SDLCHERRY_H_

#include "Cherry.h"
#include "SDLEntity.h"
#include <memory>
namespace SDL {

class SDLCherry: public Logic::Cherry, public SDL::SDLEntity {
public:
	SDLCherry(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, std::shared_ptr<Logic::ScoreHandler> score);
	virtual ~SDLCherry();
	void visualize(int frame) override;
};

} /* namespace SDL */

#endif /* SDLCHERRY_H_ */
