/*
 * SDLMenu.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLMENU_H_
#define SDLMENU_H_

#include "Menu.h"

namespace SDL {

class SDLMenu: public Menu {
public:
	SDLMenu();
	virtual ~SDLMenu();
};

} /* namespace SDL */

#endif /* SDLMENU_H_ */
