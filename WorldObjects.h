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
#include "Dot.h"
#include "Consumable.h"

/**
 * This class contains the collections of the different objects
 * Furthermore this class has the pure virtual method to visualize everything
 */
class Pacman;
class Ghost;
class Blinky;

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
	virtual void addGhost(std::shared_ptr<Ghost>);
	virtual void addDot(std::shared_ptr<Dot>);
	virtual void addBlinky(std::shared_ptr<Ghost>);
	virtual void addConsumable(std::shared_ptr<Logic::Consumable>);
	virtual std::vector<std::shared_ptr<Logic::Consumable>>& getConsumables();
	virtual std::vector<std::shared_ptr<Dot>>& getDots();
	virtual std::vector<std::shared_ptr<Ghost>>& getGhosts();
	virtual const Ghost& getBlinky();
	virtual void moveGhosts();
	virtual void printDotSize(); //used for debugging
protected:
	std::vector<std::shared_ptr<Entity>> objects;
	std::vector<std::shared_ptr<Wall>> walls;
	std::vector<std::shared_ptr<Ghost>> ghosts;
	std::shared_ptr<Pacman> pacman;
	std::shared_ptr<Ghost> blinky;
	std::vector<std::shared_ptr<Dot>> dots;
	std::vector<std::shared_ptr<Logic::Consumable>> consumables;
};

#endif /* WORLDOBJECTS_H_ */
