#ifndef DNode_H
#define DNode_H
#pragma once

template<class ItemType>
class DNode{
public:
    DNode<ItemType>();
    DNode(ItemType* it);
    ~DNode();

    DNode* prev = nullptr;
    DNode* next = nullptr;
    ItemType* data = nullptr;
};
#endif // DNode_h

#include <cstddef>
/*public:
DNode* prev = nullptr;
    DNode* next = nullptr;
    ItemType* data = nullptr;
*/

template <class ItemType>
DNode<ItemType>::DNode(){

}
template <class ItemType>
DNode<ItemType>::DNode(ItemType* it){
    this->data = it;
}
template <class ItemType>
DNode<ItemType>::~DNode(){
    if(this->data != NULL)
        delete this->data;
    this->next = nullptr;
    this->prev = nullptr;
}
