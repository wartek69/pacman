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


class AbstractFactory {
public:
	AbstractFactory();
	virtual ~AbstractFactory();
	//pure virtual declaration
	virtual Ghost* createGhost(int posX, int posY, int type) = 0;
	virtual Pacman* createPacman(int posX, int posY) = 0;
	virtual Wall* createWall(int posX, int posY, int type) = 0;
	virtual void clearScreen() = 0;
	virtual void showScreen() = 0;
	virtual Timer* createTimer() = 0;
	virtual InputHandler* createInputHandler(Pacman* handleObject) = 0;
};

#endif /* ABSTRACTFACTORY_H_ */
