/*
 * Ghost.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#include "Ghost.h"
#include "Types.h"
#include "WorldObjects.h"
#include "MovingEntity.h"
#include "Pacman.h"
#include <string>
#include <iostream>
#include <map>
#include <set>
#include "Math.h"
#include <Time.h>

using namespace std;

int Ghost::mode = SCATTER;
bool Ghost::blink = false;

Ghost::Ghost(int posX, int posY, shared_ptr<WorldObjects> world): MovingEntity(posX, posY, 24, 24) {
	this->world = world;
	//init random num generator
	srand(time(NULL));
	eaten = false;
	spawned = false;
}

Ghost::~Ghost() {
}

/**
 * function to check if a ghost is on a cross road or not
 * done by making sure that all the paths in each direction are free
 */

bool Ghost::isCrossRoad() {
	for(shared_ptr<Wall> wall: world->getWalls()) {
		for(int i = 0;i < 4; i++) {
			//move the ghost without animation
			MovingEntity::place(i,1);
			if(checkCollision(*wall)) {
				MovingEntity::place(i,-1);
				return false;
			} else
				MovingEntity::place(i,-1);	//place the ghost to the initial position
		}
	}
	//exit the for loop means no collisions were found
	return true;
}

bool Ghost::doesCollideWall(int direction) {

	MovingEntity::place(direction, 1);

	for(shared_ptr<Wall> wall: world->getWalls()) {
		if(checkCollision(*wall)) {
			MovingEntity::place(direction, -1);
			return true;
		}
	}
	MovingEntity::place(direction, -1);
	return false;
}

bool Ghost::doesCollidePac() {
	if(MovingEntity::checkCollision(world->getPacman())) {
		return true;
	}
	return false;
}

void Ghost::setMode(int mode) {
	Ghost::mode = mode;
}

int Ghost::getMode() {
	return Ghost::mode;
}

void Ghost::decidePath(int posGoalX, int posGoalY) {
	if(this->eaten) {
		const Wall& gate = world->getGate();
		posGoalX = gate.getPositionX();
		posGoalY = gate.getPositionY();
		//check for collision with the gate
		for(int i = 0;i < 4; i++) {
			MovingEntity::place(i,1);
			if(checkCollision(gate)) {
				Ghost::setEaten(false);
			}
			MovingEntity::place(i,-1);

		}
	}

	//has to be a multi map since multiple values should be stored
	multimap<int, int> shortestD;
	for(int i = 0; i < 4; i++) {
		//TODO parametrize the velocity
		MovingEntity::place(i,1);
		int temp = pow((posGoalX - this->position.x), 2.0) + pow((posGoalY - this->position.y), 2.0);
		MovingEntity::place(i,-1);
		if(!(Ghost::doesCollideWall(i))) {
			shortestD.insert(make_pair(temp, i));
		}

	}
	//checks if the new ain't the opposite direction of the old direction
	//since the ghost can't move back
	if( shortestD.size() > 1) {
		if((shortestD.begin()->second + dir)%2 == 0 && dir != 100 && shortestD.begin()->second != dir) {
			//remove the first element from the list
			shortestD.begin() = shortestD.erase(shortestD.begin());
			dir = shortestD.begin()->second;
		} else
			dir = shortestD.begin()->second;
	} else {
		dir = shortestD.begin()->second;
	}

}

void Ghost::frighten() {
	//get a random number between 0 and 3
	int randNumber = rand() % 4;
	//set has a o(log n) lookup time instead of o(n) for vector
	set<int> possibleWays;
	//first determine the possible ways
	for(int i = 0; i < 4; i++) {
		if(!(Ghost::doesCollideWall(i))) {
			possibleWays.insert(i);
		}

	}
	//choose a random way out of the possible ones
	//can't be previous dir or a value that is not in the possible ways
	// have to check the size of the set to not stay infinityly in the loop when the ghosts is in a 1way alley
	while(possibleWays.find(randNumber) == possibleWays.end() || ((randNumber+dir)%2 == 0 && (randNumber != dir && possibleWays.size()>1)) ) {
		//get a new random
		randNumber = rand() % 4;
	}

	dir = randNumber;
}

void Ghost::setBlink(bool flag) {
	Ghost::blink = flag;
}

bool Ghost::getBlink() {
	return Ghost::blink;
}

void Ghost::setEaten(bool flag) {
	eaten = flag;
}

bool Ghost::getEaten() {
	return eaten;
}

void Ghost::setSpawned(bool flag) {
	spawned = flag;
}

bool Ghost::getSpawned() {
	return spawned;
}

bool Ghost::spawn() {
	//first check where the gate of the ghost house is
	for(int i = 0; i < 4; i++) {
		MovingEntity::place(i, 1);
		if(checkCollision(world->getGate())) {
			//spawn the ghost
			MovingEntity::place(i, -1);
			move(i, 1);
			vel = 1;
			return true;
		}
		MovingEntity::place(i, -1);
	}
	return false;

}
