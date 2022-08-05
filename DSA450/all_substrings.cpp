#include <bits/stdc++.h>
using namespace std;

void printSubStrings(string a, int low, int high){
    for(int i=low;i<high;i++){
        for(int j=i;j<high;j++){
            cout << a.substr(i,j-i+1) << endl;
        }
    }
    return;
}

int main(){
    // char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    //                       'h', 'i', 'j', 'k', 'l', 'm', 'n',
    //                       'o', 'p', 'q', 'r', 's', 't', 'u',
    //                       'v', 'w', 'x', 'y', 'z' };
 
    string a = "aabc";
    // for (int i = 0; i < 10; i++)
    //     a = a + alphabet[rand() % 26];
    cout << a << endl;
    printSubStrings(a, 0, 4);
    return 0;
}