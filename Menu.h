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

//this is needed to break cyclic redundancy of header files
// Menu needs abstractF and the latter needs the former
namespace Logic {
class AbstractFactory;

class Menu {
public:
	Menu(shared_ptr<Logic::AbstractFactory> F);
	virtual ~Menu();
	void startGame();
	virtual void interact(bool& quit) = 0;
	virtual void visualize() = 0;
protected:
	shared_ptr<Logic::AbstractFactory> F;
};
}
#endif /* MENU_H_ */
