#include <bits/stdc++.h>
using namespace std;

void printSubsets(string i, string o){
    if(i=="") cout << "'" << o << "'" << endl;
    else{
        printSubsets(i.substr(1,i.size()-1), o);
        printSubsets(i.substr(1,i.size()-1), o.append(i.substr(0,1)));
    } 
    return;
}

int main(){
    string S = "abcde";
    printSubsets(S, "");

    return 0;
}