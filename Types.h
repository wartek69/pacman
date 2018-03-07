/*
 * Types.h
 *
 *  Created on: 26 feb. 2018
 *      Author: Alex
 */

#ifndef TYPES_H_
#define TYPES_H_

/*enum GhostSprites{
	    FORWARD,
	    BACKWARD,
	    LEFT,
	    RIGHT
};
*/
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
	BHOST,
	DOTS

};

struct PACMAN {
			int x = 0;
			int y = 288;
			int w = 95;
			int h = 95;
};




#endif /* TYPES_H_ */
