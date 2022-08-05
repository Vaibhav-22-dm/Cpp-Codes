#include <bits/stdc++.h>
using namespace std;

string longestPalin (string S) {
        int mini = 0;
        int maxj = 0; 
        int flagG = 0;
        int cnt = 0;
        for(int i = 0; i < S.size(); i++){
            for(int j = S.size()-1;j>i;j--){
                int flag = 1;
                for(int k = i; k<=i+((j-i)/2); k++){
                    cnt++;
                    if(S[k]!=S[j-k+i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag!=0){
                    flagG = 1;
                    if((j-i)>(maxj-mini)){
                        maxj = j;
                        mini = i;
                    }
                    cout << "j: " << j << ", i: " << i << endl;
                    break;
                }
            }
            if(flagG){
                if((maxj-mini) >= (S.size()-(i+1))){
                    break;
                }
            }
        }
        string strcopy;
        if(flagG){
            cout << "1" << endl;
            strcopy = S.substr(mini, maxj-mini+1);
            cout << "2" << endl;
        }
        else{
            cout << "3" << endl;
            strcopy = S.substr(0, 1);
            cout << "4" << endl;
        }
        cout << "Count: " << cnt << endl;
        return strcopy;
    }

int main(){
    string a = longestPalin("abcdefgg");
    for(int i=0; i<a.size(); i++) cout << a[i] << " ";
    return 0;
}