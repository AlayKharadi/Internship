#include <iostream>

using namespace std;

//create a Node using class
class LinkedListNode{
    //make data and next pointer public
    public:
        //stores data
        int data;
        //stores address to the next node
        LinkedListNode *next;

        //constructor to create a node
        // LinkedListNode(){
        //     this->data = NULL;
        //     this->next = NULL;
        // }

        LinkedListNode(int data){
            this->data = data;
            this->next = NULL;
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
        //iterate through the linked List to print all the nodes
        LinkedListNode *temp = Head;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void AddNodeToListEnd(int data){
        //If link empty
        if((this->Head == NULL) && (this->Tail == NULL)){
            this->Head = new LinkedListNode(data);
            this->Tail = this->Head;
        } else {
            this->Tail->next = new LinkedListNode(data);
            this->Tail = this->Tail->next;
        }
        //Increase the size
        size++;
    }
};

int main(){
    //create list using the size
    LinkedList *List = new LinkedList();

    //Total enteries in linked list
    int n;
    cin >> n;

    //take input values and add into the list
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        List->AddNodeToListEnd(temp);
    }

    //Print the list
    List->PrintList();

    return 0;
}
