/*
Musa Yiğit Yayla
22003108
*/
#include "LinkedList.h"
#include "Subscriber.h"
#include "Movie.h"
#include "Transaction.h"
#include <cstddef>
#include <iostream>
//#include <string>

using namespace std;

//Returns the node at the given position, displays a warning message if the given position is invalid
//Position should be given from 1 to list length inclusive
template <class ItemType>
Node<ItemType>& LinkedList<ItemType>::getNodeAt(int position) const{
        if(position < 1 || position > this->itemCount){
            cout << "Given position is invalid, cannot get the node at position " << position << ".";
            exit(1); // Exit the program
        }
        else if(position == 1){
            return *this->headPtr;
        }
        else{
            Node<ItemType>* curr = this->headPtr->getNextPointer();
            Node<ItemType>* prevCurr = this->headPtr;
            //Traverse the list until we hit the null pointer, return the prevCurr e.g the searched element
            while(position > 1){ // change back to 0 ?
                prevCurr = curr;
                if(curr != NULL){
                    curr = curr->getNextPointer();
                }
                position--;
            }
            return *prevCurr;
        }
    }
template <class ItemType>
//public:
    LinkedList<ItemType>::LinkedList(){
        this->headPtr =  nullptr;
        this->itemCount = 0;
    }
template <class ItemType>
    LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
        this->headPtr = aList.headPtr;
        this->itemCount = aList.itemCount;
    }
template <class ItemType>
    //Delete linked list elements one by one
    LinkedList<ItemType>::~LinkedList<ItemType>(){
        /*Node<ItemType>* start = this->headPtr;
        int deleteCount = 0;
        while(deleteCount < this->itemCount){
            Node<ItemType>* currStart = start;
            start = currStart->getNextPointer();
            delete start;                           // MIGHT BE PROBLEMATICCCCCCCC !!!!!!!!!!!!!!!!!!!
            deleteCount++;
        }
        this->itemCount = 0;*/
    }
template <class ItemType>
    bool LinkedList<ItemType>::isEmpty() const{
        return this->itemCount == 0;
    }
template <class ItemType>
    int LinkedList<ItemType>::getLength() const{
        return this->itemCount;
    }
template <class ItemType>
    bool LinkedList<ItemType>::insertElt(int newPosition, const ItemType& newEntry){
        Node<ItemType>* newNode = new Node<ItemType>();
        newNode->setItem(newEntry);
        if(newPosition == 1 || newPosition == this->itemCount + 1){
            //Node<ItemType>* prevHead = this->headPtr;
            Node<ItemType>* prevHead = this->headPtr;
            newNode->setNextPointer(prevHead);
            this->headPtr = newNode;
            this->itemCount++;
            return true;
        }

        else if(newPosition < 0 || newPosition > this->itemCount + 1){ // itemCount -1 is to satisfy the insertion if list has no elts
            return false;
        }

        else{
            Node<ItemType>* futureNext = &(this->getNodeAt(newPosition));
            Node<ItemType>* prevNode = &(this->getNodeAt(newPosition - 1));
            prevNode->setNextPointer(newNode);
            newNode->setNextPointer((futureNext));

            this->itemCount++;
            return true;
        }
    }
template <class ItemType>
//Assuming the given entry is nonnull !! Might be problematic
    bool LinkedList<ItemType>::append(const ItemType& newEntry){
        //if(&newEntry == NULL){
          //  return false;
        //}
        Node<ItemType> newNode;
        newNode.setItem(newEntry);
        if(this->itemCount == 0){
            this->headPtr = &newNode;
            this->itemCount++;
        }
        else{
            //get the last node of the list
            Node<ItemType> lastNode = (this->getNodeAt(this->itemCount));
            lastNode.setNextPointer(&newNode);
            this->itemCount++;
        }
        return true;
    }
    //Removes an element at the given position
template <class ItemType>
    bool LinkedList<ItemType>::removeElt(int position){
        if(position < 1 || position > this->itemCount + 1){
            std::cout <<    "Cannot remove the element at position" << position << endl;
            return false;
        }

        Node<ItemType> eltToRemoved = this->getNodeAt(position);; // CHANGE BACK TO OBJECT TYPE MAYBE
        if(position == 1){
            Node<ItemType>* newHead = eltToRemoved.getNextPointer();
            delete this->headPtr;
            this->headPtr = newHead;
            this->itemCount--;
        }
        else if(position == this->itemCount){ // removal of the last elt
            //find the prev pointer
            Node<ItemType>* curr = this->headPtr;
            Node<ItemType>* prev = this->headPtr;
            //find the prev pointer and last elt pointer
            for(int i = 1; i < position; i++){
                prev = curr;
                curr = curr->getNextPointer();
            }
            //delete curr set nextpr null
            delete curr;
            prev->setNextPointer(nullptr);
            Node<ItemType>* midHead = eltToRemoved.getNextPointer();
        //delete eltToRemoved;
        prev->setNextPointer(midHead);
        this->itemCount--; // decrement the item count
        }
        else{
            //find the prev pointer
            Node<ItemType>* curr = this->headPtr;
            Node<ItemType>* prev;

            for(int i = 1; i < position; i++){
                prev = curr;
                curr = curr->getNextPointer();
            }

            Node<ItemType>* midHead = eltToRemoved.getNextPointer();
        //delete eltToRemoved;
        prev->setNextPointer(midHead);
        this->itemCount--; // decrement the item count
        }
        return true;
    }
    //Clears the whole list
template <class ItemType>
    void LinkedList<ItemType>::clearElts(){
        while(this->itemCount != 0){
            this->removeElt(1);
            this->itemCount--;
        }
    }
template <class ItemType>
    ItemType LinkedList<ItemType>::getEntry(int position) const{
        int count1 = 1;
        Node<ItemType>* curr = this->headPtr;
        while(count1 < position){
            curr = curr->getNextPointer();
            count1++;
        }
        return curr->getItem();
    }
template <class ItemType>
    void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry){
        int count1 = 1;
        Node<ItemType>* curr = this->headPtr;
        while(count1 < position){
            curr = curr->getNextPointer();
            count1++;
        }
        curr->setItem(newEntry);
    }

    //instantiate templates for testing
    template class LinkedList<int>;
    template class LinkedList<Subscriber>;
    template class LinkedList<Transaction>;
    template class LinkedList<Movie>;
