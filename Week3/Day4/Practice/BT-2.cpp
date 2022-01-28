//Find the height of the Binary Tree
#include <bits/stdc++.h>
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

int FindHeghit(Node* root){
    //If tree is empty then height is 0
    if(root == NULL){
        return 0;
    }
    //A level order traversal to check the number of levels to find height
    int height = 0;
    //Vertices to visit
    queue<Node*> visit; 
    visit.push(root);

    //Do this till you have vertices to visit
    while(visit.size() > 0){
        int nodes = visit.size();
        //Empty all the nodes on this level and add 1 to the height
        while(nodes > 0){
            //remove the front element
            Node* current = visit.front();
            visit.pop();

            if(current->left != NULL){
                //visit the left child as well
                visit.push(current->left);
            }
            if(current->right != NULL){
                //visit the right child as well
                visit.push(current->right);
            }
            nodes--;
        }
        height++;
    }
    return height;
}

int main(){
    Node* root = NULL;

    //creating a complete a binary tree
    root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(14);
    root->left->left = new Node(10);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right = new Node(34);
    root->right->left = new Node(34);
    root->right->left->right = new Node(34);

    cout << "Height of the Binary tree: " << FindHeghit(root) << endl;
    return 0;
}