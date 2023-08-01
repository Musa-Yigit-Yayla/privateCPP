/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This is the implementation file for the heap class
*/
#include <cstddef>
#include "heap.h"

using namespace std;

heap::heap(int maxArrayLength){
    this->maxArrayLength = maxArrayLength;
    this->arr = new int[this->maxArrayLength];
    for(int i = 0; i < this->maxArrayLength; i++){
        this->arr[i] = -1;
    }
}
void heap::buildHeap(int arr[], int n, long long& moveCount, long long& compCount){
    for(int i = 0; i < n; i++){
        this->insert(arr[i]);
    }
}
//User is liable of not exceeding the maximum size of the heap that they have provided
void heap::insert(const int a){
    if(this->arrayLength == 0){
        this->arr[0] = a;
        this->arrayLength++;
    }
    else{
        //create a new array with size + 1
        /*int* newArr = new int[this->arrayLength + 1];
        for(int i = 0; i < this->arrayLength; i++){
            newArr[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = newArr;*/
        //insert the new element into the array
        this->arr[this->arrayLength] = a;
        // Trickle new item up to its proper position
        int place = this->arrayLength;
        int parent = (place - 1) / 2;
        while((place > 0) && (this->arr[place] > this->arr[parent])){
            int temp = this->arr[parent];
            this->arr[parent] = this->arr[place];
            this->arr[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        this->arrayLength++;
    }
}
//returns -1 if the heap is empty
int heap::maximum(){
    if(this->arr != nullptr){
        return this->arr[0];
    }
    return -1;
}
//Once we pop the maximum, our heap is readjusted to a state where it is a heap again
int heap::popMaximum(long long& moveCount, long long& compCount) {
    if (this->arrayLength != 0) {
        int returnValue = this->arr[0];
        this->arr[0] = this->arr[this->arrayLength - 1];
        this->arr[this->arrayLength - 1] = -1; // no need to count this as a movecount since we assign -1 directly to it
        this->arrayLength--;
        moveCount++;
        int i = 0;

        while (i < this->arrayLength) {
            // Swap the current root with its larger child if it has any
            int child1 = -1;
            int child2 = -1;
            if (i * 2 + 1 < this->arrayLength) {
                child1 = this->arr[i * 2 + 1];
            }
            compCount++;
            if (i * 2 + 2 < this->arrayLength) {
                child2 = this->arr[i * 2 + 2];
            }
            compCount++;

            if (child1 == -1) {
                // Since the first child is out of bounds, this implies that the second child is also out of bounds
                break; // Exit the while loop
            }
            else if (child2 == -1) {
                // Only the first child exists; if it's larger, swap it with the parent
                if (child1 > this->arr[i]) {
                    int temp = this->arr[i];
                    this->arr[i] = this->arr[i * 2 + 1];
                    this->arr[i * 2 + 1] = temp;
                    moveCount += 3;
                }
                compCount++;
                break; // Exit the while loop
            }
            else {
                // Both children exist; swap with the larger one if it's greater than the parent
                int largerChild = child1;
                int largerIndex = 2 * i + 1;
                if (child2 > child1 && child2 > this->arr[i]) {
                    largerChild = child2;
                    largerIndex = 2 * i + 2;
                }
                compCount++;

                if (largerChild > this->arr[i]) {
                    int temp = this->arr[i];
                    this->arr[i] = largerChild;
                    this->arr[largerIndex] = temp;
                    i = largerIndex; // Update i to the larger child's index
                    moveCount += 3;
                }
                else {
                    break; // Exit the while loop
                }
            }
        }
        return returnValue;
    }
    return -1;
}
