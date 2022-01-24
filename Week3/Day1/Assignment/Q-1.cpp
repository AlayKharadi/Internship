#include <iostream>

using namespace std;

//define the size of the array
int n;

//reverse array function using Array parameter
int* reverseArray(int arr[]){
    //get the first and last index of the array
    int i = 0;
    //swap the first and last element to reverse array
    //After the swap just go towards middle element of array from both the side
    //last index would be (n - 1 - i) of not reversed array
    //So condition would be i < (n - 1 - i)
    // 2*i < (n - 1)
    while (2*i < (n - 1)){
        //swap the values from first and last index of not reversed array
        int temp = arr[i];
        arr[i] = arr[(n - 1) - i];
        arr[(n - 1) - i] = temp;
        i++;
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