#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

vector<int> g[N];
int depth[N];

//First we find the max depth considering any node as the root node.
//Fact - The node at which we hit the max_depth will be one end of the path that will give the diameter.
//Now using the above fact, if we find the max depth considering the above found node as the root node then we will ge the length of diameter of the tree.

void dfs(int vertex, int par=-1){
    for(auto child : g[vertex]){
        if(child==par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
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
    for(int i=0;i<n;i++){
        cout << i << ": ";
        for(auto j:g[i]) cout << j << " ";
        cout << endl;
    }
    dfs(0);

    int mx_depth = -1;
    int mx_d_node;
    for(int i=0; i<n; i++){
        if(mx_depth<depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(mx_d_node);
    mx_depth = -1;
    for(int i=0; i<n; i++){
        if(mx_depth<depth[i]) mx_depth = depth[i];
    }

    cout << "Diameter: " << mx_depth << endl;   

    return 0;
}