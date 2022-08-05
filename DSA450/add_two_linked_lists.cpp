// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int solve(struct Node* head, long long int* i){
        if(head->next==NULL){
            *i = head->data;
            return 1;
        }
        else{
            int j = solve(head->next, i);
            *i = (head->data)*pow(10,j) + *i;
            return j+1;
        }
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        long long int a = 0;
        long long int b = 0;
        int i = solve(first, &a);
        cout << "i: " << i << endl;
        cout << "a: " << a << endl;
        int j = solve(second, &b);
        cout << "j: " << j << endl;
        cout << "b: " << b << endl;
        
        long long int s = a+b;
        cout << "s: " << s << endl;
        int k = max(i,j)-1;
        cout << "k: " << k << endl;
        long long int r = pow(10,k+1);
        cout << "r: " << r << endl;
        if(s>=r) k++;
        cout << "k: " << k << endl;
        Node* head = NULL;
        Node* prev = NULL;
        while(k>=0){
            if(prev!=NULL) cout << "prev: " << prev->data << endl;
            int p = pow(10,k);
            cout << "p: " << p << endl;
            int t = s/p;
            cout << "t: " << t << endl;
            s = s- t*p;
            cout << "s: " << s << endl;
            k--;
            cout << "k: " << k << endl;
            Node* temp = new Node(t);
            if(head==NULL){
                head = temp;
                cout << "head: " << head->data << endl;
            } 
            else{
                prev->next = temp;
                cout << "prev1: " << prev->data << endl;
            } 
            prev = temp;
            cout << "prev2: " << prev->data << endl;
        }
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends