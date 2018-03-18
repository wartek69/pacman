/*
 * SDLMenu.h
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLMENU_H_
#define SDLMENU_H_

#include "Menu.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_TTF.h>

namespace SDL {

class SDLMenu: public Menu {
public:
	SDLMenu(SDL_Renderer *gRenderer, shared_ptr<AbstractFactory> F);
	virtual ~SDLMenu();
	void loadFont();
	void visualize();
	void close();
	void interact(bool& quit) override;
private:
	void renderStaticText(std::stringstream&, SDL_Rect renderQuad);
	TTF_Font *gFont;
	SDL_Renderer* gRenderer;
	int currentSelection;
};

} /* namespace SDL */

#endif /* SDLMENU_H_ */
