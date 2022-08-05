// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


string removeConsecutiveCharacter(string S){
    if(S.size()==1) return S;
    char c = S[S.size()-1]; 
    cout << "c: " << c << endl;
    S.erase(S.begin()+S.size()-1);
    string A = removeConsecutiveCharacter(S);
    char b = A[A.size()-1];
    if(b==c) return A;
    else {
        cout << "A+c: " << A+c << endl;
        return A + c;
    }
}

int main() 
{ 
    string s;
    cin>>s;
    cout<<removeConsecutiveCharacter(s)<<endl;
} 



  // } Driver Code Ends