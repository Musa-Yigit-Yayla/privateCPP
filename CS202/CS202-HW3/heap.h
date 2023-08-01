/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This is the header file for the heap class.
*/

#include <iostream>
#include <cstddef>

using namespace std;
#ifndef HEAP_H
#define HEAP_H
class heap{
private:
    int arrayLength = 0;
    int maxArrayLength;
    int* arr = nullptr; //an array representation for heap elements

public:
    heap(int maxArrayLength);
    void buildHeap(int arr[], int n);
    void insert(const int a);
    int maximum();
    int popMaximum();
};

#endif // HEAP_H


