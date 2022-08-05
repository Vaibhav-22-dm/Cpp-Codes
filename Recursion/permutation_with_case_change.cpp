#include <bits/stdc++.h>
using namespace std;
int j = 0;

void printPermutationsWithCaseChange(string i, string o){
    if(i.size()==0){
        cout << o << endl;
        j++;
    } 
    else{
        o.push_back(i[0]);
        printPermutationsWithCaseChange(i.substr(1, i.size()-1), o);
        o.pop_back();
        o.push_back(tolower(i[0]));
        printPermutationsWithCaseChange(i.substr(1, i.size()-1), o);
    }
    return;
}

int main(){
    string S = "ABCDE";
    printPermutationsWithCaseChange(S, "");
    cout << "\nj: " << j;
    return 0;
}