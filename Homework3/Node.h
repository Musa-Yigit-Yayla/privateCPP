#ifndef NODE_H
#define NODE_H

using namespace std;
template<class ItemType>
class Node{
public:
    Node(ItemType elt); // maybe remove ?
    void setNextPointer(Node<ItemType>* nextElt);
    Node<ItemType>* getNextPointer() const;
    ItemType getItemType() const;
    void setItemType(ItemType newItem);
private:
    Node<ItemType>* nextPtr = nullptr;
    ItemType item;
};

#endif // NODE_H

