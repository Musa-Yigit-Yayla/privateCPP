#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include "AVLTree.h"

using namespace std;

bool isAlphaNumeric(char ch);
string** tokenize(string s, int& newLength);

void AVLTree::AVLTree(){

}
void AVLTree::~AVLTree(){

}
void AVLTree::addWord(string word){

}
void AVLTree::generateTree(string inputFileName){
    ifstream inputFile(inputFileName);
    string currLine;
    string* words = nullptr;
    int currLength = 0; //length for the words array that we will be instantiating soon
    while(getline(inputFile, currLine)){
        int newLength = 0;
        string** arr = tokenize(currLine, newLength);
        for(int i = 0; i < newLength; i++){
            string word = *arr[i];
            this->addWord(word);
        }
        delete[] arr;
    }
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
//each and every character that is nonAlphaNumeric is considered to be a delimiter
//Returns a pointer to dynamically allocated array of strings which represent input words.
//Also sets the given int reference to the length of the returned array.
string** tokenize(string s, int& newLength){
    string** result = nullptr;
    int length = 0;
    int wordBeginIndex = -1; //set this to -1 after we have added a word
    //char* terminatingChar = nullptr;
    for(int i = 0; i < s.size(); i++){
        char ch = s.at(i);
        if(isAlphaNumeric(ch)){
            if(wordBeginIndex == -1){
                wordBeginIndex = i;
            }
        }
        //below condition implies that we have in fact found a word
        else if(wordBeginIndex != -1){
            length++;
            wordBeginIndex = -1;
        }
        //terminatingChar = &ch;
    }
    /*if(isAlphaNumeric(*terminatingChar)){
        //add the last word so that we have the correct results
        length++;
    }*/
    //now instantiate the array and traverse once more so we can add the words as desired
    if(length == 0){
        newLength = length;
        return result;
    }
    else{
        wordBeginIndex = -1;
        result = new string*[length];
        newLength = length;
        int currIndex = 0; //index for keeping track of where we are at in the array

        for(int i = 0; i < s.size(); i++){
            char ch = s.at(i);
            if(isAlphaNumeric(ch)){
                if(wordBeginIndex == -1){
                    wordBeginIndex = i;
                }
            }
            //below condition implies that we have in fact found a word
            else if(wordBeginIndex != -1){
                int currLength = i - wordBeginIndex;
                string currWord = substr(s.begin() + wordBeginIndex, currLength);
                result[currIndex++] = &currWord;
                wordBeginIndex = -1;
            }
            //terminatingChar = &ch;
        }
        return result;
    }
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
