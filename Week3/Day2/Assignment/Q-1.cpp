//Q-1
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//getMax function with operations array as parameters
int getMax(stack <int> arr){
    //Assume element at the top is of max value
    int max = arr.top();
    arr.pop();
    //Pop every element of stack to find max number
    while(!arr.empty()){
        int temp = arr.top();
        if(temp > max){
            max = temp;
        }
        arr.pop();
    }
    return max;
}

int main() {
    //Number of query
    int n;
    cin >> n;

    //Define the operations array from n
    string operations[n];

    //Deaclare a stack of datatype int
    stack <int> arr;

    //take input from STDIN
    for(int i = 0; i < n; i++){
        getline(cin >> ws, operations[i]);
    }

    for(int i = 0; i < n; i++){
        //Insert Element into stack
        if((operations[i][0] == '1') && (operations[i][1] == ' ')){

            //get the number part of the string that needs to be pushed into stack
            string temp = operations[i].substr(2, temp.length());

            //convert the number's string into number
            //push it into the stack
            arr.push(stoi(temp));
            continue;
        }
        //Delete an element from the top of stack
        if(operations[i][0] == '2' && (operations[i].length() == 1)){
            arr.pop();
            continue;
        }
        //Print the maximum element in the stack
        if(operations[i][0] == '3' && (operations[i].length() == 1)){
            cout << getMax(arr) << endl;
            continue;
        }
        //If the input string does option from above three skip that part
    }

    return 0;
}