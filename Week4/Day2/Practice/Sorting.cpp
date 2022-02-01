#include <bits/stdc++.h>

//Four diffrent sorting algorithm Bubble, Selection, Insertion and Merge sort
//In main uncomment the function to use algorithm

using namespace std;

void PrintArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << "-" << arr[i] << "-";
    }
    cout << endl;
    return;
}

void BubbleSort(int arr[], int n){
    //For each position check whether the position we are checking with is small
    //If small swap them
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Bubble Sort:" << endl;
    PrintArray(arr, n);
    return;
} 

void SelectionSort(int arr[], int n){
    //for each position find the min element
    //At the end of every round swap it with that particular position
    for(int i = 0; i < n - 1; i++){
        int minELM = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minELM]){
                minELM = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minELM];
        arr[minELM] = temp;
    }
    cout << "Selection Sort:" << endl;
    PrintArray(arr, n);
    return;
}

void InsertionSort(int arr[], int n){
    //For each iteration, if elements are bigger they are supposed to be after the current element
    //Move these elements after the current element
    for(int i = 1; i < n; i++){
        int current = arr[i];
        int j;
        for(j = i - 1; (j >= 0) && (arr[j] > current); j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }
    cout << "Insertion Sort:" << endl;
    PrintArray(arr, n);
    return;
}

void Merge(int arr[], int left, int middle, int right){

    //Create two arrays to store the values of the left and right array
    queue<int> leftArray;
    queue<int> rightArray;
    for(int i = 0; i < (((middle - left) + 1) || (right - middle)) ; i++){
        if(i < ((middle - left) + 1)){
            leftArray.push(arr[left + i]);
        }
        if(i < (right - middle)){
            rightArray.push(arr[middle + i + 1]);
        }
    }
    //Find the smalled element from both the array particular position at the time
    //Store that element into the main array
    //Go further in the either of the array
    int i;
    for(i = left; (leftArray.size() > 0) && (rightArray.size() > 0); i++){
        //i is index for main array
        //j is index for left array
        //k is index for right array
        if(leftArray.front() <= rightArray.front()){
            arr[i] = leftArray.front();
            leftArray.pop();
        }else{
            arr[i] = rightArray.front();
            rightArray.pop();
        }
    }

    //Check if either of the element have still element left to push in lfet array
    while(leftArray.size() > 0){
        arr[i] = leftArray.front();
        leftArray.pop();
        i++;
    }
    //Check if either of the element have still element left to push in right array
    while(rightArray.size() > 0){
        arr[i] = rightArray.front();
        rightArray.pop();
        i++;
    }
    return;
}

//Divide and conquor
void MergeSort(int arr[], int left, int right){
    if(left < right){
        //Find the mid element
        //
        int middle = left + ((right - left) / 2);
        //Sort the left portion
        MergeSort(arr, left, middle);
        //Sort the right portion
        MergeSort(arr, middle + 1, right);

        Merge(arr, left, middle, right);
    }else {
        return;
    }
    return;
}

int main(){
    int arr[] = { 10, 3, 5, 6, 8, 9, 12, 56, 22, 89 };
    cout << "Original Array:" << endl;
    PrintArray(arr, 10);
    //Every sort below is implementd
    BubbleSort(arr, 10);
    // SelectionSort(arr, 10);
    // InsertionSort(arr, 10);
    // MergeSort(arr, 0, 9);
    // cout << "Merge Sort:" << endl;
    // PrintArray(arr, 10);
    return 0;
}