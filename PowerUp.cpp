/*
 * PowerUp.cpp
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#include "PowerUp.h"
#include "Consumable.h"
#include "Ghost.h"
#include "Types.h"

namespace Logic {

PowerUp::PowerUp(int posX, int posY): Consumable(posX, posY) {
	// TODO Auto-generated constructor stub

}

PowerUp::~PowerUp() {
	// TODO Auto-generated destructor stub
}

void PowerUp::action() {
	Ghost::setMode(FRIGHTENED);
}
} /* namespace Logic */
