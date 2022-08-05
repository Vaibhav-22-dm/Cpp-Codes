#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<int> g[N];
int h[N];
int d[N];

void dfs(int vertex, int par){
    cout << vertex << " ";
    for(auto child:g[vertex]){
        if(child==par) continue;
        d[child] = d[vertex] + 1;
        dfs(child,vertex);
        h[vertex] = max(h[vertex],h[child]+1);
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

    dfs(0,0);
    cout << endl;
    for(int i=0;i<n;i++) cout << "i: " << i << " h: " << h[i] << " d: " << d[i] << endl;

    return 0;
}