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
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

class SDLGhost: public Ghost, public SDLEntity {
public:
	SDLGhost(int x, int y, int w, int h,SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLGhost();
	void move(int direction, int velocity) override;
	void visualize() override;
	void loadSprites();
private:
	SDL_Rect sprites[8];
	int frameCounter, j;
};

#endif /* SDLGHOST_H_ */
