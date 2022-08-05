#include <bits/stdc++.h>
using namespace std;
// 1 2 5 7 | 3
int j = 0;

void insert(int a[], int i, int b){
    if(i==-1){
        a[0] = b;
        j++;
        return;
    }
    else if(a[i]<b) {
        a[i+1] = b;
        j++;
        return;
    }

    a[i+1] = a[i];
    insert(a, i-1, b);
    j++;
    return;
}

void sort(int a[], int N){
    if(N==1) return;
    sort(a, N-1);
    insert(a, N-2, a[N-1]);
    return;
}


int main(){

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    sort(a, 10);
    for(int i = 0; i<10; i++) cout << a[i] << " ";
    cout << "\ncount: " << j << endl;

    return 0;
}