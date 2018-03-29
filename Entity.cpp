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
	this->collisionWidth = 1;
	this->collisionHeight = 1;
}

Entity::~Entity() {
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
