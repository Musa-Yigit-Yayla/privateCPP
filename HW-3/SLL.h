#ifndef SLL_H
#define SLL_H
#pragma once

#include "SNode.h"

class<ItemType it>
class SLL{
public:
    SLL();
    SLL(SNode<ItemType>* head);
    ~SLL();
    bool insert(SNode<ItemType>* node);
    void printList(SNode<ItemType>* node);

    SNode<ItemType>* head = nullptr;
};
#endif // SLL_H
