/*
 * SDLWorldObjects.h
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLWORLDOBJECTS_H_
#define SDLWORLDOBJECTS_H_

#include "WorldObjects.h"
#include <SDL2\SDL.h>
#include "ScoreHandler.h"

class SDLWorldObjects: public WorldObjects {
public:
	SDLWorldObjects(SDL_Renderer* gRenderer);
	virtual ~SDLWorldObjects();
	void visualize(const std::shared_ptr<ScoreHandler>& score) override;
private:
	int frames;
	SDL_Renderer* gRenderer;
};

#endif /* SDLWORLDOBJECTS_H_ */
