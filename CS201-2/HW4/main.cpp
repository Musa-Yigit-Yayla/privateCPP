#include <iostream>
#include "AlgebraicExpression.h"

using namespace std;

void test0(){
    string infix = "1+2";
    string postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix = "    3 -4 +    5";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix = "(2+3)*4";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix = "9/3+6";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix = "8*(2-4)/3";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix = "7-(3+2)*4";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    infix =  "1/(5-9)*2";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;

    //infix = "12+(3-4)/5-67+8/9-1+23-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7+8-91+2/3-(4-5)/6+78-9+1/2-34+(5-6)/7";
    infix = "(1+2)(3-4)+(5/6)(7-8)+(9+1)(2-3)+(4/5)(6-7)+(8+9)(1-2)+(3/4)(5-6)+(7+8)(9-1)+(2/3)(4-5)+(6+7)(8-9)+(1/2)(3-4)+(5+6)(7-8)+(9/1)(2-3)+(4+5)(6-7)+(8/9)(1-2)+(3+4)(5-6)+(7/8)(9-1)+(2+3)(4-5)+(6/7)(8-9)+(1+2)(3-4)+(5/6)(7-8)+(9+1)(2-3)+(4/5)(6-7)+(8+9)(1-2)+(3/4)(5-6)+(7+8)(9-1)+(2/3)(4-5)+(6+7)(8-9)+(1/2)(3-4)+(5+6)(7-8)+(9/1)(2-3)+(4+5)(6-7)+(8/9)(1-2)+(3+4)(5-6)+(7/8)(9-1)+(2+3)(4-5)+(6/7)(8-9)+(1+2)(3-4)+(5/6)(7-8)+(9+1)(2-3)+(4/5)(6-7)+(8+9)(1-2)+(3/4)(5-6)+(7+8)(9-1)+(2/3)(4-5)+(6+7)(8-9)+(1/2)(3-4)+(5+6)(7-8)+(9/1)(2-3)+(4+5)(6-7)+(8/9)(1-2)+(3+4)(5-6)+(7/8)(9-1)+(2+3)(4-5)+(6/7)(8-9)+(1+2)(3-4)+(5/6)(7-8)+(9+1)(2-3)+(4/5)(6-7)+(8+9)(1-2)+(3/4)(5-6)+(7+8)(9-1)+(2/3)(4-5)+(6+7)*(8-9)";
    postfix = infix2postfix(infix);
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl;
}
int main(){
    string postfix = infix2postfix (" (3+5) -8*4");
    cout << postfix << endl;
    cout << evaluatePostfix(postfix) << endl ;
    cout << evaluatePostfix (" 653 -8*+2/ ") << endl ;

    cout << "--------------------------------------------------------" << endl;
    test0();
    return 0;
}
