#ifndef DLL_H
#define DLL_H
#pragma once

#include "DNode.h"

template<class ItemType>
class DLL{
public:
    DLL();
    DLL(DNode<ItemType>* head);
    ~DLL();
    bool insert(DNode<ItemType>* node);
    DNode<ItemType>* remove(const int id)
    void printList();

    DNode<ItemType>* head = nullptr;

};
#endif // DLL_H
