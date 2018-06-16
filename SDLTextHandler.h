/*
 * SDLTextHandler.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef SDLTEXTHANDLER_H_
#define SDLTEXTHANDLER_H_

#include "TextHandler.h"
#include <SDL2\SDL_TTF.h>
#include "types.h"

namespace SDL {

class SDLTextHandler: public Logic::TextHandler {
public:
	SDLTextHandler(SDL_Renderer* gRenderer, Size screenSize);
	virtual ~SDLTextHandler();
	void renderText(std::string text) override;
private:
	void loadFont();
	void close();
	TTF_Font *gFont;
	SDL_Renderer* gRenderer;
	Size screenSize;

};

} /* namespace SDL */

#endif /* SDLTEXTHANDLER_H_ */
