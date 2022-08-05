#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

bool IsSubtreeLesser(Node* root, int value);
bool IsSubtreeGreater(Node* root, int value);
bool IsBinarySearchTree(Node* root);
bool IsBinarySearchTree_new(Node* root, int min, int max);
void Insert(Node** root, char data);

int main(){
    Node* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);

    cout << "Non Efficient Check: " << IsBinarySearchTree(root) << endl;
    cout << "Efficient Check: "  << IsBinarySearchTree_new(root, 1e-9, 1e9);
    return 0;
}

void Insert(Node** root, char data){
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    if(*root==NULL){
        *root = temp;
    }
    else if(data <= (*root)->data){
        Insert(&((*root)->left), data);
    }
    else{
        Insert(&((*root)->right), data);
    }
    return;
}

bool IsSubtreeLesser(Node* root, int value){
    if(root == NULL) return true;
    if(
        root->data <= value &&
        IsSubtreeLesser(root->left, value) &&
        IsSubtreeLesser(root->right, value)
    ) 
        return true;
    else 
        return false;

}

bool IsSubtreeGreater(Node* root, int value){
    if(root == NULL) return true;
    if(
        root->data >= value &&
        IsSubtreeGreater(root->left, value) &&
        IsSubtreeGreater(root->right, value)
    ) 
        return true;
    else 
        return false;

}

bool IsBinarySearchTree(Node* root){
    if(root == NULL) return true; 
    if(
        IsSubtreeLesser(root->left, root->data) &&
        IsSubtreeGreater(root->right, root->data) &&
        IsBinarySearchTree(root->left) &&
        IsBinarySearchTree(root->right)
    ) 
        return true;
    else 
        return false;
}

bool IsBinarySearchTree_new(Node* root, int min, int max){
    if(root == NULL) return true;
    if(
        root->data > min &&
        root->data < max &&
        IsBinarySearchTree_new(root->left, min, root->data) &&
        IsBinarySearchTree_new(root->right, root->data, max)
    ) 
        return true;
    else 
        return false;
}