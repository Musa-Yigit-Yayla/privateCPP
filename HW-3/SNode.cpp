#include "SNode.h"
#include <cstddef>
/*public:
//public datafields
    SNode* next = nullptr;
    ItemType* data = nullptr;
*/
template<class ItemType>
SNode<ItemType>::SNode(){

}
template<class ItemType>
SNode<ItemType>::SNode(ItemType* it){
    this->data = it;
}
template<class ItemType>
SNode<ItemType>::~SNode(){
    if(this->data != NULL)
        delete this->data;
    this->next = nullptr;
}
