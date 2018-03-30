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
class Blinky: public Ghost {
public:
	Blinky(int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~Blinky();
	void findPath(const Entity& entity) override;

};

} /* namespace Logic */

#endif /* BLINKY_H_ */
