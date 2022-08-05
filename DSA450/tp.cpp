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
struct Node* reverseList1(struct Node *head);
void PrintLinkedListRecursively(Node* head);
void PrintLinkedListReversedRecursively(Node* head);
void reverseLinkedListRecursively(Node** head, Node* prev);
Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* temp = head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        cout << "Entered !" << endl;
        if(prev!=NULL&&prev->data==temp->data){
            Node* temp1 = temp;
            temp = temp->next;
            free(temp1);
            prev->next=temp;
        }
        else{
            prev=temp;
            temp=temp->next;
        } 
        
    }
    if(prev!=NULL&&temp->data==prev->data){
        cout << "Entered !" << endl;
        free(temp);
        prev->next = NULL;
    }
    return head;
}
struct Node *reverse (struct Node *head, int k)
    { 
        // Complete this method
        struct Node* temp = head;
        struct Node* temp2 = temp;
        struct Node* temp3 = NULL;
        int cnt = 0;
        int flag = 1; 
        if(k==1) return head;
        while(flag){
            int i = 0; 
            struct Node* prev = NULL;
            if(cnt%2==0) temp2 = temp;
            if(cnt%2==1) temp3 = temp;
            while(i<k&&temp->next!=NULL){
                struct Node* temp1 = temp->next;
                temp->next = prev;
                prev = temp;
                temp = temp1;
                i++;
            }
            if(temp->next==NULL){
                flag = 0;
                if(cnt==0&&k==1){
                    prev->next=temp;
                    return head;
                }
                else if(i==k){
                    if(cnt==0) head=prev;
                    else{
                        if(cnt%2==1) temp2->next = prev;
                        if(cnt%2==0&&temp3!=NULL) temp3->next = prev;
                    }
                    cnt++;
                    cout << "Entered: " << cnt << endl;
                    cout << "temp: " << temp->data << endl;
                    cout << "prev: " << prev->data << endl;
                    cout << "temp2: " << temp2->data << endl;
                    cout << "temp3: " << ((temp3!=NULL)?temp3->data:NULL) << endl;
                    if(cnt%2==1){
                         temp2->next = temp;
                         cout << "temp2->next->data: " << temp2->next->data << endl;
                    }
                    if(cnt%2==0&&temp3!=NULL){
                        temp3->next = temp;
                        cout << "temp3->next->data: " << temp3->next->data << endl;
                    } 
                    cout << "head: " << head->data << endl;
                    return head;
                };
                
                temp->next = prev;
                prev=temp;
            }
            if(cnt==0){
              head = prev;
            }
            if(cnt%2==1) temp2->next = prev;
            if(cnt%2==0&&temp3!=NULL) temp3->next = prev;
            cnt++;
        }
        return head;
    }

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
    head = removeDuplicates(head);
    PrintLinkedList(head);
    cout << "\n";
    head = reverse(head, 2);
    cout << "Linked list after reversing by 6: ";
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
    cout << "Linked list after deleting Node at 2nd position: ";
    PrintLinkedList(head);
    cout << "\n";

    head = reverseList1(head);
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