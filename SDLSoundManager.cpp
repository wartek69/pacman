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
	intro = Mix_LoadMUS("pacman_beginning.wav");
	death = Mix_LoadWAV("pacman_death.wav");
	winSound = Mix_LoadWAV("pacman_intermission.wav");


	if(munchSound == NULL || fruit == NULL || ghost == NULL || intro == NULL) {
		std::cout << "Failed to load sound effect: " << Mix_GetError() << std::endl;
	}
}

void SDLSoundManager::close() {
	//Free the sound effects
	    Mix_FreeChunk(munchSound);
	    Mix_FreeChunk(fruit);
	    Mix_FreeChunk(ghost);
	    Mix_FreeMusic(intro);
	    Mix_FreeChunk(death);
	    Mix_FreeChunk(winSound);
	    munchSound = NULL;
	    fruit = NULL;
	    ghost = NULL;
	    intro = NULL;
	    death = NULL;
	    winSound = NULL;
}

void SDLSoundManager::munch() {
	//if(Mix_PlayingMusic() == 0)
	//Mix_HaltChannel(-1);
	//Mix_HaltMusic();
	Mix_PlayChannel(1, munchSound, 0);
}

void SDLSoundManager::eatFruit() {
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	Mix_PlayChannel(-1, fruit, 0);
}

void SDLSoundManager::eatGhost() {
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	Mix_PlayChannel(-1, ghost, 0);
}

void SDLSoundManager::die() {
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	Mix_PlayChannel(-1, death, 0);
	/*Mix_HaltChannel(-1);
			Mix_HaltMusic();
			Mix_PlayChannel(-1,lost,0);*/
}

void SDLSoundManager::win() {
	Mix_HaltChannel(-1);
	Mix_HaltMusic();
	Mix_PlayChannel(-1, winSound, 0);
}

void SDLSoundManager::menu() {
	Mix_PlayMusic( intro,1 );
}

void SDLSoundManager::stopMusic() {
	Mix_HaltMusic();
}

} /* namespace SDL */
