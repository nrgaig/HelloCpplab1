/***********************************************************
 * Created by Maor Frost 206370231 and Itay Oren 318648482 *
 * cpp lab - Meir Litman                                   *
 * exercise # task #                                       *
 * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$               *
************************************************************/

#include <iostream>
#include <string>
#include "StackVector.h"

using namespace std;

//Convert infix expression to postfix expression:
string infixToPostfix(string exp) {
    string str;
    StackVector<char> stack;
    char ch;
    int i = 0;
    while (i < exp.length()) {
        ch = exp[i];
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            str.push_back(32);//adding space between every character
            while (stack.top() != '(') {
                str += stack.top();
                stack.pop();
//                str.push_back(32);//adding space between every character
            }
            stack.pop();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!stack.isEmpty() && stack.top() != '(' &&
                   (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')) {
                str += stack.top();
                stack.pop();

            }
            stack.push(ch);
            str.push_back(32);//adding space between every character

        } else {
            str += ch;
        }
        i++;
    }
    while (!stack.isEmpty()) {
        str.push_back(32);//adding space between every character
        str += stack.top();
        stack.pop();
    }
    return str;
}

// calculate the result of the postfix expression
string calcPostfix(string postfix) {
    StackVector<int> stk;
    int i = 0;
    int spaceIndex;
    float num1, num2, result;
    while (i < postfix.length()) {
        if (47 < postfix[i] && postfix[i] < 58) { // digit
            spaceIndex = (int) postfix.find(' ', i);
            stk.push(stoi(postfix.substr(i, spaceIndex - i)));
            if (spaceIndex > 0) {
                i = spaceIndex;
            }
        }
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') { // operation
            num2 = (float) stk.top();
            stk.pop();
            num1 = (float) stk.top();
            stk.pop();
            if (postfix[i] == '+') {
                result = num1 + num2;
            }
            else if (postfix[i] == '-') {
                result = num1 - num2;
            }
            else if (postfix[i] == '*') {
                result = num1 * num2;
            }
            else if (postfix[i] == '/') {
                result = num1 / num2;
            }
            stk.push((int)result);
        }
        i++;
    }
    return to_string(stk.top());
}

int main() { //main function from Exercise's writer

    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "in postfix form: " << postfix << endl;
    cout << "calculated value: " << calcPostfix(postfix) << endl;
    return 0;
}//end main
