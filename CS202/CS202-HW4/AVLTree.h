/*
* Title: Balanced Search Trees
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 4
* Description: This is the header file for our AVLTree representation
*/
#include <iostream>
#include <cstddef>
#include <string>
#include "AVLNode.h"
#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree{
private:
    AVLNode* root = nullptr;
public:
    void AVLTree(); //empty default contrsuctor
    void ~AVLTree();
    void addWord(string word);
    void generateTree(string inputFileName);
    int printHeight() const;
    int getTotalWordCount() const;
    void printTotalWordCount() const;
    void printWordFrequencies() const;
    void printMostFrequent() const;
    void printLeastFrequent() const;
    void printStandartDeviation() const;
    static int wordCounter(bool reset); //will be used to help count words
private:
    void fixtree(); //will be used to preserve the height property of avl
    bool isFixed(AVLNode* currNode);
    bool isFixedHelper(AVLNode* currNode);
    int getHeightHelper(BSTNode* currNode, int currHeight) const;
    void inorderHelper(AVLNode* currNode, void (*visit(AVLNode* currNode)));
    AVLNode* postorderHelper(AVLNode* currNode); // will be used to retrieve the most frequent node after traversal
    AVLNode* preorderHelper(AVLNode* currNode); // will be used to retrieve the least frequent node after traversal
    void inorderHelper(AVLNode* currNode, int* arr, int& currIndex);
};

#endif // AVLTREE_H
