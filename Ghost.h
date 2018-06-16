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

namespace Logic {
class Ghost: public MovingEntity {
public:
	Ghost(int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~Ghost();
	virtual bool isCrossRoad();
	virtual void findPath(const MovingEntity& entity) = 0;
	virtual void decidePath(int, int);
	virtual void setSpawned(bool);
	virtual bool doesCollidePac();
	virtual bool doesCollideWall(int direction);
	virtual void frighten();
	static void setMode(int mode);
	static int getMode();
	static void setBlink(bool);
	static bool getBlink();
	virtual void setEaten(bool flag);
	virtual void isSpawning(bool flag);
	bool spawn();
	virtual bool getEaten();
	virtual bool getSpawned();
	virtual bool getSpawnStatus();
protected:
	std::shared_ptr<WorldObjects> world;
	static int mode;
	static bool blink;
	bool eaten;
	bool spawned;
	// this flag is used to indicate that the ghost is spawning
	bool spawnStatus;
private:
	Ghost();

};
}
#endif /* GHOST_H_ */
