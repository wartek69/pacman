/*
 * SDLClyde.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLCLYDE_H_
#define SDLCLYDE_H_

#include "Clyde.h"
#include "SDLGhost.h"

namespace SDL {

class SDLClyde: public Logic::Clyde, public SDLGhost {
public:
	SDLClyde(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLClyde();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;

};

} /* namespace SDL */

#endif /* SDLCLYDE_H_ */
