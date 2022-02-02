#include <bits/stdc++.h>

using namespace std;

//Heap node should have no child, one left child or both left and right child
//In a min-heap parent's value should be less than its children nodes
//In a max-heap parent's value should be greater than its children nodes
class Heap{
    private:
        int *arr;
        int currentSize;
        int maxSize;
    
    public:

        Heap(int size){
            this->maxSize = size;
            this->currentSize = 0;
            this->arr = (int *)malloc(size*sizeof(int));
        }

        int parentIndex(int child){
            return floor((child - 1)/2);
        }

        int leftIndex(int parent){
            return (2*parent + 1);
        }

        int rightIndex(int parent){
            return (2*parent + 2);
        }

        void InsertHeapItem(int value){
            //If heap is full
            if(this->maxSize == this->currentSize){
                cout << "OverFlow Detected." << endl;
                return;
            }

            //Insert the value at the end of the heap
            this->arr[this->currentSize] = value;

            int i = this->currentSize;

            //Increrse the size
            this->currentSize = this->currentSize + 1;

            //Maintain the rule of parent node being smaller than its children
            //Check till we reach 0 or we have a parent whose value is large
            while((i != 0) && (this->arr[parentIndex(i)] > this->arr[i])){
                int temp = this->arr[i];
                this->arr[i] = this->arr[parentIndex(i)];
                this->arr[parentIndex(i)] = temp;
                i = parentIndex(i);
            }

            cout << "Element added value in the heap: " << value << endl;
            return;
        }

        //Heapify the sub-tree for a given index
        void Heapify(int i){
            int min = i;
            if((leftIndex(i) < this->currentSize) && (this->arr[leftIndex(i)] < this->arr[min])){
                min = leftIndex(i);
            }
            if((rightIndex(i) < this->currentSize) && (this->arr[leftIndex(i)] < this->arr[min])){
                min = rightIndex(i);
            }
            if(min != i){
                int temp = this->arr[i];
                this->arr[i] = this->arr[min];
                this->arr[min] = temp;

                Heapify(min);
            }
            return;
        }

        void PrintHeap(){
            for(int i = 0; i < this->currentSize; i++){
                cout << "-" << this->arr[i] << "-";
            }
            cout << endl;
            return;
        }

        void DeleteHeapItem(int i){
            if((i + 1) > this->currentSize){
                cout << "Index out of bound" << endl;
                return;
            }
            if(this->currentSize == 0){
                cout << "UndeFlow detected." << endl;
                return;
            }
            if(this->currentSize == 1){
                this->currentSize = this->currentSize - 1;
                cout << "Node deleted from the given index." << i << endl;
                return;
            }
            //Make the element that you want to remove at the top
            while(i > 0){
                int temp = this->arr[i];
                this->arr[i] = this->arr[parentIndex(i)];
                this->arr[parentIndex(i)] = temp;
                i = parentIndex(i);
            }
            this->currentSize = this->currentSize - 1;
            this->arr[0] = this->arr[this->currentSize];
            Heapify(0);

            cout << "Node deleted from the given index." << i << endl;
            return;
        }

};

int main(){
    Heap h(10);
    h.InsertHeapItem(11);
    h.InsertHeapItem(23);
    h.InsertHeapItem(38);
    h.PrintHeap();
    h.DeleteHeapItem(2);
    h.PrintHeap();
    h.InsertHeapItem(53);
    h.InsertHeapItem(95);
    h.InsertHeapItem(34);
    h.InsertHeapItem(76);
    h.InsertHeapItem(47);
    h.PrintHeap();
    return 0;
}