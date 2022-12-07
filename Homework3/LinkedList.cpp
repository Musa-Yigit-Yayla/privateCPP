/*
Musa Yiğit Yayla
22003108
*/
#include "LinkedList.h"
#include <cstddef>
//#include <string>

using namespace std;
template <class ItemType>
Node<ItemType> LinkedList<ItemType>::getNodeAt(int position) const{
        Node<ItemType> returnValue;
        if(position == 0){
            returnValue = *this->headPtr;
        }
        else{
            Node<ItemType>* curr = this->headPtr;
            Node<ItemType>* prevCurr;
            //Traverse the list until we hit the null pointer, return the prevCurr e.g the searched element
            while(position > 0){
                prevCurr = curr;
                curr = curr->getNextPointer();
                position--;
            }
            returnValue = *prevCurr;
        }
        return returnValue;
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
        Node<ItemType>* start = this->headPtr;
        int deleteCount = 0;
        while(deleteCount < this->itemCount){
            Node<ItemType>* currStart = start;
            start = currStart->getNextPointer();
            delete start;                           // MIGHT BE PROBLEMATICCCCCCCC !!!!!!!!!!!!!!!!!!!
            deleteCount++;
        }
        this->itemCount = 0;
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
        Node<ItemType> newNode;
        newNode.setItem(newEntry);
        if(newPosition < 0 || newPosition > this->itemCount){
            return false;
        }
        else if(newPosition == 1){
            //Node<ItemType>* prevHead = this->headPtr;
            this->headPtr = &newNode;
            newNode.setNextPointer(&newNode);
            this->itemCount++;
            return true;
        }
        else{
            Node<ItemType> futureNext = this->getNodeAt(newPosition);
            newNode.setNextPointer(&(futureNext));
            Node<ItemType> prevNode = this->getNodeAt(newPosition - 1);
            prevNode.setNextPointer(&newNode);
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
template <class ItemType>
    bool LinkedList<ItemType>::removeElt(int position){
        if(position < 0 || position > this->itemCount){
            return false;
        }
        Node<ItemType> eltToRemoved = this->getNodeAt(position);
        if(position == 1){
            Node<ItemType>* newHead = eltToRemoved.getNextPointer();
            delete this->headPtr;
            this->headPtr = newHead;
            this->itemCount--;
        }
        else{
            //find the prev pointer
            Node<ItemType>* curr = this->headPtr;
            Node<ItemType> prev;
            while(true){
                if(curr->getNextPointer() == &eltToRemoved){
                    prev = *curr;
                    break;
                }
                curr = curr->getNextPointer();
            }
            Node<ItemType>* midHead = eltToRemoved.getNextPointer();
            delete &eltToRemoved;
            prev.setNextPointer(midHead);
            this->itemCount--; // decrement the item count
        }
        return true;
    }
template <class ItemType>
    void LinkedList<ItemType>::clearElts(){
        while(this->itemCount != 0){
            this->removeElt(1);
            this->itemCount--;
        }
    }
template <class ItemType>
    ItemType LinkedList<ItemType>::getEntry(int position) const{
        int count = 0;
        Node<ItemType>* curr = this->headPtr;
        while(count < position){
            curr = curr->getNextPointer();
            count++;
        }
        return curr->getItem();
    }
template <class ItemType>
    void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry){
        int count = 0;
        Node<ItemType>* curr = this->headPtr;
        while(count < position){
            curr = curr->getNextPointer();
            count++;
        }
        curr->setItem(newEntry);
    }
    //instantiate templates for testing
    template class LinkedList<int>;

