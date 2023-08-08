/*
* Title: Balanced Search Trees
* Author: Musa Yiğit Yayla
* ID: 22003108
* Section: 1
* Assignment: 4
* Description: This is the cpp file for our AVLTree representation
*/
#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <cmath>
#include "AVLTree.h"

using namespace std;

bool isAlphaNumeric(char ch);
string** tokenize(string s, int& newLength);
void incrementCount(AVLNode* node);
void printMostFreqHelper(AVLNode* node);
void printLeastFreqHelper(AVLNode* node);
void printFreqHelper(AVLNode* node);
double getStandardDeviation(int arr[], int length);
void writeFrequencies(AVLNode* currNode, ofstream wordFreq);
string adjustDecimal(string result);

AVLTree::AVLTree(){

}
AVLTree::~AVLTree(){
    //before performing any deallocation we must produce the outputs
    this->wordFreqs.open(wordFreqsFile);
    //write the word frequencies
    this->inorderHelper(this->root, writeFrequencies);
    this.statistics.open(statisticsFile);
    this->writeStatistics();

    //just deallocate the root node and the whole tree will be deleted
    if(this->root != nullptr){
        delete this->root;
        this->root = nullptr;
    }
}
void AVLTree::addWord(string word){
    this->addWordHelper(this->root, nullptr, word);
    if(!this->isFixed(this->root)){
        //fix the tree
        this->fixtree();
    }
}
void AVLTree::addWordHelper(AVLNode* currNode, AVLNode* parentNode, string word){
    //perform search similar to bst, if the target already exists then simply increment the counter, otherwise create a new node and add it to the position
    //if a new node is inserted then preserve the height property if there is some issues regarding it
    if(currNode != NULL){
        int comparison = stringCompare(currNode->word, word);
        if(comparison < 0){
            //search right subtree
            this->addWordHelper(currNode->right, currNode, word);
        }
        else if(comparison == 0){
            //increment the counter of the current node
            currNode->counter++;
        }
        else{
            //search the leftg subtree
            this->addWordHelper(currNode->left, currNode, word);
        }
    }
    else{
        //if the search terminates when the currNode is nullptr, then we must instantiate a new AVLNode and insert it into the tree
        AVLNode* newNode = new AVLNode(word);
        if(parentNode == NULL){
            //set the curr node as root
            this->root = newNode; // in this case no need to check for whether the tree is balanced since there is only the root node
        }
        else{
            int compareWithParent = stringCompare(parentNode->word, word);
            if(compareWithParent < 0){
                //the new node must be inserted into the right child
                parentNode->right = newNode;
            }
            else if(compareWithParent > 0){
                parentNode->left = newNode;
            }
        }
    }
}
void AVLTree::generateTree(string inputFileName){
    ifstream inputFile(inputFileName);
    string currLine;
    string* words = nullptr;
    int currLength = 0; //length for the words array that we will be instantiating soon
    while(getline(inputFile, currLine)){
        int newLength = 0;
        string** arr = tokenize(currLine, newLength);
        for(int i = 0; i < newLength; i++){
            string word = *arr[i];
            this->addWord(word);
        }
        delete[] arr;
    }
}
int AVLTree::printHeight() const{
    //traverse the whole tree recursively to retrieve the max height
    if(this->root == NULL){
        cout << "Tree Height: " << maxHeight << endl;
        return 0;
    }
    else{
        int maxHeight = this->getHeightHelper(this->root, 1);
        //!!!! PRINT THE HEIGHT OR WRITE IT INTO THE OUTPUT FILE !!!!
        cout << "Tree Height: " << maxHeight << endl;
        return maxHeight;
    }
}
//private visibility modifier
//Pass the root node and 1 to the currHeight from the caller
int AVLTree::getHeightHelper(BSTNode* currNode, int currHeight) const{
    if(currNode != NULL){
        //traverse in preorder fashion
        //currHeight;
        string currString = currNode->str;
        int leftHeight = this->getHeightHelper(currNode->leftChild, currHeight + 1);
        int rightHeight = this->getHeightHelper(currNode->rightChild, currHeight + 1);
        int maxHeight = max(max(leftHeight, rightHeight), currHeight);
        return maxHeight;
    }
    return 0; //return 0 when the currNode is nullptr
}
//Print the number of nodes in the tree
void AVLTree::printTotalWordCount() const{
    this->inorderHelper(this->root, incrementCount);
    int result = wordCounter(true);
    //!!!!!! PRINT OR WRITE THE RESULT TO OUTPUT FILE !!!!!!
    cout << "Total Word Count: " << result << endl;
}
int AVLTree::getTotalWordCount() const{
    this->inorderHelper(this->root, incrementCount);
    int result = wordCounter(true);
    return result;
}
void AVLTree::printWordFrequencies() const{
    this->inorderHelper(this->root, printFreqHelper);
}
void AVLTree::printMostFrequent() const{
    AVLNode* result = this->postorderHelper(this->root);
    if(result != NULL){
        cout << "Most Frequent: " << result->word << " " << result->counter << endl;
    }
    else{
        cout << "Most Frequent: " << endl;
    }
}
void AVLTree::printLeastFrequent() const{
    AVLNode* result = this->preorderHelper(this->root);
    if(result != NULL){
        cout << "Least Frequent: " << result->word << " " << result->counter << endl;
    }
    else{
        cout << "Least Frequent: " << endl;
    }

}
void AVLTree::printStandartDeviation() const{
    //retrieve the node frequencies in an int array
    int length = this->getTotalWordCount();
    int arr[length];
    int currIndex = 0;
    this->inorderHelper(this->root, arr, currIndex);
    //after the helper has been invoked, our array is filled with tree's nodes' frequencies
    double result = getStandardDeviation(arr, length);
    string resultString = "" + result;
    string resultString = adjustDecimal(resultString);
    cout << "Standard Deviation: " << resultString << endl;
}
string AVLTree::getStandardDeviation(){
    int length = this->getTotalWordCount();
    int arr[length];
    int currIndex = 0;
    this->inorderHelper(this->root, arr, currIndex);
    //after the helper has been invoked, our array is filled with tree's nodes' frequencies
    double result = getStandardDeviation(arr, length);
    string resultString = "" + result;
    string resultString = adjustDecimal(resultString);
    return resultString;
}
AVLNode* AVLTree::getMostFrequent(){
    AVLNode* result = this->postorderHelper(this->root);
    return result;
}
AVLNode* AVLTree::getLeastFrequent(){
    AVLNode* result = this->preorderHelper(this->root);
    return result;
}
void AVLTree::writeStatistics(){
    int wordCount = this->getTotalWordCount();
    int treeHeight = this->printHeight();

    AVLNode* mostFreq = this->getMostFrequent();
    AVLNode* leastFreq = this->getLeastFrequent();

    string sv = this->getStandardDeviation();

    this->statistics << "Total Word Count: " << wordCount << endl;
    this->statistics << "Tree Height: " << treeHeight << endl;
    this->statistics << "Most Frequent: ";
    if(mostFreq != NULL){
        this->statistics << mostFreq.word << " " << mostFreq.counter;
    }
    this->statistics << "\n";

    this->statistics << "Least Frequent: ";
    if(leastFreq != NULL){
        this->statistics << leastFreq.word << " " << leastFreq.counter;
    }
    this->statistics << "\n";
    this->statistics << "Standard Deviation: " << sv << endl;
}
//User is liable of invoking by first ensuring that there is an imbalanced node certainly
//addedWord is the string value of the recently inserted node
void AVLTree::fixtree(string addedWord){
    //retrieve the first node where balance factor is larger than 1
    //To do this, we first need to retrieve the parent of the node containing the given string parameter
    AVLNode* currParent = nullptr;
    //AVLNode* insertedNode = this->root;
    /*while(insertedNode != NULL){
        int comparison = stringCompare(insertedNode->word, word);
        if(comparison < 0){
            //search the right subtree
            insertedNode = insertedNode->right;
        }
        else if(comparison > 0){
            //search the left subtree
            insertedNode = insertedNode->left;
        }
        else{
            break;
        }
    }*/
    //if(insertedNode != NULL){
        //currParent = this->getParent(addedWord);
    //}
    currParent = this->getParent(addedWord); //imbalanced parent
    //retrieve the balance factor of the imbalanced parent

    //left subtree is taller
    //Single right rotation
    if(balance > 1 && addedWord < currParent->left->word){
        this->rightRotate(currParent);
    }
    //Single left rotation
    else if(balance < -1 && addedWord > currParent->right->word){
        this->leftRotate(currParent);
    }
    //Left right rotation
    else if(balance > 1 && addedWord > currParent->left->word){
        currParent->left = this->leftRotate(currParent->left);
        this->rightRotate(currParent);
    }
    //Right left rotation
    else if(balance < -1 && addedWord < currParent->right->word){
        currParent->right = this->rightRotate(currParent->right);
        this->leftRotate(currParent);
    }
}
//Checks whether the current tree satisfies the conditions of being height balanced
//pass the root as the parameter when you want to check the whole tree
bool AVLTree::isFixed(AVLNode* currNode){
    if(currNode != NULL){
        if(!isFixedHelper(currNode)){
            return false;
        }
        if(!this->isFixed(currNode->left))){
            return false;
        }
        if(!this->isFixed(currNode->right)){
            return false;
        }
    }
    return true;
}
//Given a node it will check whether the subtree with root currNode
//helper function that checks whether the given node's left subtree's height differ by the right subtree's height by at most 1
bool AVLTree::isFixedHelper(AVLNode* currNode){
    int leftHeight = this->getHeightHelper(currNode->left);
    int rightHeight = this->getHeightHelper(currNode->right);
    return abs(leftHeight - rightHeight) <= 1;
}
//Performs single right rotation on the subtree with given root
//Invoke by passing the required node when a right rotation is necessary
AVLNode* AVLTree::rightRotate(AVLNode* currRoot){
    Node* currLeft = currRoot->left;
    Node* clRight = currLeft->right; //right child of current left (cl)

    currLeft->right = currRoot;
    currRoot->left = clRight;

    //return the updated root
    return currLeft;
}

