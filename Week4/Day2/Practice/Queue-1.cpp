//Implement Stack using Queue

#include <bits/stdc++.h>

using namespace std;

//If we implement Queue's push function properly we can make this a stack
//We won't need to modify pop
class STACK{
    private:
        queue<int> *arr;

    public:
        STACK(){
            this->arr = new queue<int>();
        }

        //This function pop size number of element from the Queue
        //And push them at the end of the Queue
        void SetStack(int size){
            for(int i = 0; i < size; i++){
                this->arr->push(this->arr->front());
                this->arr->pop();
            }
            return;
        }

        //Push elment at the end of the Queue
        //Then push every element before it, after that eleement in stack
        void PUSH(int data){
            this->arr->push(data);
            this->SetStack(this->arr->size() - 1);
            cout << "Element added at the top of the Stack-" << data << endl;
            return;
        }

        void POP(){
            if(this->arr->size() == 0){
                cout << "Underflow detected." << endl;
                return;
            }
            cout << "Element poped from the Queue-" << this->arr->front() << "." << endl;
            this->arr->pop();
            return;
        }

        void PRINT(){
            int size = this->arr->size();
            for(int i = 0; i < size; i++){
                cout << "-" << this->arr->front() << "-";
                this->arr->push(this->arr->front());
                this->arr->pop();
            }
            return;
        }
};

int main(){
    STACK* arr = new STACK();
    arr->PUSH(0);
    arr->PUSH(1);
    arr->PUSH(2); 
    arr->PUSH(3);
    arr->PUSH(4);
    arr->PRINT();
    cout << endl;
    arr->POP();
    arr->PRINT();
    cout << endl;
    arr->PUSH(5);
    arr->PUSH(6);
    arr->PRINT();
    cout << endl;
    arr->POP();
    arr->PRINT();
    cout << endl;
    return 0;
}