/*
 * Entity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "Entity.h"
#include <iostream>

Entity::Entity(int posX, int posY, int collisionWidth, int collisionHeight) {
	position.x = posX;
	position.y = posY;
	this->collisionWidth = 1;
	this->collisionHeight = 1;
}

Entity::~Entity() {
}

int Entity::getHeight() const {
	return collisionHeight;
}

int Entity::getWidth() const {
	return collisionWidth;
}

int Entity::getPositionX() const {
	return position.x;
}

int Entity::getPositionY() const {
	return position.y;
}

void Entity::print() const {
	std::cout << "I'm an entity" << std::endl;
}
