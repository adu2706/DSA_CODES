#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 1e9
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<int>> g;

vector<int> dis;
vector<int> vis;
int n,m;

void bfs(int sc){
    dis.assign(n+1,INF);
    vis.assign(n+1,0);

    queue<int> q;
    dis[sc] = 0;
    q.push(sc);

    while(!q.empty()){
        int cur = q.front(); 
        q.pop(); 

        if(vis[cur]==1){
            continue;
        }
        vis[cur] = 1;

        for(auto neigh:g[cur]){
            if(dis[neigh]>dis[cur]+1){
                dis[neigh] = dis[cur]+1;
                q.push(neigh);
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.clear();
   g.resize(n+1);
   for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     g[b].push_back(a);
   }

   int sc;
   cin>>sc;
   bfs(sc);
    
   for(int i = 1; i <= n; i++) {
       cout << "Distance from " << sc << " to " << i << " is " << dis[i] << "\n";
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
