/*
 * Blinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Blinky.h"
#include "Math.h"
#include <limits>
#include <map>
#include "Types.h"


namespace Logic {

Blinky::Blinky(int posX, int posY, shared_ptr<Logic::WorldObjects> world): Logic::Ghost(posX, posY, world) {

}

Blinky::~Blinky() {

}
/**
 * Blinky chases pacman, if he is in scatter mode he goes to the upper right corner
 */
void Blinky::findPath(const Logic::MovingEntity& entity) {
	int posX = 0;
	int posY = 0;
	if(this->eaten) {
		Logic::Ghost::decidePath(posX, posY);
	}else if(Logic::Ghost::mode == CHASE) {
		posX = entity.getPositionX();
		posY = entity.getPositionY();
		Logic::Ghost::decidePath(posX, posY);
	} else if(Logic::Ghost::mode == SCATTER) {
		//right top corner
		posX = 10000;
		posY = 1;
		Logic::Ghost::decidePath(posX, posY);
	} else if(Logic::Ghost::mode == FRIGHTENED) {
		Logic::Ghost::frighten();
	}
}

} /* namespace Logic */
