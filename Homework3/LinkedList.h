#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
using namespace std;

template<class ItemType>
class LinkedList{
private:
    Node<ItemType>* headPtr;
    int itemCount;

    Node<ItemType> getNodeAt(int position) const;
public:
    LinkedList<ItemType>();
    LinkedList<ItemType>(const LinkedList<ItemType>& aList);
    ~LinkedList<ItemType>();

    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool append(const ItemType& newEntry);
    bool remove(int position);
    void clear();

    ItemType getEntry(int position) const;

    void setEntry(int position, const ItemType& newEntry);
};
#endif // _LINKED_LIST
