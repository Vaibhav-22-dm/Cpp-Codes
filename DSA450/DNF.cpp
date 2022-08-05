#include <bits/stdc++.h>
using namespace std;

void sort_0_1_2(int arr[], int n);

int main(){

    int a[9] = {1,2,2,0,0,1,0,2,2};
    sort_0_1_2(a,9);
    for(int i = 0; i < 9; i++){
        cout << a[i] << " ";
    }
    return 0;
}

void sort_0_1_2(int arr[], int n){
    int low = 0, mid = 0, high = n - 1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    return;
}