#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

vector<int> g[N];
bool vis[N];
bool vis1[N];
int level[N];

void bfs(int vertex, queue<int>& q){
    cout << vertex << " ";
    vis[vertex] = true;
    if(q.size()) q.pop();
    for(int child:g[vertex]){
        if(vis[child]) continue;
        q.push(child);
    }
    while(q.size()){
        bfs(q.front(), q);
    }
}

void bfs1(int source){
    queue<int> q;
    q.push(source);
    vis1[source] = true;
    while(!q.empty()){
        int cur_v = q.front();
        cout << cur_v << " ";
        q.pop();
        for(int child : g[cur_v]){
            if(!vis1[child]){
                q.push(child);
                vis1[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
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

    queue<int> q;
    bfs(0,q);
    cout << endl;
    bfs1(0);
    cout << endl;
    for(int i=0;i<n;i++) cout << level[i] << " ";

    return 0;
}