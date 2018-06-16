/*
 * Consumable.h
 *
 *  Created on: 3 apr. 2018
 *      Author: Alex
 */

#ifndef CONSUMABLE_H_
#define CONSUMABLE_H_

#include "Entity.h"

namespace Logic {

class Consumable: public Logic::Entity {
public:
	Consumable(int posX, int posY);
	virtual ~Consumable();
	virtual void action() = 0;
	virtual void print();
};

} /* namespace Logic */

#endif /* CONSUMABLE_H_ */
