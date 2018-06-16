/*
 * Pinky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef PINKY_H_
#define PINKY_H_

#include "Ghost.h"

namespace Logic {

class Pinky: public Ghost {
public:
	Pinky(int posX, int posY, shared_ptr<Logic::WorldObjects> world);
	virtual ~Pinky();
	void findPath(const Logic::MovingEntity& entity) override;

};

} /* namespace Logic */

#endif /* PINKY_H_ */
