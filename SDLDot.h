/*
 * SDLDots.h
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLDOT_H_
#define SDLDOT_H_

#include "Dot.h"
#include "SDLEntity.h"

class SDLDot: public Dot, public SDLEntity {
public:
	SDLDot(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLDot();
	void visualize(int frame) override;
};

#endif /* SDLDOT_H_ */
