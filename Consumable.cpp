/*
 * Consumable.cpp
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#include "Consumable.h"
#include "Entity.h"
#include <iostream>

namespace Logic {

Consumable::Consumable(int posX, int posY): Logic::Entity(posX, posY, 1, 1) {

}

Consumable::~Consumable() {
}

void Consumable::print() {
	std::cout << "I'm a consumable" << std::endl;
}
} /* namespace Logic */
