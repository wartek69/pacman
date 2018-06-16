/*
 * SDLPacman.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "SDLPacman.h"
#include "Pacman.h"
#include "SDLEntity.h"
#include "Entity.h"
#include "Types.h"
#include <iostream>
using namespace std;
namespace SDL {
SDLPacman::SDLPacman(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
Logic::Pacman(posX, posY), SDL::SDLMovingEntity(data, gRenderer, spriteSheet) {
	loadSprites();
	frameCounter = 0;
	j = 0;
	dyingCounter = 0;
	isDead = false;
}

SDLPacman::~SDLPacman() {
}
//loads sprites from the spriteSheet
void SDLPacman::loadSprites() {
	//currentSprite is the first sprite that got initiliased
	//from the current sprite the other sprites can be calculated depending on the spriteSheet

	//fill the array with the sprites for pacman
	//cout << "testtt" << endl;

	for(int i = 0;i < 8;i++) {
		sprites[i] = currentSprite;
		currentSprite.x = currentSprite.x + currentSprite.w;
	}
	currentSprite.y = currentSprite.y + 4*currentSprite.h;
	currentSprite.x = currentSprite.x - 8*currentSprite.w;
	//sprite for a closed pacman
	sprites[P_CLOSED] = currentSprite;
	//sprites for dead animation
	currentSprite.x = currentSprite.x + 4*currentSprite.w;
	for(int i = 0;i < 12;i++) {
		deadSprites[i] = currentSprite;
		currentSprite.x = currentSprite.x + currentSprite.w;
	}
	//default value
	currentSprite = sprites[7];

}
void SDLPacman::move(int direction, int velocity) {
	//call base class move
	Logic::MovingEntity::move(direction, velocity);
	//animations
	int temp;
	float multiplyFactor = 0.8f;

	switch(dir) {
		case FORWARD:
			temp = P_FORWARD;
		break;
		case BACKWARD:
			temp = P_BACKWARD;
		break;
		case LEFT:
			temp = P_LEFT;
		break;
		case RIGHT:
			temp = P_RIGHT;
		break;
	}

	//next part of code switches the picture every multiplyFactor of frames
		if(vel == 0) {
			//the pacman isn't moving, --> mouth is half open
			currentSprite = sprites[temp+2];
		} else {
			if(frameCounter>3*(multiplyFactor/abs(velocity))) {
				j = 2;
				frameCounter = 0;
			} else if(frameCounter > 2*(multiplyFactor/abs(velocity))) {
				j = 1;
			} else if(frameCounter > (multiplyFactor/abs(velocity))) {
				j = 0;
			}

			if(j == 1) {
				currentSprite = sprites[temp+2];
			} else if(j == 2) {
				currentSprite = sprites[8];
			} else {
				currentSprite = sprites[temp];
			}
		}

	frameCounter++;
}

/**
 * visualizes every frame individually
 */
void SDLPacman::visualize(int frame) {
	SDL::SDLMovingEntity::visualize(position.x, position.y, vel, dir, frame);
}

bool SDLPacman::die() {
	vel = 0;
	if(dyingCounter < 12) {
		currentSprite = deadSprites[dyingCounter];
		dyingCounter++;
		return true;
	} else
		return false;
}
}
