/*
 * SDLBlinky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLBLINKY_H_
#define SDLBLINKY_H_

#include "Blinky.h"
#include "SDLGhost.h"

namespace SDL {

class SDLBlinky: public Logic::Blinky, public SDLGhost {
public:
	SDLBlinky(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLBlinky();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;


};

} /* namespace SDL */

#endif /* SDLBLINKY_H_ */
