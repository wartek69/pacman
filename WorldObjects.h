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
#include "ScoreHandler.h"
#include "Wall.h"
/**
 * This class contains the collections of the different objects
 * Furthermore this class has the pure virtual method to visualize everything
 */
class Pacman;

class WorldObjects {
public:
	WorldObjects();
	virtual ~WorldObjects();
	virtual void visualize(const std::unique_ptr<ScoreHandler>& score) = 0;
	virtual void add(std::shared_ptr<Entity>);
	virtual void addWall(std::shared_ptr<Wall>);
	virtual const Pacman& getPacman();
	virtual const std::vector<std::shared_ptr<Wall>>& getWalls();
	virtual void remove(std::shared_ptr<Entity>);
	virtual void addPacman(std::shared_ptr<Pacman>);
protected:
	std::vector<std::shared_ptr<Entity>> objects;
	std::vector<std::shared_ptr<Wall>> walls;
	std::shared_ptr<Pacman> pacman;
};

#endif /* WORLDOBJECTS_H_ */
