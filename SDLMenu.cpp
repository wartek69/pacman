/*
 * SDLMenu.cpp
 *
 *  Created on: 18 mrt. 2018
 *      Author: Alex
 */

#include "SDLMenu.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_TTF.h>
#include <sstream>
#include <iostream>
#include "Types.h"

namespace SDL {

SDLMenu::SDLMenu(SDL_Renderer* gRenderer, shared_ptr<AbstractFactory> F): Menu(F) {
	currentSelection = 0;
	this->gRenderer = gRenderer;
	loadFont();
}

SDLMenu::~SDLMenu() {
}

void SDLMenu::loadFont() {
	gFont = TTF_OpenFont("CrackMan.ttf",80);
	if( gFont == NULL ) {
		std::cout << "There was an error loading the ttf for the menu, Error: " << TTF_GetError() << std::endl;
	}
}

void SDLMenu::close() {
	TTF_CloseFont(gFont);
}

void SDLMenu::visualize() {
	std::stringstream temp[4] ;
		temp[0] << " Start game";
		temp[1] << " Load game";
		temp[2] << " Credits";
		temp[3] << " Exit";
		temp[currentSelection].str("-" + temp[currentSelection].str());
		SDL_Rect renderQuad = {220, 100, 200, 80};
		for(int i = 0;i<4; i++) {
			renderQuad.y = 100+80*i;
			renderStaticText(temp[i], renderQuad);
		}
}

void SDLMenu::renderStaticText(std::stringstream &temp, SDL_Rect renderQuad) {
	SDL_Color textColor = {255, 255, 255 }; //white
	SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, temp.str().c_str(), textColor );
	SDL_Texture* mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );

	SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(mTexture);
	//TODO useless rerendering text that isn't changing?
}

void SDLMenu::interact(bool& quit) {
	SDL_Event e;
	//polls for an event, this code will be called from a loop so no loop needed here
	SDL_PollEvent( &e );

	//User requests quit
	if( e.type == SDL_QUIT ) {
		quit = true;
	} else if( e.type == SDL_KEYDOWN ) {
		switch( e.key.keysym.sym )
		{
			case SDLK_UP:
				if (currentSelection == 0)
					currentSelection = 3;
				else
					currentSelection--;
			break;

			case SDLK_DOWN:
				if (currentSelection == 3)
					currentSelection = 0;
				else
					currentSelection++;
			break;

			case SDLK_RETURN:
				switch (currentSelection) {
					case START:
						startGame();
					break;

					case LOAD:
						std::cout << "load" << std::endl;
					break;

					case CREDITS:
						std::cout << "credits" << std::endl;
					break;

					case EXIT:
						quit = true;
					break;
				}
			break;

			default:
			break;
		}
	}


}

} /* namespace SDL */
