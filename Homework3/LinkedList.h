/*
Musa Yiğit Yayla
22003108
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <string>
using namespace std;

template<class ItemType>


class LinkedList{
private:
    Node<ItemType>* headPtr;
    int itemCount;

    Node<ItemType>& getNodeAt(int position) const; // MIGHT BE PROBLEMATIC !!1
public:
    LinkedList<ItemType>();
    LinkedList<ItemType>(const LinkedList<ItemType>& aList);
    ~LinkedList<ItemType>();

    bool isEmpty() const;
    int getLength() const;
    bool insertElt(int newPosition, const ItemType& newEntry);
    bool append(const ItemType& newEntry);
    bool removeElt(int position);
    void clearElts();
    ItemType getEntry(int position) const;
    void setEntry(int position, const ItemType& newEntry);
};
#endif // _LINKED_LIST
