/*
 * Menu.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#include "Menu.h"
#include "Game.h"
#include <memory>

Menu::Menu(shared_ptr<AbstractFactory> F): F(F) {

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::startGame() {
	unique_ptr<Game> game = make_unique<Game>(F);
	game->start();
}
