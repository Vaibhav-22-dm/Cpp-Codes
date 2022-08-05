#include <bits/stdc++.h>
using namespace std;

int dp[900][900];

bool solve(string A, string B, int i, int j, vector<int>& v){
    cout << "i: " << i << " j: " << j << endl;
    if(j>=B.size() && i<A.size()) return false;
    else if(j>=B.size() && i>=A.size()) return true;
    if(i>=A.size()){
        if(j<B.size() && v[j]!=0) return false;
        else return true;
    }
    if(j==B.size()-1){
        if(B[j]=='*') return true;
        else if(i==A.size()-1 && (A[i]==B[j]||B[j]=='?')) return true;
        else return false;
    }
    else{
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(B[j]!='*'){
            if(B[j]=='?') ans |= dp[i+1][j+1]!=-1?dp[i+1][j+1]:solve(A,B, i+1,j+1,v);
            else if(A[i]==B[j]) ans |= dp[i+1][j+1]!=-1?dp[i+1][j+1]:solve(A,B,i+1,j+1,v);
            else ans |= false;
        }
        else{
            for(int k=i+1;k<=A.size()-v[j];k++){
                cout << "k: " << k << " v[j]: "<< v[j] << " j: " << j << endl;
                ans |= dp[k][j+1]!=-1?dp[k][j+1]:solve(A,B,k,j+1,v);
            }
        }
        dp[i][j] = ans;
        return ans;
    }
}


int isMatch(const string A, const string B) {
    vector<int> v(B.size(),0);
    for(int i=B.size()-2;i>=0;i--){
        if(B[i+1]!='*') v[i] = v[i+1] + 1;
        else v[i] = v[i+1];
    }
    for(int i:v) cout << i << " ";
    cout << endl;
    for(int i=0;i<A.size()+1;i++){
        for(int j=0;j<B.size()+1;j++){
            dp[i][j] = -1;
        }
    }
    return solve(A,B,0,0,v);
}


int main(){
    string A = "cacab";
    string B = "**bcbbac?ba";
    cout << isMatch(A, B) << endl;
    // cout << sizeof(m) << endl;
    return 0;
}