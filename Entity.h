/*
 * Entity.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef ENTITY_H_
#define ENTITY_H_
namespace Logic {
class Entity {
public:
	Entity(int posX, int posY, int collisionWidth, int collisionHeight);
	virtual ~Entity();
	//virtual void visualize() = 0;
	virtual void visualize(int frame) = 0;
	virtual int getPositionX() const;
	virtual int getPositionY() const;
	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual void print() const;
protected:
	struct coordinates {
			int x;
			int y;
		};
	coordinates position;
	int collisionWidth;
	int collisionHeight;
};
}
#endif /* ENTITY_H_ */
