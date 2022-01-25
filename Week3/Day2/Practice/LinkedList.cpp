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

    //Find the n-th element in the linked list
    void GetElement(int position){
        if((position > this->size) || (position == 0)){
            cout << "Position to get is out of range." << endl;
            return;
        }
        LinkedListNode *temp = this->Head;
        for(int i = 1; i < position; i++){
            temp = temp->next;
        }
        cout << "We have element with value " << temp->getData() << " at position " << position << "." << endl;
        return;
    }

    //Size of the linked list
    int ListSize(){
        return this->size;
    }

    //Delete the element
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

    //Count the Occurance of item in the list
    void countElement(int value){
        if(this->size == 0){
            cout << "List is empty." << endl;
            return;
        }

        int count = 0;
        LinkedListNode *temp = this->Head;
        while(temp != NULL){
            if(temp->getData() == value){
                count++;
            }
            temp = temp->next;
        }
        cout << "Number of occurance for " << value << ":" << count << endl;
        return;
    }

    void FindMiddleElement(){
        if(this->size == 0){
            cout << "List is empty." << endl;
            return;
        }
        LinkedListNode *temp = Head;
        for(int i = 1; i < ((this->size / 2) + 1); i++){
            temp = temp->next;
        }
        cout << "Data of the Middle node is " << temp->getData() << endl;
    }
};

int main(){
    //Declare the list
    LinkedList *List = new LinkedList();
    //functions
    int input = 1;

    cout << "0: Exit the program." << endl;
    cout << "1: Get the size of the list." << endl;
    cout << "2: Print the whole list." << endl;
    cout << "3: Get Element from certain position." << endl;
    cout << "4: Add Element at the end of the list." << endl;
    cout << "5: Add Element at given position." << endl;
    cout << "6: Delete Element from given position." << endl;
    cout << "7: Count the occurance time of Element." << endl;
    cout << "8: Get the Middle node." << endl;

    while(input != 0){
        cout << "**************************************************************" << endl;
        cout << "Enter the code to run appropriate function:";
        cin >> input;
        switch (input) {
            case 0: {
                //Exit the loop if user enters 0
                cout << "Program exit." << endl;
                break;
            }
            case 1:{
                //to get the curernt size of linked list
                cout << "List size:" << List->ListSize() << endl;
                break;
            }
            case 2: {
                //to Print the whole list
                List->PrintList();
                break;
            }
            case 3: {
                //To get a Element at certain position
                int position;
                cout << "Enter the position to get element from:";
                cin >> position;
                List->GetElement(position);
                break;
            }
            case 4: {
                //To Add element at the end of the linked list
                int data;
                cout << "Enter the value to add:";
                cin >> data;
                List->AddNodeToListEnd(data);
                break;
            }
            case 5: {
                //To Add element at any position in between
                int position, data;
                cout << "Enter the position:";
                cin >> position;
                cout << "Enter the value to add:";
                cin >> data;
                List->AddInToList(position, data); 
                break;
            }
            case 6: {
                //To delete an item from list
                int position;
                cout << "Enter the position to delete from:";
                cin >> position;
                List->DeleteFromList(position);
                break;
            }
            case 7: {
                //To count number of occurance
                int data;
                cout << "Input the value to count occurance for:";
                cin >> data;
                List->countElement(data);
                break;
            }
            case 8: {
                //To find middle element
                List->FindMiddleElement();
                break;
            }
            default:{
                //If value is not from any given option
                cout << "Enter a valid input." << endl;
            }
        }
    }
    return 0;
}
