/*
 * SoundManager.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef SOUNDMANAGER_H_
#define SOUNDMANAGER_H_

namespace Logic {

class SoundManager {
public:
	SoundManager();
	virtual ~SoundManager();
	virtual void munch() = 0;
	virtual void eatFruit() = 0;
};

} /* namespace Logic */

#endif /* SOUNDMANAGER_H_ */
