/*
 * SDLScoreHandler.h
 *
 *  Created on: 17 mrt. 2018
 *      Author: Alex
 */

#ifndef SDLSCOREHANDLER_H_
#define SDLSCOREHANDLER_H_

#include "ScoreHandler.h"
#include <SDL2\SDL_TTF.h>
#include "Types.h"

namespace SDL {

class SDLScoreHandler: public ScoreHandler {
public:
	SDLScoreHandler(SDL_Renderer* gRenderer, Size screenSize);
	virtual ~SDLScoreHandler();
	void visualize() override;
	void close();
private:
	void loadFont();
	SDL_Renderer* gRenderer;
	TTF_Font *gFont;
	Size screenSize;
};

} /* namespace SDL */

#endif /* SDLSCOREHANDLER_H_ */
