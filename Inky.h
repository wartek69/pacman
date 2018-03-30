/*
 * Inky.h
 *
 *  Created on: 29 mrt. 2018
 *      Author: Alex
 */

#ifndef INKY_H_
#define INKY_H_

#include "Ghost.h"

namespace Logic {

class Inky: public Ghost {
public:
	Inky(int posX, int posY, shared_ptr<WorldObjects> world);
	virtual ~Inky();
	void findPath(const Entity& entity) override;

};

} /* namespace Logic */

#endif /* INKY_H_ */
