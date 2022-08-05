#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[], int vertex, vector<bool>& vis, stack<int>& topsort){
    vis[vertex] = true;
    for(int i:g[vertex]){
        if(vis[i]) continue;
        dfs(g,i,vis,topsort);
    }
    topsort.push(vertex);
}


int main(){
    int n, m;
    cin>>n>>m;
    vector<int> g[n+1];
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }
    stack<int> topsort;
    vector<bool> vis(n+1,false);
    for(int i=0;i<n+1;i++){
        if(vis[i]) continue;
        dfs(g,i,vis,topsort);
    }
    vector<int> ans;
    while(topsort.size()){
        ans.push_back(topsort.top());
        topsort.pop();
    }
    for(int i:ans) cout << i << " ";
    cout << endl;
    return 0;
}