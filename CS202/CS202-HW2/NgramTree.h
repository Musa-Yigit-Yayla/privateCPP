#include <string>
#include <cstddef>
#include "BSTNode.h"
#ifndef NGRAMTREE_H
#define NGRAMTREE_H
class NgramTree {
public:
    NgramTree();
    NgramTree(const NgramTree& copyValue);
    ~NgramTree();
    void addNgram( const string& ngram );//adds the givenData as a new node if does not exist already. If exists, increments counter of that node by 1.
    int getTotalNgramCount();
    bool isComplete() const;
    bool isFull() const;
    void generateTree( const string& fileName, const int n );
    bool isEmpty() const;
    int getHeight() const;
    string getRootString() const; //string correlated with root node
    int getRootCounter() const; //number of occurrences that our string has occurred in the text file
    bool remove(string givenData); //removes the givenData if it exists in our bst, returns whether removal is successful
    void clear();
    int getCounter(string givenData) const; //returns the counter of a node in bst, returns -1 if node does not exist
    bool nodeExists(string givenData) const;
    void preorderTraverse(void (*visit)(BSTNode* currNode)); //perform an operation to each node in preorder traversal or display them based on visit function argument
    void inorderTraverse(void (*visit)(BSTNode* currNode));
    void postorderTraverse(void (*visit)(BSTNode*));
    int postorderTraverse();
    int getMaxNodeCount() const;
private:
    BSTNode* root = nullptr;

    //private functions and overloaded operators
    friend ostream& operator<<( ostream& out, const NgramTree& tree );
    //for invoking with global functions
    int getHeightHelper(BSTNode* currNode, int& maxHeight);
    void preorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode)); //perform an operation to each node in preorder traversal or display them based on visit function argument
    bool preorderHelper(BSTNode* root, const int height); //will be invoked when we are checking whether a tree is a complete tree
    BSTNode* preorderHelper(BSTNode* currNode, BSTNode* searchNode, bool (*visit)(BSTNode*, BSTNode*));
    void inorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode));
    void inorderHelper(BSTNode** leafNodes, BSTNode* currNode, int& currIndex, const int arrSize, const int level);
    void inorderHelper(BSTNode* currNode, int& nodeCount);
    void postorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode));
    int postorderHelper(BSTNode* root);
    BSTNode* postorderHelper(BSTNode* currNode, BSTNode* (*copyNode)(BSTNode* currNode)); //helper for copy constructor
    void deleteGivenNode(BSTNode* currNode);
    int getNodeHeight(BSTNode* currNode, BSTNode* const givenNode, int currHeight); //private utility function to return a node's height if it exists in our tree
    //void countNodes(BSTNode* currNode);
    void addNgramHelper(BSTNode* currNode, BSTNode* parentNode, const string& ngram);
    bool removeHelper(BSTNode* currNode, bstNode* parentNode, const string& ngram);
    void removeHelper(BSTNode* givenNode, BSTNode* parentNode);
};
#endif // NGRAMTREE_H


