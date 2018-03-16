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

MovingEntity::MovingEntity(int posX, int posY, int collisionWidth, int collisionHeight)
: Entity(posX, posY, collisionWidth, collisionHeight) {
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

bool MovingEntity::checkCollision(shared_ptr<Entity> collisionPartner) {
	 //The sides of the rectangles
	    int leftA, leftB;
	    int rightA, rightB;
	    int topA, topB;
	    int bottomA, bottomB;

	    //Calculate the sides of rect A
	    leftA = position.x;
	    rightA = position.x + collisionWidth;
	    topA = position.y;
	    bottomA = position.y + collisionHeight;

	    //Calculate the sides of rect B
	    leftB = collisionPartner->getPositionX();
	    rightB = collisionPartner->getPositionX() + collisionPartner->getWidth();
	    topB = collisionPartner->getPositionY();
	    bottomB = collisionPartner->getPositionY() + collisionPartner->getHeight();

	    //If any of the sides from A are outside of B
	        if( bottomA <= topB ) {
	            return false;
	        }
	        if( topA >= bottomB ) {
	            return false;
	        }
	        if( rightA <= leftB ) {
	            return false;
	        }
	        if( leftA >= rightB ) {
	            return false;
	        }
	        //If none of the sides from A are outside B
	        return true;
}

