/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This file be used to provide the user with a heap sort function
*/
#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>
#include "heap.h"

using namespace std;

//initially create a heap
void heapSort(int arr[], int length, long long& moveCount, long long& compCount){
    heap newHeap(length);
    //newHeap.buildHeap(arr, length, moveCount, compCount);
    int* newArr = new int[length];
    for(int i = 0; i < length; i++){
        newArr[i] = arr[i];
    }
    newHeap.buildHeap(newArr, length, moveCount, compCount); //create the heap from the copied array

     //we have to create a new array to store the result since our heap data structure removes elements one by one
    int leftCounter = 0;
    for(int i = length - 1; i >= 0; i--){
        arr[i] = newHeap.popMaximum(moveCount, compCount);
    }
    /*if(newArr != NULL){
        delete[] newArr;
    }*/
}
int main(int argc, char** argv){
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    ifstream inputFile(inputFileName);
    string currLine;

    int length = 0;
    int currValue;
    while (inputFile >> currValue) {
        length++;
    }

    // Dynamically allocate the array to hold the integers
    int* arr = new int[length];

    // Reset the file stream and read values to the array
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);
    int currIndex = 0;
    while (inputFile >> currValue) {
        arr[currIndex++] = currValue;
    }
    inputFile.close();
    long long moveCount = 0;
    long long compCount = 0;
    //newHeap.buildHeap(arr, length, moveCount, compCount);
    heapSort(arr, length, moveCount, compCount);

    //write the resulting sorted array into the provided output file
    ofstream outputFile(outputFileName);
    currLine = "Move Count: " + to_string(moveCount) + ", Comparison Count: " + to_string(compCount) + "\n";
    outputFile << currLine;
    for(int i = 0; i < length; i++){
        currLine = to_string(arr[i]) + "\n";
        outputFile << currLine;
    }
    delete[] arr;
    return 0;
}
