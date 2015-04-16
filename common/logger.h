/*
 * logger.h
 *
 *  Created on: Apr 5, 2015
 *      Author: topeerz
 */

#ifndef COMMON_LOGGER_H_
#define COMMON_LOGGER_H_

#include <string>
#include <fstream>

namespace student {
namespace common {

class Logger {
protected:
	Logger();

private:
	std::fstream m_file;
	static const char* err_file_opening_fail_message;

public:
	Logger(std::string filename);
	virtual ~Logger();

public:
	virtual void log(std::string aLog);
	virtual void log(int* collection, int tabLenght);
	virtual void log(double nLog);
	virtual void log(int cLog);
};

}
}

#endif /* COMMON_LOGGER_H_ */
