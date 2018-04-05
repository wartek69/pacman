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

Blinky::Blinky(int posX, int posY, shared_ptr<WorldObjects> world): Ghost(posX, posY, world) {

}

Blinky::~Blinky() {

}
/**
 * Blinky chases pacman, if he is in scatter mode he goes to the upper right corner
 */
void Blinky::findPath(const MovingEntity& entity) {
	int posX = 0;
	int posY = 0;
	if(Ghost::mode == CHASE) {
		posX = entity.getPositionX();
		posY = entity.getPositionY();
		Ghost::decidePath(posX, posY);
	} else if(Ghost::mode == SCATTER) {
		//right top corner
		posX = 10000;
		posY = 1;
		Ghost::decidePath(posX, posY);
	} else if(Ghost::mode == FRIGHTENED) {
		Ghost::frighten();
	}
}

} /* namespace Logic */
