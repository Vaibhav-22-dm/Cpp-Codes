#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        if(arr.size()==0&&sum!=0) return false;
        if(sum<0) return false;
        if(sum==0) return true;
        int t = arr[arr.size()-1];
        cout << "t: " << t << endl;
        arr.pop_back();
        bool b = sum-t>=0?isSubsetSum(arr, sum-t):false;
        bool a = isSubsetSum(arr, sum);
        return a||b;
    } 

bool isSubsetSumTopDown(vector<int>arr, int sum){
    
    int dp[arr.size()+1][sum+1];
    for(int i=0;i<arr.size()+1;i++){
        for(int j = 0; j < sum+1; j++){
            if(i==0&&j>0) dp[i][j] = false;
            else if(i==0&&j==0) dp[i][j] = true;
            else if(j==0) dp[i][j] = arr[i-1]==j?true:false;
            else if(arr[i-1]<=j) dp[i][j] = (j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false)||dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[arr.size()][sum];
}

int main(){
    vector<int> a = {1,6,5,11};

    cout << isSubsetSumTopDown(a, 11) << endl;

    return 0;
}