/*
 * InputHandler.cpp
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#include "InputHandler.h"
#include "Pacman.h"
#include <memory>
namespace Logic {
InputHandler::InputHandler(std::shared_ptr<Logic::Pacman> handleObject):handleObject(handleObject) {

}

InputHandler::~InputHandler() {

}
}
