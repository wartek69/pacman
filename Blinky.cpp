/*
 * Blinky.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Blinky.h"
#include "Math.h"
#include <limits>
#include <map>


namespace Logic {

Blinky::Blinky(int posX, int posY, shared_ptr<WorldObjects> world): Ghost(posX, posY, world) {

}

Blinky::~Blinky() {

}
/**
 * decide what way to go to find the shortest path to entity
 */
void Blinky::findPath(const Entity& entity) {

	map<int, int> shortestD;
	int prevDir = dir;
	for(int i = 0; i < 4; i++) {
		//TODO parametrize the velocity
		MovingEntity::place(i,1);
		int temp = pow((entity.getPositionX() - this->position.x), 2.0) + pow((entity.getPositionY() - this->position.y), 2.0);
		//cout << temp << endl;
		shortestD.insert(make_pair(temp, i));

		MovingEntity::place(i,-1);
	}
	while(Ghost::doesCollideWall(shortestD.begin()->second)) {
		shortestD.begin() = shortestD.erase(shortestD.begin());
	}
	//checks if the new ain't the opposite direction of the old direction
	//since the ghost can't move back
	if((shortestD.begin()->second+prevDir)%2 == 0 && prevDir != 100 && !Ghost::doesCollideWall(prevDir))
		dir = prevDir;
	else
		dir = shortestD.begin()->second;
}

} /* namespace Logic */
