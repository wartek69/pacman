/*
 * TextHandler.h
 *
 *  Created on: 9 apr. 2018
 *      Author: Alex
 */

#ifndef TEXTHANDLER_H_
#define TEXTHANDLER_H_
#include <string>

namespace Logic {

class TextHandler {
public:
	TextHandler();
	virtual ~TextHandler();
	virtual void renderText(std::string text) = 0;
};

} /* namespace Logic */

#endif /* TEXTHANDLER_H_ */
