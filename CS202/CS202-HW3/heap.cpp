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

int heap::popMaximum(){
    if(this->arr != nullptr){
        int returnValue = this->arr[0];
        int* newArr = new int[this->arrayLength - 1];
        for(int i = this->arrayLength - 2; i > 0; i--){
            newArr[i] = this->arr[i];
        }
        newArr[0] = this->arr[this->arrayLength - 1]; //set the last element as the new root, subsequently trickle it down

        delete[] this->arr;
        this->arr = newArr;
        this->arrayLength--;

        int i = 0;
        if(this->arrayLength == 1){
            return returnValue;
        }

        bool isLocated;
        if(this->arrayLength == 2){
            isLocated = this->arr[i] > this->arr[i * 2 + 1]; //compare the only two elements of the heap
            if(!isLocated){
                int temp = this->arr[i];
                this->arr[i] = this->arr[i * 2 + 1];
                this->arr[i * 2 + 1] = temp;
                return returnValue;
            }
        }
        else{
            isLocated = this->arr[i] > this->arr[i * 2 + 1] && this->arr[i] > this->arr[i * 2 + 2];
        }
        while(!isLocated){
            //swap the current root with its larger child if it has any
            int child1 = -1;
            int child2 = -1;
            if(i * 2 + 1 < this->arrayLength){
                child1 = this->arr[i * 2 + 1];
            }
            if(i * 2 + 2 < this->arrayLength){
                child2 = this->arr[i * 2 + 2];
            }
            if(child1 == -1){
                //since first child is out of bounds, this implies that the second child is the same
                isLocated = true;
            }
            else if(child2 == -1){
                //first child exists if it's larger swap it with the parent
                if(child1 > this->arr[i]){
                    int temp = this->arr[i];
                    this->arr[i] = this->arr[i * 2 + 2];
                    this->arr[i * 2 + 2] = temp;
                }
                isLocated = true; //true since we have compared the current item with the last child
            }
            else{
                //both children exist swap it with the higher one and update is located
                int largerChild = child1;
                int largerIndex = 2 * i + 1;
                if(child2 > child1){
                    largerChild = child2;
                    largerIndex = 2 * i + 2;
                }
                if(largerChild > this->arr[i]){
                    int temp = this->arr[i];
                    this->arr[i] = largerChild;
                    this->arr[largerIndex] = temp;
                    i = largerIndex;
                }
                else{
                    isLocated = true; //we placed the node we have been trickling down to the correct location
                }
            }
        }
    }
    return -1;
}