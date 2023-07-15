/*
* Title: Sorting and Algorithm Efficiency
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 1
* Description: This file has implementations of some sorting algorithms and some other utility functions regarding generating arrays etc.
*/

#include "sorting.h"
#include <iostream>
#include <cmath>

using namespace std;
int maxArraySize; //will be used when merging
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false; //false when swaps occur
    int pass = 1; //start pass from 1 since at most n - 1 passes may occur
    int n = size;
    while(!sorted && (pass < n)){
        sorted = true;
        for(int index = 0; index < n; index++){

            int nextIndex = index + 1;
            if(arr[index] > arr[nextIndex]){
                int temp = arr[index];
                arr[index] = arr[nextIndex];
                arr[nextIndex] = temp;
                sorted = false; //signal exchange
                moveCount += 3; // 3 operations for swapping
            }
            compCount++;
        }
        pass++;
    }
}
void merge(int* arr, int first, int mid, int last, int& compCount, int& moveCount){
    int* tempArray = new int[::maxArraySize];

    //Initialize variables
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;

    int index = first1;
    while(first1 <= last1 && first2 <= last2){
        if(arr[first1] <= arr[first2]){
            tempArray[index] = arr[first1];
            first1++;
        }
        else{
            tempArray[index] = arr[first2];
            first2++;
        }
        index++;
        compCount++; //increment by one since we have compared two array elements
        moveCount++; //increment by one since we are copying the element to aux array
    }

    //Add the remaining part of exhausted array if any exists
    while(first1 <= last1){
        tempArray[index] = arr[first1];
        first1++;
        index++;
        moveCount++;
    }
    while(first2 <= last2){
        tempArray[index] = arr[first2];
        first2++;
        index++;
        moveCount++;
    }
    for(int i = first; i <= last; i++){
        arr[i] = tempArray[i];
        moveCount++;
    }
    //delete tempArray for avoiding memory leak
    delete[] tempArray;
}
void mergeSort(int* arr, const int first, const int last, int &compCount, int &moveCount){
    static int invokeCount = 0; // will help us to recall number of times this function has recursively invoked itself and
    static int initialFirst; //we will use these variables to determine whether invokeCount must be reset to 0 for later usage of the function
    static int initialLast;
    //we will use this function to set max array size when necessary
    if(first < last){
        if(invokeCount == 0){
            ::maxArraySize = last - first;
            initialFirst = first;
            initialLast = last;
        }
        invokeCount++;
        int mid = (first + last) / 2; //sort each half
        /*int length1 = mid - first; //lengths of each subarray when original array is split in two almost equal pieces
        int length2 = last - (mid + 1);

        maxArraySize = length1;*/
        mergeSort(arr, first, mid, compCount, moveCount);

        //maxArraySize = length2;
        mergeSort(arr, mid + 1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
        if(first == initialFirst && last == initialLast){
            invokeCount = 0;
            //initialFirst and initialLast variables will be set to desired values after the next time function has been invoked
        }
    }

}
void partition(int* arr, int first, int last, int& compCount, int& moveCount, int& pivotIndex){
           // initially, everything but pivot is in unknown
   int lastS1 = first;           // index of last item in S1
   int firstUnknown = first + 1; // index of first item in unknown

	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (arr[firstUnknown] < pivotIndex) {  	// belongs to S1
		  ++lastS1;

    	  int temp = arr[firstUnknown];
    	  arr[firstUnknown] = arr[lastS1];
    	  arr[lastS1] = temp;
    	  moveCount += 3;
      }	// else belongs to S2
      compCount++;
   }
   // place pivot in proper position and mark its location
   //swap(theArray[first], theArray[lastS1]);
   int temp = arr[first];
   arr[first] = arr[lastS1];
   arr[lastS1] = temp;
   pivotIndex = lastS1;
   moveCount += 3;
}
void quickSort(int *arr, const int first, const int last, int &compCount, int &moveCount){
    int pivotIndex = first;
    if(first < last){
        partition(arr, first, last, compCount, moveCount, pivotIndex);

        //sort remaining two halves recursively until the condition is not satisfied anymore
        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}
void displayArray(const int *arr, const int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
//Creates 3 completely identical arrays
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];

    for(int i = 0; i < size; i++){
        int currValue = rand() % INT_MAX;//curr value that has been generated, (curr generation)
        int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
        if(sign == 0){
            currValue *= -1;
        }
        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];


    int prev = INT_MIN;
    for(int i = 0; i < size; i++){
        int currValue;
        do{
            currValue = rand() % INT_MAX;//curr value that has been generated, (curr generation)
            int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
            if(sign == 0){
                currValue *= -1;
            }
        }while(currValue <= prev);

        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
        prev = currValue;
    }

}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];


    int prev = INT_MAX;
    for(int i = 0; i < size; i++){
        int currValue;
        do{
            currValue = rand() % INT_MAX;//curr value that has been generated, (curr generation)
            int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
            if(sign == 0){
                currValue *= -1;
            }
        }while(currValue >= prev);

        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
        prev = currValue;
    }

}
