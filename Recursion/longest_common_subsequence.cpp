#include <bits/stdc++.h>
using namespace std;

int solve(string a, string b, int n, int m){
    if(n==0||m==0) return 0;
    else{
        if(a[n-1]==b[m-1]) return 1 + solve(a, b, n-1, m-1);
        else return max(solve(a,b,n-1,m),solve(a,b,n,m-1));
    }
}


int main(){
   string s1 = "abdgjk";
   string s2 = "bgrtomk";
   cout << solve(s1,s2,s1.size(),s2.size());
   return 0;
}