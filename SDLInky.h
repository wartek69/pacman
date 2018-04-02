/*
 * SDLInky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLINKY_H_
#define SDLINKY_H_

#include "Inky.h"
#include "SDLGhost.h"

namespace SDL {

class SDLInky: public Logic::Inky, public SDLGhost {
public:
	SDLInky(int rectX, int rectY, int rectW, int rectH, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~SDLInky();
	void move(int direction, int velocity) override;
	void visualize(int frame) override;
	void findPath(const MovingEntity& entity) override;
};

} /* namespace SDL */

#endif /* SDLINKY_H_ */
