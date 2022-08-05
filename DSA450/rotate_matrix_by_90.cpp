#include <bits/stdc++.h>
using namespace std;
#define MAX 100


void rotate_by_90(int a[MAX][MAX], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp; 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int temp = a[i][j];
            a[i][j] = a[i][n-i-1];
            a[i][n-i-1] = temp;
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j] = rand()%90+10;
        }
    }
    cout << "Before Rotation: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp; 
        }
    }
    cout << "After 90 Rotation: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            int temp = m[i][j];
            m[i][j] = m[i][n-j-1];
            m[i][n-j-1] = temp;
        }
    }
    cout << "After -90 Rotation: " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}