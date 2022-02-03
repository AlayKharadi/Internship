#include <iostream>

using namespace std;

//0-1 KanpSack Problem
//Use a recursive approach to solve the problem
//Divide the problem into the smaller problems
int KanpSack(int arr[][2], int size, int capacitiy){
    //If you don't have size or capacity to get the element, remove 0
    if((size == 0) || (capacitiy == 0)){
        return 0;   
    }
    //Reduce the size of the array
    size--;
    //Check for the last item in the array
    //If we have capacity to store it store it in the bag
    //Go further with the smaller size array and reduced capacity
    if(arr[size][1] <= capacitiy){
        //Check wether putting that item into bag makes up for more space or 
        //All together not considering it makes more sense for our case
        //By comapring both the results through recurssion
        return max(KanpSack(arr, size, capacitiy), (arr[size][0] + KanpSack(arr, size, (capacitiy - arr[size][1]))));
    }else{
        //If the item is larger than capacity then its not possible to store in bag
        return KanpSack(arr, size, capacitiy);
    }
}


int main(){
    int n, capacitiy;
    cout << "Number of total items: ";
    cin >> n;
    //The first item stores its value
    //The second item stores its weight
    int arr[n][2];
    cout << "'Item's Value' 'Item's Weight'" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    cout << "Capacitiy of the container in which you want to store these items: ";
    cin >> capacitiy;
    cout << KanpSack(arr, n, capacitiy) << endl;
    return 0;
}