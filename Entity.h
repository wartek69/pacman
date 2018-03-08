/*
 * Entity.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
public:
	Entity(int posX, int posY);
	virtual ~Entity();
	virtual void visualize() = 0;
	virtual int getPositionX();
	virtual int getPositionY();
	virtual int getWidth();
	virtual int getHeight();
protected:
	struct coordinates {
			int x;
			int y;
		};
	coordinates position;
	int collisionWidth = 24;
	int collisionHeight = 24;
};

#endif /* ENTITY_H_ */
