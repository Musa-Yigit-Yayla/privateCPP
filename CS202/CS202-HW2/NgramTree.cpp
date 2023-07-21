#include "NgramTree.h"
#include "BSTNode.h"
#include "string.h"
using namespace std;

//Global utility function prototypes
int stringCompare(string s1, string s2);
//void countNodes(BSTNode* currNode);


//NgramTree functions
NgramTree::NgramTree(){
    //generate empty bst
}
//Copy constructor
NgramTree::NgramTree(NgramTree& copyValue){

}
NgramTree::~NgramTree(){
    //invoke clear function to delete each and every node of the tree
    this->clear();
}
//Add ngram to our bst if it doesn't exist
//If it does exist then increment its count by one
void NgramTree::addNgram( const string& ngram ){
    //If root is null, directly add it
    if(this->root == NULL){
        this->root = new BSTNode(ngram);
    }
    else{
        //search for the node
        this->addNgramHelper(this->root, ngram);
    }
}
//Perform binary search on the given subtree and add the ngram or increment count of the given ngram by one
//Private modifier so as to avoid futile calls made by client
void NgramTree::addNgramHelper(BSTNode* currNode, const string& ngram){
    if(currNode != NULL){
        int comparisonValue = stringCompare(currNode->str, ngram);
        if(currNode->str == ngram){
            currNode->counter++;
        }
        else if(comparisonValue < 0){
            //search right subtree
            this->addNgramHelper(currNode->rightChild, ngram);
        }
        else{
            //ngram precedes currNode's string value lexicographically
            this->addNgramHelper(currNode->leftChild, ngram); //search left subtree
        }
    }
    else{
        //we are at the position where our ngram should be added, instantiate a new node dynamically and add it to our bst
        currNode = new BSTNode(ngram);
    }
}
int NgramTree::getTotalNgramCount(){
    //postorder traverse the tree and count the total number of nodes
    int result = 0;
    result += this->postorderTraverse();
    return result;
}
//Will be invoked when user needs to check whether current bst is a complete bst
//Returns true when the current state of our tree satisfies a complete tree
bool NgramTree::isComplete() const{
    //The idea is to initially make a deep copy of our bst, then retrieve the height of our bst
    //Subsequently we will remove the nodes which are at the level of the height, namely farthest leaf nodes, from copied bst
    //Then we will check whether remaining bst is a full tree
    //If it's a full tree we will create another copy, then check whether the children of nodes at height h - 1 satisfy complete tree properties for leaf nodes

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
void NgramTree::preorderTraverse(void (*function)(BSTNode*)){
    //pass the client defined function and root node as parameters
    this->preorderHelper(this->root, function);
} //perform an operation to each node in preorder traversal or display them based on visit function argument
void NgramTree::inorderTraverse(void (*visit)(BSTNode*)){
    this->inorderHelper(this->root, visit);
}
void NgramTree::postorderTraverse(void (*visit)(BSTNode*)){
    this->postorderHelper(this->root, visit);
}
int NgramTree::postorderTraverse(){
    return this->postorderHelper(this->root);
}
//Private functions and overloaded operators
void NgramTree::preorderHelper(BSTNode* givenNode, void (*visit)(BSTNode* currNode )){
    //perform visit operation on our current root, then visit left and right nodes respectively
    if(givenNode != NULL){
        visit(root); //perform the given function
        preorderHelper(givenNode->leftChild, visit);
        preorderHelper(givenNode->rightChild, visit);
    }

} //perform an operation to each node in preorder traversal or display them based on visit function argument
void NgramTree::inorderHelper(BSTNode* givenNode, void (*visit)(BSTNode* currNode)){
    if(givenNode != NULL){
        inorderHelper(givenNode->leftChild, visit);
        visit(givenNode);
        inorderHelper(givenNode->rightChild, visit);
    }
}
void NgramTree::postorderHelper(BSTNode* givenNode, void (*visit)(BSTNode* currNode)){
    if(givenNode != NULL){
        postorderHelper(givenNode->leftChild, visit);
        postorderHelper(givenNode->rightChild, visit);
        visit(givenNode);
    }
}

int NgramTree::postorderHelper(BSTNode* currNode){
    int subtreeResult = 0; // result that will be attained from current subtree
    if(currNode != NULL){
        subtreeResult += postorderHelper(currNode->leftChild);
        subtreeResult += postorderHelper(currNode->rightChild);
        subtreeResult++; //increment by one since we are counting the current node aswell
    }
    return subtreeResult;
}
BSTNode* NgramTree::postorderHelper(BSTNode* currNode, BSTNode* (*copyNode)(BSTNode* currNode)){
    BSTNode* returnValue = nullptr;
    if(currNode != NULL){
        BSTNode* leftSubtree = this->postorderHelper(currNode->leftChild, copyNode); //the node assigned to this pointer reference is the root node of our copied
        //left subtree
        BSTNode* rightSubtree = this->postorderHelper(currNode->rightChild, copyNode);
        returnValue = copyNode(currNode);
        returnValue->leftChild = leftSubtree;
        returnValue->rightChild = rightSubtree;
    }
    return returnValue;
}
//private modifier
//will delete the given node regardless of whether it belongs to the NgramTree instance that our function is being invoked on
//Given node is assumed to be a leaf node
void NgramTree::deleteGivenNode(BSTNode* currNode){
    delete currNode;
}
/*private modifier
*will be used to count the total nodes in our bst
*will be passed as an argument to postorderTraverse
*will increment the given parameter by 1
*given int parameter is passed by reference so it will be incremented in the caller
*/
/*void NgramTree::countNodes(BSTNode* currNode){
    if(currNode != NULL){
        sum++;
    }
}*/
//DON'T FORGET TO IMPLEMENT << operator given in header file

//Global utility functions
//It returns negative value if s1 precedes s2 lexicographically
int stringCompare(const string& s1, const string& s2){
    return strcmp(s1, s2);
}

