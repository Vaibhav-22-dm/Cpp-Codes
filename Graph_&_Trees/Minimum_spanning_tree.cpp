#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

//Make - create an independent node
//Find - Gives parent of the group
//Union - Add groups of elements of a and b

int parent[N];
int depth[N];
multiset<int> sizes;

void make(int v){
    parent[v] = v;
    depth[v] = 1;
    sizes.insert(1);
}

int find(int v){
    if(v==parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void merge(int a, int b){
    sizes.erase(sizes.find(depth[a]));
    sizes.erase(sizes.find(depth[b]));

    sizes.insert(depth[a]+depth[b]);
}   

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by size
        if(depth[a]<depth[b]) swap(a,b);
        parent[b] = a;
        merge(a,b);
        depth[a] += depth[b];
    } 
    return;   
}

// Time complexity - O(alpha(n))
// aplha(n) is Reverse Ackerman function (amortized)
// for any reasonable n, alpha(n) doesn't go beyond 4

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
    }
    sort(edges.begin(), edges.end());
    for(int i=1;i<=n;i++) make(i);
    int total_cost = 0;
    for(auto &edge : edges){
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost += wt;
        cout << u << " " <<  v << endl;
    }
    cout << total_cost << endl;
    return 0;
}