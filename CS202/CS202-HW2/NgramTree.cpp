#include "NgramTree.h"
#include "BSTNode.h"
#include "string.h"
#include <fstream>
#include <cmath>
#include <iostream>
using namespace std;

//Global utility function prototypes
int stringCompare(string& s1, string& s2);
BSTNode* copyNode(BSTNode* givenNode);
bool isParentNode(BSTNode* givenNode, BSTNode* childNode);
static string* tokenize(string line, int& arrayLength, const int n);
void deleteNode(BSTNode* givenNode); //delete a given node if it's not null, invoke only on leaf nodes without any children
//void countNodes(BSTNode* currNode);
string getNonConstString(const string& s1);
void displayNode(BSTNode* givenNode);

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
        this->addNgramHelper(this->root, nullptr, ngram);
    }
}
//Perform binary search on the given subtree and add the ngram or increment count of the given ngram by one
//Private modifier so as to avoid futile calls made by client
//isLeftChild specified that whether our currNode is the left child of our parent node
void NgramTree::addNgramHelper(BSTNode* currNode, BSTNode* parentNode, const string& ngram){
    if(currNode != NULL){
        string copyStr = getNonConstString(ngram);

        int comparisonValue = stringCompare(currNode->str, copyStr);
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
    copiedTree->inorderHelper(leafNodes, copiedTree->root, leafIndex, size, searchLevel); //with this function we now have desired nodes

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
    string currLine;
    //below loop is executed while we haven't reached the end of file
    while(getline(inputFile, currLine)){
        int arrayLength = 0;
        string* currTokens = tokenize(currLine, arrayLength, n);
        for(int i = 0; i < arrayLength; i++){
            string token = string(currTokens[i]);
            //if(token.size() == n){
                this->addNgram(token);
            //}
        }
        //delete the tokens of current line since it's dynamically allocated
        if(currTokens != NULL){
            delete[] currTokens;
        }
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
int NgramTree::getHeightHelper(BSTNode* currNode, int currHeight) const{
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
    if(this->nodeExists(givenData)){
        //retrieve the parent node of the node with givenData and retrieve that node as well
        return true;
    }
    return false;
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
    else{ //the node to be removed has two children
        //retrieve inorder successor
        BSTNode* successor = nullptr;
        successor = this->getInorderSuccessor(givenNode);
        //retrieve the value of the successor node
        string successorString = successor->str;
        int successorCounter = successor->counter;
        //remove the successor node, but before that retrieve its parent node
        BSTNode* successorParent = this->preorderHelper(givenNode, successor, isParentNode);
        this->removeHelper(successor, successorParent);
        //we are guaranteed that the successor is removed successfully by invoking this helper method recursively
        //now we have to copy successor's data to givenNode
        givenNode->str = successorString;
        givenNode->counter = successorCounter;
    }
}
void NgramTree::clear(){
    //traverse the tree in a post order fashion and invoke remove method on each node
    if(this->root != NULL){
        this->postorderHelper(this->root, deleteNode);
    }
}
//returns the counter of a node in bst, returns -1 if node does not exist
int NgramTree::getCounter(string givenData) const{
    BSTNode* node = this->getNodeHelper(this->root, givenData);
    int result = -1;
    if(node != NULL){
        result = node->counter;
    }
    return result;
}
//Private visibility
//Performs binary search and at the end returns the node with the givenData match if it exists
//O(logn)
BSTNode* NgramTree::getNodeHelper(BSTNode* currNode, const string& givenData) const{
    if(currNode == NULL){
        return nullptr;
    }
    else{
        string copyStr = getNonConstString(givenData);
        int comparison = stringCompare(copyStr, currNode->str);
        if(comparison < 0){
            return this->getNodeHelper(currNode->leftChild, givenData);
        }
        else if(comparison == 0){
            return currNode;
        }
        else{
            return this->getNodeHelper(currNode->leftChild, givenData);
        }
    }
}
//searches the tree in a binary search manner and returns whether a node with the given string value exists
bool NgramTree::nodeExists(string givenData) const{
    BSTNode* node = this->getNodeHelper(this->root, givenData);
    return node != NULL;
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
//O(logn) time complexity
BSTNode* NgramTree::preorderHelper(BSTNode* currNode, BSTNode* searchNode, bool (*visit)(BSTNode*, BSTNode*)){
    if(currNode == NULL){
        return nullptr;
    }
    if(visit(currNode, searchNode)){
        return currNode;
    }
    int comparison = stringCompare(searchNode->str, currNode->str);
    if(comparison < 0){
        //the searchNode could be located in the left subtree
        return this->preorderHelper(currNode->leftChild, searchNode, visit);
    }
    else{
        //we disregard the case when comparison == 0 is true because we would have returned the parent node way before
        //search the parent node at the right subtree
        return this->preorderHelper(currNode->rightChild, searchNode, visit);
    }/* //old implementation, current one has better time complexity and efficiency
    BSTNode* result = this->preorderHelper(currNode->leftChild, searchNode, visit);
    if(result != NULL){
        return result;
    }
    result = this->preorderHelper(currNode->rightChild, searchNode, visit);
    if(result != NULL){
        return result;
    }
    result = nullptr;
    return result;*/
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
void NgramTree::inorderHelper(BSTNode* currNode, int& nodeCount) const{
    if(currNode != NULL){
        this->inorderHelper(currNode->leftChild, nodeCount);
        nodeCount++;
        this->inorderHelper(currNode->rightChild, nodeCount);
    }
}
//Invoke when we need to get the inorder successor of a node
//given string parameter is the string value of the given node which is about to be removed and certainly has 2 children
//Currently we are not interested with nodes that have only one child or no children
BSTNode* NgramTree::getInorderSuccessor(BSTNode* currNode){
    static int invokeCount = 0;
    BSTNode* returnValue = nullptr;
    if(currNode != NULL){
        if(invokeCount == 0){
            invokeCount++;
            returnValue = this->getInorderSuccessor(currNode->rightChild); //search the right subtree of the given node
        }
        else{
            if(currNode->leftChild == NULL){
                //this is the leftmost node in our right subtree hence the inorder successor
                //set the invokeCount back to 0 so we can use this method properly later on
                invokeCount = 0;
                return currNode;
            }
            else{
                returnValue = this->getInorderSuccessor(currNode->leftChild);
            }
        }

    }
    return returnValue;
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
ostream& operator<<( ostream& out, const NgramTree& tree ){
    //traverse the tree in an inorder fashion and print each tree node
    NgramTree* constTree = const_cast<NgramTree*>(&tree);
    constTree->inorderTraverse(displayNode);
    return out;
}
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
void deleteNode(BSTNode* givenNode){
    if(givenNode != NULL){
        delete givenNode;
    }
}
//It returns negative value if s1 precedes s2 lexicographically
int stringCompare(string& s1, string& s2){
    if(s1 == s2){
        return 0;
    }
    else if(s1 > s2){
        return 1;
    }
    else{
        return -1;
    }
}
string getNonConstString(const string& s1){
    string s;
    for(int i = 0; i < s.size(); i++){
        s += s1.at(i);
    }
    return s;
}
//Displays the given node
void displayNode(BSTNode* givenNode){
    if(givenNode != NULL){
        cout << "\"" << givenNode->str << "\"" << " appears " << givenNode->counter << " time(s)" << endl;
    }
}
//This method will be used to split a given string, representing a line, into tokens and return it as an array
//User must pass the string line and an integer that can have value 0 before the method is called
//After the method passed integer value will obtain returned array'S length
//A dynamically allocated array will be returned, hence we the caller is responsible of deletion of the array
//Delimiter is a single blank space
static string* tokenize(string line, int& arrayLength, const int n){
    //initially traverse the whole string so we can retrieve array length
    int wordCount = 1;
    for(int i = 0; i < line.size(); i++){
        if(line.at(i) == ' '){
            wordCount++;
        }
    }
    arrayLength = wordCount;
    string resultArr[arrayLength];
    //traverse the string again and split into tokens
    int prevBlankIndex = -1;
    int arrIndex = 0;
    //!!!!!!!! WARNING THIS LOOP MIGHT BE PROBLEMATIC DUE TO ITS INDEXING, PAY ATTENTION IF ANY PROBLEM  OCCURS !!!!!!!!!!!!!!!!!!!!!!!!!!!11
    for(int i = 0; i < line.size(); i++){
        if(line.at(i) == ' '){
           //add a word
           string currElement;
            if(arrIndex == 0){
                currElement = line.substr(0, i);
            }
            else if(arrIndex == arrayLength - 1){
                currElement = line.substr(prevBlankIndex + 1);
            }
            else{
                currElement = line.substr(prevBlankIndex + 1, i);
            }
           resultArr[arrIndex++] = currElement;
           prevBlankIndex = i;
        }
    }
    //after we have retrieved the array, alter the array so that it only contains usable words
    int newLength = 0;
    for(int i = 0; i < arrayLength; i++){
        if(resultArr[i].size() == n){
            newLength++;
        }
        else if(resultArr[i].size() > n){
            newLength += (resultArr[i].size() - n) + 1;
        }
    }
    if(newLength == 0){
        return nullptr;
    }
    else{
        string* newArr = new string[newLength];
        arrIndex = 0;
        for(int i = 0; i < arrayLength; i++){
            string str = resultArr[i];
            if(str.size() >= n){
                newArr[arrIndex++] = str;
            }
            else if(str.size() > n){
                for(int i = 0; i < str.size() - n + 1; i++){
                    string currSubstr;
                    if(i != str.size() - n){
                        currSubstr = str.substr(i, i + n);
                    }
                    else{
                        currSubstr = str.substr(i);
                    }
                    newArr[arrIndex++] = currSubstr;
                }
            }
        }
        arrayLength = newLength;
        return newArr;
    }
}
