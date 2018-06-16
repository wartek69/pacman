/*
 * Dots.h
 *
 *  Created on: 10 mrt. 2018
 *      Author: Alex
 */

#ifndef DOT_H_
#define DOT_H_

#include "Entity.h"
namespace Logic {
class Dot: public Logic::Entity {
public:
	Dot(int posX, int posY);
	virtual ~Dot();
};
}
#endif /* DOT_H_ */
