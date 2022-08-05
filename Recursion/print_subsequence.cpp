#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string s){
    int j = 0;
    while(s.size()>0){
        string s1 = s;
        while(s1.size()>0){
            cout << s1 << endl;
            s1 = s1.substr(0,s1.size()-1);
            j++;
        }
        s = s.substr(1,s.size()-1);
    }
    cout << "count: " << j;
    return;
}

int main(){
    string S = "abcdefg"; 
    printSubsequence(S);
    return 0;
}