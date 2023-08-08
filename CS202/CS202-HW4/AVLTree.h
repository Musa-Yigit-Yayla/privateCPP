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
#include <fstream>
#include "AVLNode.h"
#ifndef AVLTREE_H
#define AVLTREE_H

class AVLTree{
private:
    AVLNode* root = nullptr;
    ofstream wordFreqs;
    ofstream statistics;
public:
    AVLTree(); //empty default contrsuctor
    ~AVLTree();
    void addWord(string word);
    void generateTree(string inputFileName);
    int printHeight() const;
    void getTotalWordCount() const;
    int printTotalWordCount() const;
    void printWordFrequencies() const;
    void printMostFrequent() const;
    void printLeastFrequent() const;
    void printStandartDeviation() const;
    int getBalanceFactor(AVLNode* givenNode); //will be used to retrieve the balance factor of a given node
    static int wordCounter(bool reset); //will be used to help count words
private:
    AVLNode* getMostFrequent();
    AVLNode* getLeastFrequent();
    string getStandardDeviation();
    void addWordHelper(AVLNode* currNode, AVLNode* parentNode, string word);
    void fixtree(string addedWord); //will be used to preserve the height property of avl
    bool isFixed(AVLNode* currNode);
    bool isFixedHelper(AVLNode* currNode);
    AVLNode* rightRotate(AVLNode* currRoot);
    AVLNode* leftRotate(AVLNode* currRoot);
    AVLNode* getParent(string word); //returns the parent node of the node with a given word if it exists
    int getHeightHelper(AVLNode* currNode, int currHeight) const;
    void writeStatistics(); //invoke this function from the destructor after having opened the statistics file
    void inorderHelper(AVLNode* currNode, void (*visit(AVLNode* currNode)));
    void inorderHelper(AVLNode* currNode, void (*visit(AVLNode* currNode, ofstream wordFreq)));
    AVLNode* postorderHelper(AVLNode* currNode); // will be used to retrieve the most frequent node after traversal
    AVLNode* preorderHelper(AVLNode* currNode); // will be used to retrieve the least frequent node after traversal
    void inorderHelper(AVLNode* currNode, int* arr, int& currIndex);
};

#endif // AVLTREE_H
