/*
 * WorldObjects.h
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#ifndef WORLDOBJECTS_H_
#define WORLDOBJECTS_H_

#include <vector>
#include <memory>
#include "Entity.h"

class WorldObjects {
public:
	WorldObjects();
	virtual ~WorldObjects();
	virtual void visualize() = 0;
	virtual void add(std::shared_ptr<Entity>);
	virtual void remove(std::shared_ptr<Entity>);
protected:
	std::vector<std::shared_ptr<Entity>> objects;
};

#endif /* WORLDOBJECTS_H_ */
