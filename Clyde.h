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
class Clyde: public Ghost {
public:
	Clyde(int posX, int posY);
	virtual ~Clyde();
	void findPath() override;
};

} /* namespace Logic */

#endif /* CLYDE_H_ */
