#include <string>
#include <cstddef>
#include "AVLNode.h"

using namespace std;
AVLNode::AVLNode(string word){
    this->word = word;
    this->counter++;
}
