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
#include "ScoreHandler.h"
#include <memory>


class AbstractFactory {
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	//pure virtual declaration
	virtual shared_ptr<Ghost> createGhost(int posX, int posY, int type) = 0;
	virtual shared_ptr<Pacman> createPacman(int posX, int posY) = 0;
	virtual shared_ptr<Wall> createWall(int posX, int posY, int type) = 0;
	virtual shared_ptr<Dot> createDot(int posX, int posY) = 0;
	virtual void clearScreen() = 0;
	virtual void showScreen() = 0;
	virtual unique_ptr<Timer> createTimer() = 0;
	virtual unique_ptr<InputHandler> createInputHandler(shared_ptr<Pacman> handleObject) = 0;
	virtual unique_ptr<ScoreHandler> createScoreHandler() = 0;
};

#endif /* ABSTRACTFACTORY_H_ */
