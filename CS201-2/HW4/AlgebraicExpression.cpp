#include "AlgebraicExpression.h"

using namespace std;

bool AlgebraicExpression::isCharOperator(char ch){
    return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'));
}
//The given operands are assumed to exclude 0
int AlgebraicExpression::operate(char op, int n1, int n2){
    int result;
    switch(op){
        case '+': result = n1 + n2; break;
        case '-': result = n1 - n2; break;
        case '*': result = n1 * n2; break;
        case '/': result = n1 / n2; break;
    }
    return result;
}
// It converts an infix expression exp to its equivalent postfix form .
string AlgebraicExpression::infix2postfix ( const string exp ){

}
// It evaluates a postfix expression .
double AlgebraicExpression::evaluatePostfix ( const string exp ){
    stack<string> newStack;

    for(int i = 0; i < exp.size(); i++){
        char ch = exp.at(i);
        if(!this->isCharOperator(ch)){
            //push the operand
            string currCh = "" + ch;
            newStack.push(currCh);
        }
        else{
            string s2 = (string)(newStack.pop());
            string s1 = (string)(newStack.pop());
            double operand2 = stod(s1);
            double operand1 = stod(s2);
            double value = this->operate(ch, n1, n2);
            newStack.push(to_string(value));
        }
    }
    string value = newStack.pop();
    return stod(value);
}
