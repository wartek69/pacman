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

using namespace std;


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



