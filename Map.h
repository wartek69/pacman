/*
 * Map.h
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#ifndef MAP_H_
#define MAP_H_
#include <string>
#include <vector>

class Map {
public:
	Map();
	int getMap();
	virtual ~Map();
	void setValue(int i, int j, int value);
	int getValue(int i, int j);
	int getCols();
	int getRows();
private:
	void loadMap(std::string fileName);
	void printMap();
	std::vector<std::vector<int>> map;			//20 rows, 26 columns
	int rows;
	int cols;

};

#endif /* MAP_H_ */
