/*
 * SDLPacman.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLPACMAN_H_
#define SDLPACMAN_H_

#include "Pacman.h"
#include <SDL2\SDL.h>
#include "SDLEntity.h"
#include "Entity.h"

class SDLPacman:public Pacman,public SDLEntity {
public:
	SDLPacman(int x, int y, int w, int h,SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLPacman();
	void move(int direction, int velocity) override;
	void loadSprites();
	void visualize(int frame) override;
private:
	//9 sprites needed t animate and move the pacman
	SDL_Rect sprites[9];
	int frameCounter, j;


};

#endif /* SDLPACMAN_H_ */
