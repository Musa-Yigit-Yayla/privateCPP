#include "NgramTree.h"
#include "BSTNode.h"
#include "string.h"
#include <fstream>
#include <cmath>
using namespace std;

//Global utility function prototypes
int stringCompare(string s1, string s2);
BSTNode* copyNode(BSTNode* givenNode);
bool isParentNode(BSTNode* givenNode, BSTNode* childNode);
//void countNodes(BSTNode* currNode);


//NgramTree functions
NgramTree::NgramTree(){
    //generate empty bst
}
//Copy constructor
NgramTree::NgramTree(const NgramTree& copyValue){
    BSTNode* newRoot = nullptr;
    newRoot = this->postorderHelper(copyValue.root, copyNode); //WARNING MIGHT BE PROBLEMATIC TO CALL INSTANCE FUNCTION ON OBJECT THAT IS
    //CURRENTLY BEING INITIALIZED
    this->root = newRoot;
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
    else if(ngram.size() == this->root->str.size()){
        //search for the node
        this->addNgramHelper(this->root, nullptr, false, ngram);
    }
}
//Perform binary search on the given subtree and add the ngram or increment count of the given ngram by one
//Private modifier so as to avoid futile calls made by client
//isLeftChild specified that whether our currNode is the left child of our parent node
void NgramTree::addNgramHelper(BSTNode* currNode, BSTNode* parentNode, const string& ngram){
    if(currNode != NULL){
        int comparisonValue = stringCompare(currNode->str, ngram);
        if(currNode->str == ngram){
            currNode->counter++;
        }
        else if(comparisonValue < 0){
            //search right subtree
            this->addNgramHelper(currNode->rightChild, currNode, ngram);
        }
        else{
            //ngram precedes currNode's string value lexicographically
            this->addNgramHelper(currNode->leftChild, currNode, ngram); //search left subtree
        }
    }
    else{
        //we are at the position where our ngram should be added, instantiate a new node dynamically and add it to our bst
        currNode = new BSTNode(ngram);
        //the node to be added cannot be the root node, so we are sure that parentNode is not nullptr, hence perform linkage
        bool isLeftChild = parentNode->leftChild == currNode;
        if(isLeftChild){
            parentNode->leftChild = currNode;
        }
        else{
            parentNode->rightChild = currNode;
        }
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

    //1-) copy our bst
    NgramTree* copiedTree = new NgramTree(*this);
    //2-)Retrieve the height
    int height = this->getHeight();
    if(height == 0 || height == 1){
        return true; //an empty tree is a complete tree just like a tree with a single node
    }

    //invoke the correlated postorderHelper function on copied tree so we can remove its leaf nodes
    bool isLeafRemoved = copiedTree->preorderHelper(copiedTree->root, height); //this bool variable is useless, just written it for increasing readability
    if(!copiedTree->isFull()){
        delete copiedTree;
        return false; //return false as the subtree is not a full tree
    }
    delete copiedTree;
    copiedTree = new NgramTree(*this); //copy this tree object by using all of the nodes again
    //Traverse each and every node at level height - 1 and ensure that the order of their children satisfy a complete tree's properties for
    //leaf nodes
    const int size = pow(2, height - 1);
    const int searchLevel = height - 1;
    BSTNode** leafNodes = new BSTNode*[size]; //we will store the nodes at level height - 1 in this pointer array
    int leafIndex = 0;
    copiedTree->inorderHelper(levelNodes, copiedTree->root, leafIndex, size, searchLevel); //with this function we now have desired nodes

    //Now we will check the children of leafNodes, notice that leafNodes stands for nodes at level height - 1
    int prevChildStatus = 0;
    for(int i = 0; i < leafIndex; i++){
        BSTNode* currNode = leafNodes[i];
        if(currNode->leftChild == NULL && currNode->rightChild != NULL){ //this condition fails a tree for being a complete tree
            //deallocate the memory we allocated for only this function's purposes and return false
            delete[] leafNodes;
            delete copiedTree;
            return false;
        }
        if(i == 0){
            if(currNode->leftChild != NULL){
                prevChildStatus++;
            }
            if(currNode->rightChild != NULL){
                prevChildStatus++;
            }
        }
        else{
            int currChildStatus = 0; //status of current node's child count
            if(currNode->leftChild != NULL){
                currChildStatus++;
            }
            if(currNode->rightChild != NULL){
                currChildStatus++;
            }

            if(prevChildStatus == 0 && currChildStatus != 0){
                delete[] leafNodes;
                delete copiedTree;
                return false; //fails to be a complete tree
            }
            else if(prevChildStatus == 1 && currChildStatus != 0){
                delete[] leafNodes;
                delete copiedTree;
                return false;
            }
            //reset the prevChildStatus to a value based on this node's corresponding state
            prevChildStatus = currChildStatus;
        }
    }
    return true;
}
bool NgramTree::isFull() const{
    //retrieve the max height of this tree
    int height = this->getHeight();
    if(height == 0){
        return true;
    }
    int nodeCount = 0;
    int maxPossibleNodes = pow(2, height) - 1;
    this->inorderHelper(this->root, nodeCount);

    bool result = (nodeCount == maxPossibleNodes);
    return result;

}
void NgramTree::generateTree( const string& fileName, const int n ){
    //create a file object representing current input file
    ifstream inputFile(fileName);
    //below loop is executed while we haven't reached the end of file
    while(!inputFile.eof()){
        string currLine;
        getline(inputFile, currLine);
        int arrayLength;
        string* currTokens = tokenize(currLine);
        for(int i = 0; i < arrayLength; i++){
            string token = currTokens[i];
            if(token.size() == n){
                this->add(token);
            }
        }
        //delete the tokens of current line since it's dynamically allocated
        delete[] currTokens;
    }
}
//If the root is nullptr then the tree must be empty
bool NgramTree::isEmpty() const{
    return this->root == NULL;
}
int NgramTree::getHeight() const{
    //traverse the whole tree recursively to retrieve the max height
    if(this->root == NULL){
        return 0;
    }
    else{
        int maxHeight = this->getHeightHelper(this->root, 1);
        return maxHeight;
    }
}
//private visibility modifier
//Pass the root node and 1 to the currHeight from the caller
int NgramTree::getHeightHelper(BSTNode* currNode, int currHeight){
    if(currNode != NULL){
        //traverse in preorder fashion
        currHeight;
        int maxHeight = this->getHeightHelper(currNode->leftChild, currHeight + 1);
        int rightHeight = this->getHeightHelper(currNode->rightChild, currHeight + 1);

        if(rightHeight > maxHeight){
            maxHeight = rightHeight;
        }
        return maxHeight;
    }
    return -1; //return -1 when the currNode is nullptr
}
//string correlated with root node
//Returns empty string if root is empty
string NgramTree::getRootString() const{
    if(!this->isEmpty()){
        return this->root->str;
    }
    else{
        return "";
    }
}
//return the root's counter
//return -1 if the tree is empty
//number of occurrences that our root's string has occurred in the text file
int NgramTree::getRootCounter() const{
    if(!this->isEmpty()){
        return this->root->counter;
    }
    else{
        return -1;
    }
}
//removes the givenData if it exists in our bst, returns whether removal is successful
bool NgramTree::remove(string givenData){
    //perform a search correlated with binary search

}
//private modifier
bool NgramTree::removeHelper(BSTNode* currNode, BSTNode* parentNode, const string givenData){
    if(currNode != NULL){
        if(currNode->str == givenData){
            this->removeHelper(currNode);
            return true;
        }
    }
}
//Private modifier
//Removes the given node
//Invoke when you are sure that you are going to remove a node that is existent in our tree
void NgramTree::removeHelper(BSTNode* givenNode, BSTNode* parentNode){
    bool isLeftChild = parentNode->leftChild == givenNode;
    if(givenNode->leftChild == NULL && givenNode->rightChild == NULL){
        //simply delete the given node
        delete givenNode;
    }
    //Node to be removed has one and only one child
    else if(givenNode->leftChild != NULL && givenNode->rightChild == NULL){
        BSTNode* child = givenNode->leftChild;
        delete givenNode;
        if(isLeftChild){
            parentNode->leftChild = child;
        }
        else{
            parentNode->rightChild = child;
        }
    }
    else if(givenNode->rightChild != NULL && givenNode->leftChild == NULL){
        BSTNode* child = givenNode->rightChild;
        delete givenNode;
        if(isLeftChild){
            parentNode->leftChild = child;
        }
        else{
            parentNode->rightChild = child;
        }
    }
    else{
        //retrieve inorder successor
    }
}
void NgramTree::clear(){

}
//returns the counter of a node in bst, returns -1 if node does not exist
int NgramTree::getCounter(string givenData) const{

}
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

//Deletes leaf nodes on height h
bool NgramTree::preorderHelper(BSTNode* currNode, const int height){
    //Since we will perform remove operation on farthest leaf nodes without any children, we can perform in preorder manner
    if(currNode != NULL){
        int currNodeHeight = this->getNodeHeight(this->root, currNode, 1); //retrieve the height of currNode
        if(currNodeHeight == height){
            //delete the current node as it's one of the farthest leaf nodes
            //Before deletion retrieve its parent node
            BSTNode* parent = this->preorderHelper(this->root, currNode, isParentNode);
            if(parent->leftChild == currNode){
                parent->leftChild = nullptr;
            }
            else{
                parent->rightChild = nullptr; //CAREFUL, SOME ERRORS MAY OCCUR
            }
            delete currNode;
            return true;
        }
        bool isDeleted = this->preorderHelper(currNode->leftChild, height);
        isDeleted = isDeleted || this->preorderHelper(currNode->rightChild, height);
        return isDeleted;
    }
    return false;
}
//We want to invoke isParentNode function so we can retrieve the parent node of the searchNode if it exists
//Returns the parent node if it exists, otherwise returns nullptr
BSTNode* NgramTree::preorderHelper(BSTNode* currNode, BSTNode* searchNode, bool (*visit)(BSTNode*, BSTNode*)){
    if(visit(currNode, searchNode)){
        return currNode;
    }
    BSTNode* result = this->preorderHelper(currNode->leftChild, searchNode, visit);
    if(result != NULL){
        return result;
    }
    result = this->preorderHelper(currNode->rightChild, searchNode, visit);
    if(result != NULL){
        return result;
    }
    result = nullptr;
    return result;
}
void NgramTree::inorderHelper(BSTNode* givenNode, void (*visit)(BSTNode* currNode)){
    if(givenNode != NULL){
        inorderHelper(givenNode->leftChild, visit);
        visit(givenNode);
        inorderHelper(givenNode->rightChild, visit);
    }
}
//Store the nodes at the given levelNodes node array if they have the same height as the given level
//It's caller's responsibility to create the pointer array of right size and specify correct parameters starting currNode as root and level as 1
//and currIndex as 0
//currIndex represents the current index that the next array element will be inserted onto
void NgramTree::inorderHelper(BSTNode** levelNodes, BSTNode* currNode, int& currIndex, const int arrSize, const int level){
    if(currNode != NULL){


        this->inorderHelper(levelNodes, currNode->leftChild, currIndex, arrSize, level);
        //calculate the height of the current node
        int currHeight = this->getNodeHeight(this->root, currNode, 1);
        if(currHeight == level){
            //add the currNode to our array
            levelNodes[currIndex++] = currNode;
        }
        this->inorderHelper(levelNodes, currNode->rightChild, currIndex, arrSize, level);
    }
}
//We will invoke this function to count the overall occurrences of a node in the tree
//We must pass the root node of this tree and pass the nodeCount as 0
void NgramTree::inorderHelper(BSTNode* currNode, int& nodeCount){
    if(currNode != NULL){
        this->inorderHelper(currNode->leftChild);
        nodeCount++;
        this->inorderHelper(currNode->rightChild);
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
//Will be used to copy a tree given its root node
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
int NgramTree::getMaxNodeCount() const{
    int currHeight = this->getHeight();
    return ceil(log2(currHeight + 1));
}
//Has public modifier
//Will be used when the parent of a child node has to be retrieved
//If the given node is a null pointer or an irrelevant node the function will return false
//If the given node is the predecessor of child node return true
bool isParentNode(BSTNode* givenNode, BSTNode* childNode){
    bool isParent = false;
    if(givenNode != NULL && (givenNode->leftChild == childNode || givenNode->rightChild == childNode)){
        isParent = true;
    }
    return isParent;
}
//private modifier
//will delete the given node regardless of whether it belongs to the NgramTree instance that our function is being invoked on
//Given node is assumed to be a leaf node
void NgramTree::deleteGivenNode(BSTNode* currNode){
    delete currNode;
}

//Return -1 if given node does not exist in this tree or the tree is empty
int NgramTree::getNodeHeight(BSTNode* currNode, BSTNode* const givenNode, int currHeight){
    static int invokeCount = 0;
    static int maxPossibleNodeCount = this->getMaxNodeCount();
    int currResult = -1;
    if(this->root == NULL){
        return -1;
    }
    else{
        if(currNode == givenNode){
            return currHeight;
        }
        //preorder traverse here
        int h1 = this->getNodeHeight(currNode->leftChild, givenNode, currHeight + 1);
        int h2 = this->getNodeHeight(currNode->leftChild, givenNode, currHeight + 1);
        currResult = max(h1, h2);
    }
    return currResult;

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

//Copies the given BSTNode instance by copying its string and counter value
BSTNode* copyNode(BSTNode* givenNode){
    BSTNode* returnValue = nullptr;
    if(givenNode != NULL){
        returnValue = new BSTNode(givenNode->str);
        returnValue->counter = givenNode->counter;
    }
    return returnValue;
}
//It returns negative value if s1 precedes s2 lexicographically
int stringCompare(const string& s1, const string& s2){
    return strcmp(s1, s2);
}
//This method will be used to split a given string, representing a line, into tokens and return it as an array
//User must pass the string line and an integer that can have value 0 before the method is called
//After the method passed integer value will obtain returned array'S length
//A dynamically allocated array will be returned, hence we the caller is responsible of deletion of the array
//Delimiter is a single blank space
static string* tokenize(string line, int& arrayLength){
    //initially traverse the whole string so we can retrieve array length
    int wordCount = 1;
    for(int i = 0; i < line.size(); i++){
        if(line.at(i) == ' '){
            wordCount++;
        }
    }
    arrayLength = wordCount;
    string* resultArr = new string[arrayLength];
    //traverse the string again and split into tokens
    int prevBlankIndex = -1;
    int arrIndex = 0;
    //!!!!!!!! WARNING THIS LOOP MIGHT BE PROBLEMATIC DUE TO ITS INDEXING, PAY ATTENTION IF ANY PROBLEM  OCCURS !!!!!!!!!!!!!!!!!!!!!!!!!!!11
    for(int i = 0; i < line.size(); i++){
        if(line.at(i) == ' '){
           string currElement = line.substr(prevBlankIndex + 1, i);
           resultArr[arrIndex++] = currElement;
        }
    }
    return resultArr;
}
