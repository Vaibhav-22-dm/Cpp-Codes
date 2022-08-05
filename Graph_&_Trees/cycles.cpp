#include <bits/stdc++.h>
using namespace std;
const int N =1e7+10;

vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExists = false;
    for(int child : g[vertex]){
        if(vis[child] && child==par) continue;
        if(vis[child]) return true;
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
}


int main(){
    int v, e;
    cin >> v >> e;
    for(int i=0;i<e; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    bool isLoopExists = false;
    for(int i=0;i<v;i++){
        if(vis[i]) continue;
        if(dfs(i,0)){
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists;
    return 0;
}