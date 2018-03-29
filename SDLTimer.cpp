/*
 * SDLTimer.cpp
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#include "SDLTimer.h"
#include <SDL2\SDL.h>
#include <iostream>


using namespace std;

SDLTimer::SDLTimer(): startTime(0), isStarted(false), passedTime(0), isPaused(false){
}

SDLTimer::~SDLTimer() {
}

void SDLTimer::startTimer() {
	startTime = SDL_GetTicks();
	isStarted = true;
}

void SDLTimer::stopTimer() {
	startTime = 0;
	isStarted = false;
}

int SDLTimer::getTimePassed() {
	if(isStarted ) {
		return (SDL_GetTicks() - startTime);
	}  else {
		cout << "The timer wasn't running" << endl;
		return -1;
	}
}

void SDLTimer::Delay(int delay) {
	SDL_Delay(delay);
}

void SDLTimer::pause() {
	isPaused = true;
	passedTime = SDL_GetTicks() - startTime;
}

void SDLTimer::resume() {
	if(isPaused)
		startTime = SDL_GetTicks() - passedTime;
	else
		cout << "can't resume, timer wasn't paused" << endl;
	isPaused = false;
}
