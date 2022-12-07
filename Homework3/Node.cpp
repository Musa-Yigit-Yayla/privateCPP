/*
Musa Yiğit Yayla
22003108
*/

#include "Node.h"
#include <cstddef>
#include <iostream>

using namespace std;

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
    ItemType Node<ItemType>::getItem() const{ // Remove pointer from return type if necessary
        return *this->item;
    }
template<class ItemType>
    void Node<ItemType>::setItem(ItemType newItem){
        ItemType* itemPtr;
        itemPtr = (this->item);
        //std::cout << itemPtr;
        //If the start of the itemCopyPtr is 0 we have a null element
        if(itemPtr){
            delete itemPtr; // redundant ?
        }
        this->item = &newItem;

    }
template class Node<int>;

