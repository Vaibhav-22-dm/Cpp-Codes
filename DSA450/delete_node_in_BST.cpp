#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;    
    TreeNode* left;
    TreeNode* right;   
};

void Insert(TreeNode** root, char val);
TreeNode* FindMin(TreeNode* root);
TreeNode* Delete(TreeNode* root, int val);
void LevelOrder(TreeNode* root);

int main(){
    TreeNode* root = NULL; //to store address of root node & setting tree as empty
    
    // Insert(&root, 12);
    Insert(&root, 5);
    // Insert(&root, 15);
    Insert(&root, 3);
    Insert(&root, 6);
    Insert(&root, 2);
    Insert(&root, 4);
    Insert(&root, 7);
    // Insert(&root, 13);
    // Insert(&root, 17);
    // Insert(&root, 1);
    // Insert(&root, 9);

    LevelOrder(root);
    cout << "\n";

    root = Delete(root, 3);

    LevelOrder(root);
    cout << "\n";
    return 0;
}

void Insert(TreeNode** root, char val){
    TreeNode* temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    if(*root==NULL){
        *root = temp;
    }
    else if(val <= (*root)->val){
        Insert(&((*root)->left), val);
    }
    else{
        Insert(&((*root)->right), val);
    }
    return;
}


void LevelOrder(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode* current = Q.front();
        cout << current->val << " ";
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }

    return;
}

TreeNode* Delete(TreeNode* root, int key){
    TreeNode* temp = root;
    TreeNode* last;
    
    //Searching for key
    while(temp!=NULL){
        if(temp->val==key) break;
        else if(temp->val>key){
            last = temp;
            temp=temp->left;
        } 
        else {    
            last = temp;
            temp = temp->right;
        }
    }

    //If no key found return root
    if(temp==NULL) return root;

    cout << "temp->val: " << temp->val << " last->val: " << last->val<< endl;

    // If key found 3 cases are possible: 

    TreeNode* temp1 = temp;

    //key node has right subtree
    if(temp->right!=NULL){
        temp1 = temp->right;
        TreeNode* prev = NULL;

        //Finding minimum val node in right subtree of keynode
        while(temp1->left!=NULL){
            prev = temp1;
            temp1=temp1->left;
        } 
        cout << "temp1->val: " << temp1->val << endl;

        //if right node of keynode is not the minimum itself
        if(prev!=NULL) {
            prev->left = NULL; //Pointing left of the node previous to the minimum node to NULL
            temp1->right = temp->right; //Pointing right of minimum node to right of key node
        }
        temp1->left = temp->left; //Pointing left of minimum node to left of key node

        //If key node is left node of its parent
        if(last->val>temp->val){
            cout << "2" << endl;
            last->left = temp1;
        }
        //If key node is right node of its parent
        else last->right = temp1;

        free(temp);
    }

    //key node has no right subtree but has left subtree
    else if(temp->left!=NULL){
        last->left = temp->left;
        free(temp);
    }

    //key node has no right or left subtree
    else{
        //If key node is left node of its parent
        if(last->val>temp->val) last->left = NULL;
        //If key node is right node of its parent
        else last->right = NULL;
        free(temp);
    }
    
    return root;
}