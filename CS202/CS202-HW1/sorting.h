/*
* Title: Sorting and Algorithm Efficiency
* Author: Name Surname
* ID: 21000000
* Section: 1
* Assignment: 1
* Description: description of your code
*/
#ifndef SORTING_H
#define SORTING_H
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
#endif // SORTING_H
