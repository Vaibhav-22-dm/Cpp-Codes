#include <bits/stdc++.h>
using namespace std;

void printSubsets(string S){
    string s = S.substr(1, S.length());
    printSubsets(s);
    cout << s << endl;
    s = S.substr(0, S.length());
    return;
}

int main(){
    string S = "abcd";

    return 0;
}