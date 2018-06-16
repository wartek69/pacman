/*
 * SDLInputHandler.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef SDLINPUTHANDLER_H_
#define SDLINPUTHANDLER_H_

#include "InputHandler.h"
#include <memory>
namespace SDL {
class SDLInputHandler: public Logic::InputHandler {
public:
	SDLInputHandler(std::shared_ptr<Logic::Pacman> handleObject);
	virtual ~SDLInputHandler();
	void handleInput(bool& quit, int& direction,int& velocity);
	void handleEndScreen(bool& quit, bool& repeat);

private:

};
}
#endif /* SDLINPUTHANDLER_H_ */
