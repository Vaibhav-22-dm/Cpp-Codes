#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue{
    private:
        Node* front;
        Node*rear;
    public:
        Queue(){
            front = rear = NULL;
        }

        void enqueue(int x){
            Node* temp = new Node; 
            temp->data = x;
            temp->next = NULL; 
            if(front == NULL && rear == NULL){
                front = rear = temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }

        void dequeue(){
            Node* temp = front;
            if(front == NULL && rear == NULL){
                cout << "Error: Queue is empty\n";
                return;
            }
            if(front==rear){
                front = rear = NULL;
            }
            else{
                front = front->next;
            }
            free(temp);
        }

        int Front(){
            return front->data;
        }

        bool isempty(){
            return(rear == NULL);
        }

        void print(){
            Node* temp = front;
            cout << "Queue: ";
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }

};

int main(){
    Queue Q; // creating an instance of Queue. 
    Q.enqueue(2);  Q.print();  
    Q.enqueue(4);  Q.print();  
    Q.enqueue(6);  Q.print();
    int front = Q.Front();
    cout << "Front: " << front << "\n";
    Q.dequeue();   Q.print();
    Q.enqueue(8);  Q.print();
    return 0;
}