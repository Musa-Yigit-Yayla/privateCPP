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

heap::heap(){

}
void heap::insert(const int a){
    if(this->arr == nullptr){
        this->arrayLength = 1;
        this->arr = new int[arrayLength];
        this->arr[0] = a;
    }
    else{
        //create a new array with size + 1
        int* newArr = new int[this->arrayLength + 1];
        for(int i = 0; i < this->arrayLength; i++){
            newArr[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = newArr;
        //insert the new element into the array
        this->arr[this->arrayLength] = a;
        // Trickle new item up to its proper position
        int place = this->arrayLength;
        int parent = (place - 1) / 2;
        while ((place > 0) && (this->arr[place] > this->arr[parent])) {
            int temp = this->arr[parent];
            this->arr[parent] = this->arr[place];
            this->arr[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        this->arrayLength++;
    }
}
int heap::maximum(){

}
int heap::popMaximum(){

}
