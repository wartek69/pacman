/*
 * Inky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Inky.h"
#include "Types.h"

namespace Logic {

Inky::Inky(int posX, int posY, shared_ptr<Logic::WorldObjects> world): Logic::Ghost(posX, posY, world) {

}

Inky::~Inky() {
}
/**
 * inky uses a vector to calculate the position it should go to
 * when inky scatters he goes to the right lower corner
 */
void Inky::findPath(const Logic::MovingEntity& entity) {
	int posGoalX = 0;
	int posGoalY = 0;
	if(this->eaten) {
		Logic::Ghost::decidePath(posGoalX, posGoalY);
	}else if(Logic::Ghost::mode == CHASE) {
		//first determine 2tiles in front of pacman

		switch(entity.getDirection()) {
			case FORWARD:
				posGoalX = entity.getPositionX();
				posGoalY = entity.getPositionY() - 2;
			break;
			case BACKWARD:
				posGoalX = entity.getPositionX();
				posGoalY = entity.getPositionY() + 2;
			break;
			case RIGHT:
				posGoalX = entity.getPositionX() + 2;
				posGoalY = entity.getPositionY();
			break;
			case LEFT:
				posGoalX = entity.getPositionX() - 2;
				posGoalY = entity.getPositionY();
			break;
		}

		auto& blinky = world->getBlinky();
		//this formula can be easily derived with vector math
		posGoalX = 2*posGoalX - blinky.getPositionX();
		posGoalY = 2*posGoalY - blinky.getPositionY();
		Logic::Ghost::decidePath(posGoalX, posGoalY);

	} else if(Logic::Ghost::mode == SCATTER) {
		posGoalX = 15;
		posGoalY = 15;
		Logic::Ghost::decidePath(posGoalX, posGoalY);

	} else if(Logic::Ghost::mode == FRIGHTENED ) {
		Logic::Ghost::frighten();
	}


}

} /* namespace Logic */
