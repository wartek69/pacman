/*
 * Clyde.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Clyde.h"
#include "Types.h"
#include "Math.h"

namespace Logic {

Clyde::Clyde(int posX, int posY, shared_ptr<WorldObjects> world): Ghost(posX, posY, world) {


}

Clyde::~Clyde() {
}
/**
 * Clyde algorithm has 2sides to it
 * if clyde is closer than 8 tiles to pacman he should scatter
 * else he should do the same as blinky
 * when scattering clyde should go to the left bottom corner
 */
void Clyde::findPath(const MovingEntity& entity) {
	int posGoalX = 0;
	int posGoalY = 0;
	if(this->eaten) {
		Ghost::decidePath(posGoalX, posGoalY);
	}else if(Ghost::mode == CHASE) {
		//distance  to entity < 8
		if(sqrt(pow((entity.getPositionX() - this->position.x), 2.0) + pow((entity.getPositionY() - this->position.y), 2.0)) < 8) {
			//scatter
			posGoalX = 1;
			posGoalY = 10000;
		} else {
			//do same as blinky
			posGoalX = entity.getPositionX();
			posGoalY = entity.getPositionY();
		}
		Ghost::decidePath(posGoalX, posGoalY);

	} else if(Ghost::mode == SCATTER) {
		posGoalX = 1;
		posGoalY = 10000;
		Ghost::decidePath(posGoalX, posGoalY);
	} else if(Ghost::mode == FRIGHTENED) {
		Ghost::frighten();
	}

}

} /* namespace Logic */
