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
    //Sets the nextPointer of this node
template<class ItemType>
    void Node<ItemType>::setNextPointer(Node<ItemType>* nextElt){
        this->nextPtr = nextElt;
    }
    //Returns the next pointer of this node
    //returns null if there is no next node
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

