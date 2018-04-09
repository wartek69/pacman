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

}

void ScoreHandler::addScore() {
	score = score + 1;
}

void ScoreHandler::removeScore() {
	score = score - 1;
}

int ScoreHandler::getScore() {
	return score;
}

void ScoreHandler::add(int amount) {
	score = score + amount;
}
