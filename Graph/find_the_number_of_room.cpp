#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> vis;
vector<vector<int>> g;
int n,m;
bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]==0){
        return 1;
    }
    return 0;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<pair<int,int>> neighbour(int x, int y){
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
    for(auto v:neighbour(x,y)){
        int i = v.first;
        int j = v.second;
        if(!vis[i][j]){
            dfs(i,j,color);
        }
    }
}
void solve(){
   cin>>n>>m;
   
   g = vector<vector<int>>(n+1,vector<int>(m+1,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        char ch;
        cin>>ch;
        if(ch=='#'){
            g[i][j] = 1;
        }
    }
   }
   vis = vector<vector<int>> (n+1,vector<int>(m+1,0));
   int color = 0;
   
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && g[i][j]==0){
            color++;
            dfs(i,j,color);
        }
    }
   }

   cout<<color<<endl;
    
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