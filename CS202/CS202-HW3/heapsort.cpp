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
void heapSort(int arr[], int length, int& moveCount, int& compCount){
    heap newHeap(length);
    int* newArr = new int[length];
    for(int i = 0; i < length; i++){
        newArr[i] = arr[i];
    }
    newHeap.buildHeap(newArr, length, int& moveCount, int& compCount); //create the heap from the copied array

     //we have to create a new array to store the result since our heap data structure removes elements one by one
    int leftCounter = 0;
    for(int i = length - 1; i > 0; i++){
        int currMax = newHeap.popMaximum();
        int temp = arr[i];
        arr[i] = currMax;
        arr[leftCounter++] = temp;
    }
    if(newArr != NULL){
        delete[] newArr;
    }
}
int main(int argc, char** argv){
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    ifstream inputFile(inputFileName);
    string currLine;

    int length = 0;
    while(inputFile){
        getline(inputFile, currLine);
        length++;
    }
    heap newHeap(length); //create a heap instance
    int arr[length];
    inputFile.open(inputFileName); //reopen the input file this time we will place the items in our array
    int currIndex = 0;
    while(inputFile){
        getline(inputFile, currLine);
        int currValue = stoi(currLine);
        arr[currIndex++] = currValue;
    }
    newHeap.buildHeap(arr, length);
    heapSort(arr, length);

    //write the resulting sorted array into the provided output file
    ofstream outputFile(outputFileName);

    for(int i = 0; i < length; i++){
        currLine = to_string(arr[i]) + "\n";
        outputFile << currLine;
    }
    return 0;
}
