/*
Problem Statement -

Let there be N workers and N jobs. 
Any worker can be assigned to perform any job, incurring some cost that may depend on the work-job assignment. 
It is required to perform all jobs by assigning exactly one worker to each job and one job to each worker in such a way that the total cost of the assignment is minimized.

Input Format -

Number of workers and job: N 
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth job. 

Sample Input -

4

[
    9 2 7 8
    6 4 3 7
    5 8 1 8
    7 6 9 4
]

Sample Output -
13


*/

#include <bits/stdc++.h>
using namespace std;


//Recursive -
int findCost(vector<vector<int>> C, int i, vector<bool> vis){
    if(i>=C.size()){ 
        // for(bool k:vis) cout << k << " ";
        // cout << endl;
        return 0;
    }
    int cost = INT_MAX;
    // cout <<"i: " << i << endl;
    for(int j=0;j<vis.size();j++){
        if(!vis[j]){
            // cout << "j: " << j << endl;
            vis[j]=true;
            int x = C[j][i] + findCost(C,i+1,vis);
            // cout << "x: " << x << endl; 
            if(cost>x){ 
                cost = x;
                // cout << "job: " << job << endl;
            }
            vis[j]=false;
        }
    }
    return cost;
}


int findCostBM(vector<vector<int>> C, int i, long long int vis, vector<vector<long long int>> dp){
    if(i>=C.size()){ 
        return 0;
    }
    if(dp[i][vis]!=-1){ 
        return dp[i][vis];
    }
    int cost = INT_MAX;
    for(int j=0;j<C.size();j++){
        if(!(1<<j & vis)){
            vis |= 1<<j;
            int x = C[j][i] + findCostBM(C,i+1,vis,dp);
            if(cost>x){ 
                cost = x;
            }
            vis ^= 1<<j;
        }
    }
    return dp[i][vis] = cost;
}

//Bitmask DP -


int main(){
    vector<vector<int>> C = 
        {
            {9,2,7,8},
            {6,4,3,7},
            {5,8,1,8},
            {7,6,9,4}
        };
    // vector<bool> vis(4,false);
    long long int vis = 0;
    vector<vector<long long int>> dp(C.size(),vector<long long int>((int)pow(2,C.size()),-1));
    cout << findCostBM(C,0,vis,dp) << endl; 

    return 0;
}