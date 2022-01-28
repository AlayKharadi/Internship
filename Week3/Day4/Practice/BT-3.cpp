//Q-1 
//Check whether 2 binary trees are anangram or not
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

bool Anangram(Node* root1,Node* root2){
    //If both trees are empty then they are anagram
    if((root1 == NULL) && (root2 == NULL)){
        return true;
    }
    //If one is empty and other is not then they are not anagram
    if((root1 == NULL) || (root2 == NULL)){
        return false;
    }

    //A level order traversal to check the anagrams
    //Vertices to visit
    queue<Node*> visit1; 
    visit1.push(root1);

    queue<Node*> visit2;
    visit2.push(root2);

    //Do this till you reach to answer
    while(visit1.size() > 0){
        //Total nodes in both the tree's level
        int nodes1 = visit1.size();
        int nodes2 = visit2.size();
        //if both have different number of nodes on same level then they are not anagrams
        if(nodes1 != nodes2){
            return false;
        }

        //Get All the elements on the level in a vector and chek them whether they are same or not
        vector<int> current1, current2;
        while(nodes1 > 0){
            Node* current;

            //remove the front element
            current = visit1.front();
            current1.push_back(current->data);
            visit1.pop();

            if(current->left != NULL){
                //visit the left child as well
                visit1.push(current->left);
            }
            if(current->right != NULL){
                //visit the right child as well
                visit1.push(current->right);
            }
            nodes1--;

            //remove the front element
            current = visit2.front();
            current2.push_back(current->data);
            visit2.pop();

            if(current->left != NULL){
                //visit the left child as well
                visit2.push(current->left);
            }
            if(current->right != NULL){
                //visit the right child as well
                visit2.push(current->right);
            }
            nodes2--;
        }
        //Check the nodes of both levels
        //anagrams or not
        sort(current1.begin(), current1.end());
        sort(current2.begin(), current2.end());
        if(current1 != current2){
            return false;
        }
    }
    //If all the test cases pass it means they are anangram
    return true;
}

int main(){
    Node *root1, *root2 = NULL;

    //creating a complete a binary tree
    root1 = new Node(9);
    root1->left = new Node(8);
    root1->right = new Node(14);
    root1->left->left = new Node(10);
    root1->left->right = new Node(5);
    root1->right->right = new Node(6);
    root1->right->left = new Node(4);
    root1->right->left->left = new Node(14);
    // root1->right->left->right = new Node(23);

    root2 = new Node(9);
    root2->left = new Node(14);
    root2->right = new Node(8);
    root2->left->left = new Node(6);
    root2->left->right = new Node(10);
    root2->right->right = new Node(4);
    root2->right->left = new Node(5);
    root2->right->left->right = new Node(14);

    cout << "Are Both trees anagram: " << (Anangram(root1, root2) ? "Yes" : "No") << endl;
    return 0;
}