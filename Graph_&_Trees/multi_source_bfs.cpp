#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int INF = 1e4+10;

int val[N][N];
int vis[N][N];
int level[N][N];
int n, m;

void reset(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vis[i][j] = 0;
            level[i][j] = INF;
        }
    }
}

vector<pair<int,int>> movements = {
    {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}
};

bool isValid(int x,int y){
    return x<m&&y<n&&x>=0&&y>=0;
}

int bfs(){
    int mx = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mx = max(mx, val[i][j]);
        }
    }
    cout << "max: " << mx << endl;
    queue<pair<int,int>>  q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mx==val[i][j]){
                q.push({i,j});
                vis[i][j] = 1;
                level[i][j] = 0;
            }
        }
    }
    cout << "Added level 0" << endl;
    while(!q.empty()){
        pair<int,int> curr_v = q.front();
        q.pop();
        int v_x = curr_v.first;
        int v_y = curr_v.second;
        cout << "v_x: " << v_x << " v_y: " << v_y << endl;
        for(auto movement:movements){
            int child_x = movement.first +v_x;
            int child_y = movement.second + v_y;
            cout << "child_x: " << child_x << " child_y: " << child_y << endl;
            if(!isValid(child_x,child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x,child_y});
            level[child_x][child_y] = level[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;
            ans = max(ans, level[child_x][child_y]);
            cout << "ans: " << ans << endl;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        reset();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> val[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << val[i][j]<< " ";
            }
            cout << endl;
        }
        cout << bfs() << endl;
    }


    return 0;
}