#include "DLL.H"
#include "DNode.H"
#include <iostream>
#include <cstddef>
#include "Student.h"
#include <typeinfo>

template<class ItemType>
DLL<ItemType>::DLL(){

}
template<class ItemType>
DLL::DLL<ItemType>(DNode<ItemType>* head){
    this->head = head;
}
//When you want to delete all students you invoke this method or it gets invoked automatically
template<class ItemType>
DLL::~DLL<ItemType>(){
    DNode<ItemType>* curr = this->head;
    while(curr != NULL){
        DNode<ItemType>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}
template<class ItemType>
DNode<ItemType>* DLL<ItemType>::insert(DNode<ItemType>* node){

}
