/*
 * Map.cpp
 *
 *  Created on: 7 mrt. 2018
 *      Author: Alex
 */

#include "Map.h"
#include <fstream>
#include <string>
#include <iostream>
#include <memory>
#include <limits>
#include <vector>
using namespace std;
namespace Logic {
Map::Map() {
	//just max value, the value gets changed when loading in the map
	cols = numeric_limits<int>::max();
	rows = numeric_limits<int>::max();

	cout << "map created" << endl;
	loadMap("map.txt");
	//printMap();

	//flush the buffer!!
	cout << endl;
}

Map::~Map() {

}

void Map::loadMap(string fileName) {
	int temp;
	int i = 0;
	int j = 0;
	ifstream stream(fileName);

	if(!stream) {
		cout << "There was an error opening file: " << fileName << endl;
	} else {
		cout << "Opened file : " << fileName << " successfully." << endl;
	}
	stream >> cols;
	stream >> rows;
	map = vector<vector<int>>(rows,vector<int>(cols));
	while(stream >> temp) {
		if(i<rows) {
			if(j<cols) {
				map[i][j] = temp;
				j++;
			} else {
				j = 0;
				i++;
				map[i][j] = temp;
				j++;
			}
		}
	}
	stream.close();
}

void Map::printMap() {
	for(int i = 0;i<cols;i++) {
		cout << endl;
		for(int j = 0;j<rows;j++) {
			cout << map[i][j] << " ";
		}
	}
	//flush the buffer!
	//cout << endl;
}

void Map::setValue(int i, int j,int value) {
	map[i][j] = value;
}

int Map::getValue(int i, int j) {
	return map[i][j];
}

int Map::getCols() {
	return cols;
}

int Map::getRows() {
	return rows;
}
}
