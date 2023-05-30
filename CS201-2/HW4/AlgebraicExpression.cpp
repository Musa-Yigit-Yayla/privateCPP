#include "AlgebraicExpression.h"

using namespace std;

bool AlgebraicExpression::isCharOperator(char ch){
    return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'));
}
bool AlgebraicExpression::isOperand(char ch){
    return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9');
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
//Assumes that the given exp is a valid infix expression
string AlgebraicExpression::infix2postfix ( const string exp ){
    string postfixExp = "";
    stack<char> newStack;
    for(int i = 0; i < exp.size(); i++){
        char ch = exp.at(i);
        if(this->isOperand(ch)){
            postfixExp += ch;
        }
        else if(ch == '('){
            newStack.push(ch);
        }
        else if(this->isCharOperator(ch)){
            while(!newStack.empty() && newStack.top() != '(' && this->getPrecedence(ch) <= this->getPrecedence(newStack.top())){
                postfixExp += newStack.top();
                newStack.pop();
            }
            newStack.push(ch);
        }
        else if(ch == ')'){
            while(newStack.top() != '('){
                postfixExp += newStack.top();
                newStack.pop();
            }
            newStack.pop();
        }
    }
    //append the remaining operators to the postfixExp;
    while(!newStack.empty()){
        postfixExp += newStack.top();
        newStack.pop();
    }
    return postfixExp;
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
            string s2 = (string)(newStack.top());
            newStack.pop();
            string s1 = (string)(newStack.top());
            newStack.top();
            double operand2 = stod(s1);
            double operand1 = stod(s2);
            double value = this->operate(ch, operand1, operand2);
            newStack.push(to_string(value));
        }
    }
    if(newStack.empty()){
        return INT_MIN; // problem occured
    }
    string value = newStack.top();
    newStack.pop();
    return stod(value);
}
