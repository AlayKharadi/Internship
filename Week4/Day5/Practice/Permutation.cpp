#include <iostream>

using namespace std;

//Count the permutation that doesn't have consecutive 1's
int CountPermutation(int n){
    //This array items contain string of length i which doesn't have consecutive 1's
    //a is the number of strings which ends with 0
    //b is the number of strings which ends with 1
    int a[n], b[n];
    a[0] = 1;
    b[0] = 1;
    for(int i = 1; i < n; i++){
        //We can add 0 or 1 to the end of these strings that end with 0 with length i - 1
        //If we add 0 thats okay, so that is represented using b[i-1]
        //We can use other strings with length i - 1 that end with 1 that is represented using a[i-1]
        a[i] = a[i - 1] + b[i - 1];
        //you can just add 0 at the end of all the strings with length (i - 1)
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}

int main(){
    int n;
    cout << "Input the length of the string: ";
    cin >> n;
    cout << "Number of the permuatation that doesn't have consecutive 1's: " << CountPermutation(n) << endl;
    return 0;
}