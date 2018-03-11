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
using namespace std;


int main( int argc, char* args[] ) {
	//AbstractFactory *F = new SDLFactory();
	shared_ptr<AbstractFactory> F = make_shared<SDLFactory>();

	//Game *game = new Game(F);
	unique_ptr<Game> game = make_unique<Game>(F);

	game->start();
	return 0;

}
