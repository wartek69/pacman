/*
 * Entity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "Entity.h"

Entity::Entity(int posX, int posY, int collisionWidth, int collisionHeight) {
	position.x = posX;
	position.y = posY;
	this->collisionWidth = collisionWidth;
	this->collisionHeight = collisionHeight;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

int Entity::getHeight() {
	return collisionHeight;
}

int Entity::getWidth() {
	return collisionWidth;
}

int Entity::getPositionX() {
	return position.x;
}

int Entity::getPositionY() {
	return position.y;
}
