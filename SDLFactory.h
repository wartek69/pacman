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
#include <memory>
#include "ConfigParser.h"


class SDLFactory: public AbstractFactory {
public:
	SDLFactory();
	virtual ~SDLFactory();
	shared_ptr<Ghost> createGhost(int posX, int posY, int type, shared_ptr<WorldObjects> world) override;
	shared_ptr<Pacman> createPacman(int posX, int posY) override;
	unique_ptr<Timer> createTimer() override;
	shared_ptr<Wall> createWall(int posX, int posY, int type) override;
	shared_ptr<Dot> createDot(int posX, int posY) override;
	unique_ptr<ScoreHandler> createScoreHandler() override;
	unique_ptr<Menu> createMenu(shared_ptr<AbstractFactory> F) override;
	shared_ptr<WorldObjects> createWorld(int width, int height) override;
	shared_ptr<Logic::PowerUp> createPowerUp(int posX, int posY, shared_ptr<Timer> timer) override;
	shared_ptr<Logic::Cherry> createCherry(int posX, int posY, shared_ptr<ScoreHandler> score) override;
	bool createWindow();
	bool loadSpriteSheet();
	bool loadFromFile(string path);
	void close();
	void clearScreen() override;
	void showScreen() override;
	unique_ptr<InputHandler> createInputHandler(shared_ptr<Pacman> handleObject) override;
	unique_ptr<Logic::SoundManager> createSoundManager() override;
	unique_ptr<Logic::TextHandler> createTextHandler() override;

private:
	bool init();
	SDL_Window* window;
	SDL_Surface* gScreenSurface;
	SDL_Renderer* gRenderer;
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 530;
	SDL_Texture* spriteSheet;
	Config::ConfigParser config;
};

#endif /* SDLFACTORY_H_ */
