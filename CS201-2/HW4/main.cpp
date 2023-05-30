#include <iostream>
#include "AlgebraicExpression.h"

using namespace std;
int main(){
    string postfix = infix2postfix (" (3+5) -8*4");
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl ;
    cout << evaluatePostfix (" 653 -8*+2/ ") << endl ;

    return 0;
}
