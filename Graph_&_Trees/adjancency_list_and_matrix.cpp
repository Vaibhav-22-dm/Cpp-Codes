#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int graph1[N][N]; //Global variables are always initialized as zero
vector<int> graph2[N];
int graph3[N][N];
vector<pair<int,int> > graph4[N];

int main(){
    //There are two ways of representing a graph -
    //1. Adjacency Matrix - has O(V*V) space complexity were V = #vertices.
    //Maximum continous memory allocation limit is around 10^6 or 10^7, so we can't make arrays with size 10^6 or 10^7.
    //That's why we use a more space efficient way to store graphs.
    //2. Adjacency List - has O(V+E) where E=#edges < V*V for all V.
    //Time complexity for finding edge between two vertices is O(V) while in case of adjacency matrix it is O(1).

    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph1[v1][v2] = 1; //graph[i][j] denotes whether there is an edge between i and j
        graph1[v2][v1] = 1; //graph[i][j] = graph[j][i] = 1 for undirected unweighted graph
        graph2[v1].push_back(v2); //graph[i] vector contains all the vertices that are linked to v1
        graph2[v2].push_back(v1);
        graph3[v1][v2] = wt;
        graph3[v2][v1] = wt;
        graph4[v1].push_back({v2,wt}); //graph[i] vector contains all the vertices that are linked to v1
        graph4[v2].push_back({v1,wt});
    }

    for(int i=0; i<=n; i++){
        cout << i << ": ";
        for(auto j:graph2[i]) cout << j << " ";
        cout << endl;
    }

    return 0;
}