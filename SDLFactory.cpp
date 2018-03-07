/*
 * SDLFactory.cpp
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#include "SDLFactory.h"
#include "Ghost.h"
#include "SDLGhost.h"
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include "SDLTimer.h"
#include "SDLInputHandler.h"
#include "Types.h"
#include "SDLPacman.h"
#include <iostream>

using namespace std;


SDLFactory::SDLFactory() {
	if(!init()) {
		cout << "Something went wrong initialiasing SDL" << endl;
	} else {
		if(!loadSpriteSheet()) {
			cout << "Something went wrong loading the media" << endl;
		} else {
			cout << "SDL setup succeeded" << endl;

		}

	}
}
/**
 * Clears screen, call before rendering
 */
void SDLFactory::clearScreen() {
	//Clear screen
	//SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
	SDL_RenderClear(gRenderer);
}
/**
 * shows rendered content on screen
 */
void SDLFactory::showScreen() {
	SDL_RenderPresent(gRenderer);
}

SDLFactory::~SDLFactory() {
	close();
}

Ghost* SDLFactory::createGhost(int x, int y, int w, int h, int posX, int posY) {
	//TODO MEMORY LEAK?
	return new SDLGhost(x, y, w, h, gRenderer, spriteSheet, posX, posY);
}

Pacman* SDLFactory::createPacman(int posX, int posY) {
	//return new SDLPacman(PACMAN.x, PACMAN.y, PACMAN.w, PACMAN.h, gRenderer, spriteSheet, posX, posY);
	return new SDLPacman(0,70 ,24 ,24 , gRenderer, spriteSheet, posX, posY);
}

/**
 * initiliazes SDL, creates a window, creates a renderer and initiliazes SDLimage
 */
bool SDLFactory::init() {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	} else {
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		window = SDL_CreateWindow( "PacMan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

			if( gRenderer == NULL ) {
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

/**
 * method to load a file into a texture
 */
bool SDLFactory::loadFromFile(string path) {

		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL ) {
			printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		}
		else {
			//Color key image (black)
			SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 148, 148, 0 ) );

			//Create texture from surface pixels
	        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
			if( newTexture == NULL )
			{
				printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			}

			//Get rid of old loaded surface
			SDL_FreeSurface( loadedSurface );
		}

		//Return success
		spriteSheet = newTexture;
		return spriteSheet != NULL;
}
/**
 * method to load a spritesheet into the system
 *
 */
bool SDLFactory::loadSpriteSheet() {
	bool success = true;
	if(!loadFromFile("pacman3.png")) {
		cout << "Failed to load pacman sprite from the system" << endl;
		success = false;
	}
	return success;
}

/**
 * cleans up the memory
 */
void SDLFactory::close() {
	cout <<" shutting down sdl" <<endl;
	//Free texture if it exists
		if( spriteSheet != NULL ) {
			SDL_DestroyTexture( spriteSheet );
			spriteSheet = NULL;
		}

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( window );
	window = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

Timer* SDLFactory::createTimer() {
	//TODO MEMORY LEAK?
	return new SDLTimer();
}

InputHandler* SDLFactory::createInputHandler(Pacman* handleObject) {
	//TODO MEMORY LEAK?
	return new SDLInputHandler(handleObject);
}


