/*
 * logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: topeerz
 */

#include <string>
#include <fstream>
#include <iostream>

#include "logger.h"

using namespace student;
using namespace student::common;

const char* Logger::err_file_opening_fail_message = "Error: file not opened: "; // Cx11 would allow this in header but who needs extra warnings

Logger::Logger(std::string filename) {
	m_file.open(filename,
			std::fstream::in | std::fstream::out | std::fstream::trunc);
	if (!m_file.is_open()) {
		std::cerr << err_file_opening_fail_message << filename << std::endl;
	}
}


Logger::~Logger() {
	m_file.close();
}

void Logger::log(std::string aLog) {
	std::cout << aLog << std::endl;
	m_file << aLog << std::endl;
}
void Logger::log(int cLog) {
    std::cout << cLog << std::endl;
	m_file << cLog << std::endl;
}
void Logger::log(double nLog) {
	std::cout << nLog << std::endl;
	m_file << nLog << std::endl;
}

void Logger::log(int* collection, int array_size)
{
    for(int i=0; i<array_size; ++i)
    {
        std::cout << collection[i] << " ";
        m_file << collection[i] << " ";
    }
    std::cout<<std::endl;
    m_file <<std::endl;
}

