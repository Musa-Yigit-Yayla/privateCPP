#include <string>
#include <cstddef>
#include "BSTNode.h"
#ifndef NGRAMTREE_H
#define NGRAMTREE_H
class NgramTree {
public:
    NgramTree();
    NgramTree(NgramTree& copyValue);
    ~NgramTree();
    void addNgram( const string& ngram );
    int getTotalNgramCount();
    bool isComplete() const;
    bool isFull() const;
    void generateTree( const string& fileName, const int n );
    bool isEmpty() const;
    int getHeight() const;
    string getRootString() const; //string correlated with root node
    int getRootCounter() const; //number of occurrences that our string has occurred in the text file
    void add(string givenData); //adds the givenData as a new node if does not exist already. If exists, increments counter of that node by 1.
    bool remove(string givenData); //removes the givenData if it exists in our bst, returns whether removal is successful
    void clear();
    int getCounter(string givenData) const; //returns the counter of a node in bst, returns -1 if node does not exist
    bool nodeExists(string givenData) const;
    void preorderTraverse(void (*visit)(BSTNode* currNode)); //perform an operation to each node in preorder traversal or display them based on visit function argument
    void inorderTraverse(void (*visit)(BSTNode* currNode));
    void postorderTraverse(void (*visit)(BSTNode*));
    int postorderTraverse();
private:
    BSTNode* root = nullptr;

    //private functions and overloaded operators
    friend ostream& operator<<( ostream& out, const NgramTree& tree );
    //for invoking with global functions
    void preorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode)); //perform an operation to each node in preorder traversal or display them based on visit function argument
    void inorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode));
    void postorderHelper(BSTNode* root, void (*visit)(BSTNode* currNode));
    int postorderHelper(BSTNode* root);
    BSTNode* postorderHelper(BSTNode* currNode, BSTNode* (*copyNode)(BSTNode* currNode)); //helper for copy constructor
    void deleteGivenNode(BSTNode* currNode);
    //void countNodes(BSTNode* currNode);
    void addNgramHelper(BSTNode* currNode, const string& ngram);
};
#endif // NGRAMTREE_H


