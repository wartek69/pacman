/*
 * SDLClyde.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLCLYDE_H_
#define SDLCLYDE_H_

#include "Clyde.h"
#include "SDLGhost.h"

namespace SDL {

class SDLClyde: public Logic::Clyde, public SDLGhost {
public:
	SDLClyde(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<Logic::WorldObjects> world);
	virtual ~SDLClyde();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;
	void findPath(const Logic::MovingEntity& entity) override;

};

} /* namespace SDL */

#endif /* SDLCLYDE_H_ */
