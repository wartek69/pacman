/*
 * PowerUp.cpp
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#include "PowerUp.h"
#include "Consumable.h"
#include "Ghost.h"
#include "Types.h"
#include "Timer.h"
namespace Logic {

PowerUp::PowerUp(int posX, int posY, shared_ptr<Logic::Timer> timer ): Logic::Consumable(posX, posY) {
	this->frightenedTimer = timer;
}

PowerUp::~PowerUp() {
}

void PowerUp::action() {
	Logic::Ghost::setMode(FRIGHTENED);
	frightenedTimer->startTimer();
}
} /* namespace Logic */
