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
#include "AVLNode.h"

using namespace std;
AVLNode::AVLNode(string word){
    this->word = word;
    this->counter++;
}
AVLNode::~AVLNode(){
    if(this->left != NULL){
        delete this->left;
        this->left = nullptr;
    }
    if(this->right != NULL){
        delete this->right;
        this->right = nullptr;
    }
}
