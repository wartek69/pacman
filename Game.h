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
#include "Map.h"

namespace Logic {
class Game {
public:
	Game(shared_ptr<Logic::AbstractFactory> F);
	virtual ~Game();
	void start(bool& repeat);
private:
	shared_ptr<Logic::WorldObjects> world;
	const int DELAY = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000/DELAY;
	shared_ptr<Logic::AbstractFactory> F;
	shared_ptr<Logic::Ghost> blueGhost;
	shared_ptr<Logic::Ghost> redGhost;
	shared_ptr<Logic::Ghost> orangeGhost;
	shared_ptr<Logic::Ghost> pinkGhost;
	shared_ptr<Logic::Pacman> pacman;
	unique_ptr<Logic::InputHandler> iHandler;
	shared_ptr<Logic::ScoreHandler> score;
	unique_ptr<Logic::SoundManager> sound;
	unique_ptr<Logic::TextHandler> textHandler;
	shared_ptr<Logic::Timer> frightenedTimer;

	bool pacCollision(int inputBuffer, int velocity);
	int countedFrames; //used to calculate fps
	//default constructor shouldn't be used --> private
	Game();
	void loadMap(Logic::Map mapController);
};
}
#endif /* GAME_H_ */
