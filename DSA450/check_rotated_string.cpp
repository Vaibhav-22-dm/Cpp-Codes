#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal);
bool isScramble(string s1, string s2);

int main(){
    string s = "abcde";
    string goal = "caebd";
    cout << isScramble(s, goal);
    return 0;
}

bool rotateString(string s, string goal) {
        // vector<char> s_copy, goal_copy;
        // for(int i = 0; i < s.length(); i++){
        //     s_copy[i] = s[i];
        //     goal_copy[i] = goal[i];
        // }
        for(int i = 0; i < s.length(); i++){
            rotate(s.begin(), s.begin() + 1, s.end());
            cout << s << endl;
            if(s==goal) return true;
        }
        return false;
    }

bool isScramble(string s1, string s2) {
    vector<int> all_chars_1(26,0), all_chars_2(26, 0);
    if(s1.length() == 1) return true;
    for(int i = 0; i < s1.length(); i++){
        all_chars_1[s1[i]-'a']++;
        all_chars_2[s2[i]-'a']++;
    }
    for(int i = 0; i < 26; i++) cout << all_chars_1[i] << " ";
    cout << endl;
    for(int i = 0; i < 26; i++) cout << all_chars_2[i] << " ";
    cout << endl;
    for(int i = 0; i < 26; i++){
        if(all_chars_1[i]!=all_chars_2[i]) return false;
    }
    return true;
    
}