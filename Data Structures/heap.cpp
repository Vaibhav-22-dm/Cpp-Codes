#include <bits/stdc++.h>
using namespace std;
#define MAX 200

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

void insert(int a[MAX], int& size, int x){
    a[size+1] = x;
    int parent = (size+1)/2;
    int i = size+1;
    while(parent>0){
        if(a[i]>a[parent]) swap(a, i, parent);
        else break;
        i = parent;
        parent = i/2;
    }
    size++;
    return;
}

void deleteNode(int a[], int& size){
    a[1] = a[size];
    int i = 1;
    int larger = a[2]>a[3]?2:3; 
    while(larger<size){
        if(a[larger]>a[i]){
            swap(a, i, larger);
            i = larger;
        } 
        else return;
        larger = a[2*larger]>a[2*larger+1]?2*larger:2*larger+1;
    } 
    size--;
    return;
}

void print(int arr[], int size){
    cout << "Array with size "<< size << ": ";
    for(int i=1;i<=size;i++) cout << arr[i] << " ";
    cout << endl;
}

void heapify(int arr[], int size, int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;
    if(l<size&&arr[largest]<arr[l]) largest = l;
    if(r<size&&arr[largest]<arr[r]) largest = r;
    if(largest!=i){
        swap(arr, i, largest);
        heapify(arr,size,largest);
    }

}

void buildHeap(int a[], int size){
    for(int i=size/2;i>0;i--){
        heapify(a, size, i);
    }
    return;
}

int main(){
    //Heap  is a complete binary tree based data structure. 
    //Complete binary tree satisfies the propert thar each node has 2 children or 1 left child or no child.
    //Heaps are of two types - 
    //1) Min Heap - Every root element is smaller than its children elements.
    //2) Max Heap - Every root element is larger than its children elements.
    //Heap data structure is implemented using an array.
    //Formulae - (index(current) = i) ... i starts from 1
    //  1. index(parent) = i/2
    //  2. index(left child) = 2*i
    //  3. index(right child) = 2*i + 1
    int arr[100];
    int size = 0;
    insert(arr,size,40);
    print(arr,size);
    insert(arr,size,30);
    print(arr,size);
    insert(arr,size,10);
    print(arr,size);
    insert(arr,size,20);
    print(arr,size);
    insert(arr,size,15);
    print(arr,size);
    insert(arr,size,45);
    print(arr,size);
    insert(arr,size,25);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);
    deleteNode(arr,size);
    print(arr,size);

    int a[7] = {0,50,30,40,5,10,20};
    buildHeap(a,7);
    print(a, 6);

    return 0;
}