/*
 * file benchmark.h
 * created on 7 Apr, 2015
 * author: sheaim
 *
 */


#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "Stos.hh"
#include "common/logger.h"
#include "Stoper.hh"
#include "quicksort/quicksort.h"

/*!
 * Class Benchmark contains all functions required to benchmark quicksort algorithm implemented in quicksort.h
 * file. It requires outside data in the form of an array of elements of any numerical type including but not
 * limited to int, double, bool, unsigned int, signed int etc.
 */
template <typename type>
class benchmark_number
{
private:
    Stos<type> *arrayStack;
    double timer;

protected:
    benchmark_number();

public:
    benchmark_number(type* inputArray, int inputArraylength);
    virtual ~benchmark_number();

public:
    virtual double runBenchmark();
    virtual void changeArray(type* newArray, int newArraySize);
    virtual void resetTimer();
    virtual double readTimer();
};

//As templates can't be defined outside header file


/*!
 * \brief generic argument-less constructor is set to protected to limit the possibility of accidental call.
 * This constructor allows for input of the array that will be sorted during the benchmark.
 * As no special types are used (could be either std::vector or std::array) additional input is needed
 * in the form of the inputArraylength which equals to the number of elements in the array. If those numbers
 * don't match the whole thing will go to hell either due to index out of bounds or segfault.
 * TODO: add error handling in the form of try/catch functions that will handle the ioob or segfault errors.
 * \param inputArray is the main array that will be sorted during the benchmark running
 * \param inputArrayLength is the number of elements in inputArray
 */
template <typename type>
benchmark_number<type>::benchmark_number(type* inputArray, int inputArraylength)
{
    arrayStack = new Stos<type>();
    for(int i=0; i<inputArraylength; ++i)
    {
        arrayStack->push200(inputArray[i]); //using most efficient push method provided.
    }
    timer = 0;
}

/*!
 * \brief generic destructor frees up memory at delete.
 */
template <typename type>
benchmark_number<type>::~benchmark_number()
{
    delete arrayStack;
    timer=0;
}
/*!
 * \brief function readTimer() is self-explanatory
 */
template <typename type>
double benchmark_number<type>::readTimer()
{
    return timer;
}

/*!
 * \brief runBenchmark() runs a time benchmark of the quicksort algorithm, based on the previous benchmark
 * frameworks and using methods provided by the 'Stos' data structure.
 * It is argument-less as all arguments are provided when creating the array, and returns "timer" double value.
 */
template <typename type>
double benchmark_number<type>::runBenchmark()
{

    int templength = arrayStack->size_licznik(); //takes value provided by the data structure
    int* temp = new type[templength]; //self explanatory

    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    performanceCountStart = startTimer(); //method provided by 'Stoper' header file. Otherwise self-explanatory
    temp= quicksort(arrayStack->getTab(), arrayStack->size_licznik()); //sorts the array and stores it in the form of 'temp' array
    performanceCountEnd = endTimer();
    delete arrayStack;
    arrayStack = new Stos<type>(); //reallocates data structure
    for (int i=0; i<templength; ++i)
    {
        arrayStack->push200(temp[i]); //using most efficient method provided by data structure
    }
    delete temp;
    timer = performanceCountEnd.QuadPart - performanceCountStart.QuadPart; //acquire time difference
    return timer;
}
/*!
 * method changeArray(), while unused can be useful in the future.
 * All it does is replacing the array in benchmark object
 */
template <typename type>
void benchmark_number<type>::changeArray(type* newArray, int newArraylength)
{
    delete arrayStack;
    arrayStack = new Stos<type>();
    for(int i=0; i<newArraylength; ++i)
    {
        arrayStack->push200(newArray[i]);
    }
}
/*!
 * Method resetTimer(), while unused can be useful in the future.
 * Resets the timer to 0 effectively prepping the benchmark object for another run without reallocating memory.
 */
template <typename type>
void benchmark_number<type>::resetTimer()
{
    timer=0;
}



#endif // BENCHMARK_H_
