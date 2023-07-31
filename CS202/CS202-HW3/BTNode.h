/*
* Title: Heaps and AVL Tree
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include <cstddef>
#ifndef BTNODE_H
#define BTNODE_H

using namespace std;
class BTNode{
public:
    int data;
    BTNode* left = nullptr;
    BTNode* right = nullptr;

    BTNode(int data);
};
#endif // BTNODE_H
