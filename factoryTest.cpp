//============================================================================
// Name        : factoryTest.cpp
// Author      : Alex
// Version     :
// Copyright   : Oef2a
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>

#include "AbstractFactory.h"
#include "SDLFactory.h"
#include "Game.h"
#include "Menu.h"
using namespace std;


int main( int argc, char* args[] ) {
	//AbstractFactory *F = new SDLFactory();
	shared_ptr<Logic::AbstractFactory> F = make_shared<SDL::SDLFactory>();
	bool quit = false ;
	unique_ptr<Logic::Menu> menu = F->createMenu(F);
	while(!quit) {
		F->clearScreen();
		menu->interact(quit);
		menu->visualize();
		F->showScreen();
	}
	//Game *game = new Game(F);
	//unique_ptr<Game> game = make_unique<Game>(F);

	//game->start();
	return 0;

}
