#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }  
};

int heightOfTree(Node* root){
    if(root == NULL) return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

int main(){
    Node* root = new Node(1);
 
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->left->right = new Node(6);
    cout << heightOfTree(root) << endl;
}