#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;
};

void PreOrder(Node* root);
void InOrder(Node* root);
void PostOrder(Node* root);
void Insert(Node** root, char data);

int main(){
    Node* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 'A');
    Insert(&root, 'B');
    Insert(&root, 'C');
    Insert(&root, 'D');
    Insert(&root, 'E');
    Insert(&root, 'F');
    Insert(&root, 'G');
    Insert(&root, 'H');
    Insert(&root, 'I');
    Insert(&root, 'J');
    Insert(&root, 'K');

    cout << "PreOrder: ";
    PreOrder(root);
    cout << "\nInOrder: ";
    InOrder(root);
    cout << "\nPostOrder: ";
    PostOrder(root);

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

void PreOrder(Node* root){
    if(root==NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
    return;
}

void InOrder(Node* root){
    if(root==NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
    return;
}

void PostOrder(Node* root){
    if(root==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
    return;
}