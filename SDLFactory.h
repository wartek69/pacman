/*
 * SDLFactory.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef SDLFACTORY_H_
#define SDLFACTORY_H_

#include "AbstractFactory.h"
#include "Ghost.h"
#include "SDLGhost.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "Timer.h"


class SDLFactory: public AbstractFactory {
public:
	SDLFactory();
	virtual ~SDLFactory();
	Ghost* createGhost(int posX, int posY, int type) override;
	Pacman* createPacman(int posX, int posY) override;
	Timer* createTimer() override;
	Wall* createWall(int posX, int posY, int type) override;
	bool createWindow();
	bool loadSpriteSheet();
	bool loadFromFile(string path);
	void close();
	void clearScreen() override;
	void showScreen() override;
	InputHandler* createInputHandler(Pacman* handleObject) override;

private:
	bool init();
	SDL_Window* window;
	SDL_Surface* gScreenSurface;
	SDL_Renderer* gRenderer;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	//TODO
	SDL_Texture* spriteSheet;
};

#endif /* SDLFACTORY_H_ */
