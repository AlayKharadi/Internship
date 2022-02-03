#include <iostream>

using namespace std;

//Find the PermutationCoefficient(n, k)
//It takes at most k steps to get result
long long int Permutation(int n, int k){
    //At initial, for k = 0 => P(n, 0) would result in 1.
    if(k == 0){
        return 1;
    }
    //Formula: Permutation(n, k) = Permutation(n - 1, k - 1) * n
    return n*Permutation(n - 1, k - 1);
}

long long int PermutationCheck(int n, int k){
    if(k < 0 || n < 0){
        cout << "All the values should be postive." << endl;
        return -1;
    }
    if(k > n){
        cout << "N should be greater than k." << endl;
        return -1;
    }
    return Permutation(n, k);
}

int main(){
    long long int ans = Permutation(17, 3);
    cout << ((ans > 0) ? ans : -1) << endl;
    return 0;
}