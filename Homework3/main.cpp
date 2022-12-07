#include <iostream>

using namespace std;
#include "LinkedList_imp.h"

int main()
{
    LinkedList<int> list1;
    list1.append(3);
    list1.append(5);
    /*Node<int> node1;
    Node<int> node2;
    Node<int> node3;*/

    list1.append(4);
    list1.removeElt(2);
    list1.removeElt(3);
    list1.append(5);
    list1.insertElt(1, 5);
    cout << list1.getLength();
    list1.clearElts();
    return 0;
}
