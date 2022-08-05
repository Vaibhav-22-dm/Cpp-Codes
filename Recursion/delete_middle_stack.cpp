#include <bits/stdc++.h>
using namespace std;

int deleteMiddle(stack <int>& s, int size){
    if(s.size()==1) return 1;
    int temp = s.top();
    s.pop();
    int n = deleteMiddle(s, size);
    if(n==size/2) return -1;
    s.push(temp);
    if(n!=-1) return n + 1;
    else return -1;
}

void deleteMiddleEfficiently(stack <int>& s, int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMiddleEfficiently(s,k-1);
    s.push(temp);
    return;
}

int main(){
    stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    deleteMiddleEfficiently(s, s.size()/2 + 1);
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}