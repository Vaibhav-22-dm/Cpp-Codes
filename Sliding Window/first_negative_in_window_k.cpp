#include <bits/stdc++.h>
using namespace std;

void first_negative(int a[], int ws, int size){
    queue<int> negs;
    int i = 0;
    for(int j = 0; j < size; j++){
        if(a[j]<0) negs.push(a[j]);
        if(j==ws-1){ 
            if(negs.size()==0) cout << 0 << " ";
            else cout << negs.front() << " ";
        }
        else if(j>=ws){
            if(a[i]==negs.front()) negs.pop();
            i++;
            if(negs.size()==0) cout << 0 << " ";
            else cout << negs.front() << " ";
        }
        
    }
    return;
}

int main(){
    int ws = 3;
    int a[9] = {12,-1,-7,8,-15,30,13,28,-21};
    first_negative(a, 3, 9);

    return 0;
}