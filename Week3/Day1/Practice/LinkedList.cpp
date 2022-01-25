#include <iostream>

using namespace std;

//create a Node using class
class LinkedListNode{
    //make data of the node private
    private:
        //stores data
        int data;

    public:
        //stores address to the next node
        LinkedListNode *next;

        //constructor to create a node
        LinkedListNode(int data){
            this->data = data;
            this->next = NULL;
        }

        //Set method
        void setMethod(int data){
            this->data = data;
        }

        //Get method
        int getData(){
            return this->data;
        }
};

class LinkedList{
    public:
        //Head of the linked list
        LinkedListNode *Head;
        //Tail of the linked list
        LinkedListNode *Tail;
        //Size of the linked list
        int size;

        //constructor for linked list
        LinkedList(){
            this->Head = NULL;
            this->Tail = NULL;
            this->size = 0;
        }

    //Print the linkedList
    void PrintList(){
        //Iterate through the linked List to print all the nodes
        if(this->size == 0){
            cout << "Linked is empty" << endl;
            return;
        }
        cout << "Linked List: ";
        LinkedListNode *temp = this->Head;
        while(temp->next != NULL){
            cout << temp->getData() << "->";
            temp = temp->next;
        }
        cout << temp->getData() << endl;
    }

    //Addition at the end
    void AddNodeToListEnd(int data){
        //If link empty, add element to head/tail
        if((this->Head == NULL) && (this->Tail == NULL)){
            this->Head = new LinkedListNode(data);
            this->Tail = this->Head;
        } else {
        //If list is not empty, add at the end of it
            this->Tail->next = new LinkedListNode(data);
            this->Tail = this->Tail->next;
        }
        //Increase the list size
        size++;
        cout << "SuccessFull Addition At the end of the list." << endl;
    }

    //Addition in between
    void AddInToList(int position, int data){
        if((position > this->size) || (position == 0)){
            cout << "Position to add is out of range." << endl;
            return;
        }
        LinkedListNode *newNode = new LinkedListNode(data);

        //If addition is at Head;
        if(position == 1){
            newNode->next = this->Head;
            this->Head = newNode;
        } else {
            LinkedListNode *temp = this->Head;
            for(int i = 1; i < (position - 1); i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        //Increase the list size
        size++;
        cout << "SuccessFull Addition At the given position in the list." << endl;
    }

    void DeleteFromList(int position){
        if((position > this->size) || (position == 0)){
            cout << "Position to delete is out of range." << endl;
            return;
        }
        if (position == 1) {
            //Node to delete
            LinkedListNode *flag = this->Head;
            this->Head = this->Head->next;
            if(size == 1){
                this->Tail = NULL;
            }
            delete flag;
        } else {
            
            LinkedListNode *temp = this->Head;
            for(int i = 1; i < (position - 1); i++){
                temp = temp->next;
            }

            //Node to delete
            LinkedListNode *flag = temp->next;
            temp->next = flag->next;
            delete flag;

            //If the element is at tail
            if(position == size){
                Tail = temp;
            }
        }
        //Decrease the list size
        size--;
        cout << "SuccessFull Deletion From the given position in the list." << endl;
    }
};

int main(){
    LinkedList *List = new LinkedList();
    List->AddNodeToListEnd(1);
    //Delete From Head in size = 1
    List->DeleteFromList(1);
    List->AddNodeToListEnd(1);
    List->AddNodeToListEnd(2);
    List->AddNodeToListEnd(3);
    List->AddNodeToListEnd(4);
    List->AddNodeToListEnd(5);
    //Add 0 value at third position
    List->AddInToList(0, 3);
    List->PrintList();
    //Delete from third position
    List->DeleteFromList(3);
    List->PrintList();

    //Delete From Head
    List->DeleteFromList(1);
    List->AddInToList(1, 3);
    List->PrintList();


    return 0;
}
