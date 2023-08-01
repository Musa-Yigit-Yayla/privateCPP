/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This file be used to provide the user with a heap sort function
*/
/*#include <cstddef>
#include <fstream>
#include <string>
#include <iostream>
#include <random>
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
    for(int i = length - 1; i > 0; i++){
        int currMax = newHeap.popMaximum(moveCount, compCount);
        int temp = arr[i];
        arr[i] = currMax;
        arr[leftCounter++] = temp;
        moveCount += 3;
    }
    /*if(newArr != NULL){
        delete[] newArr;
    }*/
/*}
void test0(){
    int n = 20;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 800;
    }
    long long moveCount = 0, compCount = 0;
    heapSort(arr, n, moveCount, compCount);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(int argc, char** argv){
    bool debugMode = true;
    if(debugMode){
        test0();
        return 0;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    ifstream inputFile(inputFileName);
    string currLine;

    int length = 0;
    while(inputFile){
        getline(inputFile, currLine);
        length++;
    }
    //heap newHeap(length); //create a heap instance
    int arr[length];
    inputFile.open(inputFileName); //reopen the input file this time we will place the items in our array
    int currIndex = 0;
    while(inputFile){
        getline(inputFile, currLine);
        int currValue = stoi(currLine);
        arr[currIndex++] = currValue;
    }
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
    return 0;
}
*/
