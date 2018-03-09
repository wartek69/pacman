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
	loadMap();
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
					Ghost* tempGhost = F->createGhost(l*24, k*24, object);
					if(object == RGHOST) {
						redGhost = tempGhost;
					} else if( object == BGHOST) {
						blueGhost = tempGhost;
					} else if( object == OGHOST ) {
						orangeGhost = tempGhost;
					} else if( object == PGHOST) {
						pinkGhost = tempGhost;
					}
					mEntities.push_back(tempGhost);
				}

			}
		}
}
/**
 * This functions checks collision for pacman
 * if no collision occurs the pacman gets moved
 */
bool Game::pacCollision(int inputBuffer, int velocity) {
	pacman->move(inputBuffer, velocity, false);
	//checks collision with walls
	for(Wall* wall : walls) {
		if(pacman->checkCollision(wall)) {
			//if there is a collision move the pacman back to it's initial position
			pacman->move(inputBuffer, -velocity, false);
			return true;
		}
	}
	pacman->move(inputBuffer, -velocity, false);
	pacman->move(inputBuffer, velocity, true);
	return false;
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
	//direction that the player has chosen for pacman
	int direction = 1;
	//the direction the player has chosen prior the direction
	int previousDirection = direction;
	int velocity = 0;

	//used to make the ghosts move
	int i = 0;
	int j = 0;

	//GAME LOOP
	while( !quit ) {
		//timer that times the duration of the loop
		capTimer->startTimer();
		//calculate fps
		FPS =  countedFrames / (FPSTimer->getTimePassed()/ 1000. );
		//cout << "FPS: " << FPS << endl;


		/////////////// VISUAL ASPECTS
		F->clearScreen();
		for(Wall* wall : walls) {
			wall->visualize();
		}
		for(Entity* entity : mEntities) {
			entity->visualize();
		}
		F->showScreen();

		////////////////COLLISION DETECTION FOR PACMAN

		//checks if there was a pacman created
		if(pacman != NULL) {
			int temp = direction;
			iHandler->handleInput(quit,direction, velocity);
			//the user input changed the direction, so there is another previous direction now
			if(temp != direction)
				previousDirection = temp;
			//collision algorithm takes previous direction if given direction isn't possible
			if(pacCollision(direction, velocity)) {
					if(pacCollision(previousDirection, velocity)) {
						//stop
						pacman->move(previousDirection, 0, true);
						//previousDirection = direction;
					}
			}
		}

		////////////// GAME LOGIC
		if(i<100) {
			//checks if there was a ghost created
			if(blueGhost != NULL && pinkGhost != NULL && orangeGhost != NULL && redGhost != NULL) {
				blueGhost->move(FORWARD-j,1, true);
				redGhost->move(RIGHT+j,1, true);
				orangeGhost->move(FORWARD-j,2, true);
				pinkGhost->move(FORWARD-j,2, true);
			}

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
