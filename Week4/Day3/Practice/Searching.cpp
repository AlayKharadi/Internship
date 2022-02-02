#include <bits/stdc++.h>

//diffrent Searching algorithm : Linear Search, Binary Search, 
//In main uncomment the function to use algorithm

using namespace std;

//This method works for every array
//Go through array and find the element
int LinearSearch(int arr[], int left, int right, int item){
    for(int i = left; i <= right; i++){
        if(arr[i] == item){
            return i;
        }
    }
    return -1;
}

//This method works for sorted array
//Check if an element is at middle
//If not found go for either left or right
//Depending upon wether element is big or small
int BinarySearch(int arr[], int left, int right, int item){
    if(left <= right){
        int middle = left + ((right - left) / 2);

        if(arr[middle] == item){
            return middle;
        }
        if(arr[middle] > item){
            return BinarySearch(arr, left, middle - 1, item);
        }
        if(arr[middle] < item){
            return BinarySearch(arr, middle + 1, right, item);
        }
    }
    return -1;
}

//This algorithm also works on only sorted algorithms
//Make a jump of certain number to find the range such that arr[i] < item < arr[k]
//then perform linear search on that
//The optimal value to jump is root of size of the array
int JumpSearch(int arr[], int n, int item){
    int i = 0;
    for( i = 0; (arr[i] < item) && (i < n); i = i + sqrt(n)){
        if(arr[i] == item){
            return i;
        }
    }
    return LinearSearch(arr, i - sqrt(n), i , item);
}



int main(){
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int find = 10;
    cout << "Element-" << find << " found at " << LinearSearch(arr, 0, size - 1, find) << endl;
    find = 6;
    cout << "Element-" << find << " found at " << BinarySearch(arr, 0, size - 1, find) << endl;
    find = 9;
    cout << "Element-" << find << " found at " << JumpSearch(arr, size, find) << endl;
    
    return 0;
}