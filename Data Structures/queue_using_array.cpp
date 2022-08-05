#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 101

class Queue{
    private:
        int A[MAX_SIZE];
        int front, rear;
    public:
        Queue(){
            front = -1;
            rear = -1; 
        }

        bool isempty(){
            return(front == -1 && rear == -1);
        }

        bool isfull(){
            return (rear+1)%MAX_SIZE == front ? true : false;
        }

        void enqueue(int x){
            cout << "Enqueuing " << x << "\n";
            if(isfull()){
                cout << "Error: Queue is Full\n";
                return;
            }
            if(isempty()){
                front = rear = 0;
            }
            else{
                rear = (rear+1)%MAX_SIZE;
            }
            A[rear] = x;
        }

        void dequeue(){
            cout << "Dequeuing \n";
            if(isempty()){
                cout << "Error: Queue is empty\n";
                return;
            }
            else if(front == rear){
                rear = front = -1;
            }
            else {
                front = (front+1)%MAX_SIZE;
            }
        }

        int Front(){
            if(front == -1){
                cout << "Error: cannot return front from empty queue\n";
                return -1;
            }
            return A[front];
        }

        void print(){
            int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
            cout << "Queue      :";
            for(int i = 0; i < count; i++){
                int index = (front+i)%MAX_SIZE;
                cout << A[index]<<" ";
            }
            cout << "\n\n";
        }
};





int main(){
    Queue Q; // creating an instance of Queue. 
    Q.enqueue(2);  Q.print();  
    Q.enqueue(4);  Q.print();  
    Q.enqueue(6);  Q.print();
    Q.dequeue();   Q.print();
    Q.enqueue(8);  Q.print();


    return 0;
}