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

class WorldObjects;

using namespace std;


class Ghost: public MovingEntity {
public:
	Ghost(int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~Ghost();
	virtual bool isCrossRoad();
	virtual void findPath(const MovingEntity& entity) = 0;
	virtual void decidePath(int, int);
	virtual bool doesCollidePac();
	virtual bool doesCollideWall(int direction);
	static void setMode(int mode);
	static int getMode();
protected:
	std::shared_ptr<WorldObjects> world;
	static int mode;
private:
	Ghost();

};

#endif /* GHOST_H_ */
