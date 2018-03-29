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


SDLGhost::SDLGhost(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY):
		Ghost(posX, posY), SDLMovingEntity(rectX, rectY, rectW, rectH, gRenderer, spriteSheet) {
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

	}
	/*sprites[RIGHT] = currentSprite;
	currentSprite.x = currentSprite.x + 2*currentSprite.w;
	sprites[BACKWARD] = currentSprite;
	currentSprite.x = currentSprite.x + 2*currentSprite.w;
	sprites[LEFT] = currentSprite;
	currentSprite.x = currentSprite.x + 2*currentSprite.w;
	sprites[FORWARD] = currentSprite;
*/
	//default value
	currentSprite = sprites[RIGHT];
}

void SDLGhost::visualize(int frame) {
	SDL::SDLMovingEntity::visualize(position.x, position.y, vel, dir, frame);
}

void SDLGhost::move(int direction, int velocity) {
	int temp = 0;
	int multiplyFactor = 1;

	Ghost::move(direction, velocity);
	switch(dir) {
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

	if(frameCounter > 2*(multiplyFactor/vel)) {
		j = 1;
		frameCounter = 0;
	} else if(frameCounter > multiplyFactor/vel){
		j = 0;
	}

	if(j == 0) {
		currentSprite = sprites[temp];
	} else {
		currentSprite = sprites[temp+4];
	}
	frameCounter++;


}

