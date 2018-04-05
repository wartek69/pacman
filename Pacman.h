/*
 * Pacman.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include "MovingEntity.h"


class Pacman: public MovingEntity {
public:
	Pacman(int posX, int posY);
	virtual ~Pacman();
};

#endif /* PACMAN_H_ */
