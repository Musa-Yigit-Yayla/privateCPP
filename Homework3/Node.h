#ifndef NODE_H
#define NODE_H


template<class ItemType>
class Node{
public:
    Node<ItemType>(); // maybe remove ?
    ~Node<ItemType>();
    void setNextPointer(Node<ItemType>* nextElt);
    Node<ItemType>* getNextPointer() const;
    ItemType getItem() const;
    void setItem(ItemType newItem);
private:
    Node<ItemType>* nextPtr = nullptr;
    ItemType* item = nullptr; // convert pointer to normal var
};

#endif // NODE_H

