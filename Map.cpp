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
using namespace std;

Map::Map() {
	cout << "map created" << endl;
	loadMap("map.txt");
	//printMap();

	//flush the buffer!!
	cout << endl;
}

Map::~Map() {
	// TODO Auto-generated destructor stub
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
	while(stream >> temp) {
		if(i<20) {
			if(j<26) {
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
	for(int i = 0;i<20;i++) {
		cout << endl;
		for(int j = 0;j<26;j++) {
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

