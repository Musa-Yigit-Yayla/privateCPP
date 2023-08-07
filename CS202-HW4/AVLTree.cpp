#include <iostream>
#include <cstddef>
#include <string>
#include "AVLTree.h"

using namespace std;

bool isAlphaNumeric(char ch);
void AVLTree::AVLTree(){

}
void AVLTree::~AVLTree(){

}
void AVLTree::addWord(string word){

}
void AVLTree::generateTree(string inputFileName){

}
void AVLTree::printHeight() const{

}
void AVLTree::printTotalWordCount() const{

}
void AVLTree::printWordFrequencies() const{

}
void AVLTree::printMostFrequent() const{

}
void AVLTree::printLeastFrequent() const{

}
void AVLTree::printStandartDeviation() const{

}
void AVLTree::fixtree(){

}
bool AVLTree::isFixed(){

}
bool isAlphaNumeric(char ch){
    switch(ch){
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'O':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'U':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
        case 'a':
        case 'b':
        case 'c':
        case 'd':
        case 'e':
        case 'f':
        case 'g':
        case 'h':
        case 'i':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'o':
        case 'p':
        case 'q':
        case 'r':
        case 's':
        case 't':
        case 'u':
        case 'v':
        case 'w':
        case 'x':
        case 'y':
        case 'z': return true; break;
        default: return false;
    }
}
