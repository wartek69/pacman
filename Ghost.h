/*
 * Ghost.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef GHOST_H_
#define GHOST_H_

#include <string>
#include <iostream>
#include "MovingEntity.h"

using namespace std;


class Ghost: public MovingEntity {
public:
	Ghost(int posX, int posY);
	virtual ~Ghost();
private:
	Ghost();

};

#endif /* GHOST_H_ */
