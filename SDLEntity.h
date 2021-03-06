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
#include "Data.h"
namespace SDL {
/**
 * every sdl instance will make use of a renderer and spritesheet
 * the currentsprite is needed to make
 * animations possible.
 */
class SDLEntity {
public:
	SDLEntity(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet) ;
	virtual ~SDLEntity();
	//virtual void loadSprites() = 0;
	void visualize();
	static void setTileDimensions(int width, int height);
protected:
	int SDLX;
	int SDLY;
	SDL_Rect currentSprite;
	SDL_Renderer* gRenderer;
	SDL_Texture* spriteSheet;
	Config::Data data;
	static Size tileDimensions;

};
}
#endif /* SDLENTITY_H_ */
