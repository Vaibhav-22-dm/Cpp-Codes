#include <bits/stdc++.h>
using namespace std;

long long int factorial(int N){
    if(N==0||N==1) return 1;
    return (1ll)*N*factorial(N-1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n) << endl;

    return 0;
}