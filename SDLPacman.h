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
#include "SDLMovingEntity.h"
#include "Entity.h"
namespace SDL {
class SDLPacman:public Logic::Pacman,public SDL::SDLMovingEntity {
public:
	SDLPacman(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY);
	virtual ~SDLPacman();
	void move(int direction, int velocity) override;
	void loadSprites();
	void visualize(int frame) override;
	bool die() override;
private:
	//9 sprites needed t animate and move the pacman
	SDL_Rect sprites[9];
	SDL_Rect deadSprites[12];
	int frameCounter, j;
	int dyingCounter;
	bool isDead;


};
}
#endif /* SDLPACMAN_H_ */
