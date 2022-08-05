#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;

vector<int> g[N];

bool dfs(int vertex, int par, vector<int>& p, int x){
    p.push_back(vertex);
    if(x==vertex) return true;
    bool isFound = false;
    for(int child:g[vertex]){
        if(child==par) continue;
        isFound |= dfs(child, vertex, p, x);
    }
    if(!isFound) p.pop_back();
    return isFound;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for(int i=0;i<n;i++){
        cout << i << ": ";
        for(auto j:g[i]) cout << j << " ";
        cout << endl;
    }



    int x, y;
    cin >> x >> y;
    vector<int> a, b;
    if(dfs(0,0,a,x)&&dfs(0,0,b,y)){
        for(int child : a) cout << child << " ";
        cout << endl;
        for(auto child : b) cout << child << " ";
    }    
    int i = 0;
    while(i<a.size()){
        if(a[i]!=b[i]) break;
        i++;
    }
    cout << "\nLeast Common Ancestor: " << a[i-1] << endl;

    return 0;
}