/*
 * Cherry.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef CHERRY_H_
#define CHERRY_H_

#include "Consumable.h"
#include "ScoreHandler.h"
#include <memory>

namespace Logic {

class Cherry: public Consumable {
public:
	Cherry(int posX, int posY, std::shared_ptr<ScoreHandler> score);
	virtual ~Cherry();
	void action() override;
protected:
	std::shared_ptr<ScoreHandler> score;
};

} /* namespace Logic */

#endif /* CHERRY_H_ */
