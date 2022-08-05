#include <bits/stdc++.h>
using namespace std;

int count_anagrams(string s, string a) {
    map<char, int> m;
    int n = 0;
    for (int i = 0; i < a.size(); i++){
        if(m.count(a[i])==0){
            m[a[i]] = 1;
            n++;
        }
        else m[a[i]] += 1;
    }
    cout << "n: " << n << endl;
    for(auto l : m) cout<<l.first<<" - "<< l.second <<endl;
    cout << endl;

    int k = 0;
    int i = 0;
    for(int j = 0; j < s.size(); j++){
        cout << "n: " << n << " j: " << j << " i: " << i <<endl;
        if(j<a.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) n--;
            }
        }
        if(j==a.size()-1){
            if(n==0) k++;
        }
        else if(j>=a.size()){
            if(m.find(s[i])!=m.end()){
                cout << "s[i]: " << s[i] << endl;
                if(m[s[i]]==0) n++;
                m[s[i]]++;
            }
            i++;
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0) n--;
            }
            if(n==0) k++;
        }
        for(auto l : m) cout<<l.first<<" - "<< l.second <<endl;
        cout << "k: " << k << endl;
        cout << endl;
    }
    return k;
}

int main(){
    string s = "aabbabbacabbabbbbbbbbbbbbbabbbbbba";
    //abb bba bab abb bba abb bba bab abb bba
    string a = "bba";
    cout << count_anagrams(s, a) << endl;
    return 0;
}