/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: This is the header file for the heap class.
*/

#include <iostream>
#include "BSTNode.h"

using namespace std;

class heap{
private:


public:
    void insert(const int a);
    int maximum();
    int popMaximum();
};

