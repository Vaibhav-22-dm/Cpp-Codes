#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* top =  NULL;

void Push(int x);
void Pop();
void Print();

int main(){
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    return 0;
}

void Push(int x){
    Node* temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    return;
}

void Pop(){
    Node* temp = new Node;
    if(top == NULL) return;
    temp = top;
    top = top->next;
    free(temp);
    return;
}

void Print(){
    Node* temp = top;
    printf("Stack: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}