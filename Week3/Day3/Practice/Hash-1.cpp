//A Hash Table with search, delete and insert 
//Linear Probing
#include <bits/stdc++.h>

using namespace std;

//Define a hash key-value node
//to store items with certain key in HashTable
class HashNode{
    public:
        int key;
        int value;

    //Constructor
    HashNode(){
        this->key = -1;
        this->value = -1;
    }
};

//Create a Hash Table out of it
class HashTable{
    public:
        //Point to the table
        HashNode arr[100];
        //size of the table
        int size;

    //HashTable constructor
    HashTable(int size){
        //Assign the given size 
        this->size = size;
    }

    //Index to store the Hash<key, value> pair
    //Or Hash Function
    int hashIndex(int key){
        return (key%(this->size));
    }

    //Search Function
    void SearchItem(int key){
        //get the index for given key from the hashIndex
        int hashKey = hashIndex(key);
        //Find the value till we reach the end
        int i = 0;
        while((this->arr[hashKey].key != -1) && (i < this->size)){
            //Check the item in the array
            //If found return it to the user
            if(this->arr[hashKey].key == key){
                cout << "Key: " << this->arr[hashKey].key << endl << "Value: " << this->arr[hashKey].value << endl;
                return;
            }
            //As this is linear probing
            //Go to the next item in the array
            hashKey++;

            //Go to the first index if reach the end
            hashKey = hashKey % this->size;
            i++;
        }
        cout << "Element not found." << endl;
        return;
    }

    void InsertItem(int key, int data){
        //get the index for given key from the hashIndex
        int hashKey = hashIndex(key);
        int i = 0;
        //Find a space to fill in
        while((this->arr[hashKey].key != -1) && (i < this->size)){
            cout << this->arr[hashKey].key << endl;
            //As this is linear probing
            //Go to the next item in the array
            hashKey++;
            //Go to the first index if reach the end
            hashKey = hashKey % this->size;
            i++;
        }

        if(i < this->size){
            this->arr[hashKey].value = data;
            this->arr[hashKey].key = key;
            cout << "Item added at the position " << hashKey << "." << endl;
            return;
        }
        cout << "not enough space." << endl;
        return;
    }

    void DeleteItem(int key){
        //get the index for given key from the hashIndex
        int hashKey = hashIndex(key);
        //Find the value till we reach the end
        int i = 0;
        while((this->arr[hashKey].key != -1) && (i < this->size)){
            //Check the item in the array
            //If found delete it
            if(this->arr[hashKey].key == key){
                cout << "Item removed from the position" << hashKey << "." << endl;
                this->arr[hashKey].key = -1;
                this->arr[hashKey].value = -1;
                return;
            }
            //As this is linear probing
            //Go to the next item in the array
            hashKey++;

            //Go to the first index if reach the end
            hashKey = hashKey % this->size;
            i++;
        }
        cout << "Element not found." << endl;
        return;
    }
};

int main(){
    int n;
    cin >> n;

    HashTable *arr = new HashTable(n);

    cout << "-->Insertion" << endl;
    for(int i = 0; i < n; i++){
        arr->InsertItem(i, 12*(i+1));
    }

    cout << "-->Search" << endl;
    for(int i = 0; i < n; i++){
        arr->SearchItem(i);
    }

    cout << "-->Search" << endl;
    for(int i = 0; i < n; i = i +2){
        arr->DeleteItem(i);
    }

    cout << "-->Search" << endl;
    for(int i = 0; i < n; i++){
        arr->SearchItem(i);
    }

    return 0;
}
