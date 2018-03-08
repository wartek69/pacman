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
		///RENDER WALLS


		/////////////// VISUAL ASPECTS
		F->clearScreen();
		for(Wall* wall : walls) {
			wall->visualize();
		}
		for(Entity* entity : mEntities) {
			entity->visualize();
		}
		F->showScreen();
		//checks if there was a pacman created
		if(pacman != NULL) {
			int previousDirection = direction;
			iHandler->handleInput(quit,direction, velocity);
			//moves pacman
			pacman->move(direction, velocity);
			//checks collision with walls
			for(Wall* wall : walls) {
				if(pacman->checkCollision(wall)) {
					//if a collision happends put pacman back in its first position
					if(previousDirection == direction) {
						pacman->move(direction, -velocity);
						//stop the moving of pacman
						pacman->move(direction, 0);
						cout << "testtt" << endl;
					} else {
						pacman->move(direction, -velocity);
						direction = previousDirection;
						pacman->move(previousDirection, velocity);
						cout << "test" << endl;
						cout << direction << endl;
						cout << previousDirection << endl;
						//TODO fix no clipping + fix da je nie in een directie kan gaan die nie mogelijk is
					}
					break;
				}
			}
		}
		////////////// GAME LOGIC
		if(i<100) {
			//checks if there was a ghost created
			if(blueGhost != NULL && pinkGhost != NULL && orangeGhost != NULL && redGhost != NULL) {
				blueGhost->move(FORWARD-j,1);
				redGhost->move(RIGHT+j,1);
				orangeGhost->move(FORWARD-j,2);
				pinkGhost->move(FORWARD-j,2);
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
