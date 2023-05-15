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

            int studentId = currStudent->getId();
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
    return nullptr;
}
//Deletion must take place in the caller!!!!
template<class ItemType>
DNode<ItemType>* DLL<ItemType>::remove(const int id){
    Student* student;
    ItemType* it;
    if(typeid(student) == typeid(it)){
        Student* currStudent = reinterpret_cast<Student*>(this->head->data);
            DNode<Student>* currNode = reinterpret_cast<DNode<Student>>(this->head);
            DNode<Course>* prevNode = nullptr;
            Student* prevStudent = nullptr;
            while(currStudent != NULL){
                int currId = currStudent->getId();
                if(currId == id){
                    //we must remove the current course
                    if(prevStudent == NULL){
                        //this is the first student
                        this->head = nullptr;
                        return currNode; //it may return nullptr or the next node depending on the list length
                    }
                    else{
                        prevNode->next = currNode->next;
                        currNode->next->prev = prevNode;
                        currNode->next = nullptr;
                        currNode->prev = nullptr;
                        return currNode;
                    }
                }
                prevNode = currNode;
                prevStudent = currStudent;
                currNode = currNode->next;
                currStudent = reinterpret_cast<Student*>(currNode->data);
            }
    }
    return nullptr;
}
template<class ItemType>
void DLL<ItemType>::printList() const{
    Student* student;
    ItemType* it;

    if(typeid(it) == typeid(student)){
        DNode<Student>* currNode = reinterpret_cast<DNode<Student>*>(this->head);
        Student* currStudent = currNode->data;

        cout << "Student id First name Last name" << endl;
        while(currStudent != NULL){
            cout << currStudent->getId() << " " << currStudent->getFirstName() << " " << currStudent->getLastName() << endl;
            currNode = currNode->next;
            currStudent = currNode->data;
        }
    }
}
