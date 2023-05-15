#include "SLL.h"
#include "Course.h"
#include <typeinfo>
#include "SNode.h"
#include <cstddef>

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
    SNode<ItemType>* curr = this->head;
    while(curr != nullptr){
        SNode<ItemType>* nextNode = curr->next;
        delete curr;
        curr = nextNode;
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
        }
        //If we have completed this loop and haven't returned anything, this implies that we must certainly insert at the end
        prevNode->next = node;
        return initialHead;

    }
    return nullptr; //YOU MAY HAVE TO REMOVE THIS !!!!!!!!!!!!!!!!!!!!!!11
}
    //Removes the element with the given id if it exists, if removal is not performed returns nullptr
    //In this case we will be removing courses
    //Does not decrement the coursesLength, hence the caller must be doing that
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


