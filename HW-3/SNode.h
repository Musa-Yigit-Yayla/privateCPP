#ifndef SNODE_H
#define SNODE_H
#pragma once

//Represents the node for singly linked list
template<class ItemType>
class SNode{
public:
    SNode();
    SNode(ItemType* it);
    ~SNode();

    //public datafields
    SNode* next = nullptr;
    ItemType* data = nullptr;

};
#endif // SNODE_H
