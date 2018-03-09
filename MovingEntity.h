/*
 * MovingEntity.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef MOVINGENTITY_H_
#define MOVINGENTITY_H_

#include "Entity.h"

class MovingEntity:public Entity {
public:
	MovingEntity(int posX, int posY, int collisionWidth, int collisionHeight);
	virtual ~MovingEntity();
	virtual void move(int direction, int velocity, bool animation);
	virtual bool checkCollision(Entity* collisionPartner);
};

#endif /* MOVINGENTITY_H_ */
