/*
 * SDLSoundManager.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef SDLSOUNDMANAGER_H_
#define SDLSOUNDMANAGER_H_

#include "SoundManager.h"
#include <SDL2\SDL_mixer.h>

namespace SDL {

class SDLSoundManager: public Logic::SoundManager {
public:
	SDLSoundManager();
	virtual ~SDLSoundManager();
	void LoadMusic();
	void close();
	void eatFruit();
	void munch() override;
private:
	Mix_Chunk* munchSound;
	Mix_Chunk* fruit;
	Mix_Chunk* ghost;
	Mix_Chunk* intro;
};

} /* namespace SDL */

#endif /* SDLSOUNDMANAGER_H_ */
