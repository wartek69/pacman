/*
 * Inky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Inky.h"
#include "Types.h"

namespace Logic {

Inky::Inky(int posX, int posY, shared_ptr<WorldObjects> world): Ghost(posX, posY, world) {
	// TODO Auto-generated constructor stub

}

Inky::~Inky() {
	// TODO Auto-generated destructor stub
}
/**
 * inky uses a vector to calculate the position it should go to
 * when inky scatters he goes to the right lower corner
 */
void Inky::findPath(const MovingEntity& entity) {
	int posGoalX = 0;
	int posGoalY = 0;
	if(this->eaten) {
		Ghost::decidePath(posGoalX, posGoalY);
	}else if(Ghost::mode == CHASE) {
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
		Ghost::decidePath(posGoalX, posGoalY);

	} else if(Ghost::mode == SCATTER) {
		posGoalX = 15;
		posGoalY = 15;
		Ghost::decidePath(posGoalX, posGoalY);

	} else if(Ghost::mode == FRIGHTENED ) {
		Ghost::frighten();
	}


}

} /* namespace Logic */
