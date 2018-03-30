/*
 * Ghost.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef GHOST_H_
#define GHOST_H_

#include <string>
#include <iostream>
#include "MovingEntity.h"
#include "WorldObjects.h"

using namespace std;


class Ghost: public MovingEntity {
public:
	Ghost(int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~Ghost();
	virtual bool isCrossRoad();
	virtual void findPath(const Entity& entity) = 0;
	virtual bool doesCollideWall(int direction);
protected:
	shared_ptr<WorldObjects> world;
private:
	Ghost();

};

#endif /* GHOST_H_ */
