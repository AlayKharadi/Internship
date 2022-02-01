//Implement Queue using stack

#include <bits/stdc++.h>

using namespace std;

//If we implement stack's push function properly we can make this a Queue
//We won't need to modify pop
class QUEUE{
    private:
        stack<int> *arr;

    public:
        QUEUE(){
            this->arr = new stack<int>();
        }

        //Before entering a value into the stack pop every value
        //Then at the last recursive call push it at the bottom of the stack
        //As we want it to get out last(FIFO)
        void PUSH(int data){
            if(this->arr->size() == 0){
                this->arr->push(data);
                cout << "Element added at the end of the Queue-" << this->arr->top() << endl;
                return;
            }
            int temp = this->arr->top();
            this->arr->pop();
            this->PUSH(data);
            this->arr->push(temp);
            return;
        }

        void POP(){
            if(this->arr->size() == 0){
                cout << "Underflow detected." << endl;
                return;
            }
            cout << "Element poped from the Queue-" << this->arr->top() << "." << endl;
            this->arr->pop();
            return;
        }

        void PRINT(){
            if(this->arr->size() == 0){
                return;
            }
            int temp = this->arr->top();
            this->arr->pop();
            cout << "-" << temp << "-";
            this->PRINT();
            this->arr->push(temp);
            return;
        }
};

int main(){
    QUEUE* arr = new QUEUE();
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