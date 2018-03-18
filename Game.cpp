/*
 * Game.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#include "Game.h"
#include "AbstractFactory.h"
#include "Types.h"
#include "Ghost.h"
#include "InputHandler.h"
#include "Map.h"
#include <vector>
#include <typeinfo>


#include <iostream>
using namespace std;


Game::Game(shared_ptr<AbstractFactory> F): F(F) {
	countedFrames = 0; //used to calculate fps
	score = F->createScoreHandler();
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
					shared_ptr<Ghost> tempGhost = F->createGhost(l*24, k*24, object);
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
				} else if (object == DOT) {
					mEntities.push_back(F->createDot(l*24+5, k*24+5));
				}

			}
		}
}
/**
 * This functions checks collision for pacman
 * if no collision occurs the pacman gets moved
 */
bool Game::pacCollision(int inputBuffer, int velocity) {
	pacman->MovingEntity::move(inputBuffer, velocity);
	//checks collision with walls
	for(shared_ptr<Wall> wall : walls) {
		if(pacman->checkCollision(wall)) {
			//if there is a collision move the pacman back to it's initial position
			//use the base class for this so that the animations stay correct
			pacman->MovingEntity::move(inputBuffer, -velocity);
			return true;
		}
	}
	pacman->MovingEntity::move(inputBuffer, -velocity);
	pacman->move(inputBuffer, velocity);
	return false;
}
void Game::start() {
	//creates the needed instrument using factory
	//delete map;
	unique_ptr<Timer> capTimer = F->createTimer();
	unique_ptr<Timer> FPSTimer = F->createTimer();
	//starts up timer
	FPSTimer->startTimer();
	float FPS;
	//Main loop flag
	bool quit = false;
	//variables to control movement
	//direction that the player has chosen for pacman
	int direction = 1;
	//the direction the player has chosen prior the direction, init value is +1 of direction
	//else wise the pacman will get stuck when pressing for and then back at the start of the game
	int previousDirection = direction+1;
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
		for(shared_ptr<Wall> wall : walls) {
			wall->visualize();
		}
		for(shared_ptr<Entity> entity : mEntities) {
			entity->visualize();
		}
		score->visualize();
		F->showScreen();

		////////////////COLLISION DETECTION FOR PACMAN

		//checks if there was a pacman created
		if(pacman != NULL) {
			int temp = direction;
			iHandler->handleInput(quit,direction, velocity);
			//the user input changed the direction, so there is another previous direction now
			//the modulo 2 operator checks that the prev direction ain't the opposite of the direction
			if(temp != direction && (temp+direction)%2 != 0)
				previousDirection = temp;
			//collision algorithm takes previous direction if given direction isn't possible
			if(pacCollision(direction, velocity)) {
					if(pacCollision(previousDirection, velocity)) {
						//stop
						pacman->move(previousDirection, 0);
					}
			} else {
				previousDirection = direction;
			}

			//////COLLISION DETECTION ON DOTS AND GHOSTS
			for(vector<shared_ptr<Entity>>::iterator it = mEntities.begin(); it != mEntities.end();) {
				if(pacman->checkCollision(*it) && *it != pacman) {
					score->addScore();
					it = mEntities.erase(it);
					//TODO reallocate the memory!!
				} else
					it++;
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
