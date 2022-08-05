#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& s, int n, int m, string o){
    if(n==0) s.push_back(o);
    else{
        if(m>o.size()/2){
            o.push_back('0');
            solve(s, n-1, m, o);
            o.pop_back();
        }
        o.push_back('1');
        solve(s, n-1, m+1, o);
    }
    return;
}

vector<string> NBitBinary(int N){
    vector<string> s;
    solve(s, N, 0, "");
    for(int i=0;i<s.size();i++) cout << s[i] << endl;
    return s;
}


int main(){
    int n;
    cout << "n: ";
    cin >> n;
    vector<string> s = NBitBinary(n);

    return 0;
}