/*
* Title: Sorting and Algorithm Efficiency
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 1
* Description: This main file is responsible of testing algorithm efficiency and displaying correlated results.
*/

#include <iostream>
#include <string>
#include "sorting.h"

using namespace std;
int main()
{
    int arr1[] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1, 15, 18, 3, 11, 13, 6};
    int arr2[] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1, 15, 18, 3, 11, 13, 6};
    int arr3[] = {10, 5, 9, 16, 17, 7, 4, 12, 19, 1, 15, 18, 3, 11, 13, 6};

    int compCount1 = 0;
    int moveCount1 = 0;
    int compCount2 = 0;
    int moveCount2 = 0;
    int compCount3 = 0;
    int moveCount3 = 0;

    /*int& refc1 = compCount1;
    int& refmc1 = moveCount1;
    int& refc2 = compCount2;
    int& refmc2 = moveCount2;
    int& refc3 = compCount3;
    int& refmc3 = moveCount3;*/

    const int size = 16;
    int mid = (size - 1) / 2;
    bubbleSort(arr1, size, compCount1, moveCount1);
    cout << "Bubble Sort" << endl;
    cout << "Comparisons Movements" << endl;

    cout << compCount1 << " " << moveCount1 << endl;
    displayArray(arr1, size);

    mergeSort(arr2, 0, size - 1, compCount2, moveCount2);
    cout << "Merge Sort" << endl;
    cout << "Comparisons Movements" << endl;

    cout << compCount2 << " " << moveCount2 << endl;
    displayArray(arr2, size);

    quickSort(arr3, 0, size - 1, compCount3, moveCount3);
    cout << "Quick Sort" << endl;
    cout << "Comparisons Movements" << endl;

    cout << compCount3 << " " << moveCount3 << endl;
    displayArray(arr3, size);

    cout << "Invoke Performance Analysis" << endl;
    performanceAnalysis();
    return 0;
}
