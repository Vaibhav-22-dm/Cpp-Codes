#include <bits/stdc++.h>
using namespace std;

// class Stack{
//     private:
//         char A[101];
//         int top;

//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool IsEmpty();
// };

void Reverse(string* S, int n);

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << &s << endl;
    cout << (s[1]) << endl;
    cout << &(s[1]) << endl;
    Reverse(&s, s.size());
    cout << s;
    return 0;
}

void Reverse(string* S, int n){
    cout << S <<endl;
    cout << *S <<endl;
    cout << (*S)[0] <<endl;
    stack<char> C;
    for(int i = 0; i < n; i++){
        C.push((*S)[i]);
    }

    for(int i = 0; i < n; i++){
        (*S)[i] = C.top();
        C.pop();
    }
}