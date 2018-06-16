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

namespace SDL {
SDLGhost::SDLGhost(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet):
		SDL::SDLMovingEntity(data, gRenderer, spriteSheet) {
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
	//add the frigthened animation sprites
	SDL_Rect frightenedSprite = {data.getData(WHITE).x, data.getData(WHITE).y, data.getData(WHITE).w, data.getData(WHITE).h};
	for(int i = WHITE; i < WHITE + 4; i++) {
		sprites[i] = frightenedSprite;
		frightenedSprite.x = frightenedSprite.x + frightenedSprite.w;
	}

	//add the dead animation sprites
	SDL_Rect deadSprite = {data.getData(EATEN).x, data.getData(EATEN).y, data.getData(EATEN).w, data.getData(EATEN).h};
	for(int i = EATEN; i < EATEN+4; i++) {
		sprites[i] = deadSprite;
		deadSprite.x = deadSprite.x + 2*deadSprite.w;
	}

	//default value
	currentSprite = sprites[RIGHT];
}

void SDLGhost::showOnScreen(int posX, int posY, int velocity, int direction, int frame) {
	SDL::SDLMovingEntity::visualize(posX, posY, velocity, direction, frame);
}

void SDLGhost::animation(int direction, int velocity, bool eaten) {
	int multiplyFactor = 1;
	//switching sprites, every picture gets displayed for multiplyFactor frames
	if(eaten) {
		currentSprite = sprites[EATEN + direction];
	} else if(Logic::Ghost::getMode() == CHASE || Logic::Ghost::getMode() == SCATTER) {
		if(frameCounter > 2*(multiplyFactor/velocity)) {
			j = 1;
			frameCounter = 0;
		} else if(frameCounter > multiplyFactor/velocity){
			j = 0;
		}

		if(j == 0) {
				currentSprite = sprites[direction];
		} else {
				currentSprite = sprites[direction + 4];
		}
	} else if (Logic::Ghost::getMode() == FRIGHTENED && Logic::Ghost::getBlink() == true) {
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
	} else if(Logic::Ghost::getMode() == FRIGHTENED){
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
	}
	frameCounter++;



}
}
