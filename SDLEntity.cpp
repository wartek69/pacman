/*
 * SDLEntity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "SDLEntity.h"
#include <SDL2\SDL.h>
#include <iostream>
#include "Types.h"
using namespace std;

SDLEntity::SDLEntity(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet) {
	this-> data = data;
	//gets the coordinates to get the right sprite from the spritesheet
	SDL_Rect clip ;
	clip.x = data.getData(0).x;
	clip.y = data.getData(0).y;
	clip.w = data.getData(0).w;
	clip.h = data.getData(0).h;
	//TODO  ??
	SDLX = 200;
	SDLY = 200;
	//initializes the renderer and sprite sheet
	this->gRenderer = gRenderer;
	this->spriteSheet = spriteSheet;
	this->currentSprite = clip;
}

SDLEntity::~SDLEntity() {
}

void SDLEntity::visualize() {
	//SDL_RenderSetScale(gRenderer,1.5,1.5);
	//Set rendering space and render to screen

	SDL_Rect renderQuad = {SDLX, SDLY, currentSprite.w, currentSprite.h};
	SDL_RenderCopy(gRenderer, spriteSheet, &currentSprite, &renderQuad);

}

