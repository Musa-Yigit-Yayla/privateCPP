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
};
#endif // AVLNODE_H

