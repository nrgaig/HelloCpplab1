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
        }
        else if (ch == ')') {
            str.push_back(32);//adding space between every character
            while (stack.top() != '(') {
                str += stack.top();
                stack.pop();
                str.push_back(32);//adding space between every character
            }
            stack.pop();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!stack.isEmpty() && stack.top() != '(' && (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/')) {
                str += stack.top();
                stack.pop();
            }
            stack.push(ch);
            str.push_back(32);//adding space between every character

        }
        else {
            str += ch;
        }
        i++;
    }
    while (!stack.isEmpty()) {
        str += stack.top();
        stack.pop();
    }
    return str;


//    string str; // creating new blank string
//    StackVector<char> stk; // creating new blank char-stack
//    char ch;
//
//    //ch=exp[0];
//    int i = 0; //
//    while (i < exp.length()) {
//        if (exp[i] == '(') // (
//            stk.push(exp[i]);
//
//        if (exp[i] == ')') { // )
//            str.push_back(32);//adding space between every character
//            if (!stk.isEmpty()) {
//                while (stk.top() != '(') {
//                    str.push_back(stk.top());
//                    stk.pop();
//                    str.push_back(32);//adding space between every character
//                }
//                stk.pop();
//            }
//
//        }
//        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { // operation
//            str.push_back(32);//adding space between every character
//            if (exp[i] == '+' || exp[i] == '-') {
//                if (!stk.isEmpty()) {
//                    while (stk.top() != '(' && stk.top() != '+' && stk.top() != '-') {
//                        str.push_back(stk.top());
//                        stk.pop();
//                        str.push_back(32);//adding space between every character
//                    }
//                }
//                stk.push(exp[i]);
//
//            } else {
//                if (!stk.isEmpty()) {
//                    while (stk.top() != '(') {
//                        str.push_back(stk.top());
//                        stk.pop();
//                        str.push_back(32);//adding space between every character
//                    }
//                }
//                stk.push(exp[i]);
//            }
//        }
//        if (47 < exp[i] && exp[i] < 58) { // digit
//            str.push_back(exp[i]);
//
//        }
//        i++;
//    }
//
//    return str;
}
// calculate the result of the postfix expression
string calcPostfix(string postfix) {
    StackVector<int> stk;
    int i = 0;
    int num1, num2, result;
    while (i < postfix.length()) {
        if (47 < postfix[i] && postfix[i] < 58) { // digit
            stk.push(stoi(postfix.substr(i, postfix.find(' ', i) - i)));
            i = postfix.find(' ', i);
//            stk.push(postfix[i] - '0');
        }
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') { // operation
            num1 = stk.top();
            stk.pop();
            num2 = stk.top();
            stk.pop();
            if (postfix[i] == '+') {
                result = num1 + num2;
            }
            if (postfix[i] == '-') {
                result = num1 - num2;
            }
            if (postfix[i] == '*') {
                result = num1 * num2;
            }
            if (postfix[i] == '/') {
                result = num1 / num2;
            }
            stk.push(result);
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
