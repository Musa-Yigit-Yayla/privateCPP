#include <string>
#ifndef NGRAMTREE_H
#define NGRAMTREE_H
class NgramTree {
public:
    NgramTree();
    ~NgramTree();
    void addNgram( const string& ngram );
    int getTotalNgramCount() const;
    bool isComplete() const;
    bool isFull() const;
    void generateTree( const string& fileName, const int n );
    private:
    // ...
    friend ostream& operator<<( ostream& out, const NgramTree& tree );
};
#endif // NGRAMTREE_H


