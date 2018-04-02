/*
 * MovingEntity.cpp
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#include "MovingEntity.h"
#include "Types.h"
#include <iostream>

using namespace std;

MovingEntity::MovingEntity(int posX, int posY, int collisionWidth, int collisionHeight)
: Entity(posX, posY, collisionWidth, collisionHeight) {
	vel = 1;
	dir = 100;

}

MovingEntity::~MovingEntity() {

}
/**
 * move is a function to move an entity
 */
void MovingEntity::move(int direction, int velocity) {
	dir = direction;
	vel = velocity;
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

/**
 * place is a method that is used by the collision detection to place an entity
 * without triggering any animations or changing the direction
 */
void MovingEntity::place(int direction, int velocity) {
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
/**
 * if there is a collision return true
 * else return false
 */
bool MovingEntity::checkCollision(const Entity& collisionPartner) {
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
	    leftB = collisionPartner.getPositionX();
	    rightB = collisionPartner.getPositionX() + collisionPartner.getWidth();
	    topB = collisionPartner.getPositionY();
	    bottomB = collisionPartner.getPositionY() + collisionPartner.getHeight();

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

int MovingEntity::getDirection() {
	return dir;
}

int MovingEntity::getVelocity() {
	return vel;
}
