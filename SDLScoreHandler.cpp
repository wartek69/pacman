/*
 * SDLScoreHandler.cpp
 *
 *  Created on: 17 mrt. 2018
 *      Author: Alex
 */

#include "SDLScoreHandler.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_TTF.h>
#include <iostream>
#include <sstream>

namespace SDL {

SDLScoreHandler::SDLScoreHandler(SDL_Renderer* gRenderer) {
	this->gRenderer = gRenderer;
	loadFont();
}

SDLScoreHandler::~SDLScoreHandler() {
	close();
}

void SDLScoreHandler::visualize() {
	SDL_Color textColor = {255, 255, 255 }; //white
	std::stringstream temp;
	temp << score;
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, temp.str().c_str(), textColor );
    SDL_Texture* mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
    SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = {590, 480, 50, 50};
    SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad );
    SDL_DestroyTexture(mTexture);
    //TODO somewhere in here there is a memory leak I suppose
}

void SDLScoreHandler::loadFont() {
	    //Open the font
	    gFont = TTF_OpenFont( "lazy.ttf", 28 );
	    if( gFont == NULL ) {
			std::cout << "Failed to load ttf font, error: " << TTF_GetError() << std::endl;
	    }
}

void SDLScoreHandler::close() {
	TTF_CloseFont(gFont);
}

} /* namespace SDL */
