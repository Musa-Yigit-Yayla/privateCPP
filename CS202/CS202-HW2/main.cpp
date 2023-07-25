#include <iostream>
#include <string>

using namespace std;
#include "NgramTree.h"

void test0(){
NgramTree tree;
string fileName("input.txt");
int n = 4;
tree.generateTree( fileName, n );
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
cout << tree << endl;
cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
// Before insertion of new n-grams
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
tree.addNgram( "samp" );
tree.addNgram( "samp" );
tree.addNgram( "zinc" );
tree.addNgram( "aatt" );
cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
cout << tree << endl;
cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
}
void test1(){
    NgramTree tree;
    string fileName("input2.txt");
    int n = 5;
    tree.generateTree( fileName, n );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    // Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.addNgram( "sample" );
    tree.addNgram( "simp" );
    tree.addNgram( "zincir" );
    tree.addNgram( "aatte" );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    tree.remove("aatte");
    tree.remove("sampl");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

}
void test2(){
    NgramTree tree;
    string fileName("input2.txt");
    int n = 5;
    tree.generateTree( fileName, n );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    //remove nodes that prohibit our tree from being complete
    tree.remove("comin");
    tree.remove("strik");
    tree.remove("unter");
    tree.remove("rvesu");
    tree.remove("ounte");
    tree.remove("merve");
    tree.remove("trike"); //!!! THIS IS WHERE WE FAIL TO REMIVE THE NODE
    tree.remove("oming");
    tree.remove("riend");
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

}
int main( int argc, char** argv ) {
    test0();
    return 0;
}

