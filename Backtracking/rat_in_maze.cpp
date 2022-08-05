// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> m, int n, vector<string>& S, string s, int i, int j){
        if(i==n-1&&j==n-1){
          S.push_back(s);  
          cout << "Reached: " << S[S.size()-1] << endl;
        }
        else{
            int k = -1;
            if(i<n-1&&m[i+1][j]==1){
                cout << "D" << endl;
                s+="D";
                m[i+1][j] = -1;
                k=1;
                solve(m,n,S,s,i+1,j);
            }
            if(k==1){
                s.erase(s.size()-1);
                m[i+1][j] = 1;
                k=-1;
            }
            if(j<n-1&&m[i][j+1]==1){
                cout << "R" << endl;
                k=1;
                s+="R";
                m[i][j+1] = 0;
                solve(m,n,S,s,i,j+1);
            }
            if(k==1){
                s.erase(s.size()-1);
                m[i][j+1] = 1;
                k=-1;
            }
            if(j>0&&m[i][j-1]==1){
                cout << "L" << endl;
                k=1;
                s+="L";
                m[i][j-1] = -1;
                solve(m,n,S,s,i,j-1);
            }
            if(k==1){
                s.erase(s.size()-1);
                m[i][j-1] = 1;
                k=-1;
            }
            if(i>0&&m[i-1][j]==1){
                cout << "U" << endl;
                k=1;
                s+="U";
                m[i-1][j] = -1;
                solve(m,n,S,s,i-1,j);
            }
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> S;
        m[0][0] = -1;
        solve(m,n,S,"",0,0);
        return S;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends