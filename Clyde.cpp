/*
 * Clyde.cpp
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#include "Clyde.h"

namespace Logic {

Clyde::Clyde(int posX, int posY, shared_ptr<WorldObjects> world): Ghost(posX, posY, world) {
	// TODO Auto-generated constructor stub

}

Clyde::~Clyde() {
	// TODO Auto-generated destructor stub
}

void Clyde::findPath(const Entity& entity) {
	//TODO ALGORITHM
}

} /* namespace Logic */
