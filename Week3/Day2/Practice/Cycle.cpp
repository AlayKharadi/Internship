#include <iostream>
//Detect the cycle in Linked list

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

//Check for the cycle
bool isCyclic(Node* node){
    //create a node that will go further one step at a time 
    Node* hair = node;
    //create a node that will go two steps at a time
    Node* rabbit = node;
    //Iterate through the list till one of them reaches end
    //If before reaching end, both have same ADDRESS then its a cylce
    while((hair != NULL) && (rabbit != NULL)){
        hair = hair->next->next;
        rabbit = rabbit->next;
        if(hair == rabbit){
            return true;
        }
    };
    return false;
}

int main(){
    //Declare the head of the list
    Node* Head = new Node(0);
    //to travel in the list
    Node* temp = Head;
    //Insert few elements
    //Create a cylce in linked list
    for(int i = 1; i < 10; i++){
        temp->next = new Node(i);
        if(i != 9){
            temp = temp->next; 
        }
    }
    //Before creating cycle
    cout << (isCyclic(Head) ? "Cyclic" : "Not Cyclic") << endl;

    //After creating cycle
    //Atach tail to the second element
    temp->next = (Head->next)->next;
    cout << (isCyclic(Head) ? "Cyclic" : "Not Cyclic") << endl;
    return 0;
}