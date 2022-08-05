#include <bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};

int FindMin(BSTNode* root);
int FindMax(BSTNode* root);
int FindMinRecursive(BSTNode* root);
int FindMaxRecursive(BSTNode* root);
void Insert(BSTNode** root, int data);

int main(){
    BSTNode* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);

    cout << "Min(iterative): " << FindMin(root) << endl;
    cout << "Max(iterative): " << FindMax(root) << endl;
    cout << "Min(Recursive): " << FindMinRecursive(root) << endl;
    cout << "Max(Recursive): " << FindMaxRecursive(root) << endl;

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

int FindMin(BSTNode* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
    }

    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;

}

int FindMax(BSTNode* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
    }

    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;

}

int FindMinRecursive(BSTNode* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
    }

    else if(root->left==NULL){
        return root->data;
    }
    return FindMinRecursive(root->left);

}

int FindMaxRecursive(BSTNode* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
    }

    else if(root->right==NULL){
        return root->data;
    }
    return FindMaxRecursive(root->right);

}