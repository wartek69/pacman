/*
 * configParser.h
 *
 *  Created on: 16 apr. 2018
 *      Author: Alex
 */

#ifndef CONFIGPARSER_H_
#define CONFIGPARSER_H_

#include "tinyxml\tinyxml2.h"
#include <string>
#include "Types.h"
#include "Data.h"


namespace Config {

class ConfigParser {
public:
	ConfigParser();
	Data searchElement(std::string query);
	Size getScreenSize();
	virtual ~ConfigParser();
private:
	tinyxml2::XMLDocument doc;

};

} /* namespace Config */

#endif /* CONFIGPARSER_H_ */
