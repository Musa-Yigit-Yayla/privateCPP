/*
Musa Yiğit Yayla
22003108
*/

#include "Node.h"

template<class ItemType>
    Node<ItemType>::Node(){

    } // maybe remove ?
template<class ItemType>
    void Node<ItemType>::setNextPointer(Node<ItemType>* nextElt){
        this->nextPtr = nextPtr;
    }
template<class ItemType>
    Node<ItemType>* Node<ItemType>::getNextPointer() const{
        return this->nextPtr;
    }
template<class ItemType>
    ItemType Node<ItemType>::getItem() const{
        return this->item;
    }
template<class ItemType>
    void Node<ItemType>::setItem(ItemType newItem){
        delete &this->item; // redundant ?
        this->item = newItem;

    };
template class Node<int>;

