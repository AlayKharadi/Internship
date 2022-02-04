#include <bits/stdc++.h>

using namespace std;

//We want to find the k-th smallest element in the array
int FindMaxK(int arr[], int n, int k){
    int ans;
    vector<int> heap;
    for(int i = 0; i < n; i++){
        heap.push_back(arr[i]);
        push_heap(heap.begin(), heap.end());
        if(heap.size() > k){
            ans = heap.front();
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
    }
    return heap.front();
}

int main(){
    int n, k;
    cout << "Input the size of array: " ; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout << "array[" << (i+1) << "]: "; 
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    cout << "k-th largest element: " << FindMaxK(arr, n, k) << endl;
    return 0;
}