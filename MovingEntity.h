/*
 * MovingEntity.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

#include "Entity.h"
#include "WorldObjects.h"

class MovingEntity:public Entity {
public:
	MovingEntity(int posX, int posY, int collisionWidth, int collisionHeight);
	virtual ~MovingEntity();
	virtual void move(int direction, int velocity);
	virtual void place(int direction, int velocity);
	virtual bool checkCollision(const Entity& collisionPartner);
protected:
	int dir;
	int vel;
};

#endif /* MOVINGENTITY_H_ */
