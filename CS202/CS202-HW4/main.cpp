#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
//#include "AVLNode.h"
#include "AVLTree.h"

using namespace std;

int main(int argc, char** argv){
    AVLTree tree;
    string inputFileName = argv[1];
    tree.generateTree(inputFileName);
    return 0;
}
