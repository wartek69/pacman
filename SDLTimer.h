/*
 * SDLTimer.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef SDLTIMER_H_
#define SDLTIMER_H_

#include "Timer.h"

class SDLTimer: public Timer {
public:
	SDLTimer();
	virtual ~SDLTimer();
	void startTimer() override;
	void stopTimer() override;
	void pause() override;
	void resume() override;
	int getTimePassed() override;
	void Delay(int delay) override;
private:
	int startTime;
	bool isStarted;
	int passedTime;
	bool isPaused;
};

#endif /* SDLTIMER_H_ */
