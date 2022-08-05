#include <bits/stdc++.h>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};

void Insert(BSTNode** root, int data);
int FindHeight(BSTNode *root);
int height(struct BSTNode* node);

int main(){
    BSTNode* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 15);
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 25);
    Insert(&root, 8);
    Insert(&root, 12);

    cout << "Height: " << height(root) << endl;

    return 0;
}

int height(struct BSTNode* node)
{
    //code here
    if(node==NULL) return 0;
    int h1 = node->left!=NULL?height(node->left):0;
    int h2 = node->right!=NULL?height(node->right):0;
    return h1>h2?(h1+1):(h2+1);
}

int FindHeight(BSTNode *root){
    if(root == NULL){
        return -1;
    }
    return max(FindHeight(root->left),FindHeight(root->right)) + 1;
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