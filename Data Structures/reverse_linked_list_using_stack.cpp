#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void Reverse(Node** head);
void PrintLinkedList(Node *head);

int main(){
    Node* head;
    int n;
    cin >> n;
    Node* prev;   
    for (int i = 0; i < n;i++){
        Node* temp = new Node();
        cin >> temp->data;
        if(i==0)  head = temp;
        else{
            prev->next=temp;
            temp->next=NULL;
        }
        prev = temp;
    }
    cout << "Linked list: ";
    PrintLinkedList(head);
    cout << "\n";

    Reverse(&head);
    cout << "Reversed Linked list: ";
    PrintLinkedList(head);
    cout << "\n";
    return 0;
}

void Reverse(Node** head){
    stack<Node*> S;
    Node* temp = *head;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();  
    *head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return;

}

void PrintLinkedList(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}