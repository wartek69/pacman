/*
 * InputHandler.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "Pacman.h"
#include <memory>

class InputHandler {
public:
	InputHandler(std::shared_ptr<Pacman> handleObject);
	virtual ~InputHandler();
	virtual void handleInput(bool& quit,int& direction, int& velocity) = 0;
	virtual void handleEndScreen(bool& quit, bool& repeat) = 0;
protected:
	std::shared_ptr<Pacman> handleObject;
};

#endif /* INPUTHANDLER_H_ */
