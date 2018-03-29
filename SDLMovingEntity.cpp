/*
 * SDLMovingEntity.cpp
 *
 *  Created on: 28 mrt. 2018
 *      Author: Alex
 */

#include "SDLMovingEntity.h"
#include "Types.h"
#include <iostream>

namespace SDL {

SDLMovingEntity::SDLMovingEntity(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet)
	:SDLEntity(rectX, rectY, rectW, rectH, gRenderer, spriteSheet)	{

}

SDLMovingEntity::~SDLMovingEntity() {

}

void SDLMovingEntity::visualize(int posX, int posY, int vel, int dir, int frame) {
	int velFactor = 0;
	if(vel == 0) {
		velFactor = 1;
		//frameDelay is a constant that specifies with how much the game loop is delayed
		frame = frameDelay;
	}
	else
		velFactor = vel;
	switch (dir) {
		case FORWARD:
			SDLY = posY * currentSprite.h - frame * (currentSprite.h / frameDelay * velFactor) + currentSprite.h;
			break;

		case BACKWARD:
			SDLY = posY * currentSprite.h + frame * (currentSprite.h / frameDelay * velFactor) - currentSprite.h;
			break;

		case RIGHT:
			SDLX = posX * currentSprite.w + frame * (currentSprite.h / frameDelay * velFactor) - currentSprite.w;
			break;

		case LEFT:
			SDLX = posX * currentSprite.w - frame * (currentSprite.h / frameDelay * velFactor) + currentSprite.w;
			break;
		default:
			//default value
			//this state is only used when the entity is initialized
			SDLX = posX * currentSprite.w;
			SDLY = posY * currentSprite.h;
			break;
	}
	SDLEntity::visualize();

}

} /* namespace SDL */
