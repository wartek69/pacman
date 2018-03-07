/*
 * Map.h
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#ifndef MAP_H_
#define MAP_H_
#include <string>
using namespace std;

class Map {
public:
	Map();
	int getMap();
	virtual ~Map();
	void setValue(int i, int j, int value);
	int getValue(int i, int j);
private:
	void loadMap(string fileName);
	void printMap();
	int map[20][26];			//20 rows, 26 columns


};

#endif /* MAP_H_ */
