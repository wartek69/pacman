/*
 * WorldObjects.cpp
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#include "WorldObjects.h"
#include "Pacman.h"



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

void WorldObjects::addWall(std::shared_ptr<Wall> wall) {
	walls.push_back(wall);
}

void WorldObjects::addPacman(std::shared_ptr<Pacman> pacman) {
	this->pacman = pacman;
}

const Pacman& WorldObjects::getPacman() {
	return *pacman;
}
const std::vector<std::shared_ptr<Wall>>& WorldObjects::getWalls() {
	return walls;
}
