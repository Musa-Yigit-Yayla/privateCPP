/*
* Title: Balanced Search Trees
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 4
* Description: This is the header file for our AVLTree representation
*/

#include <string>
#include <cstddef>

#ifndef AVLNODE_H
#define AVLNODE _H

using namespace std;
class AVLNode{
public:
    AVLNode* left = nullptr;
    AVLNode* right = nullptr;
    string word;
    int counter = 0;

    AVLNode(string word);
    ~AVLNode();
};
#endif // AVLNODE_H

