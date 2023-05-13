#include "DNode.h"

/*public:
DNode* prev = nullptr;
    DNode* next = nullptr;
    ItemType* data = nullptr;
*/

template <class ItemType>
DNode<ItemType>::DNode(){

}
template <class ItemType>
DNode<ItemType>::DNode(ItemType* it){
    this->data = it;
}
template <class ItemType>
DNode<ItemType>::~DNode(){
    delete this->data;
    this->next = nullptr;
    this->prev = nullptr;
}
