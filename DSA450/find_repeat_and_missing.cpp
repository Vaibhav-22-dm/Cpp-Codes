#include <bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) {
        // code here
        int sum = 0;
        int sumo = n*(n+1)/2;
        cout << "sumo: " << sumo << endl;
        vector<int> a(n+1,0);
        int* b = new int(2);
        int d;
        for(int i=0;i<n;i++){
            cout << "i: " << i << endl;
            a[arr[i]]++;
            if(a[arr[i]]>1) d = arr[i];
            sum+=arr[i];
            
        }
        b[0] = d;
        b[1] = (d-(sum-sumo));
        return b;
    }

int main(){
    int arr[5] = {1,2,3,3,5};
    int *b = findTwoElement(arr, 5);
    cout << b[0] << b[1] << endl;
    return 0;
}