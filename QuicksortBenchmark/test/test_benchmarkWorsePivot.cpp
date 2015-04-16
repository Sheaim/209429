/*
 * test_benchmark.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: sheaim
 */

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <string>
#include <fstream>

#include "common/logger.h"
#include "common/catch.hpp"
#include "../benchmarkWorsePivot.h"
#include "quicksort/quicksort_number.h"


TEST_CASE ("benchmarking quicksortSimpleStack", "[factorial]")
{
    //pre
    std::cout<<"abc"<<std::endl;
    const std::string logFileName = "lolz.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));

    //given
    int testing_tab[5] = {5, 3, 2, 4, 1};
    int tab_lenght = sizeof(testing_tab)/sizeof(int);
    benchmark_number<int>* ptestBenchmark = new benchmark_number<int>(testing_tab, tab_lenght);
    double time = 0;
	// when
	pLogger->log(testing_tab, tab_lenght);
	ptestBenchmark->runBenchmark();
	time = ptestBenchmark->readTimer();
    pLogger->log(time);

    //then
    REQUIRE(time!=0);
    //cleanup


}
