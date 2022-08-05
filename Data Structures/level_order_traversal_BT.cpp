#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data; 
    Node* left;
    Node* right; 
};

void Insert(Node** root, char data);

void LevelOrder(Node* root);

int main(){

    Node* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 'E');
    Insert(&root, 'G');
    Insert(&root, 'C');
    Insert(&root, 'D');
    Insert(&root, 'F');
    Insert(&root, 'H');
    Insert(&root, 'A');
//              E
//            /   \
//          C       G
//         / \     / \
//        A   D   F   H

    LevelOrder(root);


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

void LevelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty()){
        Node* current = Q.front();
        cout << current->data << " ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }

    return;
}