#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,k;
vector<vector<int>> g;
vector<vector<int>> vis;
int comp_sz;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<10){
        return 1;
    }
    return 0;
}

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
    vis[x][y]=1;
    comp_sz++;
    for(auto neigh:neighbour(x,y)){
        if(vis[neigh.F][neigh.S]==0 && g[neigh.F][neigh.S]==color){
            dfs(neigh.F,neigh.S,color);
        }
    }
}

void deletion(int x, int y, int color){
    g[x][y] = 0;
    for(auto neigh:neighbour(x,y)){
        if(g[neigh.F][neigh.S]==color){
            deletion(neigh.F,neigh.S,color);
        }
    }
}

void gravity(){
    for(int j=0;j<10;j++){
        int p = n-1;
        for(int i=n-1;i>=0;i--){
            if(g[i][j]!=0){
                swap(g[i][j],g[p][j]);
                p--;
            }
        }
    }
}

void solve(){
   cin>>n>>k;
   g.resize(n);
   for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
        char ch;
        cin>>ch;
        g[i].push_back(ch-'0');
    }
   }

   vis.assign(n,vector<int>(10,0));

   bool flag = true;
   
   while(flag){
    flag = false;
    vis.assign(n,vector<int>(10,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            if(vis[i][j]==0 && g[i][j]!=0){
                comp_sz=0;
                dfs(i,j,g[i][j]);
                if(comp_sz>=k){
                    deletion(i,j,g[i][j]);
                    flag = true;
                }
            }
        }
    }
    gravity();
   }
    
   for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
        cout<<g[i][j];
    }
    cout<<endl;
   }
    cout<<endl;
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