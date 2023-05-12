#ifndef DLL_H
#define DLL_H
#pragma once

#include "DNode.h"

class DLL{
public:
    DLL();
    DLL(DNode<ItemType>* head);
    ~DLL();
    bool insert(DNode<ItemType>* node);
    void printList(DNode<ItemType>* node);

    DNode<ItemType>* head = nullptr;

};
#endif // DLL_H