//Perform single left rotation and return the updated root
AVLNode* AVLTree::leftRotate(AVLNode* currRoot){
    Node* currRight = currRoot->right;
    Node* crLeft = currRight->left;

    //perform the operation
    currRight->left = currRoot;
    currRoot->right = crLeft;

    return currRight;
}
//Pass the current node as the parent of the added node initially
//It will go all the way up to the root until finding the imbalanced node if it exists
AVLNode* AVLTree::getImbalancedNode(AVLNode* currNode){
    if(currNode != NULL){
        if(!this->isFixed(currNode)){
            return currNode;
        }
        else{
            AVLNode* parent = this->getParent(currNode);
            return this->getImbalancedNode(parent);
        }
    }
    return nullptr;
}
AVLNode* AVLTree::getParent(string word){
    AVLNode* currNode = this->root;
    if(currNode->word == word){
        return nullptr;
    }
    AVLNode* result = nullptr;
    while(currNode != NULL){
        int comparison = stringCompare(currNode->word, word);
        if(comparison < 0){
            //search the right subtree
            if(currNode->right != NULL && currNode->right->word == word){
                return currNode;
            }
            else{
                currNode = currNode->right;
            }
        }
        else if(comparison > 0){
            if(currNode->left != NULL && currNode->left->word == word){
                return currNode;
            }
            else{
                currNode = currNode->right;
            }
        }
    }
    return result;
}
//returns the height difference between the left subtree and right subtree of a given node
int AVLTree::getBalanceFactor(AVLNode* givenNode){
    if(givenNode == NULL){
        return 0;
    }
    else{
        return this->getHeightHelper(givenNode->left, 1) - this->getHeightHelper(givenNode->right, 1);
    }
}
void AVLTree::inorderHelper(AVLNode* currNode, void (*visit(AVLNode* currNode))){
    if(currNode != NULL){
        this->inorderHelper(currNode->left);
        visit(currNode);
        this->inorderHelper(currNode->right);
    }
}
void AVLTree::inorderHelper(AVLNode* currNode, void (*visit(AVLNode* currNode, ofstream wordFreq))){
    if(currNode != NULL){
        this->inorderHelper(currNode->left);
        visit(currNode, wordFreq);
        this->inorderHelper(currNode->right);
    }
}
// will be used to retrieve the most or least frequent node after traversal
AVLNode* AVLTree::postorderHelper(AVLNode* currNode){
    AVLNode* result = nullptr;
    if(currNode != NULL){
        AVLNode* leftNode = this->preorderHelper(currNode->left);
        AVLNode* rightNode = this->preorderHelper(currNode->right);
        int currFreq = currNode->counter;
        int maxFreq = currFreq;
        if(leftNode == NULL && rightNode == NULL){
            return currNode;
        }
        else if(leftNode != NULL && rightNode == NULL){
            maxFreq = max(currFreq, leftNode->counter);
            if(maxFreq == currFreq){
                result = currNode;
            }
            else{
                result = leftNode;
            }
        }
        else if(leftNode == NULL && rightNode != NULL){
            maxFreq = max(currFreq, rightNode->counter);
            if(maxFreq == currFreq){
                result = currNode;
            }
            else{
                result = rightNode;
            }
        }
        else{
            int leftFreq = leftNode->counter;
            int rightFreq = rightNode->counter;

            maxFreq = max(currFreq, max(leftFreq, rightFreq));
            switch(maxFreq){
                case leftFreq: result = leftNode; break;
                case rightFreq: result = rightNode; break;
                case currFreq: result = currNode; break;
            }
        }
    }
    return result;
}
//will be used to retrieve the least frequent node in the tree
AVLNode* AVLTree::preorderHelper(AVLNode* currNode){
    AVLNode* result = nullptr;
    if(currNode != NULL){
        int currFreq = currNode->counter;
        AVLNode* leftNode = this->preorderHelper(currNode->left);
        AVLNode* rightNode = this->preorderHelper(currNode->right);
        int maxFreq = currFreq;
        if(leftNode == NULL && rightNode == NULL){
            return currNode;
        }
        else if(leftNode != NULL && rightNode == NULL){
            maxFreq = min(currFreq, leftNode->counter);
            if(maxFreq == currFreq){
                result = currNode;
            }
            else{
                result = leftNode;
            }
        }
        else if(leftNode == NULL && rightNode != NULL){
            maxFreq = min(currFreq, rightNode->counter);
            if(maxFreq == currFreq){
                result = currNode;
            }
            else{
                result = rightNode;
            }
        }
        else{
            int leftFreq = leftNode->counter;
            int rightFreq = rightNode->counter;

            maxFreq = min(currFreq, min(leftFreq, rightFreq));
            switch(maxFreq){
                case leftFreq: result = leftNode; break;
                case rightFreq: result = rightNode; break;
                case currFreq: result = currNode; break;
            }
        }
    }
    return result;
}
//Invoke from the print median function
//Pass an initial empty array which is of size of the number of nodes in our tree, the array be filled with frequencies of each word
void AVLTree::inorderHelper(AVLNode* currNode, int* arr, int& currIndex){
    if(currNode != NULL){
        this->inorderHelper(currNode->left, arr, currIndex);
        arr[currIndex++] = currNode->counter;
        this->inorderHelper(currNode->right, arr, currIndex);
    }
}
//each and every character that is nonAlphaNumeric is considered to be a delimiter
//Returns a pointer to dynamically allocated array of strings which represent input words.
//Also sets the given int reference to the length of the returned array.
string** tokenize(string s, int& newLength){
    string** result = nullptr;
    int length = 0;
    int wordBeginIndex = -1; //set this to -1 after we have added a word
    //char* terminatingChar = nullptr;
    for(int i = 0; i < s.size(); i++){
        char ch = s.at(i);
        if(isAlphaNumeric(ch)){
            if(wordBeginIndex == -1){
                wordBeginIndex = i;
            }
        }
        //below condition implies that we have in fact found a word
        else if(wordBeginIndex != -1){
            length++;
            wordBeginIndex = -1;
        }
        //terminatingChar = &ch;
    }
    /*if(isAlphaNumeric(*terminatingChar)){
        //add the last word so that we have the correct results
        length++;
    }*/
    //now instantiate the array and traverse once more so we can add the words as desired
    if(length == 0){
        newLength = length;
        return result;
    }
    else{
        wordBeginIndex = -1;
        result = new string*[length];
        newLength = length;
        int currIndex = 0; //index for keeping track of where we are at in the array

        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(isAlphaNumeric(ch)){
                if(wordBeginIndex == -1){
                    wordBeginIndex = i;
                }
            }
            //below condition implies that we have in fact found a word
            else if(wordBeginIndex != -1){
                int currLength = i - wordBeginIndex;
                string currWord = substr(s.begin() + wordBeginIndex, currLength);
                result[currIndex++] = &currWord;
                wordBeginIndex = -1;
            }
            //terminatingChar = &ch;
        }
        return result;
    }
}
void printMostFreqHelper(AVLNode* node){
    //ToDo
}
void printLeastFreqHelper(AVLNode* node){

}
void printFreqHelper(AVLNode* node){
    cout << node->word << " " << node->counter << "\n";
}
void writeFrequencies(AVLNode* currNode, ofstream wordFreq){
    if(currNode != NULL){
        wordFreq << currNode->word + " " + to_string(currNode->counter) + "\n";
    }
}
//When reset is passed as true the current count of encountered words is returned and the counter is set back to 0 for later use
//If the reset is false we keep incrementing the count on each invoke and return -1
//User is responsible of properly invoking the function, and retrieving the output by setting reset to true and reseting the function for later use
static int wordCounter(bool reset){
    static int counter = 0;
    if(!reset){
        counter++;
        return -1;
    }
    else{
        int result = counter;
        counter = 0;
        return result;
    }
}
string adjustDecimal(string result){
    string newResult = "";
    int l1 = 0, l2 = 0;
    int dotIndex = -1;
    for(int i = 0; i < result.size(); i++){
        char ch = result.at(i);
        if(ch == '.'){
            newResult = result.substr(result.begin(), l1);
            dotIndex = i;
            break;
        }
        else{
            l1++;
        }
    }
    l2 = result.size() - dotIndex - 1;
    newResult += result.substr(result.begin() + dotIndex + 1, l2);
    return newResult;
}
//A function which will be passed as an argument to helper functions so as to count the number of nodes in the avl tree
void incrementCount(AVLNode* node){
    wordCounter(false);
}
double getStandardDeviation(int arr[], int length){
    if(length <= 1){
        return 0.0;  // If there's only one element or less, the standard deviation is 0.
    }

    double mean = 0.0;
    double squaredSum = 0.0;

    for(int i = 0; i < length; ++i){
        mean += arr[i];
    }
    mean /= length;

    for(int i = 0; i < length; ++i){
        double deviation = arr[i] - mean;
        squaredSum += deviation * deviation;
    }

    double variance = squaredSum / (length - 1);
    double stdDev = sqrt(variance);

    // Round to two decimal places
    stdDev = round(stdDev * 100) / 100;

    return stdDev;
}
//Function to calculate standard deviation of a given array
double calculateStandardDeviation(int arr[], int length) {
    if (length <= 1) {
        return 0.0;
    }

    double mean = 0.0;
    double squaredSum = 0.0;

    for (int i = 0; i < length; ++i) {
        mean += arr[i];
    }
    mean /= length;

    for (int i = 0; i < length; ++i) {
        double deviation = arr[i] - mean;
        squaredSum += deviation * deviation;
    }

    double variance = squaredSum / (length - 1);
    double stdDev = sqrt(variance);

    // Round to two decimal places
    stdDev = round(stdDev * 100) / 100;

    return stdDev;
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
bool isAlphaNumeric(char ch){
    switch(ch){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z': return true; break;
        default: return false;
    }
}
