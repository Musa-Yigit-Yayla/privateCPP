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
void mergeSort(int *arr, const int size, int &compCount, int &moveCount){
    int mid = first + (last - first) / 2; //sort each half
    int length1 = mid - first; //lengths of each subarray when original array is split in two almost equal pieces
    int length2 = last - (mid + 1);
    maxArraySize = length1;
    mergeSort(arr, length1, compCount, moveCount);
    maxArraySize = length2;
    mergeSort(arr, length2, compCount, moveCount);
    merge(arr, first, mid, last);
}
void quickSort(int *arr, const int size, int &compCount, int &moveCount){

}
void merge(int* arr, int first, int mid, int last){
    //Initialize variables
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;


}
