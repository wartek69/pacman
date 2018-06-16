/*
 * Pacman.h
 *
 *  Created on: 1 mrt. 2018
 *      Author: Alex
 */

#ifndef PACMAN_H_
#define PACMAN_H_

#include "MovingEntity.h"

namespace Logic {
class Pacman: public Logic::MovingEntity {
public:
	Pacman(int posX, int posY);
	virtual ~Pacman();
	virtual bool die() = 0;
};
}
#endif /* PACMAN_H_ */
