#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<int> g[N];
int s[N];
int cE[N];

void dfs(int vertex, int par){
    s[vertex]=vertex;
    if(vertex%2==0) cE[vertex]=1;
    for(auto child:g[vertex]){
        if(child==par) continue;
        dfs(child,vertex);
        s[vertex] += s[child]; 
        cE[vertex] += cE[child];
    }
    return;
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
    int sum = 0;
    dfs(0,0);
    for(int i=0;i<n;i++) cout << "s[" << i << "]: " << s[i] << " Even Numbers: " << cE[i] << endl;
    
    return 0;
}