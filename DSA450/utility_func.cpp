#include <bits/stdc++.h>
using namespace std;

int findLargestSmallerThanK(vector<int> a, int k){
    int h = a.size()-1;
    int l = 0;
    int mid = -1;
    while(l<=h){
        mid = l + (h-l)/2;
        if(a[mid]>k){
            h=mid-1;
        }
        else if(a[mid]<k){
            l=mid+1;
        }
        else return mid;
    }
    if(mid!=-1&&a[mid]>k) return mid-1;
    return mid;
}

int main(){
    vector<int> a{2,4,7,9,10};
    cout << findLargestSmallerThanK(a, 5) << endl;
    return 0;
}