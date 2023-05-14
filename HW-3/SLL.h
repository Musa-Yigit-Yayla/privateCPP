#ifndef SLL_H
#define SLL_H
#pragma once

#include "SNode.h"

template<class ItemType>
class SLL{
public:
    SLL();
    SLL(SNode<ItemType>* head);
    ~SLL();
    SNode<ItemType>* insert(SNode<ItemType>* node);
    SNode<ItemType>* remove(const int id); //removes the ItemType with given id (in our case Course)
    void printList() const;

private:
    SNode<ItemType>* head = nullptr;
};
#endif // SLL_H
