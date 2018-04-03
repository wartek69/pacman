/*
 * SDLGhost.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef SDLGHOST_H_
#define SDLGHOST_H_

#include "Ghost.h"
#include "SDLEntity.h"
#include "SDLMovingEntity.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

class SDLGhost: public SDL::SDLMovingEntity {
public:
	SDLGhost(int x, int y, int w, int h,SDL_Renderer* gRenderer, SDL_Texture* spriteSheet);
	virtual ~SDLGhost();
	void animation(int direction, int velocity);
	void showOnScreen(int posX, int posY, int velocity, int direction, int frame);
	void loadSprites();
private:
	SDL_Rect sprites[12];
	// j is used to swap animations
	int frameCounter, j;
};

#endif /* SDLGHOST_H_ */
