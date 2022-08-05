#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string S);

int main(){
    string S = "abba";
    cout << isPalindrome(S);
}

int isPalindrome(string S)
{
    // Your code goes here
    int l = S.size();
    for(int i = 0; i < l/2; i++){
        if(S[i]!=S[l-1-i]) return 0;
    }
    return 1;
}