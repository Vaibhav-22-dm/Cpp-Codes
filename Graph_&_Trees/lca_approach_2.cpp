#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

vector<int> g[N];
int p[N];

void dfs(int vertex, int par=-1){
    p[vertex] = par;
    for(int child : g[vertex]){
        if(child == par) continue;
        dfs(child, vertex);
    }
}

vector<int> path(int vertex){
    vector<int> ans;
    while(vertex != -1){
        ans.push_back(vertex);
        vertex = p[vertex];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    int x, y;
    cin >> x >> y;
    
    dfs(0);
    for(int i=0;i<n;i++) cout << p[i] << " ";
    cout << endl;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    
    for(auto child : path_x) cout << child << " ";
    cout << endl;
    for(auto child : path_y) cout << child << " ";
    cout << endl;

    int l = min(path_x.size(),path_y.size());
    int i = 0;
    
    while(i<l){
        if(path_x[i]!=path_y[i]) break;
        i++;
    }
    cout << "Least Common Ancestor: " << path_x[i-1] << endl;


    return 0;
}