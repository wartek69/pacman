/*
 * Pinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Pinky.h"
#include "Types.h"

namespace Logic {

Pinky::Pinky(int posX, int posY, shared_ptr<Logic::WorldObjects> world) : Logic::Ghost(posX, posY, world){

}

Pinky::~Pinky() {
}
/**
 * pinky targets a tile 4 tiles before pacman
 * in scatter mode he goes to the left upper corner
 */
void Pinky::findPath(const Logic::MovingEntity& entity) {
	int posGoalX = 0;
	int posGoalY = 0;
	if(this->eaten) {
		Ghost::decidePath(posGoalX, posGoalY);
	}else if(Ghost::mode == CHASE) {
		switch(entity.getDirection()) {
			case FORWARD:
				posGoalX = entity.getPositionX();
				posGoalY = entity.getPositionY() - 4;
			break;
			case BACKWARD:
				posGoalX = entity.getPositionX();
				posGoalY = entity.getPositionY() + 4;
			break;
			case RIGHT:
				posGoalX = entity.getPositionX() + 4;
				posGoalY = entity.getPositionY();
			break;
			case LEFT:
				posGoalX = entity.getPositionX() - 4;
				posGoalY = entity.getPositionY();
			break;
		}
		Ghost::decidePath(posGoalX, posGoalY);
	} else if(Ghost::mode == SCATTER) {
		posGoalX = 1;
		posGoalY = 1;
		Ghost::decidePath(posGoalX, posGoalY);
	} else if(Ghost::mode == FRIGHTENED) {
		Ghost::frighten();
	}

}

} /* namespace Logic */
