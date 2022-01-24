#include<iostream>
#include<stack>
using namespace std;

bool isClosedParenthesis(string statment) {
    stack<char> temp;
    for (int i = 0; i < statment.length(); i++) {
        //Skip the steps if it is not an tag character

        //Add the opening tag in stack   
        if ((statment[i] == '[') || (statment[i] == '{') || (statment[i] == '(')) {
            temp.push(statment[i]);
            continue;
        }

        if((statment[i] == ']') || (statment[i] == '}') || (statment[i] == ')')){
            //If stack is empty, having a closing tag would be string with unclosed tag
            if (temp.empty()){
                return false;
            }

            //If there isn't a matching opening tag in stack for given closing tag then it would be string with unclosed tag
            if((statment[i] == ']') && (temp.top() != '[')){
                return false;
            } else if((statment[i] == '}') && (temp.top() != '{')){
                return false;
            } else if((statment[i] == ')') && (temp.top() != '(')){
                return false;
            }
            //Pop out the element from stack
            temp.pop();
        }
    }

    //After everything, If there is an tag in temp, then it would be string with unclosed tag
    //other wise everytag is in closed state
    return (temp.empty());
}

int main() {
    string expr = "[{(vfvjfnj)}][4342425]{(%$%#$^#)}[{gfnjb}{(njdvgf)}]()";
    cout << (isClosedParenthesis(expr) ? "Closed" : "Not Closed") << endl;
    return 0;
}