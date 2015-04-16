/*
 * test_logger.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/logger.h"
#include "common/catch.hpp"
#include "../quicksort.h"

TEST_CASE( "quicksort sortSimpleArray", "[factorial]" ) {

	// pre
	std::cout<<"abc"<<std::endl;
    const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));

	// given
	int testing_tab[5] = {5, 3, 2, 4, 1};
	int expected_tab[5] = {1, 2, 3, 4, 5};
    int tab_lenght = sizeof(testing_tab)/sizeof(int);
	int* result_tab = new int[tab_lenght];
	// when
	pLogger->log(testing_tab, tab_lenght);
	result_tab = quicksort<int>(testing_tab, tab_lenght);
    pLogger->log(result_tab, tab_lenght);
    pLogger->log(expected_tab, tab_lenght);
	// then
	for(int i=0; i<tab_lenght;++i)
	{
        REQUIRE(testing_tab[i] == expected_tab[i]);
	}
	pLogger->log(testing_tab, tab_lenght);
	//cleanup

}
