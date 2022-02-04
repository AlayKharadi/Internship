#include <iostream>
using namespace std;

//Formula: C(n, k) = C(n - 1, k) + C(n - 1, k - 1)
//This algorithm will take O(n*max(n, (n -k)))
long long int BionomialCoefficient1(int n, int k){
    if((k == 0) || (k == n)){
        return 1;
    }
    return (BionomialCoefficient1(n - 1, k) + BionomialCoefficient1(n - 1, k - 1));
}

//Formula: C(n, k) = C(n - 1, k)*((n/(n - k))
//This algorithm will take O(n) time
long long int BionomialCoefficient2(int n, int k){
    if(k == n){
        return 1;
    }
    return ( (n*BionomialCoefficient2(n - 1, k)) / (n - k) );
}

long long int Check(int n, int k){
    if(k > n){
        return 0;
    }
    if(k == 0){
        return 1;
    }
    return BionomialCoefficient2(n,k);
}

int main(){
    int n, k;
    cout << "C(n, k) :";
    cin >> n >> k; 
    cout << "C(" << n << "," << k << ") =>" << Check(n, k) << endl;
    return 0;
}