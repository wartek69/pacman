/*
 * InputHandler.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include "Pacman.h"

class InputHandler {
public:
	InputHandler(Pacman* handleObject);
	virtual ~InputHandler();
	virtual void handleInput(bool& quit,int& direction, int& velocity) = 0;
protected:
	Pacman* handleObject;
};

#endif /* INPUTHANDLER_H_ */
