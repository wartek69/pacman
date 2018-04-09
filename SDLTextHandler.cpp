/*
 * SDLTextHandler.cpp
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#include "SDLTextHandler.h"
#include <iostream>
#include <SDL2\SDL.h>
#include <SDL2\SDL_TTF.h>
namespace SDL {

SDLTextHandler::SDLTextHandler(SDL_Renderer* gRenderer) {
	this->gRenderer = gRenderer;
	loadFont();
}


SDLTextHandler::~SDLTextHandler() {
	close();
}

void SDLTextHandler::loadFont() {
	gFont = TTF_OpenFont("open-sans/OpenSans-Bold.ttf",40);
	if( gFont == NULL ) {
		std::cout << "There was an error loading the ttf for the menu, Error: " << TTF_GetError() << std::endl;
	}
}

void SDLTextHandler::close() {
	TTF_CloseFont(gFont);
}

void SDLTextHandler::renderText(std::string text) {
	SDL_Color textColor = {255, 255, 255 }; //white
	//TODO param the renderquad?
	SDL_Rect renderQuad = {230, 200, 160, 80};
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, text.c_str(), textColor );
	SDL_Texture* mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );

	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
	//TODO useless rerendering text that isn't changing?
}


} /* namespace SDL */
