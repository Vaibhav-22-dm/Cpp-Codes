#include <bits/stdc++.h>
using namespace std;

string longestSubstringWithKUniqueCharacters(string s, int k){
    string S;
    int max = -1;
    int i = 0;
    int j = 0;
    map<char, int> m;
    int count = 0;
    while(j<s.size()){
        cout << "s[" << j << "]: " << s[j] << endl;
        if(m.count(s[j])==0){
            m[s[j]] = 1;
            count++;
        }
        else m[s[j]]++;
        cout << "count: " << count << endl;
        if(count==k){
            cout << "j: " << j << " i: " << i << " S: " << S << " temp: " << s.substr(i, j-i+1) <<endl;
            if(j-i+1>S.size()){
                S = s.substr(i, j-i+1);
                max = j-i+1;
            };
        }
        else if(count>k) {
            cout << "Entered count(" <<count<<")>k("<< k << "): " << endl;
            while(count>k){ 
                cout << "   s["<<i<<"]: " << s[i] << endl;
                if(m.count(s[i])>0){
                    m[s[i]]--;
                } 
                if(m.count(s[i])>0&&m[s[i]]==0){
                    m.erase(s[i]);
                    count--;
                }
                i++;
                for(auto l: m) cout << "    " << l.first << " - " << l.second << " ";
                cout << endl << "   count: " << count<< endl;
            }
        } 
        j++;
    }

    cout << "max: " << max << endl;
    return S;
}

int main(){
    string s = "aaaaa";
    int k = 2;
    cout << longestSubstringWithKUniqueCharacters(s, k) << endl;
    return 0;
}