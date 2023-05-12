#ifndef SNODE_H
#define SNODE_H
#pragma once

//Represents the node for singly linked list
class <ItemType it>
class SNode{
public:
    SNode();
    SNode(ItemType* it);
    ~SNode;

    //public datafields
    SNode* next = nullptr;
    ItemType* data;

};
#endif // SNODE_H
