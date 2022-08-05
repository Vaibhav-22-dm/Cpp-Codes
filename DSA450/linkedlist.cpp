#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void PrintLinkedList(Node *head);
void InsertNodeat1(Node** head, int data);
void InsertNodeatn(Node** head, int data, int n);
void deleteNodeatn(Node** head, int n);
void reverseLinkedList(Node** head);
void reverseLinkedList1(Node* head);
void PrintLinkedListRecursively(Node* head);
void PrintLinkedListReversedRecursively(Node* head);
void reverseLinkedListRecursively(Node** head, Node* prev);

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

    InsertNodeat1(&head, 41);
    cout << "Linked list after inserting 41 at 1st position: ";
    PrintLinkedList(head);
    cout << "\n";

    InsertNodeatn(&head, 80, 3);
    cout << "Linked list after inserting 80 at 3rd position: ";
    PrintLinkedList(head);
    cout << "\n";

    deleteNodeatn(&head, 2);
    cout << "Linked list after deleting node at 2nd position: ";
    PrintLinkedList(head);
    cout << "\n";

    reverseLinkedList1(head);
    cout << "Linked list after reversing: ";
    PrintLinkedList(head);
    cout << "\n";

    cout << "Linked list printed using recursion: ";
    PrintLinkedListRecursively(head);
    cout << "\n";

    cout << "Linked list printed reversed using recursion: ";
    PrintLinkedListReversedRecursively(head);
    cout << "\n";

    reverseLinkedListRecursively(&head, head);
    cout << "Linked list reversed using recursion: ";
    PrintLinkedList(head);
    cout << "\n";

    return 0;
}

void PrintLinkedList(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void InsertNodeat1(Node** head, int data){
    Node* temp = new Node;
    temp->data = data;
    if((*head)->next==NULL){
        temp->next = *head;
        *head = temp;
        return;
    }
    temp->next = (*head)->next;
    *head = temp;
}


void InsertNodeatn(Node** head, int data, int n){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(n==1){
        temp->next = (*head)->next;
        *head = temp;
        return;
    }
    Node* temp1 = *head;
    for(int i = 0; i < n - 2; i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteNodeatn(Node** head, int n){
    Node* temp1 = *head;
    if(n == 1){
        *head = temp1->next; 
        free(temp1);
        return;
    }
    for(int i = 0; i < n - 2; i++){
        temp1 = temp1->next;
    }
    Node *temp = temp1->next;
    temp1->next = temp->next;
    free(temp);
}

void reverseLinkedList(Node** head){
    Node* temp1 = *head;
    Node* prev = NULL;  
    while(temp1!=NULL){
        Node* temp = temp1->next;
        temp1->next = prev;
        prev = temp1;
        temp1 = temp;
    }
    *head = prev;
}

struct Node* reverseList1(struct Node *head)
    {
        // code here
        
        struct Node* prev = NULL;
        while(head->next!=NULL){
            struct Node* temp = head;
            head=head->next;
            temp->next=prev;
            prev=temp;
        }
        head->next=prev;
        return head;
        // return head of reversed list
    }

void PrintLinkedListRecursively(Node* head){
    if(head->next==NULL){
        cout << head->data;
        return;
    }
    cout << head->data << " ";
    PrintLinkedListRecursively(head->next);
    return;
}


void PrintLinkedListReversedRecursively(Node* head){
    if(head->next==NULL){
        cout << head->data << " ";
        return;
    }
    PrintLinkedListReversedRecursively(head->next);
    cout << head->data << " ";
    return;
}

void reverseLinkedListRecursively(Node** head, Node* prev){
    if(prev->next==NULL){
        (*head) = prev;
        return;
    }
    reverseLinkedListRecursively(head, (prev->next));
    prev->next->next = prev;
    prev->next = NULL;
    return;
}