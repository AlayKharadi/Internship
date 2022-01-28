//Q-1
//Generate binary number between 1 to n using Queue
#include <bits/stdc++.h>

using namespace std;

void generateBinary(int n){
    queue<string> temp;

    //First element from 1 to n
    temp.push("1");

    //generate n values
    for(int i = 0; i < n; i++){
        //Add 0 and 1 at the end of the front element of the queue
        temp.push(temp.front() + "0");
        temp.push(temp.front() + "1");

        //Remove the front element and print it
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    return;
}

int main() {
    //Size of the input
    int n;
    cin >> n;

    generateBinary(n);

    return 0;
}