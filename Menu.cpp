/*
 * Menu.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#include "Menu.h"
#include "Game.h"
#include <memory>
namespace Logic {
Menu::Menu(shared_ptr<Logic::AbstractFactory> F): F(F) {

}

Menu::~Menu() {
}

void Menu::startGame() {
	bool repeat;
	do {
		repeat = false;
		unique_ptr<Logic::Game> game = make_unique<Logic::Game>(F);
		game->start(repeat);
	}while(repeat);

}
}
