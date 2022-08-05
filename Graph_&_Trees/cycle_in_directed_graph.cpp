#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int vertex, vector<int> g[], bool vis[], bool dfsVis[]){
    vis[vertex] = true;
    dfsVis[vertex] = true;
    for(int i:g[vertex]){
        if(!vis[i]){
            if(checkCycle(i,g,vis,dfsVis)) return true;
        }
        else if(dfsVis[i]) return true;
    }
    dfsVis[vertex] = false;
    return false;
}

bool isCyclic(vector<int> g[], int n){
    bool vis[n+1];
    bool dfsVis[n+1];
    memset(vis,false,sizeof(vis));
    memset(dfsVis,false,sizeof(dfsVis));

    for(int i=0;i<n+1;i++){
        if(vis[i]) continue;
        if(checkCycle(i,g,vis,dfsVis)) return true;
    }
    return false;
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
    cout << isCyclic(g,n) << endl;
    return 0;
}










