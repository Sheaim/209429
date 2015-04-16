/*
 * quicksort.h
 * created on april 5 2015
 * author: sheaim
 *
 */



#ifndef QUICKSORT_H_
#define QUICKSORT_H_
const std::string wrong_value_error_message = "Error: array part is not a number.";

//As I cannot have templates in a .cpp file, they need to be defined in a 'h file (here).


/*!
 * \param collection
 * \brief is an input array of 'type' elements, has a set lenght
 * \param array_lenght
 * \brief is the amount of elements that make up the 'collection' array
 *
 * \brief output 'collection' is an array of 'type' elements of lenght 'array_lenght'. The array is the sorted 'collection' array.
 */
template<typename type>
type* quicksort(type* collection,int array_lenght);
/*!
 * \param low
 * \param high
 * \brief are input arrays of 'type' elements that will be merged into output array. They have set lenghts, but don't need to be of same lenght.
 * If an array has zero elements the other array is returned.
 * \param lowLenght
 * \param highLenght
 * \brief are lenghts of the low and high arrays. These numbers MUST match, else the whole thing will go to hell.
 *
 * \brief output 'mergedArray' is an array of 'type', lenght 'ArrayLenght' equal to sum of 'lowLenght' and 'highLenght'.
 * It's the result of merging arrays 'low' and 'high' with 'low's elements producing lower part of the array and 'high's elements producing the higher part.
 */
template<typename type>
type* merge_arrays(type* low, int lowLenght, type* high, int highLenght);

template<typename type>
type* merge_arrays(type* low, int lowArrayLenght, type* high, int highArrayLenght)
{
    if(lowArrayLenght==0)
    {
        return high;
    }
    if(highArrayLenght==0)
    {
        return low;
    }
//    else
//    std::cout<<"low array"<<std::endl;
//    for(int i=0; i<lowArrayLenght;++i)
//    {
//        std::cout<<low[i]<<" ";
//    }
//    std::cout<<std::endl;
    int mergedArrayLenght = lowArrayLenght+highArrayLenght;
    type* mergedArray = new type[mergedArrayLenght];
    for(int i=0; i<lowArrayLenght;++i)
    {
        mergedArray[i] = low[i];
    }
//    std::cout<<"high array"<<std::endl;
//    for(int i=0; i<highArrayLenght;++i)
//    {
//        std::cout<<high[i]<<" ";
//    }
//    std::cout<<std::endl;
    for(int i=0; i<highArrayLenght;++i)
    {
        mergedArray[i+lowArrayLenght] = high[i];
    }
//    for(int i=0; i<mergedArrayLenght;++i)
//    {
//        std::cout<<mergedArray[i]<<" ";
//    }
//    std::cout<<std::endl;
    return mergedArray;
}

template<typename type>
type min(type firstValue, type secondValue)
{
    if (firstValue>=secondValue)
        return secondValue;
    else
        return firstValue;
}

template<typename type>
type max(type firstValue, type secondValue)
{
    if (firstValue>=secondValue)
        return firstValue;
    else
        return secondValue;
}


template<typename type>
type* quicksort(type* collection, int array_lenght)
{
    type pivot;
    type* low = new type[array_lenght];
    type* high = new type[array_lenght];
    int counterOfLowArrayElements=0;
    int counterOfHighArrayElements=0;
//    for(int i=0; i<array_lenght;++i)
//    {
//        std::cout<<collection[i]<<" ";
//    }
//    std::cout<<std::endl;
//    std::cout<<"finding pivot"<<std::endl;
    int a = collection[rand()%array_lenght];
    int b = collection[rand()%array_lenght];
    int c = collection[rand()%array_lenght];
    pivot = max(min(a,b), min(max(a,b),c));
    for(int i=0; i<array_lenght; ++i)
    {
        if (collection[i]<=pivot)
        {
//            std::cout<<"adding "<<collection[i]<<"to low"<<std::endl;
            low[counterOfLowArrayElements]=collection[i];
            ++counterOfLowArrayElements;
        }
        else
            if(collection[i]>pivot)
        {
            high[counterOfHighArrayElements]=collection[i];
            ++counterOfHighArrayElements;
//            std::cout<<"adding "<<collection[i]<<"to high"<<std::endl;
        }
        else
        {
            std::cout<<wrong_value_error_message<<std::endl;
            break;
        }
    }
    if(counterOfLowArrayElements!=1&&counterOfHighArrayElements!=0)
    {
        low = quicksort(low, counterOfLowArrayElements);
        high = quicksort(high, counterOfHighArrayElements);
    }

        collection = merge_arrays<type>(low, counterOfLowArrayElements, high, counterOfHighArrayElements);
//        std::cout<<collection[i]<<" ";
    delete low;
    delete high;
//    std::cout<<std::endl;
    return collection;
}


#endif // QUICKSORT_H_
