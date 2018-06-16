/*
 * Wall.h
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#ifndef WALL_H_
#define WALL_H_

#include "Entity.h"
namespace Logic {
class Wall: public Logic::Entity {
public:
	Wall(int posX, int posY);
	virtual ~Wall();
	void print() const override;
private:
	Wall(); 		//default constructor shouldn't be used
};
}
#endif /* WALL_H_ */
