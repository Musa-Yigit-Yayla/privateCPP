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
#include <climits>
#include <chrono>
#include <cstddef>

using namespace std;
int maxArraySize; //will be used when merging
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false; //false when swaps occur
    int pass = 1; //start pass from 1 since at most n - 1 passes may occur
    int n = size;
    while(!sorted && (pass < n)){
        sorted = true;
        for(int index = 0; index < n - pass; index++){

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
//It is the exact overloaded version and same implementation of bubble sort but suitable for larger array sizes
/*void bubbleSort(int *arr, const int size, long long &compCount, long long &moveCount){
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
}*/
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

    int pivot = arr[first];
	// move one item at a time until unknown region is empty
   for (  ; firstUnknown <= last; ++firstUnknown) {
      // Invariant: theArray[first+1..lastS1] < pivot
      //            theArray[lastS1+1..firstUnknown-1] >= pivot

      // move item from unknown to proper region
      if (arr[firstUnknown] < pivot) {  	// belongs to S1
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

    const int delimeter = 8000000;
    for(int i = 0; i < size; i++){
        int currValue = rand() % delimeter;//curr value that has been generated, (curr generation)
        /*int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
        if(sign == 0){
            currValue *= -1;
        }*/
        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, const int size){
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];


    /*int prev = INT_MIN;
    for(int i = 0; i < size; i++){
        int currValue;
        do{
            currValue = rand() % INT_MAX;//curr value that has been generated, (curr generation)
            /*int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
            if(sign == 0){
                currValue *= -1;
            }*/
        /*}while(currValue <= prev);

        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
        prev = currValue;
    }*/
    int divisor = (INT_MAX / (size * 2));
    int prev = 0;
    for(int i = 0; i < size; i++){
        int currValue = rand() % divisor + prev;

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


    /*int prev = INT_MAX;
    for(int i = 0; i < size; i++){
        int currValue;
        do{
            currValue = rand() % (INT_MAX / 2);//curr value that has been generated, (curr generation)
            /*int sign = rand() % 2; //if 0 the sign is negative, if 1 the sign is positive
            if(sign == 0){
                currValue *= -1;
            }*/
        /*}while(currValue >= prev);

        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
        prev = currValue;
    }*/
    int divisor = (INT_MAX / (size * 2));
    int prev = 0;
    for(int i = 0; i < size; i++){
        int currValue = rand() % divisor - prev;

        arr1[i] = currValue;
        arr2[i] = currValue;
        arr3[i] = currValue;
        prev = currValue;
    }
}
/*
*algorithmVariation: int, specifies whether algorithm should be bubble, merge or quick sorting. 0, 1, 2 must be passed respectively for desired attributes.
* Implicit helper of performanceAnalysis
*/
void printAlgorithm(int* arr, int size, int algorithmVariation){
    int compCount = 0;
    int moveCount = 0;
    //long long comparisonCount = 0;
    //long long movementCount = 0;
    auto startTime = std::chrono::steady_clock::now();

    if(algorithmVariation == 0){
        //bubble sort
        bubbleSort(arr, size, compCount, moveCount);
    }
    else if(algorithmVariation == 1){
        //merge sort
        mergeSort(arr, 0, size - 1, compCount, moveCount);
    }
    else if(algorithmVariation == 2){
        //quick sort
        quickSort(arr, 0, size - 1, compCount, moveCount);
    }
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    //cout << duration.count() << endl;
    cout << size << " ";
    //std::cout << std::chrono::high_resolution_clock::duration::period::den << " ms ";
    cout << duration.count() << " ms ";
    /*if(algorithmVariation == 0){
        //use long values for comp and move counts
        cout << comparisonCount << " ";
        cout << movementCount << endl;
    }*/
    //else{
        cout << compCount << " ";
        cout << moveCount << endl;
    //}
}
//Invoke when we are executing each and every sorting algorithms
//helper of performanceAnalysis
void executeSortingAlgorithms(int**& arr1Pointers, int**& arr2Pointers, int**& arr3Pointers){
    const int sizeCoefficient = 4000;
    const int sizeVariation = 10;

    int sc = sizeCoefficient;
    int sv = sizeVariation;


    //execute bubble sort for each arrays in arr1Pointers
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array SizeElapsed timecompCount moveCount" << endl;

    for(int i = 0; i < sv; i++){
        int compCount = 0;
        int moveCount = 0;
        printAlgorithm(arr1Pointers[i], (i + 1) * sc, 0);
    }
    //deallocate arrays in arr1Pointers then arr1Pointers
    for(int i = 0; i < sv; i++){
        delete[] arr1Pointers[i];
    }
    delete[] arr1Pointers;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array SizeElapsed timecompCount moveCount" << endl;

    for(int i = 0; i < sv; i++){
        int compCount = 0;
        int moveCount = 0;
        printAlgorithm(arr2Pointers[i], (i + 1) * sc, 1);
    }
    //deallocate arrays in arr1Pointers then arr1Pointers
    for(int i = 0; i < sv; i++){
        delete[] arr2Pointers[i];
    }
    delete[] arr2Pointers;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array SizeElapsed timecompCount moveCount" << endl;

    for(int i = 0; i < sv; i++){
        int compCount = 0;
        int moveCount = 0;
        printAlgorithm(arr3Pointers[i], (i + 1) * sc, 2);
    }
    //deallocate arrays in arr1Pointers then arr1Pointers
    for(int i = 0; i < sv; i++){
        delete[] arr3Pointers[i];
    }
    delete[] arr3Pointers;

    arr1Pointers = nullptr;
    arr2Pointers = nullptr;
    arr3Pointers = nullptr; //for increasing readibility
}
//Systematically calls various functions to generate different array variations and invoke various sorting algorithms to measure time efficiency.
void performanceAnalysis(){
    //initially we will call all 3 algorithms on random arrays with different sizes
    const int sizeCoefficient = 4000;
    const int sizeVariation = 10;

    int sc = sizeCoefficient;
    int sv = sizeVariation;

    int** arr1Pointers = new int*[sizeVariation]; //for bubble sort
    int** arr2Pointers = new int*[sizeVariation]; //for merge sort
    int** arr3Pointers = new int*[sizeVariation]; //for quick sort

    //instantiate random arrays sequentially
    for(int i = 1; i <= sv; i++){
        int currSize = sc * i;

        int* arr1 = nullptr;
        int* arr2 = nullptr;
        int* arr3 = nullptr;
        createRandomArrays(arr1, arr2, arr3, currSize);

        arr1Pointers[i - 1] = arr1;
        arr2Pointers[i - 1] = arr2;
        arr3Pointers[i - 1] = arr3;
    }

    cout << "Random Order Arrays" << endl;
    executeSortingAlgorithms(arr1Pointers, arr2Pointers, arr3Pointers);

    //these arrays have been deallocated in the helper method
    arr1Pointers = new int*[sizeVariation]; //for bubble sort
    arr2Pointers = new int*[sizeVariation]; //for merge sort
    arr3Pointers = new int*[sizeVariation]; //for quick sort

    //instantiate ascending arrays sequentially
    for(int i = 1; i <= sv; i++){
        int currSize = sc * i;

        int* arr1 = nullptr;
        int* arr2 = nullptr;
        int* arr3 = nullptr;
        createAscendingArrays(arr1, arr2, arr3, currSize);

        arr1Pointers[i - 1] = arr1;
        arr2Pointers[i - 1] = arr2;
        arr3Pointers[i - 1] = arr3;
    }
    cout << "Ascending Order Arrays" << endl;
    executeSortingAlgorithms(arr1Pointers, arr2Pointers, arr3Pointers);

    //these arrays have been deallocated in the helper method
    arr1Pointers = new int*[sizeVariation]; //for bubble sort
    arr2Pointers = new int*[sizeVariation]; //for merge sort
    arr3Pointers = new int*[sizeVariation]; //for quick sort

    //instantiate descending arrays sequentially
    for(int i = 1; i <= sv; i++){
        int currSize = sc * i;

        int* arr1 = nullptr;
        int* arr2 = nullptr;
        int* arr3 = nullptr;
        createDescendingArrays(arr1, arr2, arr3, currSize);

        arr1Pointers[i - 1] = arr1;
        arr2Pointers[i - 1] = arr2;
        arr3Pointers[i - 1] = arr3;
    }
    cout << "Descending Order Arrays" << endl;
    executeSortingAlgorithms(arr1Pointers, arr2Pointers, arr3Pointers);
}
