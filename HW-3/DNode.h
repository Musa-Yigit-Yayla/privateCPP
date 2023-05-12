#ifndef DNode_h
#define DNode_h
#pragma once

class <ItemType it>
class DNode_h{
public:
    DNode();
    DNode(ItemType* it);

    DNode* prev = nullptr;
    DNode* next = nullptr;
    ItemType* data;
};
#endif // DNode_h
