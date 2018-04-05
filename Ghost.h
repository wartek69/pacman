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
	virtual void frighten();
	static void setMode(int mode);
	static int getMode();
	static void setBlink(bool);
	static bool getBlink();
	virtual void setEaten(bool flag);
	virtual bool getEaten();
protected:
	std::shared_ptr<WorldObjects> world;
	static int mode;
	static bool blink;
	bool eaten;
private:
	Ghost();

};

#endif /* GHOST_H_ */
