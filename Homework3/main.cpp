#include <iostream>

using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList<int> list1;
    cout << "hah" << endl;
    list1.append(3);
    cout << "hah" << endl;
    list1.append(5);
    cout << "hah" << endl;
    /*Node<int> node1;
    Node<int> node2;
    Node<int> node3;*/

    list1.append(4);
    cout << "hah" << endl;

    for(int i = 1; i <= 4; i++){
        std::cout<< list1.getEntry(i) << endl;
    }
    list1.removeElt(0); // Should exit the program or display error msg
    list1.removeElt(1);
    cout << "hah" << endl;
    list1.removeElt(2);
    cout << "hah" << endl;
    list1.append(5);
    cout << "hah" << endl;
    list1.insertElt(1, 5);
    cout << "hah" << endl;
    cout << list1.getLength();
    cout << "hah" << endl;
    list1.clearElts();
    cout << "hah" << endl;
    return 0;
}
