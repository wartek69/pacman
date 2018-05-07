/*
 * configParser.cpp
 *
 *  Created on: 16 apr. 2018
 *      Author: Alex
 */

#include "ConfigParser.h"

#include <iostream>
#include <string>

namespace Config {

ConfigParser::ConfigParser() {
	doc.LoadFile("config.xml");
	if( doc.ErrorID() != tinyxml2::XML_SUCCESS) {
		std::cout << "Something went wrong initializing the config file parser" << std::endl;
	}
}

ConfigParser::~ConfigParser() {
}

Data ConfigParser::searchElement(std::string query) {
	Data data;
	tinyxml2::XMLElement *pRoot;
	pRoot = doc.FirstChildElement(query.c_str());

	for (tinyxml2::XMLElement* child = pRoot->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		int id;
		child->QueryIntAttribute("id", &id);
		Rect rect;
		child->QueryIntAttribute("x", &rect.x);
		child->QueryIntAttribute("y", &rect.y);
		child->QueryIntAttribute("w", &rect.w);
		child->QueryIntAttribute("h", &rect.h);
		data.addData(id, rect);
	}
	return data;
}

Size ConfigParser::getScreenSize() {
	Size screenDimensions;
	tinyxml2::XMLElement *pRoot = doc.FirstChildElement("Screen");
	pRoot->QueryIntAttribute("width", &screenDimensions.width);
	pRoot->QueryIntAttribute("height", &screenDimensions.height);
	return screenDimensions;
}

} /* namespace Config */
