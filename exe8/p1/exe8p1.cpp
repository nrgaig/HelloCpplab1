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


string infixToPostfix(string exp){
    string str;
    StackVector<char> stk;
    char ch;
    //ch=exp[0];
    int i=0;
    while (i<exp.length()){
        if (exp[i]=='(')
            stk.push(exp[i]);
        if (exp[i]==')'){
            str.push_back(32);//adding space between every character
            while(stk.top()!='(') {
                str.push_back(stk.pop());
                str.push_back(32);//adding space between every character
            }
            stk.pop();
        }
        if (exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'){
            if (exp[i]=='+'||exp[i]=='-'){
                while(stk.top()!='(' && stk.top()!='+'&&stk.top()!='-') {
                    str.push_back(stk.pop());
                    str.push_back(32);//adding space between every character
                }
                stk.push(exp[i]);
            }

                while(stk.top()!='(' && stk.top()!='+'&&stk.top()!='-') {
                    str.push_back(stk.pop());
                    str.push_back(32);//adding space between every character
                }
                stk.push(exp[i]);
            }
        if(47<exp[i]&&exp[i]<58) {
            str.push_back(exp[i]);

        }



        i++;
    }

return str;
}

int main() {

    string exp;
    cout << "enter an infix expression as a string" << endl;
    cin >> exp;
    string postfix = infixToPostfix(exp);
    cout << "in postfix form: " << postfix << endl;
//    cout << "calculated value: " << calcPostfix(postfix) << endl;
    return 0;
}
