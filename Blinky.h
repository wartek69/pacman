/*
 * Blinky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef BLINKY_H_
#define BLINKY_H_

#include "Ghost.h"

namespace Logic {
 /**
  * red Ghost
  */
class Blinky: public Logic::Ghost {
public:
	Blinky(int posX, int posY, shared_ptr<Logic::WorldObjects> world);
	virtual ~Blinky();
	void findPath(const Logic::MovingEntity& entity) override;

};

} /* namespace Logic */

#endif /* BLINKY_H_ */
