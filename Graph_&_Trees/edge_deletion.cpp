#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;

vector<int> g[N];
int A[N];
int p[N];
int sum[N];

void dfs(int vertex, int par=-1){
    sum[vertex] += vertex;
    for(int child : g[vertex]){
        if(child==par) continue;
        dfs(child, vertex);
        sum[vertex] += sum[child]; 
    }
} 

int main(){
    int n, m;
    cin >> n;
    m = n;
    int s = n*(n+1)/2;
    for(int i=1;i<m;i++){
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
    int maxP = 0;
    dfs(1,0);
    for(int i=1;i<n;i++){
        maxP = max(maxP, (s-sum[i])*sum[i]);
    }
    cout << "Max Product: " << maxP << endl;
    return 0;
}