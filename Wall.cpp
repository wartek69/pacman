/*
 * Wall.cpp
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#include "Wall.h"
#include <iostream>
namespace Logic {
Wall::Wall(int posX, int posY) : Logic::Entity(posX, posY, 24, 24) {

}

Wall::~Wall() {

}

void Wall::print() const {
	std::cout << "I'm a wall" << std::endl;
}
}
