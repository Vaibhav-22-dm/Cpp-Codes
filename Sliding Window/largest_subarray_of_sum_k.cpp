#include <bits/stdc++.h>
using namespace std;
//Approach only for arrays with only non negative numbers
int max_subarray(vector<int> a, int k){
    int sum = 0;
    int i = 0;
    int j = 0;
    int max = 0;
    while(j<a.size()){
        sum += a[j];
        if(sum>k) while(sum>k) sum-=a[i++];
        if(sum==k){
            max = j-i+1>max?j-i+1:max;
            cout << "j: " << j << " i: " << i << endl;
        } 
        j++;
    }
    return max;
}

int main(){
    int n;
    vector<int> a = {4,1,0,0,0,0,1,1,2,3,5};
    int k;
    k = 5;
    cout << max_subarray(a,k) << endl;

    return 0;
}