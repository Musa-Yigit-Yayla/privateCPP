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
