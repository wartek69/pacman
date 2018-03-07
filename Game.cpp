/*
 * Game.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#include "Game.h"
#include "AbstractFactory.h"
#include "Types.h"
#include "InputHandler.h"

#include <iostream>
using namespace std;


Game::Game(AbstractFactory *F): F(F) {
	/*ghost = F->createGhost(864,768,95,95,300,300);
	redGhost = F->createGhost(0,575,95,95,100,100);
	orangeGhost = F->createGhost(0,864,95,95,400,300);
	pinkGhost = F->createGhost(0,768,95,95,200,200);
	pacman = F->createPacman(275,275);*/
	ghost = F->createGhost(191,192,24,24,300,300);
	redGhost = F->createGhost(0,143,24,24,100,100);
	orangeGhost = F->createGhost(0,216,24,24,400,300);
	pinkGhost = F->createGhost(0,192,24,24,200,200);
	pacman = F->createPacman(250,250);
	countedFrames = 0; //used to calculate fps
}
Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::start() {
	//creates the needed instrument using factory
	Timer* capTimer = F->createTimer();
	Timer* FPSTimer = F->createTimer();
	InputHandler* iHandler = F->createInputHandler(pacman);
	//starts up timer
	FPSTimer->startTimer();
	float FPS;
	//Main loop flag
	bool quit = false;
	//variables to control movement
	int direction = 1;
	int velocity = -1;

	//used to make the ghosts move
	int i = 0;
	int j = 0;

	//GAME LOOP
	while( !quit ) {
		//timer that times the duration of the loop
		capTimer->startTimer();
		//calculate fps
		FPS =  countedFrames / (FPSTimer->getTimePassed()/ 1000. );
		cout << "FPS: " << FPS << endl;

		/////////////// VISUAL ASPECTS
		F->clearScreen();
		pacman->visualize();
		ghost->visualize();
		redGhost->visualize();
		orangeGhost->visualize();
		pinkGhost->visualize();
		F->showScreen();
		iHandler->handleInput(quit,direction, velocity);

		pacman->move(direction, velocity);
		////////////// GAME LOGIC
		if(i<100) {
			ghost->move(FORWARD-j,1);
			redGhost->move(RIGHT+j,1);
			orangeGhost->move(FORWARD-j,2);
			pinkGhost->move(FORWARD-j,2);
			i = i+1;
		} else {
			i = 0;
			if(j<3)
				j = j+1;
			else
				j = 0;
		}
		countedFrames++;
		//if the fps is too high and needs to be capped--> not very precise --> last resort stop
		if(capTimer->getTimePassed() < SCREEN_TICKS_PER_FRAME ) {
			//wait the duration of the extra time
			cout << "ticks per frame: "<<SCREEN_TICKS_PER_FRAME - capTimer->getTimePassed() << endl;

			capTimer->Delay(SCREEN_TICKS_PER_FRAME - capTimer->getTimePassed());
		}
		//resets the timer
		capTimer->stopTimer();

		//resets timer every 5sec to keep the fps measurements precise
		if(FPSTimer->getTimePassed() > 5000) {
			countedFrames = 0;
			FPSTimer->stopTimer();
			FPSTimer->startTimer();
		}
	}
}
