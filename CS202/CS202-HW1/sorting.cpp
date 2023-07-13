#include "sorting.h"

int maxArraySize; //will be used when merging
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount){
    bool sorted = false; //false when swaps occur
    int pass = 1; //start pass from 1 since at most n - 1 passes may occur
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
void mergeSort(int* arr, const int first, const int last, int &compCount, int &moveCount){
    static int invokeCount = 0; // will help us to recall number of times this function has recursively invoked itself and
    static int initialFirst; //we will use these variables to determine whether invokeCount must be reset to 0 for later usage of the function
    static int initialFirst; //we will use these variables to determine whether invokeCount must be reset to 0 for later usage of the function
    static int initialLast;
    //we will use this function to set max array size when necessary
    if(invokeCount == 0){
        ::maxArraySize = last - first;
        initialFirst = first;
        initialLast = last;
    }
    invokeCount++;
    int mid = first + (last - first) / 2; //sort each half
    /*int length1 = mid - first; //lengths of each subarray when original array is split in two almost equal pieces
    int length2 = last - (mid + 1);

    maxArraySize = length1;*/
    mergeSort(arr, first, mid, compCount, moveCount);

    //maxArraySize = length2;
    mergeSort(arr, mid + 1, last, length2, compCount, moveCount);

    merge(arr, first, mid, last);
    if(first == initialFirst && last == initialLast){
        invokeCount = 0;
        //initialFirst and initialLast variables will be set to desired values after the next time function has been invoked
    }

}
void quickSort(int *arr, const int size, int &compCount, int &moveCount){

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
        if(theArray[first1] <= theArray[first2]){
            tempArray[index] = theArray[first1];
            first1++;
        }
        else{
            tempArray[index] = theArray[first2];
            first2++;
        }
        index++;
        compCount++; //increment by one since we have compared two array elements
        moveCount++; //increment by one since we are copying the element to aux array
    }

    //Add the remaining part of exhausted array if any exists
    while(first2 <= last2){
        tempArray[index] = theArray[first2];
        first2++;
        index++;
        moveCount++;
    }
    for(int i = first; i <= last; i++){
        theArray[i] = tempArray[i];
        moveCount++;
    }
    //delete tempArray for avoiding memory leak
    delete[] tempArray;
}
