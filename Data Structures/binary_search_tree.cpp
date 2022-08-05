#include <bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};

void Insert(BSTNode** root, int data);
bool Search(BSTNode** root, int data);

int main(){
    BSTNode* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);
    cout << Search(&root, 10) << "\n";
    cout << Search(&root, 16) << "\n";
    cout << Search(&root, 25) << "\n";

    return 0;
}

void Insert(BSTNode** root, int data){
    BSTNode* temp = new BSTNode;
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

bool Search(BSTNode** root, int data){
    if((*root)==NULL) return false;
    else if((*root)->data == data) return true;
    else if(data <= (*root)->data) Search(&((*root)->left), data);
    else return Search(&((*root)->right), data);

}