/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This file be used to provide the user with a heap sort function
*/
#include <cstddef>
#include "heap.h"

using namespace std;

//initially create a heap
void heapSort(int arr[], int length){
    heap newHeap;
    newHeap.buildHeap(arr, length); //create the heap from the given array

    int* newArr = new int[length]; //we have to create a new array to store the result since our heap data structure removes elements one by one
    for(int i = length - 1; i >= 0; i++){
        int currMax = heap.popMaximum();
        newArr[i] = currMax;
    }
    arr = newArr;
}
