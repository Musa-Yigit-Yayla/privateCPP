/*
* Title: Sorting and Algorithm Efficiency
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 1
* Description: This file has function prototypes for sorting functions and their helpers, also contains files regarding array generation and other utilities etc.
*/
#ifndef SORTING_H
#define SORTING_H
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int* arr, const int first, const int last, int &compCount, int &moveCount);
    void merge(int* arr, int first, int mid, int last, int const& compCount, int const& moveCount);
    void quickSort(int *arr, const int first, const int last, int &compCount, int &moveCount);
    void partition(int* arr, int first, int last, int& compCount, int const& moveCount, int const& pivotIndex);
    void displayArray(const int *arr, const int size);
    void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size);
    void performanceAnalysis();
#endif // SORTING_H
