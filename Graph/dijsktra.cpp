#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

vector<vector<pair<int,int>>> g;
vector<int> dis;
vector<int> vis;
int n,m;

void dijkstra(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);

    priority_queue<pair<int,int>> pq;
    dis[sc] = 0;
    pq.push({-0,sc});

    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();

        int cur_node = x.second;
        int cur_weight = -x.first;

        if(vis[cur_node]==1){
            continue;
        }else{
            vis[cur_node] = 1;
        }

        for(auto v:g[cur_node]){
            int neigh = v.first;
            int weight = v.second;
            if(dis[neigh]>dis[cur_node]+weight){
                dis[neigh] = dis[cur_node]+weight;
                pq.push({-dis[neigh],neigh});
            }
        }
    }
}

void solve(){
   cin>>n>>m;
   g.clear();
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    g[a].push_back({b,w});
    g[b].push_back({a,w});
   }

   int sc;
   cin>>sc;
   dijkstra(sc);

    
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