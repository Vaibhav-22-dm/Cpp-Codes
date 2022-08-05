#include <bits/stdc++.h>
using namespace std;

void partition(int arr[], int n);

int main(){

    int a[9] = {-1,2,3,4,-5,-7,-2,11,-13};
    partition(a,9);
    for(int i = 0; i < 9; i++){
        cout << a[i] << " ";
    }
    return 0;
}

void partition(int arr[], int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(arr[j]<0){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    return;
}