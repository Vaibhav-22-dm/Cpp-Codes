#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;    
    Node* left;
    Node* right;   
};

void Insert(Node** root, char data);
Node* FindMin(Node* root);
Node* Delete(Node* root, int data);
void LevelOrder(Node* root);

int main(){
    Node* root = NULL; //to store address of root node & setting tree as empty
    
    Insert(&root, 12);
    Insert(&root, 5);
    Insert(&root, 15);
    Insert(&root, 3);
    Insert(&root, 7);
    Insert(&root, 13);
    Insert(&root, 17);
    Insert(&root, 1);
    Insert(&root, 9);

    LevelOrder(root);
    cout << "\n";

    root = Delete(root, 15);

    LevelOrder(root);
    cout << "\n";
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


Node* FindMin(Node* root){
    if(root == NULL){
        cout << "Error: Tree is empty\n";
    }

    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root, int data){
    if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
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