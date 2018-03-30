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
	world = F->createWorld();
	loadMap();
}
Game::~Game() {
}
void Game::loadMap() {
	Map mapController;
		for(int k = 0;k<mapController.getRows();k++) {
			for(int l = 0;l<mapController.getCols();l++) {
				int object = mapController.getValue(k,l);
				if(object <= LUCORNER && object >= HWALL) {
					shared_ptr<Wall> tempWall = F->createWall(l, k, object);
					//TODO delete the useless collections
					walls.push_back(tempWall);
					world->add(tempWall);
					world->addWall(tempWall);
				} else if(object == PACMAN) {
					pacman = F->createPacman(l, k);
					//bind inputhandler to pacman
					iHandler = F->createInputHandler(pacman);
					mEntities.push_back(pacman);
					world->add(mEntities.back());
				} else if (object >= RGHOST && object <= BGHOST) {
					shared_ptr<Ghost> tempGhost = F->createGhost(l, k, object, world);
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
						world->add(tempGhost);
				} else if (object == DOT) {
					mEntities.push_back(F->createDot(l, k));
					world->add(mEntities.back());
				}

			}
		}
}
/**
 * This functions checks collision for pacman
 * if no collision occurs the pacman gets moved
 */
bool Game::pacCollision(int inputBuffer, int velocity) {
	pacman->MovingEntity::place(inputBuffer, velocity);
	//checks collision with walls
	for(shared_ptr<Wall> wall : walls) {
		if(pacman->checkCollision(*wall)) {
			//if there is a collision move the pacman back to it's initial position
			//use the base class for this so that the animations stay correct
			pacman->MovingEntity::place(inputBuffer, -velocity);
			return true;
		}
	}
	pacman->MovingEntity::place(inputBuffer, -velocity);
	pacman->move(inputBuffer, velocity);
	return false;
}
void Game::start() {
	//creates the needed instrument using factory
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


	//GAME LOOP
	while( !quit ) {
		//timer that times the duration of the loop
		capTimer->startTimer();
		//calculate fps
		FPS =  countedFrames / (FPSTimer->getTimePassed()/ 1000. );
		//cout << "FPS: " << FPS << endl;


		/////////////// VISUAL ASPECTS
		//F->clearScreen();
		//pauses timer because world visualize slows down the loop
		FPSTimer->pause();
		world->visualize(score);
		//resumes the timer
		FPSTimer->resume();
		//score->visualize();
		//TODO fix fps
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
				if(pacman->checkCollision(**it) && *it != pacman) {
					score->addScore();
					world->remove(*it);
					it = mEntities.erase(it);
				} else
					it++;
			}
			/////GAME LOGIC
			if(countedFrames <5)
				pinkGhost->move(BACKWARD,1);
			else if(countedFrames < 10)
				pinkGhost->move(RIGHT,1);
			else if(countedFrames < 15)
				pinkGhost->move(FORWARD,1);
			else
				pinkGhost->move(LEFT,1);
			redGhost->findPath(*pacman);
			//cout << redGhost->getPositionX() << endl;
			//cout << redGhost->getPositionY() << endl;
			//redGhost->move(BACKWARD,2);
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
