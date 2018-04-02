/*
 * Pacman.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "Pacman.h"
#include "MovingEntity.h"

Pacman::Pacman(int posX,int posY, std::shared_ptr<WorldObjects> world): MovingEntity(posX, posY, 1, 1) {

}

Pacman::~Pacman() {

}

