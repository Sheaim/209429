/*
 * quicksort.cpp
 * created on april 5 2015
 * author: sheaim
 *
 */
#include <iostream>
#include "quicksort/quicksort.h"
#include "common/logger.h"

int* merge_arrays_number(int* low, int lowArrayLenght, int* high, int highArrayLenght)
{
    std::cout<<"low array"<<std::endl;
    for(int i=0; i<lowArrayLenght;++i)
    {
        std::cout<<low[i]<<" ";
    }
    std::cout<<std::endl;
    int mergedArrayLenght = lowArrayLenght+highArrayLenght;
    int* mergedArray = new int[mergedArrayLenght];
    for(int i=0; i<lowArrayLenght;++i)
    {
        mergedArray[i] = low[i];
    }
    std::cout<<"high array"<<std::endl;
    for(int i=0; i<highArrayLenght;++i)
    {
        std::cout<<high[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i<highArrayLenght;++i)
    {
        mergedArray[i+lowArrayLenght] = high[i];
    }
    for(int i=0; i<mergedArrayLenght;++i)
    {
        std::cout<<mergedArray[i]<<" ";
    }
    std::cout<<std::endl;
    return mergedArray;
}


int* quicksort_number(int* collection, int array_lenght)
{
    int pivot;
    int* low = new int[array_lenght];
    int* high = new int[array_lenght];
    int counterOfLowArrayElements=0;
    int counterOfHighArrayElements=0;
    for(int i=0; i<array_lenght;++i)
    {
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"finding pivot"<<std::endl;
    pivot = 0;
    for (int i=0; i<array_lenght; ++i)
    {
        pivot = pivot + collection[i];
    }
    pivot = pivot/array_lenght;
    for(int i=0; i<array_lenght; ++i)
    {
        if (collection[i]<=pivot)
        {
            std::cout<<"adding "<<collection[i]<<"to low"<<std::endl;
            low[counterOfLowArrayElements]=collection[i];
            ++counterOfLowArrayElements;
        }
        else
            if(collection[i]>pivot)
        {
            high[counterOfHighArrayElements]=collection[i];
            ++counterOfHighArrayElements;
            std::cout<<"adding "<<collection[i]<<"to high"<<std::endl;
        }
        else
        {
            std::cout<<wrong_value_error_message<<std::endl;
            break;
        }
    }

    if(counterOfLowArrayElements!=1)
    {
        quicksort_number(low, counterOfLowArrayElements);
        quicksort_number(high, counterOfHighArrayElements);
    }


    for(int i=0; i<array_lenght;++i)
    {
        collection[i] = merge_arrays(low, counterOfLowArrayElements, high, counterOfHighArrayElements)[i];
        std::cout<<collection[i]<<" ";
    }
    std::cout<<std::endl;
    return collection;
}


