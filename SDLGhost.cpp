/*
 * SDLGhost.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#include "SDLGhost.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "types.h"

using namespace std;


SDLGhost::SDLGhost(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet):
		SDLMovingEntity(rectX, rectY, rectW, rectH, gRenderer, spriteSheet) {
		loadSprites();
		frameCounter = 0;
		j = 0;
}

SDLGhost::~SDLGhost() {
}

void SDLGhost::loadSprites() {
	for(int i = 0; i<4;i++) {
		sprites[i] = currentSprite;
		//2nd texture same direction to create ghost animation
		currentSprite.x = currentSprite.x + currentSprite.w;
		sprites[i+4] = currentSprite;
		currentSprite.x = currentSprite.x + currentSprite.w;

		//add the dead animation sprites
	}
	//add the dead animation sprites
	//TODO config file this
	SDL_Rect frightenedSprite = {143, 95, 24, 24};
	for(int i = 8; i< 12; i++) {
		sprites[i] = frightenedSprite;
		frightenedSprite.x = frightenedSprite.x + frightenedSprite.w;
	}
	//default value
	currentSprite = sprites[RIGHT];
}

void SDLGhost::showOnScreen(int posX, int posY, int velocity, int direction, int frame) {
	SDL::SDLMovingEntity::visualize(posX, posY, velocity, direction, frame);
}

void SDLGhost::animation(int direction, int velocity) {
	int temp = 0;
	int multiplyFactor = 1;

	switch(direction) {
		case FORWARD:
			temp = FORWARD;
		break;
		case BACKWARD:
			temp = BACKWARD;
		break;
		case LEFT:
			temp = LEFT;
		break;
		case RIGHT:
			temp = RIGHT;
		break;
	}

	//switching sprites, every picture gets displayed for multiplyFactor frames
	if(Ghost::getMode() == CHASE || Ghost::getMode() == SCATTER) {
		if(frameCounter > 2*(multiplyFactor/velocity)) {
			j = 1;
			frameCounter = 0;
		} else if(frameCounter > multiplyFactor/velocity){
			j = 0;
		}

		if(j == 0) {
			currentSprite = sprites[temp];
		} else {
			currentSprite = sprites[temp+4];
		}
	} else if(Ghost::getMode() == FRIGHTENED){
		if(frameCounter > 2*(multiplyFactor/velocity)) {
			j = 1;
			frameCounter = 0;
		} else if(frameCounter > multiplyFactor/velocity){
			j = 0;
		}

		if(j == 0) {
			currentSprite = sprites[BLUE];
		} else {
			currentSprite = sprites[BLUE + 1];
		}
	} else {
		//animations when ghost are frightened and time is running out
		if(frameCounter > 4*(multiplyFactor/velocity)) {
			j = 3;
			frameCounter = 0;
		} else if(frameCounter > 3*(multiplyFactor/velocity)) {
			j = 2;
		} else if(frameCounter > 2*(multiplyFactor/velocity)) {
			j = 1;
		} else if(frameCounter > (multiplyFactor/velocity)) {
			j = 0;
		}

		if(j == 3) {
			currentSprite = sprites[WHITE];
		} else if(j == 2) {
			currentSprite = sprites[WHITE + 1];
		} else if(j == 1) {
			currentSprite = sprites[BLUE];
		} else if(j == 0) {
			currentSprite = sprites[BLUE+1];
		}
	}
	frameCounter++;



}

