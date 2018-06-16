/*
 * AbstractFactory.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include "Ghost.h"
#include "Timer.h"
#include "Pacman.h"
#include "InputHandler.h"
#include "Wall.h"
#include "Dot.h"
#include "PowerUp.h"
#include "ScoreHandler.h"
#include "WorldObjects.h"
#include "Cherry.h"
#include <memory>
#include "SoundManager.h"
#include "TextHandler.h"

//needed to break cyclic redundancy

namespace Logic {
class Menu;

class AbstractFactory {
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	//pure virtual declaration
	virtual shared_ptr<Logic::Ghost> createGhost(int posX, int posY, int type, shared_ptr<WorldObjects> world) = 0;
	virtual shared_ptr<Logic::Pacman> createPacman(int posX, int posY) = 0;
	virtual shared_ptr<Logic::Wall> createWall(int posX, int posY, int type) = 0;
	virtual shared_ptr<Logic::Dot> createDot(int posX, int posY) = 0;
	virtual shared_ptr<Logic::PowerUp> createPowerUp(int posX, int posY, shared_ptr<Timer>) = 0;
	virtual shared_ptr<Logic::Cherry> createCherry(int posX, int posY, shared_ptr<ScoreHandler> score) = 0;
	virtual void clearScreen() = 0;
	virtual void showScreen() = 0;
	virtual unique_ptr<Logic::Timer> createTimer() = 0;
	virtual unique_ptr<Logic::InputHandler> createInputHandler(shared_ptr<Logic::Pacman> handleObject) = 0;
	virtual unique_ptr<Logic::ScoreHandler> createScoreHandler() = 0;
	virtual unique_ptr<Logic::SoundManager> createSoundManager() = 0;
	virtual unique_ptr<Logic::TextHandler> createTextHandler() = 0;
	virtual unique_ptr<Logic::Menu> createMenu(shared_ptr<Logic::AbstractFactory> F) = 0;
	virtual shared_ptr<Logic::WorldObjects> createWorld(int width, int height) = 0;
};
}
#endif /* ABSTRACTFACTORY_H_ */
