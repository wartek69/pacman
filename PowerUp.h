/*
 * PowerUp.h
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#ifndef POWERUP_H_
#define POWERUP_H_

#include "Consumable.h"
#include "Timer.h"
#include <memory>

namespace Logic {

class PowerUp: public Consumable {
public:
	PowerUp(int posX, int posY, std::shared_ptr<Timer>);
	virtual ~PowerUp();
	void action() override;
protected:
	std::shared_ptr<Timer> frightenedTimer;
};


} /* namespace Logic */

#endif /* POWERUP_H_ */
