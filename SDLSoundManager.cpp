/*
 * SDLSoundManager.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "SDLSoundManager.h"
#include <iostream>

namespace SDL {

SDLSoundManager::SDLSoundManager() {
	LoadMusic();
}

SDLSoundManager::~SDLSoundManager() {
	close();
}

void SDLSoundManager::LoadMusic() {
	munchSound = Mix_LoadWAV("pacman_chomp.wav");
	fruit = Mix_LoadWAV("pacman_eatfruit.wav");
	ghost = Mix_LoadWAV("pacman_eatghost.wav");
	intro = Mix_LoadWAV("pacman_beginning.wav");

	if(munchSound == NULL || fruit == NULL || ghost == NULL || intro == NULL) {
		std::cout << "Failed to load sound effect: " << Mix_GetError() << std::endl;
	}
}

void SDLSoundManager::close() {
	//Free the sound effects
	    Mix_FreeChunk( munchSound );
	    Mix_FreeChunk( fruit );
	    Mix_FreeChunk( ghost );
	    Mix_FreeChunk( intro );
	    munchSound = NULL;
	    fruit = NULL;
	    ghost = NULL;
	    intro = NULL;
}

void SDLSoundManager::munch() {
	Mix_PlayChannel(1, munchSound, 0);
}

void SDLSoundManager::eatFruit() {
	Mix_PlayChannel(1, fruit, 0);
}

} /* namespace SDL */
