/*
 * Data.h
 *
 *  Created on: 23 apr. 2018
 *      Author: Alex
 */

#ifndef DATA_H_
#define DATA_H_

#include <map>
#include "Types.h"

namespace Config {

class Data {
public:
	Data();
	virtual ~Data();
	void addData(int id, Rect sprite);
	Rect getData(int id);
private:
	std::map<int,Rect> data;
};

} /* namespace Config */

#endif /* DATA_H_ */
