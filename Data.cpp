/*
 * Data.cpp
 *
 *  Created on: 23 apr. 2018
 *      Author: Alex
 */

#include "Data.h"
#include <iostream>

namespace Config {

Data::Data() {

}

Data::~Data() {
}

void Data::addData(int id, Rect sprite) {
	data[id] = sprite;
}

Rect Data::getData(int id) {
	if(data.find(id) == data.end()) {
		std::cout << "The map doesn't contain id " << id << std::endl;
	}
	return data[id];
}
} /* namespace Config */
