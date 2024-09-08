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
    if(x<0 || x>=n || y<0 || y>=m){
        return 0;
    }
    return 1;
}

vector<pair<int,int>> neigh(int x, int y){
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

void bfs(queue<pair<int,int>> supernode){
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,1e18));

    queue<pair<int,int>> q;

    while(!supernode.empty()){
        auto cur = supernode.front();
        supernode.pop();
        dis[cur.F][cur.S]=0;
        q.push(cur);
    }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();

        if(vis[cur.F][cur.S]){
            continue;
        }
        vis[cur.F][cur.S] = 1;

        for(auto v:neigh(cur.F,cur.S)){
            if(dis[v.F][v.S]>dis[cur.F][cur.S]+1){
                dis[v.F][v.S]=dis[cur.F][cur.S]+1;
                q.push(v);
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.assign(n,vector<int>(m,0));
   queue<pair<int,int>> q;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>g[i][j];
        if(g[i][j]==1){
            q.push({i,j});
        }
    }
   }

   bfs(q);

   int x=-1;
   int y=-1;

   int maxi_dist = 0;

   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(g[i][j]==0){
            if(maxi_dist<dis[i][j]){
                maxi_dist = dis[i][j];
                x = i;
                y = j;
            }
        }
    }
   }

   if(x!=-1 && y!=-1){
    cout<<maxi_dist<<endl;
    cout<<x<<" "<<y<<endl;
   }else{
    cout<<"No zeros available"<<endl;
   }


    
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