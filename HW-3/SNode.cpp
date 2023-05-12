#include "SNode.h"

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
    delete this->data;
}
