/*
 * ScoreHandler.h
 *
 *  Created on: 17 mrt. 2018
 *      Author: Alex
 */

#ifndef SCOREHANDLER_H_
#define SCOREHANDLER_H_

class ScoreHandler {
public:
	ScoreHandler();
	virtual ~ScoreHandler();
	void addScore();
	void removeScore();
	virtual void visualize() = 0;
protected:
	int score;
};

#endif /* SCOREHANDLER_H_ */
