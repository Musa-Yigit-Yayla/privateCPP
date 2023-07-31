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
    int* newArr = new int[length];
    for(int i = 0; i < length; i++){
        newArr[i] = arr[i];
    }
    newHeap.buildHeap(newArr, length); //create the heap from the copied array

     //we have to create a new array to store the result since our heap data structure removes elements one by one
    int leftCounter = 0;
    for(int i = length - 1; i > 0; i++){
        int currMax = heap.popMaximum();
        int temp = arr[i];
        arr[i] = currMax;
        arr[leftCounter++] = temp;
    }
    if(newArr != NULL){
        delete[] newArr;
    }
}
