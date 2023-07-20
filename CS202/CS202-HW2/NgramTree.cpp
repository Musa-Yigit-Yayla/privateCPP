#include "NgramTree.h"
#include "BSTNode.h"
using namespace std;

//Global utility function prototypes
int stringCompare(string s1, string s2);

//NgramTree functions
NgramTree::NgramTree(){
    //generate empty bst
}
NgramTree::~NgramTree(){
    //delete each and every node by applying post order traversal
    this->postorderTraverse(this->deleteGivenNode());
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
        if(currNode->str == ngram){
            currNode->counter++;
        }
        int comparisonValue = stringCompare(currNode->str, ngram);
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
//private modifier
//will delete the given node regardless of whether it belongs to the NgramTree instance that our function is being invoked on
//Given node is assumed to be a leaf node
//Invoke sequentially by passing this function as a parameter to postorderTraverse during destruction
void NgramTree::deleteGivenNode(BSTNode* currNode){
    delete currNode;
}
//DON'T FORGET TO IMPLEMENT << operator given in header file

//Global utility functions
//It returns negative value if s1 precedes s2 lexicographically
int stringCompare(string s1, string s2){
    return strcmp(s1, s2);
}
