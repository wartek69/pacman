/*
 * SDLPinky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLPINKY_H_
#define SDLPINKY_H_

#include "Pinky.h"
#include "SDLGhost.h"

namespace SDL {

class SDLPinky: public Logic::Pinky, public SDL::SDLGhost {
public:
	SDLPinky(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world);
	virtual ~SDLPinky();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;
	void findPath(const Logic::MovingEntity& entity) override;
};

} /* namespace SDL */

#endif /* SDLPINKY_H_ */
