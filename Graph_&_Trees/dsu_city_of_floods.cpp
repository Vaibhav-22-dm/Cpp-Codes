#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

//Make - create an independent node
//Find - Gives parent of the group
//Union - Add groups of elements of a and b

int parent[N];
int depth[N];

void make(int v){
    parent[v] = v;
    depth[v] = 1;
}

int find(int v){
    if(v==parent[v]) return v;
    // Path compression
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        // Union by size
        if(depth[a]<depth[b]) swap(a,b);
        parent[b] = a;
        depth[a] += depth[b];
    } 
    return;   
}

// Time complexity - O(alpha(n))
// aplha(n) is Reverse Ackerman function (amortized)
// for any reasonable n, alpha(n) doesn't go beyond 4

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        make(i);
    }
    while(k--){
        int u, v;
        cin >> u >> v;
        Union(u,v);
    }

    int connected_ct = 0;
    for(int i=1; i<=n;i++){
        if(find(i)==i) connected_ct++;
    }
    cout << connected_ct << endl;

    return 0;
}