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
	MovingEntity(int posX, int posY);
	virtual ~MovingEntity();
	virtual void move(int direction, int velocity);
};

#endif /* MOVINGENTITY_H_ */
