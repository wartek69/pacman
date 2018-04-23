/*
 * SDLPowerUp.h
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#ifndef SDLPOWERUP_H_
#define SDLPOWERUP_H_

#include "PowerUp.h"
#include "SDLEntity.h"

namespace SDL {

class SDLPowerUp: public Logic::PowerUp, public SDLEntity {
public:
	SDLPowerUp(Config::Data data, SDL_Renderer* gRenderer, SDL_Texture* spriteSheet, int posX, int posY, std::shared_ptr<Timer> timer);
	virtual ~SDLPowerUp();
	void visualize(int frame) override;
private:
	int frameCounter;
	int toggle;
};

} /* namespace SDL */

#endif /* SDLPOWERUP_H_ */
