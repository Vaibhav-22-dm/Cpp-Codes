#include <bits/stdc++.h>
using namespace std;

int t[100][1002]; //t[n+1][W+1];
int j = 0;
int k = 0;
int l = 0;

int knapsack(int val[], int wt[], int W, int n){
    if(n==0||W==0){
        j++;
        return 0;
    } 
    if(t[n][W]!=-1) {
        j++;
        return t[n][W];
    }
    if(wt[n-1]<=W) {
        j++;
        t[n][W] = max(val[n-1]+knapsack(val, wt, W-wt[n-1], n-1), knapsack(val, wt, W, n-1));
        return t[n][W];
    }
    else{
        j++;
        t[n][W] = knapsack(val, wt, W, n-1);
        return t[n][W];
    }
}

int knapsackWithoutMemoization(int val[], int wt[], int W, int n){
    if(n==0||W==0){
        k++;
        return 0;
    }
    if(wt[n-1]<=W){
        k++;
        return max(val[n-1]+knapsackWithoutMemoization(val, wt, W-wt[n-1], n-1), knapsackWithoutMemoization(val, wt, W, n-1));
    } 
    else{
        k++;
        return knapsackWithoutMemoization(val, wt, W, n-1);
    } 
}

int knapsackTopDown(int val[], int wt[], int W, int n){ 
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j = 0; j < W+1; j++){
            if(i==0||j==0) dp[i][j] = 0;
            else if(wt[i-1]<=j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
            l++;
        }
    }
    return dp[n][W];
}

int main(){
    int val[] = { 120, 100, 60, 90, 50 };
    int wt[] = { 30, 20, 10, 40, 25 };
    int W = 80;
    int n = sizeof(val) / sizeof(val[0]);

    memset(t, -1, sizeof(t));
    cout << "knapsack: " << knapsack(val, wt, W, n) << endl;
    cout << "j: " << j << endl;
    
    cout << "knapsackWithoutMemoization: " << knapsackWithoutMemoization(val, wt, W, n) << endl;
    cout << "k: " << k << endl;

    cout << "knapsackTopDown: " << knapsackTopDown(val, wt, W, n) << endl;
    cout << "l: " << l << endl;

    return 0;
}