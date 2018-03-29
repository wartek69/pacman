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
	Pinky(int posX, int posY);
	virtual ~Pinky();
	void findPath() override;
};

} /* namespace Logic */

#endif /* PINKY_H_ */
