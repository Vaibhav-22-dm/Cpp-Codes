#include <bits/stdc++.h>
using namespace std;

int max_sum(int a[], int ws, int size){
    int sum = 0;
    int sumi = 0;
    int i = 0;
    for(int j = 0; j < size; j++){
        if(j-i<ws){
            sum+=a[j];
            sumi = sum;
        }
        else{
            sumi = sumi + a[j] - a[i];
            if(sumi>sum) sum = sumi;
            i++;
        }
        
    }
    return sum;
}

int main(){
    int ws = 3;
    int a[7] = {1,4,2,-1,5,3,-4};
    cout << max_sum(a, 1, 7);

    return 0;
}