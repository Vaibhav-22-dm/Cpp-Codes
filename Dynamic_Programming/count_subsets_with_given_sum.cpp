#include <bits/stdc++.h>
using namespace std;
int l = 0;

int count_subsets_with_given_sum(int a[], int n, int k){
    if(n==0&&k==0){
        l++;
        return 1;
    } 
    else if(n==0&&k!=0){
        l++;
        return 0;
    } 
    else return ((k>=a[n-1])?count_subsets_with_given_sum(a, n-1, k-a[n-1]):0)+count_subsets_with_given_sum(a, n-1, k);
}

int count_subsets_with_given_sum_top_down(int a[], int n, int k){
    int dp[n+1][k+1];
    dp[0][0] = 1;
    for(int i=1;i<k+1;i++) dp[0][i] = 0;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(a[i-1]<=j) dp[i][j] = dp[i-1][j-a[i-1]]+dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}
 
int main(){
    int a[8] = {2,3,0,0,5,6,8,10};
    cout << count_subsets_with_given_sum_top_down(a, 8, 10) << endl;
    cout << l << endl;

    return 0;
}