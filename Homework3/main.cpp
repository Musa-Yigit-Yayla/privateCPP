#include <iostream>

using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList<int> list1;
    cout << "hah1" << endl;
    list1.append(3);
    cout << "hah2" << endl;
    list1.append(5);
    cout << "hah3" << endl;
    /*Node<int> node1;
    Node<int> node2;
    Node<int> node3;*/

    list1.append(4);
    cout << "hah4" << endl;
    std::cout << list1.getLength();
    /*for(int i = 1; i <= 3; i++){
        std::cout<< to_string(list1.getEntry(i)) << endl;
    }*/
    //list1.removeElt(0); // Should exit the program or display error msg
    list1.removeElt(2);
    cout << "hah5" << endl;
    list1.removeElt(3);
    cout << "hah6" << endl;
    list1.append(5);
    cout << "hah7" << endl;
    list1.insertElt(1, 5);
    cout << "hah8" << endl;
    cout << list1.getLength();
    cout << "hah9" << endl;
    list1.clearElts();
    cout << "hah10" << endl;
    return 0;
}
