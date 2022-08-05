#include <bits/stdc++.h>
using namespace std;

void print_all_permutations(string i, string o){
    if(i.size()==0) cout << o << endl;
    else{
        int j = i.size()-1;
        while(j>=0){
            string s = "";
            s.append(i);
            s.erase(s.begin()+j);
            string t = o + i[j];
            print_all_permutations(s, t);
            j--;
        }
    }
    return;
}

int main(){
    string s = "ABC";
    print_all_permutations(s, "");

    return 0;
}