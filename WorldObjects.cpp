/*
 * WorldObjects.cpp
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#include "WorldObjects.h"


WorldObjects::WorldObjects() {

}

WorldObjects::~WorldObjects() {

}

void WorldObjects::add(std::shared_ptr<Entity> entity) {
	objects.push_back(entity);
}

void WorldObjects::remove(std::shared_ptr<Entity> entity) {
	for(std::vector<std::shared_ptr<Entity>>::iterator it = objects.begin(); it != objects.end();) {
		if(*it == entity) {
			it = objects.erase(it);
		} else
			it++;
	}
}
