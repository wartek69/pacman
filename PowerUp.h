/*
 * PowerUp.h
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#ifndef POWERUP_H_
#define POWERUP_H_

#include "Consumable.h"

namespace Logic {

class PowerUp: public Consumable {
public:
	PowerUp(int posX, int posY);
	virtual ~PowerUp();
	void action() override;
};


} /* namespace Logic */

#endif /* POWERUP_H_ */
