/*
 * Game.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef GAME_H_
#define GAME_H_


#include "AbstractFactory.h"

class Game {
public:
	Game(AbstractFactory *F);
	virtual ~Game();
	void start();
private:
	const int DELAY = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000/DELAY;
	AbstractFactory *F;
	Ghost* ghost;
	Ghost* redGhost;
	Ghost* orangeGhost;
	Ghost* pinkGhost;
	Pacman* pacman;
	int countedFrames; //used to calculate fps
	//default constructor shouldn't be used --> private
	Game();


};

#endif /* GAME_H_ */
