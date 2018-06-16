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
	void eatFruit() override;
	void munch() override;
	void die() override;
	void eatGhost() override;
	void win() override;
	void menu() override;
	void stopMusic() override;
private:
	Mix_Chunk* munchSound;
	Mix_Chunk* fruit;
	Mix_Chunk* ghost;
	Mix_Music* intro;
	Mix_Chunk* death;
	Mix_Chunk* winSound;
};

} /* namespace SDL */

#endif /* SDLSOUNDMANAGER_H_ */
