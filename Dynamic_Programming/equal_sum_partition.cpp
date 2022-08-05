#include <bits/stdc++.h>
using namespace std;

bool equalPartition(vector<int>arr){
    long long sum = 0;
    for(auto i: arr) sum+=i;
    if(sum%2==1) return false;
    int dp[arr.size()+1][sum/2+1];
    for(int i=0;i<arr.size()+1;i++){
        for(int j = 0; j < sum/2+1; j++){
            if(i==0&&j>0) dp[i][j] = false;
            else if(i==0&&j==0) dp[i][j] = true;
            else if(j==0) dp[i][j] = arr[i-1]==j?true:false;
            else if(arr[i-1]<=j) dp[i][j] = (j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false)||dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[arr.size()][sum/2];
}

int main(){
    vector<int> a = {1,3,2,7,8,10,5};

    cout << equalPartition(a) << endl;

    return 0;
}