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

namespace SDL {

class SDLScoreHandler: public ScoreHandler {
public:
	SDLScoreHandler(SDL_Renderer* gRenderer);
	virtual ~SDLScoreHandler();
	void visualize() override;
	void close();
private:
	void loadFont();
	SDL_Renderer* gRenderer;
	TTF_Font *gFont;
};

} /* namespace SDL */

#endif /* SDLSCOREHANDLER_H_ */
