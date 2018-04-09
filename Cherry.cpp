/*
 * Cherry.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "Cherry.h"
#include "ScoreHandler.h"

namespace Logic {

Cherry::Cherry(int posX, int posY, std::shared_ptr<ScoreHandler> score): Consumable(posX, posY) {
	this->score = score;

}

Cherry::~Cherry() {
	// TODO Auto-generated destructor stub
}

void Cherry::action() {
	score->add(10);
}
} /* namespace Logic */
