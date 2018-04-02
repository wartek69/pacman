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
#include "Math.h"

using namespace std;

int Ghost::mode = SCATTER;

Ghost::Ghost(int posX, int posY, shared_ptr<WorldObjects> world): MovingEntity(posX, posY, 24, 24) {
	this->world = world;
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
	//has to be a multi map since multiple values should be stored
	auto temp = world->getWalls();
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
	if((shortestD.begin()->second+dir)%2 == 0 && dir != 100 && shortestD.begin()->second != dir) {
		//remove the first element from the list
		shortestD.begin() = shortestD.erase(shortestD.begin());
		dir = shortestD.begin()->second;
	} else
		dir = shortestD.begin()->second;
}


