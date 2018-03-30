/*
 * Game.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef GAME_H_
#define GAME_H_


#include "AbstractFactory.h"
#include "Wall.h"
#include <vector>
#include <memory>
#include "ScoreHandler.h"
#include "WorldObjects.h"

class Game {
public:
	Game(shared_ptr<AbstractFactory> F);
	virtual ~Game();
	void start();
private:
	shared_ptr<WorldObjects> world;
	const int DELAY = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000/DELAY;
	shared_ptr<AbstractFactory> F;
	shared_ptr<Ghost> blueGhost;
	shared_ptr<Ghost> redGhost;
	shared_ptr<Ghost> orangeGhost;
	shared_ptr<Ghost> pinkGhost;
	shared_ptr<Pacman> pacman;
	vector<shared_ptr<Wall>> walls;
	vector<shared_ptr<Entity>> mEntities;
	unique_ptr<InputHandler> iHandler;
	unique_ptr<ScoreHandler> score;
	bool pacCollision(int inputBuffer, int velocity);
	int countedFrames; //used to calculate fps
	//default constructor shouldn't be used --> private
	Game();
	void loadMap();
};

#endif /* GAME_H_ */
