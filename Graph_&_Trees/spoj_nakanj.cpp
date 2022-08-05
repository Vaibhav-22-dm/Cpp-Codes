#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
const int INF = -1;

bool vis[8][8];
int level[8][8];

int getX(string s){
    return s[0] - 'a';
}

int getY(string s){
    return s[1]-'1';
}

vector<pair<int,int>> movements = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{1,2},{-1,-2}};

bool isValid(int X, int Y){
    return X>=0 && Y>=0 && X<8 && Y<8;
}

void bfs(string s, string d){
    int X = getX(s);
    int Y = getY(s);
    // cout << X << Y << endl;
    queue<pair<int,int>> q;
    q.push({X,Y});
    vis[X][Y] = true;
    level[X][Y] = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        // cout << x << y << endl;
        for(auto child : movements){
            if(!isValid(x+child.first,y+child.second)) continue;
            if(vis[x+child.first][y+child.second]) continue;
            q.push({x+child.first,y+child.second});
            level[x+child.first][y+child.second] = level[x][y] + 1;
            vis[x+child.first][y+child.second] = true;
        }
        if(level[getX(d)][getY(d)]!=INF) return; 
    }  
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            level[i][j] = INF;
            vis[i][j] = false;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s, d;
        cin >> s >> d;
        reset();
        bfs(s,d);
        cout << level[getX(d)][getY(d)] << endl;
    }
    return 0;
}