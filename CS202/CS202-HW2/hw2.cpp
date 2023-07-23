#include <iostream>
#include <string>

using namespace std;
#include "NgramTree.h"
int main( int argc, char** argv ) {
    cout << "Start of main" << endl;
    NgramTree tree;
    cout << "After tree instantiation" << endl;
    string fileName( argv[1] );
    cout << "After passing argument 1 as a string" << endl;
    int n = atoi( argv[2] );
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
    return 0;
}
