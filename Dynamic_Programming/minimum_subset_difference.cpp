#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int size, int sum, int currsum){
    if(size==0) return abs(sum - 2*currsum);
    else{
        int sum1 = abs(solve(arr, size-1, sum, currsum+arr[size-1]));
        int sum2 = abs(solve(arr, size-1, sum, currsum));
        return sum1>sum2?sum2:sum1;
    }
}

int min_subset_sum_diff(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++) sum+=arr[i];
    return solve(arr, size, sum, 0);
}

int min_subset_sum_diff_top_down(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++) sum+=arr[i];
    int diff = sum;
    int dp[size+1][(sum+1)/2];
    for(int i=0;i<size+1;i++){
        for(int j=0;j<(sum+1)/2;j++){
            if(i==0&&j==0) dp[i][j] = 1;
            else if(i==0||j==0){
                dp[i][j] = 0;
            }
            else{
               if(arr[i-1]<=j) dp[i][j] = (dp[i-1][j-arr[i-1]]==1)?1:dp[i-1][j];
               else dp[i][j] = dp[i-1][j];
            }
            if(i==size&&dp[i][j]==1) diff = j;
        }
    }


    return abs(2*diff-sum);
}

int main(){
    int a[4] = {1,4,3,5};
    cout << min_subset_sum_diff_top_down(a, 4);

    return 0;
}