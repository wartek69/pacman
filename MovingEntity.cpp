/*
 * MovingEntity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "MovingEntity.h"
#include "Types.h"
#include <iostream>
#include "Entity.h"

using namespace std;

MovingEntity::MovingEntity(int posX, int posY): Entity(posX, posY) {
	// TODO Auto-generated constructor stub

}

MovingEntity::~MovingEntity() {
	// TODO Auto-generated destructor stub
}

void MovingEntity::move(int direction, int velocity) {
	switch(direction) {
	case FORWARD:
		position.y = position.y - velocity;
		break;
	case BACKWARD:
		position.y = position.y + velocity;
		break;
	case LEFT:
		position.x = position.x - velocity;
		break;
	case RIGHT:
		position.x = position.x + velocity;
		break;
	}
}
