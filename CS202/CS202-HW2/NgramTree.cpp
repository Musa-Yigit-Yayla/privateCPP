#include "NgramTree.h"
#include "BSTNode.h"
using namespace std;

NgramTree::NgramTree(){

}
NgramTree::~NgramTree(){

}
void NgramTree::addNgram( const string& ngram ){

}
int NgramTree::getTotalNgramCount() const{

}
bool NgramTree::isComplete() const{

}
bool NgramTree::isFull() const{

}
void NgramTree::generateTree( const string& fileName, const int n ){

}
bool NgramTree::isEmpty() const{

}
int NgramTree::getHeight() const{

}
string NgramTree::getRootString() const{

} //string correlated with root node
int NgramTree::getRootCounter() const{

}//number of occurrences that our root's string has occurred in the text file
void NgramTree::add(string givenData){

} //adds the givenData as a new node if does not exist already. If exists, increments counter of that node by 1.
bool NgramTree::remove(string givenData){

} //removes the givenData if it exists in our bst, returns whether removal is successful
void NgramTree::clear(){

}
int NgramTree::getCounter(string givenData) const{

} //returns the counter of a node in bst, returns -1 if node does not exist
bool NgramTree::nodeExists(string givenData) const{

}
//Functions passed to travers
void NgramTree::preorderTraverse(void (*visit(BSTNode* currNode))){
    //pass the client defined function and root node as parameters
    this->preorderHelper(this->root, visit);
} //perform an operation to each node in preorder traversal or display them based on visit function argument
void NgramTree::inorderTraverse(void (*visit(BSTNode* currNode))){
    this->inorderHelper(this->root, visit);
}
void NgramTree::postorderTraverse(void (*visit(BSTNode* currNode))){
    this->postorderHelper(this->root, visit);
}
//Private functions and overloaded operators
void NgramTree::preorderHelper(BSTNode* givenNode, void (*visit(BSTNode* currNode ))){
    //perform visit operation on our current root, then visit left and right nodes respectively
    if(givenNode != NULL){
        visit(root); //perform the given function
        preorderHelper(givenNode->leftChild, visit);
        preorderHelper(givenNode->rightChild, visit);
    }

} //perform an operation to each node in preorder traversal or display them based on visit function argument
void NgramTree::inorderHelper(BSTNode* givenNode, void (*visit(BSTNode* currNode))){
    if(givenNode != NULL){
        inorderHelper(givenNode->leftChild, visit);
        visit(givenNode);
        inorderHelper(givenNode->rightChild, visit);
    }
}
void NgramTree::postorderHelper(BSTNode* givenNode, void (*visit(BSTNode* currNode))){
    if(givenNode != NULL){
        postorderHelper(givenNode->leftChild, visit);
        postorderHelper(givenNode->rightChild, visit);
        visit(givenNode);
    }
}
//DON'T FORGET TO IMPLEMENT << operator given in header file

