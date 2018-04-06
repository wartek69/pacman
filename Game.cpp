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
#include "PowerUp.h"
#include "Consumable.h"
#include <iostream>
using namespace std;


Game::Game(shared_ptr<AbstractFactory> F): F(F) {

	countedFrames = 0; //used to calculate fps
	score = F->createScoreHandler();
	world = F->createWorld();
	Ghost::setMode(SCATTER);
	loadMap();
}
Game::~Game() {
}
void Game::loadMap() {
	Map mapController;
		for(int k = 0;k<mapController.getRows();k++) {
			for(int l = 0;l<mapController.getCols();l++) {
				int object = mapController.getValue(k,l);
				if(object <= GATE && object >= HWALL) {
					shared_ptr<Wall> tempWall = F->createWall(l, k, object);
					//TODO delete the useless collections
					world->add(tempWall);
					world->addWall(tempWall);
				} else if(object == PACMAN) {
					pacman = F->createPacman(l, k);
					//bind inputhandler to pacman
					iHandler = F->createInputHandler(pacman);
					world->add(pacman);
					world->addPacman(pacman);
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
					if(tempGhost == redGhost)
						world->addBlinky(tempGhost);
					world->add(tempGhost);
					world->addGhost(tempGhost);
				} else if (object == DOT) {
					shared_ptr<Dot> tempDot = F->createDot(l, k);
					world->add(tempDot);
					world->addDot(tempDot);
				} else if(object == POWERUP) {
					shared_ptr<Logic::PowerUp> pow = F->createPowerUp(l, k);
					world->add(pow);
					world->addConsumable(pow);
				}

			}
		}
}
/**
 * This functions checks collision for pacman
 */
bool Game::pacCollision(int inputBuffer, int velocity) {
	pacman->MovingEntity::place(inputBuffer, velocity);
	std::vector<shared_ptr<Wall>> walls = world->getWalls();
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
	return false;
}
void Game::start() {
	vector<shared_ptr<Dot>>& dots = world->getDots();
	vector<shared_ptr<Ghost>>& ghosts = world->getGhosts();
	vector<shared_ptr<Logic::Consumable>>& consumables = world->getConsumables();
	//creates the needed instrument using factory
	unique_ptr<Timer> capTimer = F->createTimer();
	unique_ptr<Timer> FPSTimer = F->createTimer();
	//timer that is used to switch the ghosts between different modes
	unique_ptr<Timer> ghostTimer = F->createTimer();
	//timer for the frightened mode
	unique_ptr<Timer> frightenedTimer = F->createTimer();
	//starts up timer
	FPSTimer->startTimer();
	ghostTimer ->startTimer();
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

		/*redGhost->findPath(*pacman);
		pinkGhost->findPath(*pacman);
		orangeGhost->findPath(*pacman);
		blueGhost->findPath(*pacman);*/
		world->moveGhosts();

		//checks if there was a pacman created
		if(pacman != NULL) {
			int temp = direction;
			iHandler->handleInput(quit,direction, velocity);
			//Detect collision on ghosts before you move pacman!!
			for(vector<shared_ptr<Ghost>>::iterator it = ghosts.begin();it != ghosts.end();) {
				bool bool1 = direction != (*it)->getDirection();
				bool bool2 = (direction+(*it)->getDirection())%2 == 0;
				if(pacman->checkCollision(**it) && bool1 && bool2) {
					cout << "collision1" << endl;
					if(Ghost::getMode() == FRIGHTENED) {
						(*it)->setEaten(true);
					}
					it++;
				} else
					it++;
			}

			//the user input changed the direction, so there is another previous direction now
			//the modulo 2 operator checks that the prev direction ain't the opposite of the direction
			//else pacman can stay still in a hallway
			if(temp != direction && (temp+direction)%2 != 0)
				previousDirection = temp;
			//collision algorithm takes previous direction if given direction isn't possible
			if(pacCollision(direction, velocity)) {
				if(pacCollision(previousDirection, velocity)) {
					//stop
					pacman->move(previousDirection, 0);
				}else
					pacman->move(previousDirection, velocity);
			} else {
				previousDirection = direction;
				pacman->move(direction, velocity);
			}

			//collision detection on ghosts after the pacman got moved!!
			for(vector<shared_ptr<Ghost>>::iterator it = ghosts.begin();it != ghosts.end();) {
				if(pacman->checkCollision(**it)) {
					cout << "collision2" << endl;
					if(Ghost::getMode() == FRIGHTENED) {
						(*it)->setEaten(true);
					}

					it++;
				} else
					it++;
			}
			//////COLLISION DETECTION ON DOTS
			for(vector<shared_ptr<Dot>>::iterator it = dots.begin(); it != dots.end();) {
				if(pacman->checkCollision(**it)) {
					score->addScore();
					//remove the dot from all the collections that it is in
					world->remove(*it);
					it = dots.erase(it);
				} else
					it++;
			}

			/////COLLISION DETECTION ON CONSUMABLES

			for(vector<shared_ptr<Logic::Consumable>>::iterator it = consumables.begin();it != consumables.end();) {
				if(pacman->checkCollision(**it)) {
					(*it)->action();
					world->remove(*it);
					it = consumables.erase(it);
				} else
					it++;
			}
		}

		countedFrames++;
		//if the fps is too high and needs to be capped--> not very precise --> last resort stop
		if(capTimer->getTimePassed() < SCREEN_TICKS_PER_FRAME ) {
			//wait the duration of the extra time
			//cout << "ticks per frame: "<<SCREEN_TICKS_PER_FRAME - capTimer->getTimePassed() << endl;

			capTimer->Delay(SCREEN_TICKS_PER_FRAME - capTimer->getTimePassed());
		}
		//resets the captimer
		capTimer->stopTimer();
		//TODO fix that the amount of time in frightened mode gets stacked
		if(ghostTimer->getTimePassed() > 7000 && Ghost::getMode() == SCATTER) {
			Ghost::setMode(CHASE);
			ghostTimer->stopTimer();
			ghostTimer->startTimer();
		} else if(ghostTimer->getTimePassed() > 20000 && Ghost::getMode() == CHASE) {
			Ghost::setMode(SCATTER);
			ghostTimer->stopTimer();
			ghostTimer->startTimer();
		} else if(Ghost::getMode() == FRIGHTENED && !(frightenedTimer->isRunning())) {
			frightenedTimer->startTimer();
		} else if(Ghost::getMode() == FRIGHTENED && frightenedTimer->isRunning()) {
			if(frightenedTimer->getTimePassed() > 7000) {
				frightenedTimer->stopTimer();
				Ghost::setBlink(false);
				Ghost::setMode(CHASE);
				ghostTimer->stopTimer();
				ghostTimer->startTimer();
			} else if(frightenedTimer->getTimePassed() > 4000) {
				//Time is running out
				Ghost::setBlink(true);
			}
		}
		//resets timer every 5sec to keep the fps measurements precise
		if(FPSTimer->getTimePassed() > 5000) {
			countedFrames = 0;
			FPSTimer->stopTimer();
			FPSTimer->startTimer();
		}
	}
}
