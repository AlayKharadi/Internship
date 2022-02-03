#include <iostream>

using namespace std;

//Find the n-th element in finbonnaci series
int Fibonacci(int n){
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    //Formula: f(n) = f(n - 1) + f(n - 2)
    for(int i = 2; i < n; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

int main(){
    cout << "Fibonacci series:" << endl;
    cout << "1 1 2 3 5 ..." << endl;
    int n;
    cout << "Input the index of the fibonacci Number:" << endl;
    cin >> n;
    cout << "Fibonacci Number for given index:" << Fibonacci(n) << endl;
    return 0;
}