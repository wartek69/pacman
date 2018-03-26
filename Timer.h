/*
 * Timer.h
 *
 *  Created on: 27 feb. 2018
 *      Author: Alex
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
public:
	Timer();
	virtual ~Timer();
	virtual void startTimer() = 0;
	virtual int getTimePassed() = 0;
	virtual void stopTimer() = 0;
	virtual void Delay(int delay) = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
};

#endif /* TIMER_H_ */
