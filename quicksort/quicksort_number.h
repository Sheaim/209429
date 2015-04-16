/*
 * quicksort.h
 * created on april 5 2015
 * author: sheaim
 *
 */



#ifndef QUICKSORT_H_
#define QUICKSORT_H_
const std::string wrong_value_error_message = "Error: array part is not a number.";

/*
 * /param collection
 *
 *
 */
int* quicksort_number(int* collection,int array_lenght);
int* merge_arrays_number(int* low, int lowLenght, int* high, int highLenght);

#endif // QUICKSORT_H_
