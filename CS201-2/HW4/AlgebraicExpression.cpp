#include "AlgebraicExpression.h"

using namespace std;

bool isCharOperator(char ch){
    return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'));
}
bool isOperand(char ch){
    return (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9');
}
//The given operands are assumed to exclude 0
double operate(char op, double n1, double n2){
    int result;
    switch(op){
        case '+': result = n1 + n2; break;
        case '-': result = n1 - n2; break;
        case '*': result = n1 * n2; break;
        case '/': result = n1 / n2; break;
    }
    return result;
}
int getPrecedence(char ch){
    if(ch == '*' || ch == '/'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    return 0;
}
// It converts an infix expression exp to its equivalent postfix form .
//Assumes that the given exp is a valid infix expression
string infix2postfix ( const string exp ){
    string postfixExp = "";
    stack<char> newStack;
    for(int i = 0; i < exp.size(); i++){
        char ch = exp.at(i);
        if(isOperand(ch)){
            postfixExp += ch;
        }
        else if(ch == '('){
            newStack.push(ch);
        }
        else if(isCharOperator(ch)){
            while(!newStack.empty() && newStack.top() != '(' && getPrecedence(ch) <= getPrecedence(newStack.top())){
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
double evaluatePostfix ( const string exp ){
    stack<string> newStack;

    for(int i = 0; i < exp.size(); i++){
        char ch = exp.at(i);

        if(!isOperand(ch) && !isCharOperator(ch)){
            continue;
        }
        if(isOperand(ch)){
            //push the operand
            string currCh(1, ch);
            newStack.push(currCh);
        }
        else{
            string s2 = (string)(newStack.top());
            newStack.pop();
            string s1 = (string)(newStack.top());
            newStack.pop();
            double operand2 = stoi(s1);
            double operand1 = stoi(s2);
            double value = operate(ch, operand1, operand2);
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
//Trims the blank spaces in the given string
void trimLeft(string& s){
    int firstValidIndex = 0;
    char ch = s.at(0);
    bool isNonBlankFound = false;

    for(int i = 0; i < s.size(); i++){
        char ch = s.at(i);
        if(ch != ' '){
            firstValidIndex = i;
            isNonBlankFound = true;
            break;
        }
    }
    if(isNonBlankFound){
        s = s.substr(firstValidIndex);
    }
}
