#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void PrintDoublyLinkedList(Node* head);
void insertNodeat1(Node** head, int data);
void PrintDoublyLinkedListReversed(Node* head);

int main(){
    Node* head;
    int n;
    cin >> n;
    Node *tail = NULL;
    for(int i = 0; i < n;i++){
        Node* temp = new Node; 
        if(i==0){
            head = temp;
        } 
        else{
            tail->next = temp;
        }
        temp->prev = tail;
        temp->next = NULL;
        cin >> temp->data;
        tail = temp;
    }

    cout << "Doubly Linked list is as follows: ";
    PrintDoublyLinkedList(head);
    cout << "\n";

    insertNodeat1(&head, 99);
    cout << "Doubly Linked list after inserting a number at 1st position is as follows: ";
    PrintDoublyLinkedList(head);
    cout << "\n";

    
    cout << "Doubly Linked list in reversed order is as follows: ";
    PrintDoublyLinkedListReversed(head);
    cout << "\n";

    return 0;
}

void PrintDoublyLinkedList(Node* head){
    Node* temp = head; 
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void PrintDoublyLinkedListReversed(Node* head){
    Node* temp = head; 
    if(temp==NULL) return;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    return;
}

void insertNodeat1(Node** head, int data){
    Node* temp = new Node;
    temp->data = data; 
    temp->prev = NULL;
    temp->next = *head;
    if((*head)==NULL){
        *head = temp;
        return;
    } 

    (*head)->prev = temp;
    (*head) = temp;
    return;
}