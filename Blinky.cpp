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
	//has ot be a multi map since multiple values should be stored
	multimap<int, int> shortestD;
	for(int i = 0; i < 4; i++) {
		//TODO parametrize the velocity
		MovingEntity::place(i,1);
		int temp = pow((entity.getPositionX() - this->position.x), 2.0) + pow((entity.getPositionY() - this->position.y), 2.0);
		MovingEntity::place(i,-1);
		if(!(Ghost::doesCollideWall(i))) {
			shortestD.insert(make_pair(temp, i));
		}

	}
	//checks if the new ain't the opposite direction of the old direction
	//since the ghost can't move back
	if((shortestD.begin()->second+dir)%2 == 0 && dir != 100 && shortestD.begin()->second != dir) {
		//remove the first element from the list
		shortestD.begin() = shortestD.erase(shortestD.begin());
		dir = shortestD.begin()->second;
	} else
		dir = shortestD.begin()->second;
	if(doesCollidePac(dir)) {
		cout << "collision met pac" << endl;

	}


}

} /* namespace Logic */
