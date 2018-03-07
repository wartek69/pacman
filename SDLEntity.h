/*
 * SDLEntity.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLENTITY_H_
#define SDLENTITY_H_

#include "Entity.h"
#include <SDL2/SDL.H>
/**
 * every sdl instance will make use of a renderer and spritesheet, further is the currentsprite needed to make
 * animations possible.
 */
class SDLEntity {
public:
	SDLEntity(int rectX, int rectY, int rectW, int rectH,SDL_Renderer* gRenderer, SDL_Texture* spriteSheet) ;
	virtual ~SDLEntity();
	//virtual void loadSprites() = 0;
	void visualize(int posX, int posY);
protected:
	SDL_Rect currentSprite;
	SDL_Renderer* gRenderer;
	SDL_Texture* spriteSheet;
};

#endif /* SDLENTITY_H_ */
