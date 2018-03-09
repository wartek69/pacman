/*
 * SDLInputHandler.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef SDLINPUTHANDLER_H_
#define SDLINPUTHANDLER_H_

#include "InputHandler.h"

class SDLInputHandler: public InputHandler {
public:
	SDLInputHandler(Pacman* handleObject);
	virtual ~SDLInputHandler();
	void handleInput(bool& quit, int& direction,int& velocity);
private:

};

#endif /* SDLINPUTHANDLER_H_ */
