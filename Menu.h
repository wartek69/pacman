/*
 * Menu.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#ifndef MENU_H_
#define MENU_H_

#include "AbstractFactory.h"
#include <memory>

namespace SDL {

class Menu {
public:
	Menu();
	virtual ~Menu();
	virtual void startGame(shared_ptr<AbstractFactory> F);

};

} /* namespace SDL */

#endif /* MENU_H_ */
