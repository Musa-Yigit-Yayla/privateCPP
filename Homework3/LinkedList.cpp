/*
Musa Yiğit Yayla
22003108
*/
#include "LinkedList.h"
#include "Node.h"
#include <string>

using namespace std;
template <class ItemType>
//class LinkedList<ItemType>{
//private:
    Node<ItemType> LinkedList<ItemType>::getNodeAt(int position) const{
        return headPtr + position; // ?????
    }

//public:
    LinkedList<ItemType>::LinkedList<ItemType>(){
        this->headPtr =  nullptr;
        this->itemCount = 0;
    }
    LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList){
        this->headPtr = aList.headPtr;
        this->itemCount = aList.itemCount;
    }
    //Delete linked list elements one by one
    LinkedList<ItemType>::~LinkedList<ItemType>(){
        Node* start = this->headPtr;
        int deleteCount = 0;
        while(deleteCount < this->itemCount){
            Node* currStart = start;
            start = currStart.nextPtr;
            delete start;                           // MIGHT BE PROBLEMATICCCCCCCC !!!!!!!!!!!!!!!!!!!
            deleteCount++;
        }
        this->itemCount = 0;
    }
    bool LinkedList<ItemType>::isEmpty() const{
        return this->itemCount == 0;
    }
    int LinkedList<ItemType>::getLength() cons{
        return this->itemCount;
    };
    bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){
        Node<ItemType> newNode(newEntry);
        if(newPosition < 0 || > this->itemCount){
            return false;
        }
        else if(newPosition == 1){
            Node<ItemType> prevHead* = this->headPtr;
            this->headPtr = newNode;
            newNode.setNextPointer(newNode);
            this->itemCount++;
            return true;
        }
        else{
            newNode.setNextPointer(&this->getNodeAt(newPosition));
            Node<ItemType> prevNode = this->getNodeAt(newPosition - 1);
            prevNode.setNextPointer(newNode);
            this->itemCount++;
            return true;
        }
    }
    bool LinkedList<ItemType>::append(const ItemType& newEntry){
        if(newEntry == NULL){
            return false;
        }
        Node<ItemType> newNode(newEntry);
        //get the last node of the list
        Node<ItemType> lastNode = this->getNodeAt(this->itemCount);
        lastNode.setNextPointer(newNode);
        return true;
    }
    bool LinkedList<ItemType>::remove(int position){
        if(position < 0 || position > this->itemCount){
            return false;
        }
        Node<ItemType> eltToRemoved = this->getNodeAt(position);
        if(position == 1){
            Node<ItemType>* newHead = eltToRemoved.getNextPointer();
            delete this->headPtr;
            this->headPtr = newHead;
            this->itemCount--;
            return true;
        }
        else{
            //find the prev pointer
            Node<ItemType>* curr = this->headPtr;
            Node<ItemType> prev;
            while(true){
                if(curr.getNextPointer() == &eltToRemoved){
                    prev = *curr;
                    break;
                }
                curr = curr.getNextPointer();
            }
            Node<ItemType>* midHead = eltToRemoved.getNextPointer();
            delete &eltToRemoved;
            prev.setNextPointer(midHead);
            this->itemCount--; // decrement the item count
        }
    }
    void LinkedList<ItemType>::clear(){
        while(this->itemCount != 0){
            this.remove(1);
            this->itemCount--;
        }
    }

    ItemType LinkedList<ItemType>::getEntry(int position) const{
        int count = 0;
        Node<ItemType> curr = this.headPtr;
        while(count < position){
            curr = curr.getNextPointer();
            count++;
        }
        return curr.getItemType();
    }

    void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry){
        int count = 0;
        Node<ItemType> curr = this.headPtr;
        while(count < position){
            curr = curr.getNextPointer();
            count++;
        }
        curr.setItemType(newEntry);
    }

