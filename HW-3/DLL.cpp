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
DLL<ItemType>::DLL(DNode<ItemType>* head){
    this->head = head;
}
//When you want to delete all students you invoke this method or it gets invoked automatically
template<class ItemType>
DLL<ItemType>::~DLL(){
    DNode<ItemType>* curr = this->head;

    while(curr != NULL){
        DNode<ItemType>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}
template<class ItemType>
DNode<ItemType>* DLL<ItemType>::insert(DNode<ItemType>* node){
    ItemType* it;
    Student* student;

    if(typeid(it) == typeid(student)){
        Student* givenStudent = node->data;

        DNode<Student>* currNode = this->head;
        Student* currStudent = reinterpret_cast<Student*>(currNode->data);
        DNode<Student>* prevNode = nullptr;
        Student* prevStudent = nullptr;
        DNode<Student> initialHead = currNode;
        while(currStudent != NULL){

            int = currStudent->getId();
            if(studentId == givenStudent->getId()){
                return nullptr; //student already exists
            }
            else if(studentId > givenStudent->getId()){
                //insert the given student right before currStudent
                if(prevStudent == NULL){
                    //insert at the beginning
                    node->next = this->head;
                    this->head->prev = node;
                    return node;
                }
                else{
                    //regular insertion insert after the prevNode
                    prevNode->next = node;
                    node->prev = prevNode;
                    node->next = currNode;
                    currNode->prev = node;
                    return initialHead;
                }

            }
            prevStudent = currStudent;
            prevNode = currNode;
            currNode = currNode->next;
            currStudent = reinterpret_cast<Student*>(currNode->data);
        }
        //If we have completed this loop without returning anything insert after the last node which is apparently prevNode
        if(prevNode != NULL){
            prevNode->next = node;
            return initialHead;
        }
        else{
            this->head = node;
            return this->head;
        }

    }
}
