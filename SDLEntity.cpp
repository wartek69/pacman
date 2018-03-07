/*
 * SDLEntity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "SDLEntity.h"
#include <SDL2\SDL.h>
#include <iostream>
using namespace std;

SDLEntity::SDLEntity(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet) {
	//gets the coordinates to get the right sprite from the spritesheet
	SDL_Rect clip ;
	clip.x = rectX;
	clip.y = rectY;
	clip.w = rectW;
	clip.h = rectH;

	//initializes the renderer and sprite sheet
	this->gRenderer = gRenderer;
	this->spriteSheet = spriteSheet;
	this->currentSprite = clip;
}

SDLEntity::~SDLEntity() {
	// TODO
}

void SDLEntity::visualize(int posX, int posY) {
	//SDL_RenderSetScale(gRenderer,1.5,1.5);
	//Set rendering space and render to screen

	SDL_Rect renderQuad = {posX, posY, currentSprite.w, currentSprite.h};
	SDL_RenderCopy(gRenderer, spriteSheet, &currentSprite, &renderQuad);
}

