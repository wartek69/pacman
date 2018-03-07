//============================================================================
// Name        : factoryTest.cpp
// Author      : Alex
// Version     :
// Copyright   : Oef2a
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "AbstractFactory.h"
#include "SDLFactory.h"
#include "Game.h"


int main( int argc, char* args[] ) {
	AbstractFactory *F = new SDLFactory();

	Game *game = new Game(F);

	game->start();
	return 0;

}
