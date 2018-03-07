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
protected:
	struct coordinates {
			int x;
			int y;
		};
	coordinates position;
};

#endif /* ENTITY_H_ */
