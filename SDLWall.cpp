/*
 * SDLWall.cpp
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#include "SDLWall.h"
#include "Types.h"
#include <iostream>
using namespace std;

SDLWall::SDLWall( SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, int type) :
Wall(posX,posY), SDLEntity(rectX ,rectY ,rectW, rectH, gRenderer, spriteSheet, posX*24, posY*24) {
	//loads all wall sprites
	//cout << rectY << endl;
	loadSprites();
	setActiveSprite(type);


}

SDLWall::~SDLWall() {
	// TODO Auto-generated destructor stub
}
void SDLWall::setActiveSprite(int type) {
	//do -1 because enum starts at 1
	currentSprite = sprites[type-1];
}
void SDLWall::visualize() {
	SDLEntity::visualize();
}
/**
 * loads up all the sprites that are needed for the walls
 * starting from one sprite
 */
void SDLWall::loadSprites() {
	for(int i = 0;i<amountOfSprites;i++) {
		sprites[i] = currentSprite;
		currentSprite.x = currentSprite.x+currentSprite.w;
	}
	//set default value
	currentSprite = sprites [HWALL-1];
}
