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

SDLMovingEntity::SDLMovingEntity(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet)
	:SDLEntity(data, gRenderer, spriteSheet)	{

}

SDLMovingEntity::~SDLMovingEntity() {

}
/**
 * This function translates the game world coordinates to sdl coordinates
 * it takes in consideration the screen size, the game world grid size and the amount of frames that we delay our world with(frameDelay).
 */
void SDLMovingEntity::visualize(int posX, int posY, int vel, int dir, int frame) {
	//TODO change the currentsprite h and w to another variable that contains the value of screenwidth/amounts of rows--> how to get these parameters here??
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
			SDLY = posY * tileDimensions.height - frame * (tileDimensions.height / frameDelay * velFactor) + tileDimensions.height;
			break;

		case BACKWARD:
			SDLY = posY * tileDimensions.height + frame * (tileDimensions.height / frameDelay * velFactor) - tileDimensions.height;
			break;

		case RIGHT:
			SDLX = posX * tileDimensions.width + frame * (tileDimensions.width / frameDelay * velFactor) - tileDimensions.width;
			break;

		case LEFT:
			SDLX = posX * tileDimensions.width - frame * (tileDimensions.width / frameDelay * velFactor) + tileDimensions.width;
			break;
		default:
			//default value
			//this state is only used when the entity is initialized
			SDLX = posX * tileDimensions.width;
			SDLY = posY * tileDimensions.height;
			break;
	}
	SDLEntity::visualize();

}

} /* namespace SDL */
