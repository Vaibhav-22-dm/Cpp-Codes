#include <bits/stdc++.h>
using namespace std;

stack<int> insert(stack<int> s, int a){
    if(s.size()==0||s.top()>a) s.push(a);
    else{
        int temp = s.top();
        s.pop();
        s = insert(s, a);
        s.push(temp);
    }
    return s;
}

stack<int> sort(stack<int> s){
    if(s.size()==1) return s;
    int temp = s.top();
    s.pop();
    s = sort(s);
    s = insert(s, temp);
    return s;
}

int main(){

    stack<int> s;
    s.push(2);
    s.push(7);
    s.push(5);
    s.push(0);
    s.push(4);
    s = sort(s);
    while(s.size()>0){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}