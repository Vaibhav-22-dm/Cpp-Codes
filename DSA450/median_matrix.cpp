#include <bits/stdc++.h>
using namespace std;

void print(int a[], int n);

int main(){
    vector<vector<int>> matrix = {{1,3,5},{2,6,9},{3,6,9}};

    int m = matrix.size();
    int n = matrix[0].size();
    int arr[m*n];
    for(int i = 0; i < n; i++) arr[i] = matrix[0][i];
    for(int i = 1; i < m; i++){
        int arr1[n];
        for(int j = 0; j < n; j++) arr1[j] = matrix[i][j];
        print(arr1, n);
        int arr2[n*i];
        for(int j = 0; j < n*i; j++) arr2[j] = arr[j];
        print(arr2, n*i);
        int arr3[n*(i+1)];
        merge(arr2, (arr2+n*i), arr1, (arr1+n), arr3);
        print(arr3, n*(i+1));
        for(int j = 0; j < n*(i+1); j++) arr[j] = arr3[j];
    }
    for(int i = 0; i < m*n; i++) cout << arr[i] << " ";
    cout << "\n" << arr[m*n/2];
    return 0;
}

void print(int a[], int l){
    for(int i = 0; i < l; i++) cout << a[i] << " ";
    cout << endl;
}