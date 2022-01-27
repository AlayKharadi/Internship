//Q-1
#include <bits/stdc++.h>

using namespace std;

//arr: Array of the pairs
//size: Size of the array
int findMinAvgWait(vector<pair<int, int>> arr, int size){
    //Minimum average waiting time
    int minTime = 0;

    //Sort the array to get the asecnding order of arrival time
    sort(arr.begin(), arr.end()); 

    //the temp is to store in the sorted order of backing time for remaining items
    //After we have all the items sotred accoring to their arival time
    //we can go for the item that takes least time to cook in order to reduce the average waiting time
    set< pair<int, int> > temp;

    //Time of first given order
    int time = arr[0].first;

    //Run loop till we have someone's order to complete(arr is not empty)
    //or there are still item in temp(meaning there is yet something to cook)
    //i to iterate
    int i = 0;
    while((i < size) || temp.size()){

        //Run loop till we have someone's order to complete(arr is not empty)
        //If certain items arrived before current item then send them to get cooking list
        while((i < size) && (arr[i].first <= time)){
            temp.insert(make_pair(arr[i].second, i));
            i++;
        }

        //If backing item list is empty that means we can go for current item to cook
        if(temp.empty()){
            time = arr[i].first;
        }else{
            //If it is not then take the first item from the cook
            //remove that item from the cooking list
            int j = temp.begin()->second;
            temp.erase(temp.begin());
            //Add that time to our current time
            time = time + arr[j].second;
            minTime = minTime + (time - arr[j].first);         
        }
    }

    //Returning the integer part of the minimum average waiting time
    return minTime;
}

int main() {
    //Siz of the input
    int n;
    cin >> n;

    //Declare the array of pairs
    //Time is in 0, 1, 2 form
    //First item in pair is time at which the pan was ordered
    //Second item in pair is time to make the pan
    vector< pair<int, int>> arr;

    //Take the input params
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a;
        cin >> b;
        arr.push_back(make_pair(a, b));
    }

    //The waiting time is calculated as the difference between the time a customer orders pan (the time at which they enter the shop) and the time she is served.
    //Print minimum average waiting time
    cout << (findMinAvgWait(arr, n) / n) << endl;

    return 0;
}