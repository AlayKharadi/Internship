//Reverse stack using recursion
#include <bits/stdc++.h>

using namespace std;

//all we need to do is check about the top element
//Take that element and push it at the bottom of the stack at one step
stack<int> arr;

//Push item at the bottom of th stack
void pushBottom(int value){
    //Push the item, if stack is already empty
    if(arr.size() == 0){
        arr.push(value);
    }else{
        //if stack is not empty, pop out every item in the stack one-by-one
        //push your item to bottom.
        int top = arr.top();
        arr.pop();

        //Push the top item at the bottom
        pushBottom(value);
        //Push the item back into stack
        arr.push(top);
    }
}

//we can assume that other elements at bottom would be alreay reversed 
void ReverseStack(){
    //If stack is not empty
    if(arr.size() > 0){
        //pop out the element at the top
        //This way we can store the top element within recursive function
        //to push back at bottom
        int top = arr.top();
        arr.pop();

        //Reverse the rest of the stack
        ReverseStack();

        //Now push this element to the stack bottom
        pushBottom(top);
    }
}

void printStack(stack<int> a){
    if(a.size() > 0){
        int top = a.top();
        a.pop();
        printStack(a);
        cout << top << endl;
    }
}

int main(){
    int n;
    //number of input
    cin >> n;
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        arr.push(j);
    }
    cout << "Original Stack" << endl;
    printStack(arr);
    ReverseStack();

    cout << "Reversed Stack" << endl;
    printStack(arr);
    return 0;
}
