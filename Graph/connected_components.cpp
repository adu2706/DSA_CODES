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
vector<vector<int>> vis;
int num_node;
int n,m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool check(int x, int y){
    if(x<0 || x>=n || y<0 || y>=m || g[x][y]==1){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neighbours(int x, int y){
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

void dfs(int x, int y, int color){
    vis[x][y] = color;
    num_node++;
    for(auto v:neighbours(x,y)){
        if(!vis[v.F][v.S]){
            dfs(v.F,v.S,color);
        }
    }
}

void solve(){
   cin>>n>>m;
   g.assign(n+1,vector<int>(m+1,0));
   vis.assign(n+1,vector<int>(m+1,0));
    int color = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && g[i][j]==0){
                color++;
                num_node=0;
                dfs(i,j,color);
                mp[color] = num_node;
            }
        }
    }

    vector<vector<int>> ans;
    ans.assign(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                ans[i][j] = 1;
            }else{
                if(mp[vis[i][j]]==1){
                    ans[i][j] = g[i][j];
                }else{
                    ans[i][j] = mp[vis[i][j]];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}