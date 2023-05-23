/*
*Musa Yiğit Yayla
*CS201-1
*22003108
*/
#ifndef SLL_H
#define SLL_H
#pragma once

#include "SNode.h"

template<class ItemType>
class SLL{
public:
    SLL();
    SLL(SNode<ItemType>* head);
    ~SLL();
    SNode<ItemType>* insert(SNode<ItemType>* node);
    SNode<ItemType>* remove(const int id); //removes the ItemType with given id (in our case Course)
    void printList() const;


    SNode<ItemType>* head = nullptr;
    int listLength = -1; //-1 specifies that we haven't set the list length, setting this data field will be useful on deletion of the list
};
#endif // SLL_H

#include "Course.h"
#include <typeinfo>
#include "SNode.h"
#include <cstddef>
#include <iostream>

using namespace std;
/*private:
    SNode<ItemType>* head = nullptr;
public:*/
template<class ItemType>
SLL<ItemType>::SLL(){

}
template<class ItemType>
SLL<ItemType>::SLL(SNode<ItemType>* head){
    this->head = head;
}
//Deletes each and every Node in the singly linked list
//Must be invoked automatically when the code is finished
template<class ItemType>
SLL<ItemType>::~SLL(){
    //initially find length of the list
    /*SNode<ItemType>* currNode = this->head;
    int length = 0;
    while(currNode != NULL){
        currNode = currNode->next;
        length++;
    }*/
    bool isListLengthSet = (this->listLength != -1);
    SNode<ItemType>* curr = this->head;
    if(!isListLengthSet){
        while(curr != NULL){ // MIGHT BE PROBLEMATIC IN SOME CASES
            SNode<ItemType>* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
    else{
        int currLength = 0;
        while(currLength < this->listLength){
            SNode<ItemType>* nextNode = curr->next;
            delete curr;
            curr = nextNode;
            currLength++;
        }
    }
}
//Maintains the current order of the sorted list, by inserting the given node at the correct position
//Does not insert if the same node already exists
//Returns the new head node after having inserted
//If the insertion fails returns nullptr
//ATTENTION !!!!! THIS METHOD IS NOT UPDATING THE courseLength data field of the corresponding student. You may want to perform that on the caller.
template<class ItemType>
SNode<ItemType>* SLL<ItemType>::insert(SNode<ItemType>* node){
    ItemType itemType;// for checking whether this itemType is an instance of Course
    Course course;
    if(typeid(itemType) == typeid(course)){
        Course* givenCourse = reinterpret_cast<Course*>(node->data);

        //traverse the whole singly linked list to check whether our course already exists, if not find a place to insert our student
        SNode<ItemType> initialHead = this->head;
        Course* currCourse = reinterpret_cast<Course*>(this->head->data);
        SNode<ItemType>* currNode = this->head;
        Course* prevCourse = nullptr;
        SNode<ItemType>* prevNode = nullptr;
        while(currCourse != NULL){
            int currId = currCourse->getCourseId();
            if(currId == givenCourse->getCourseId()){
                return nullptr;// the course already exists, insertion cannot be performed
            }
            else if(currId > givenCourse->getCourseId()){
                //insert right before the currNode
                if(prevCourse == NULL){
                    //insert at the beginning
                    node->next = this->head;
                    return node;
                }
                else{
                    //normal insertion, insert after the prevNode
                    prevNode->next = node;
                    node->next = currNode;
                    return initialHead;
                }
            }
            prevCourse = currCourse;
            prevNode = currNode;
            currNode = currNode->next;
            currCourse = reinterpret_cast<Course*>(currNode->data);
        }
        //If we have completed this loop and haven't returned anything, this implies that we must certainly insert at the end
        if(prevNode != NULL){
            prevNode->next = node;
            return initialHead;
        }
        else{
            this->head = node;
            return this->head;
        }

    }
    return nullptr; //YOU MAY HAVE TO REMOVE THIS !!!!!!!!!!!!!!!!!!!!!!11
}
    //Removes the element with the given id if it exists, if removal is not performed returns nullptr
    //In this case we will be removing courses
    //Does not decrement the coursesLength, hence the caller must be doing that
    //Deletion must be taken care of in the caller
    template<class ItemType>
    SNode<ItemType>* SLL<ItemType>::remove(const int id){
        Course* course;
        ItemType* it;
        if(typeid(course) == typeid(it)){
            Course* currCourse = reinterpret_cast<Course*>(this->head->data);
            SNode<Course>* currNode = reinterpret_cast<SNode<Course>>(this->head);
            SNode<Course>* prevNode = nullptr;
            Course* prevCourse = nullptr;
            while(currCourse != NULL){
                int currId = currCourse->getCourseId();
                if(currId == id){
                    //we must remove the current course
                    if(prevCourse == NULL){
                        //this is the first course
                        this->head = nullptr;
                        return currNode; //it may return nullptr or the next node depending on the list length
                    }
                    else{
                        prevNode->next = currNode->next;
                        currNode->next = nullptr;
                        return currNode;
                    }
                }
                prevNode = currNode;
                prevCourse = currCourse;
                currNode = currNode->next;
                currCourse = reinterpret_cast<Course*>(currNode->data);
            }
            //if no match is found return nullptr
        }
        return nullptr;
    }

    //Invoke from the showStudent
    template<class ItemType>
    void SLL<ItemType>::printList() const{
        Course* course;
        ItemType* it;

        if(typeid(course) == typeid(it)){
            SNode<Course>* currNode = reinterpret_cast<SNode<Course>*>(this->head);
            Course* currCourse = currNode->data;

            cout << "Course id Course name" << endl;
            while(currCourse != NULL){
                cout << currCourse->getCourseId() << " " << currCourse->getCourseName() << endl;
                currNode = reinterpret_cast<SNode<Course>*>(currNode->next);
                currCourse = currNode->data;
            }
        }
    }
