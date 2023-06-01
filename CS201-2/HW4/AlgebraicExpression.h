/**
*Musa Yiğit Yayla
*22003108
*/


#include <stack>
#include <string>

using namespace std;
//class AlgebraicExpression{
//public:
    // It converts an infix expression exp to its equivalent postfix form .
    string infix2postfix ( const string exp );
    bool isOperand(char ch);
    int getPrecedence(char ch);
    // It evaluates a postfix expression .
    double evaluatePostfix ( const string exp );
    int operate(char op, int n1, int n2);
    bool isCharOperator(char ch);
    void trimLeft(string& s);
//};
