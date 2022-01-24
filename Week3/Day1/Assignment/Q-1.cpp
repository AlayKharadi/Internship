#include <iostream>

using namespace std;

//define the size of the array
int n;

//reverse array function using Array parameter
int* reverseArray(int arr[]){
    //get the first and last index of the array
    int i = 0;
    int j = n - 1;
    while (i < j){
        //swap the values from first and last index of not reversed array
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    //return the array
    return arr;
}

int main(){
    //Take the size of the array
    cin >> n;

    //create array using the size
    int* arr = (int *)malloc(n * sizeof(int));

    //Take all the values as space seprated input in array
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //call the reverseArray function and store the output in arr
    arr = reverseArray(arr);

    //Print the reversed Array
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }

    return 0;
}