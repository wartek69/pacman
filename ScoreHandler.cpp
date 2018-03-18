/*
 * ScoreHandler.cpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: Alex
 */

#include "ScoreHandler.h"

ScoreHandler::ScoreHandler() {
	score = 0;
}

ScoreHandler::~ScoreHandler() {
	// TODO Auto-generated destructor stub
}

void ScoreHandler::addScore() {
	score = score + 1;
}

void ScoreHandler::removeScore() {
	score = score - 1;
}
