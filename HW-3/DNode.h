#ifndef DNode_H
#define DNode_H
#pragma once

template<class ItemType>
class DNode{
public:
    DNode();
    DNode(ItemType* it);
    ~DNode();

    DNode* prev = nullptr;
    DNode* next = nullptr;
    ItemType* data = nullptr;
};
#endif // DNode_h
