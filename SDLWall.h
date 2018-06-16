/*
 * SDLWall.h
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLWALL_H_
#define SDLWALL_H_

#include "SDLEntity.h"
#include "Wall.h"
namespace SDL {
class SDLWall: public Logic::Wall, public SDL::SDLEntity {
public:
	SDLWall(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, int type);
	virtual ~SDLWall();
	void visualize(int frame) override;
private:
	SDLWall();		//Default constructor shouldn't be used
	void setActiveSprite(int type);
	void loadSprites();
	SDL_Rect sprites[7];
};
}
#endif /* SDLWALL_H_ */
