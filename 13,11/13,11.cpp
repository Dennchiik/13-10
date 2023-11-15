#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#ifdef INTEGER
typedef int DataType;
#elif defined DOUBLE
typedef double DataType;
#elif defined CHAR
typedef char DataType;
#endif

const int ARRAY_SIZE = 10;

void FillArray(DataType arr[]);
void ShowArray(DataType arr[]);
DataType FindMin(DataType arr[]);
DataType FindMax(DataType arr[]);
void SortArray(DataType arr[]);
void EditArray(DataType arr[]);

#endif 
#include "function.h"

void FillArray(DataType arr[]) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = static_cast<DataType>(rand() % 100); 
    }
}

void ShowArray(DataType arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

DataType FindMin(DataType arr[]) {
    DataType minVal = arr[0];
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

DataType FindMax(DataType arr[]) {
    DataType maxVal = arr[0];
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void SortArray(DataType arr[]) {
    std::sort(arr, arr + ARRAY_SIZE);
}

void EditArray(DataType arr[]) {
    int index;
    DataType newValue;
    std::cout << "Enter index and new value: ";
    std::cin >> index >> newValue;
    if (index >= 0 && index < ARRAY_SIZE) {
        arr[index] = newValue;
    }
    else {
        std::cout << "Invalid index!" << std::endl;
    }
}

#ifdef INTEGER
void ShowArrayInt() {
    DataType intArray[ARRAY_SIZE];
    FillArray(intArray);
    std::cout << "Integer Array: ";
    ShowArray(intArray);
    std::cout << "Min: " << FindMin(intArray) << std::endl;
    std::cout << "Max: " << FindMax(intArray) << std::endl;
    SortArray(intArray);
    std::cout << "Sorted Integer Array: ";
    ShowArray(intArray);
    EditArray(intArray);
    std::cout << "Edited Integer Array: ";
    ShowArray(intArray);
}
#elif defined DOUBLE
#elif defined CHAR
#endif
#ifndef PROG_H
#define PROG_H

#define INTEGER 

#ifdef INTEGER
#define show ShowArrayInt
#elif defined DOUBLE
#define show ShowArrayDouble
#elif defined CHAR
#define show ShowArrayChar
#endif

#endif 
#include "function.h"
#include "prog.h"

int main() {
    show(); 
    return 0;
}



