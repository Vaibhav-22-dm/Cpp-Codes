#include <bits/stdc++.h>
using namespace std;

void printN(int N){
    if(N==0) return;
    printN(N-1);
    cout << N << " ";
    return;
}

int main(){
    int n;
    cin >> n;
    printN(n);

    return 0;
}