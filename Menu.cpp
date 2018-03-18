/*
 * Menu.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#include "Menu.h"
#include "Game.h"
#include "AbstractFactory.h"
#include <memory>

namespace SDL {

Menu::Menu() {
	// TODO Auto-generated constructor stub

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::startGame(shared_ptr<AbstractFactory> F) {
	unique_ptr<Game> game = make_unique<Game>(F);
}


} /* namespace SDL */
