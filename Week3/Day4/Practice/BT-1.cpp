#include <bits/stdc++.h>
//Check wether its a complete BT or Not
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isCompleteBST(Node* root){
    //If tree is empty it can be said Complete binary tree
    if(root == NULL){
        return true;
    }
    //A level order traversal
    //Check for every node on that level
    //If first node does not have left or right child, neither should other node on that level
    //Meaning every node should be leaf node as well
    //If one node has right node but not left then it is also not a complete tree

    //Vertices to visit
    queue<Node*> visit; 
    visit.push(root);

    //Do this till you have vertices to visit
    while(visit.size() > 0){
        //remove the front element
        Node* current = visit.front();
        visit.pop();

        //If we find a non-complete node then tree is not complete
        bool NonCompleteNode = false;

        if(current->left != NULL){
            //If the current node is already non-complete node
            //then non-complete tree
            if (NonCompleteNode){
                return false;
            }
            //visit the left child as well
            visit.push(current->left);
        }else{
            //Here we don't have left child node
            //So this is a non complete child, so its non-complete binary tree
            //or this level should have all leaf node for it to be complete binary tree
            NonCompleteNode = true; 
        }

        if(current->right != NULL){
            //If the current node is already non-complete node
            //then non-complete tree
            if(NonCompleteNode){
                return false;
            }
            //visit the right child as well
            visit.push(current->right);
        }else{
            //Here we don't have right child node
            //So this is a non complete child
            NonCompleteNode = true; 
        }
    }

    //If all test cases are passed meaing its complete tree
    return true;
}

int main(){
    Node* root = NULL;

    //creating a complete a complete binary tree
    root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(14);
    root->left->left = new Node(10);
    root->left->right = new Node(5);
    //root->right->right = new Node(6);

    cout << (isCompleteBST(root) ? "Balanced BT" : "Not Balanced BT") << endl;
    return 0;
}