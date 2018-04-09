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
#include "SoundManager.h"

class Game {
public:
	Game(shared_ptr<AbstractFactory> F);
	virtual ~Game();
	void start(bool& repeat);
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
	unique_ptr<InputHandler> iHandler;
	shared_ptr<ScoreHandler> score;
	unique_ptr<Logic::SoundManager> sound;
	unique_ptr<Logic::TextHandler> textHandler;
	shared_ptr<Timer> frightenedTimer;

	bool pacCollision(int inputBuffer, int velocity);
	int countedFrames; //used to calculate fps
	//default constructor shouldn't be used --> private
	Game();
	void loadMap();
};

#endif /* GAME_H_ */
