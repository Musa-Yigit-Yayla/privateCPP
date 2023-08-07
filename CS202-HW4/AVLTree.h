#include <iostream>
#include <cstddef>
#include <string>
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
    void printHeight() const;
    void printTotalWordCount() const;
    void printWordFrequencies() const;
    void printMostFrequent() const;
    void printLeastFrequent() const;
    void printStandartDeviation() const;
private:
    void fixtree(); //will be used to preserve the height property of avl
    bool isFixed();
};

#endif // AVLTREE_H
