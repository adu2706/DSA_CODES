#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;
vector<vector<int>> vis,dis,wall_break;
int n,m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbours(int x,int y){
    vector<pair<int,int>> ans;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(check(nx,ny)){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}

void bfs(int x, int y){
    vis.assign(n+1,vector<int>(m+1,0));
    dis.assign(n+1,vector<int>(m+1,1e9));
    wall_break.assign(n+1,vector<int>(m+1,1e9));
    queue<pair<int,int>> q;
    dis[x][y] = 0;
    wall_break[x][y] = 0;
    q.push({x,y});

    while(!q.empty()){
        auto v = q.front();
        int i = v.F;
        int j = v.S;
        q.pop();

        if(vis[i][j]==1){
            continue;
        }else{
            vis[i][j]=1;
        }

        for(auto neigh:neighbours(i,j)){
            if(dis[neigh.F][neigh.S]>dis[i][j]+1){
                dis[neigh.F][neigh.S]=dis[i][j]+1;
                if(g[neigh.F][neigh.S]==1){
                    wall_break[neigh.F][neigh.S]=wall_break[i][j]+1;
                }else{
                    wall_break[neigh.F][neigh.S]=wall_break[i][j]+0;
                }
                q.push(neigh);
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.assign(n+1,vector<int>(m+1,0));
   pair<int,int> sc,en;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char ch;
        cin>>ch;
        if(ch == 'S'){
            sc = {i,j};
        }else if(ch == 'F'){
            en = {i,j};
        }
        if(ch=='#'){
            //wall
            g[i][j] = 1;
        }else{
            //floor
            g[i][j] = 0;
        }
    }
   }

   bfs(sc.F,sc.S);
   cout<<dis[en.F][en.S]<<endl; 
   cout<<wall_break[en.F][en.S]<<endl;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}