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
vector<vector<int>> vis,dis;

int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]==0){
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

void bfs(queue<pair<int,int>> virus){
    dis.assign(n,vector<int>(m,1e9));
    vis.assign(n,vector<int>(m,0));

    queue<pair<int,int>> q;

    while(!virus.empty()){
        auto cur = virus.front();
        virus.pop();
        dis[cur.F][cur.S] = 0;
        q.push(cur);
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(vis[cur.F][cur.S]==1){
            continue;
        }else{
            vis[cur.F][cur.S]=1;
        }

        for(auto neigh:neighbours(cur.F,cur.S)){
            if(dis[neigh.F][neigh.S]>dis[cur.F][cur.S]+1){
                dis[neigh.F][neigh.S]=dis[cur.F][cur.S]+1;
                q.push(neigh);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    g.clear();
    g.assign(n,vector<int>(m,0));
    queue<pair<int,int>> virus;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==2){
                virus.push({i,j});
            }
        }
    }

    bfs(virus);

    int maxdis=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                maxdis = max(maxdis,dis[i][j]);
            }
        }
    }

    if(maxdis==1e9){
        maxdis = -1;
    }
    cout<<maxdis<<endl;

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