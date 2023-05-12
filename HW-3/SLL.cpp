#include "SLL.h"

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


