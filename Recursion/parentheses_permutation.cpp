#include <bits/stdc++.h>
using namespace std;

void printParenthesesPermutation(string i, string o){
    if(i.size()==0) cout << o << endl;
    else{
        if(i[0]=='('){
            o.push_back(i[0]);
            printParenthesesPermutation(i.substr(1,i.size()-1), o);
            o.pop_back();
        }
        if(o[o.size()-1]=='('||i[0]==')'){
            o.push_back(i[i.size()-1]);
            printParenthesesPermutation(i.substr(0,i.size()-1), o);
        }

    }
    return;
}

void printParenthesesPermutationCorrect(string s, int o, int c){
    if(o==0&&c==0) cout << s << endl;
    else{
        if(o!=0){
            s.push_back('(');
            printParenthesesPermutationCorrect(s,o-1, c);
            s.pop_back();
        }
        if(c>o){
            s.push_back(')');
            printParenthesesPermutationCorrect(s, o, c-1);
        }

    }
    return;
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    string s(2*n, '(');
    for(int i = 0; i < n; i++){
        s[i] = '(';
        s[2*n-i-1] = ')';
    }
    cout << "String: " << s << endl;
    printParenthesesPermutationCorrect("", n, n);
    return 0;
}