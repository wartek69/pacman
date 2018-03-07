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
#include "Map.h"
#include <vector>

#include <iostream>
using namespace std;


Game::Game(AbstractFactory *F): F(F) {
	countedFrames = 0; //used to calculate fps
}
Game::~Game() {
	// TODO Auto-generated destructor stub
}
void Game::loadMap() {
	Map mapController;
	//TODO parameterize the for loop
		for(int k = 0;k<20;k++) {
			for(int l = 0;l<26;l++) {
				int object = mapController.getValue(k,l);
				if(object <= LUCORNER && object >= HWALL)
					walls.push_back(F->createWall(l*24,k*24,object));
				else if(object == PACMAN) {
					pacman = F->createPacman(l*24,k*24);
					//bind inputhandler to pacman
					iHandler = F->createInputHandler(pacman);
					mEntities.push_back(pacman);
				} else if (object >= RGHOST && object <= BGHOST) {
					mEntities.push_back(F->createGhost(l*24, k*24, object));
					//TODO make ghost adressable

				}

			}
		}
}
void Game::start() {
	//creates the needed instrument using factory

	//delete map;
	Timer* capTimer = F->createTimer();
	Timer* FPSTimer = F->createTimer();
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
	loadMap();

	//GAME LOOP
	while( !quit ) {
		//timer that times the duration of the loop
		capTimer->startTimer();
		//calculate fps
		FPS =  countedFrames / (FPSTimer->getTimePassed()/ 1000. );
		//cout << "FPS: " << FPS << endl;
		///RENDER WALLS


		/////////////// VISUAL ASPECTS
		F->clearScreen();
		for(Wall* wall : walls) {
			wall->visualize();
		}
		for(Entity* entity : mEntities) {
			entity->visualize();
		}
		//ghost->visualize();
		//redGhost->visualize();
		//orangeGhost->visualize();
		//pinkGhost->visualize();
		F->showScreen();
		iHandler->handleInput(quit,direction, velocity);

		pacman->move(direction, velocity);
		////////////// GAME LOGIC
		if(i<100) {
			//ghost->move(FORWARD-j,1);
			//redGhost->move(RIGHT+j,1);
			//orangeGhost->move(FORWARD-j,2);
			//pinkGhost->move(FORWARD-j,2);
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
			//cout << "ticks per frame: "<<SCREEN_TICKS_PER_FRAME - capTimer->getTimePassed() << endl;

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
