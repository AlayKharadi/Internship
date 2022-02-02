#include <bits/stdc++.h>

//diffrent sorting algorithm : Quick Sort, Heap Sort
//In main uncomment the function to use algorithm

using namespace std;

void PrintArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << "-" << arr[i] << "-";
    }
    cout << endl;
    return;
}

//Parition function gives us parition index to partition array
//Also it sets the value less than partition index's value before it
//And values greater than partition index after it
int Partition(int arr[], int left, int right){
    //Declare last element as your pivot element
    int pivot = arr[right];
    int j = left - 1;
    for(int i = left; i < right; i++){
        //Check if current element is smaller than our pivot
        //Swap it with out j-th element
        if(arr[i] < pivot){
            j++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    //After everything we will have every element bigger than pivot after its real index
    //And every element smaller than pivot before its real index
    //Make the pivot element reach its position
    arr[right] = arr[j + 1];
    arr[j + 1] = pivot;
    return (j + 1);
}

//Divide and conquor
void QuickSort(int arr[], int left, int right){
    if(left < right){
        //Find the partition element
        int partition = Partition(arr, left, right);
        //Sort the left portion
        QuickSort(arr, left, partition - 1);
        //Sort the right portion
        QuickSort(arr, partition + 1, right);
    }
    return;
}

//Heapify the array
void Heapify(int arr[], int size, int index){
    int max = index;

    //Find the minimum element from all of three (parent, left, right)
    //index for left is 2*i + 1
    if(((2*index + 1) < size) && (arr[2*index+1] > arr[max])){
        max = 2*index + 1;
    }
    //Index for right is 2*i + 2
    if(((2*index + 2) < size) && (arr[2*index+2] > arr[max])){
        max = 2*index + 2;
    }

    //Swap the max with currrent
    if(max != index){
        int temp = arr[index];
        arr[index] = arr[max];
        arr[max] = temp;
        //Call heapify again with max
        Heapify(arr, size, max);
    }
}

//HeapSort
void HeapSort(int arr[], int n){
    //First you have to create a heap out of our array
    for(int i = (n / 2) - 1; i >= 0; i--){
        Heapify(arr, n, i);
    }

    //Extract one element at a time and push that element back into heap
    //call for heapify after inserting that element back into the heap
    for(int i = (n - 1); i > 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        Heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = { 10, 3, 5, 6, 8, 9, 12, 56, 22, 89 };
    cout << "Original Array:" << endl;
    PrintArray(arr, 10);
    //Every sort below is implementd
    // QuickSort(arr, 0, 9);
    // cout << "Quick Sort:" << endl;
    HeapSort(arr, 10);
    cout << "Heap Sort" << endl;
    PrintArray(arr, 10);
    return 0;
}