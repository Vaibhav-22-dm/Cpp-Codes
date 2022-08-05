#include <bits/stdc++.h>
using namespace std;

//Kahn's Algorithm -

void bfs(vector<int> g[], int n, vector<int>& topo){
    queue<int> q;
    vector<int> indegree(n+1,0);
    for(int i=0;i<=n;i++){
        for(int j:g[i]) indegree[j]++;
    }

    for(int i=0;i<=n;i++) if(!indegree[i]) q.push(i);

    while(q.size()){
        int curr_v = q.front();
        q.pop();
        topo.push_back(curr_v);
        for(int i:g[curr_v]){
            indegree[i]--;
            if(!indegree[i]) q.push(i);
        }
    }
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
    vector<int> topo;
    bfs(g,n,topo);

    for(int i:topo) cout << i << " ";
    cout << endl;

    return 0;
}