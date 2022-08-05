#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>& s, int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    insert(s, temp);
    s.push(top);
    return;
}

void reverse(stack<int>& s){
    if(s.size()==1) return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
    return;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverse(s);
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}