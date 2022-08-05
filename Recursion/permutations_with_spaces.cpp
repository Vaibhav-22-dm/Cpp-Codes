#include <bits/stdc++.h>
using namespace std;

void printPermutationsWithSpaces(int size, string o, int n){
    if(n==1) cout << o << endl;
    else{
        printPermutationsWithSpaces(size, o, n-1);
        printPermutationsWithSpaces(size, o.insert(o.size()-n + 1, " "), n-1);
    }
    return;
}

void printPermutationsWithSpaces1(string i, string o){
    if(i.size()==0) cout << o << endl;
    else{
        string s(1, i[0]);
        printPermutationsWithSpaces1(i.substr(1, i.size()-1), o + s);
        printPermutationsWithSpaces1(i.substr(1, i.size()-1), o.append(" "+ s));
    }
    return;
}

int main(){
    string S = "ABCDE";
    string s(1, S[0]);
    printPermutationsWithSpaces1(S.substr(1, S.size()-1), s);
    return 0;
}