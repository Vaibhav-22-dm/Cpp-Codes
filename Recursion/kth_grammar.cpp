#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k){
    if(n==1) return 0;
    int a = kthGrammar(n-1, (k+1)/2);
    if(a==0&&k%2==0 || a==1&&k%2==1) return 1;
    else return 0;
}

int kthGrammar1(int n, int k){
    if(n==1||k==1) return 0;
    return k<=exp2(n-2)?kthGrammar1(n-1, k):!kthGrammar1(n-1, k-exp2(n-2));
}

int main(){
    int n, k;
    cout << "n k: ";
    cin >> n >> k;
    cout << kthGrammar1(n, k);

    return 0;
}