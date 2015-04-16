/*
 *file main.cpp
 *created on Apr 7, 2015
 *author: sheaim
 *
 *
 *
 *This is the main file that works on the stack implemented by makuchwo in repository 209429.
 *Provided implementation has been slightly modified for the quicksort to work properly.
 *
 *
 */


#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file


 #include <iostream>
 #include <fstream>
 #include "common/logger.h"
 #include "common/catch.hpp"
 #include "../benchmark.h"
 #include "../Stoper.hh"
 #include "../Stos.hh"

TEST_CASE ("benchmarking quicksortBigArray", "[factorial]")
 {
    //pre
    const std::string standardTimeLogString = "Time:";
    const std::string standardElementNumberLogString = "Elements: ";
    const std::string logFileName = "results.txt";
	std::auto_ptr<student::common::Logger> pLogger(new student::common::Logger(logFileName));
    int N = 10;
    int* testing_tab;
    int tab_lenght;
    double time =0;
    //runtime
    std::cout<<"Number of elements: "<<N<<std::endl;
    for(int i=0;i<6;++i)
    {
        testing_tab = new int[N];
        tab_lenght = N;
        for(int j=0; j<N; ++j)
        {
            testing_tab[j] = rand()%1000;
        }
//        pLogger->log(testing_tab, N);
        benchmark_number<int>* ptestBenchmark = new benchmark_number<int>(testing_tab, tab_lenght);

        time = 0;
//        pLogger->log(testing_tab, tab_lenght);
        time = ptestBenchmark->runBenchmark();
        pLogger->log(standardTimeLogString);
        pLogger->log(time);
        pLogger->log(standardElementNumberLogString);
        pLogger->log(N);
        N=N*10;
        delete[] testing_tab;
        delete ptestBenchmark;
//        delete pgenerator;
    }
    //then
    REQUIRE(false);
    //cleanup

 }

