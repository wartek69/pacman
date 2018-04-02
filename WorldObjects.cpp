/*
 * WorldObjects.cpp
 *
 *  Created on: 26 mrt. 2018
 *      Author: Alex
 */

#include "WorldObjects.h"
#include "Pacman.h"
#include <iostream>
#include <algorithm>
#include "Ghost.h"

WorldObjects::WorldObjects() {

}

WorldObjects::~WorldObjects() {

}

void WorldObjects::add(std::shared_ptr<Entity> entity) {
	objects.push_back(entity);
}

void WorldObjects::remove(std::shared_ptr<Entity> entity) {
	auto it = find(objects.begin(), objects.end(), entity);
	objects.erase(it);

}

void WorldObjects::addWall(std::shared_ptr<Wall> wall) {
	walls.push_back(wall);
}

void WorldObjects::addDot(std::shared_ptr<Dot> dot) {
	dots.push_back(dot);
}

void WorldObjects::addPacman(std::shared_ptr<Pacman> pacman) {
	this->pacman = pacman;
}

void WorldObjects::addGhost(std::shared_ptr<Ghost> ghost) {
	ghosts.push_back(ghost);
}

const Pacman& WorldObjects::getPacman() {
	return *pacman;
}
const std::vector<std::shared_ptr<Wall>>& WorldObjects::getWalls() {
	return walls;
}

std::vector<std::shared_ptr<Dot>>& WorldObjects::getDots() {
	return dots;
}

std::vector<std::shared_ptr<Ghost>>& WorldObjects::getGhosts() {
	return ghosts;
}

/*
 * this function was used for debugging
 */
void WorldObjects::printDotSize() {
	std::cout << dots.size() << std::endl;
}

