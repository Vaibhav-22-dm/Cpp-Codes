#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& l, int i, int k){
    if(l.size()==1) return;
    int t = (i+k)%l.size();
    l.erase(l.begin() + t);
    solve(l, t, k);
    return;
}

int safePos(int n, int k) {
    vector<int> l;
    int N = 0;
    while(N<n) l.push_back(++N);
    solve(l, 0, k-1);
    return *l.begin();
}

int main(){

    int n;
    cin >> n;
    cout << safePos(n, 7);

    return 0;
}