/*
 * Clyde.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef CLYDE_H_
#define CLYDE_H_

#include "Ghost.h"

namespace Logic {
/**
 * orange ghost
 */
class Clyde: public Logic::Ghost {
public:
	Clyde(int posX, int posY, shared_ptr<Logic::WorldObjects> world);
	virtual ~Clyde();
	void findPath(const Logic::MovingEntity& entity) override;
};

} /* namespace Logic */

#endif /* CLYDE_H_ */
