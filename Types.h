/*
 * Types.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef TYPES_H_
#define TYPES_H_

enum GhostSprites{
	   	RIGHT,
	    BACKWARD,
	    LEFT,
	    FORWARD
};

enum PacmanSprites {
	P_LEFT,
	P_FORWARD,
	P_LEFTHALF,
	P_FORWARDHALF,
	P_RIGHT,
	P_BACKWARD,
	P_RIGHTHALF,
	P_BACKWARDHALF,
	P_CLOSED
};

enum pacmanObjects {
	PACMAN,
	HWALL,
	VWALL,
	LBCORNER,
	RBCORNER,
	RUCORNER,
	LUCORNER,
	RGHOST,
	OGHOST,
	PGHOST,
	BGHOST,
	DOT

};

enum menu {
	START,
	LOAD,
	CREDITS,
	EXIT
};

const int frameDelay = 8;



#endif /* TYPES_H_ */
