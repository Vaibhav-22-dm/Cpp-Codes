#include <bits/stdc++.h>
using namespace std;
const int N =1e7+10;

vector<int> g[N];
bool vis[N];

void dfs(int vertex){
    vis[vertex] = true;
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
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
    int count = 0;
    for(int i=0;i<v;i++){
        if(vis[i]) continue;
        dfs(i);
        count++;
        cout << "i: " << i << " count: " << count << endl;
    }
    cout << "Count: " << count;
    return 0;
}