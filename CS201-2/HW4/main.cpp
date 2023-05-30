#include <iostream>
#include "AlgebraicExpression.h"

using namespace std;
int main(){
    cout << infix2postfix (" (3+5) -8*4") << endl ;
    cout << evaluatePostfix (" 653 -8*+2/ ") << endl ;

    return 0;
}
