/*
 * SDLBlinky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLBLINKY_H_
#define SDLBLINKY_H_

#include "Blinky.h"
#include "SDLGhost.h"

namespace SDL {

class SDLBlinky: public Logic::Blinky, public SDLGhost {
public:
	SDLBlinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~SDLBlinky();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;
	void findPath(const MovingEntity& entity) override;
};

} /* namespace SDL */

#endif /* SDLBLINKY_H_ */
