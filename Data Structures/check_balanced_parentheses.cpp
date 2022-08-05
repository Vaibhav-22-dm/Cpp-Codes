#include <bits/stdc++.h>
using namespace std;

void checkBalancedParentheses(string s);

int main(){
    string s;
    cout << "Enter a string of parentheses, brackets and curly braces: ";
    cin >> s;
    checkBalancedParentheses(s);
    return 0;
}

void checkBalancedParentheses(string s){
    int n = s.length();
    stack<char> S; 

    for(int i = 0; i < n;i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(') S.push(s[i]);
        else if((S.top() == '(' && s[i] ==')') || (S.top() == '[' && s[i] == ']') || (S.top() == '{' && s[i] == '}')) S.pop();
        else break;
    }

    if(S.empty()) cout << "Balanced!" << endl;
    else cout << "unbalanced!" << endl;
    
    return;        
}