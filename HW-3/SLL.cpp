#include "SLL.h"
#include "Course.h"
#include <typeinfo>

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
template<class ItemType>
bool SLL<ItemType>::insert(SNode<ItemType>* node){
    ItemType itemType;// for checking whether this itemType is an instance of Course
    Course course;
    if(typeid(itemType) == typeid(course)){
        Course* currCourse = reinterpret_cast<Course*>(node->data);

    }

}


