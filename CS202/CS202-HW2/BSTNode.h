#include <string>
#include <cstddef>

#ifndef BSTNODE_H
#define BSTNODE_H

using namespace std;
class BSTNode{
public:
    string str; //string contained by BSTNode
    int counter; //number of occurences this string has been attained in given text file
    BSTNode* leftChild = nullptr;
    BSTNode* rightChild = nullptr;

    BSTNode(string str);
};

#endif // BSTNODE_H
