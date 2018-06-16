/*
 * Cherry.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "Cherry.h"
#include "ScoreHandler.h"

namespace Logic {

Cherry::Cherry(int posX, int posY, std::shared_ptr<Logic::ScoreHandler> score): Logic::Consumable(posX, posY) {
	this->score = score;

}

Cherry::~Cherry() {
}

void Cherry::action() {
	score->add(10);
}
} /* namespace Logic */
