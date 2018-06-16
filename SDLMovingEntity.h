/*
 * SDLMovingEntity.h
 *
 *  Created on: 28 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLMOVINGENTITY_H_
#define SDLMOVINGENTITY_H_

#include "SDLEntity.h"

namespace SDL {
class SDLMovingEntity: public SDL::SDLEntity {
public:
	SDLMovingEntity(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet);
	virtual ~SDLMovingEntity();
	void visualize(int posX, int posY, int vel, int dir, int frame);

};

} /* namespace SDL */

#endif /* SDLMOVINGENTITY_H_ */
