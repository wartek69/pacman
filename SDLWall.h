/*
 * SDLWall.h
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLWALL_H_
#define SDLWALL_H_

#include "SDLEntity.h"
#include "Wall.h"

class SDLWall: public Wall, public SDLEntity {
public:
	SDLWall(SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, int type);
	virtual ~SDLWall();
	void visualize() override;
private:
	SDLWall();		//Default constructor shouldn't be used
	//has to be static --> the variables need to have a value at compile time
	static const int rectX = 0;
	static const int rectY = 96;
	static const int rectW = 24;
	static const int rectH = 24;
	static const int amountOfSprites = 6;
	void setActiveSprite(int type);
	void loadSprites();
	SDL_Rect sprites[amountOfSprites];
};

#endif /* SDLWALL_H_ */
