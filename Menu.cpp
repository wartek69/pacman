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
}

void Menu::startGame() {
	bool repeat;
	do {
		repeat = false;
		unique_ptr<Game> game = make_unique<Game>(F);
		game->start(repeat);
	}while(repeat);

}
