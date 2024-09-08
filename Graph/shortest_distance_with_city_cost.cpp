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
vector<int> city_cost;
int n,m;

void dijsktra(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    
    priority_queue<pair<int,int>> pq;
    dis[sc] = city_cost[sc];
    pq.push({-dis[sc],sc});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int cur_node = cur.S;

        if(vis[cur_node]){
            continue;
        }else{
            vis[cur_node] =1;
        }

        for(auto v:g[cur_node]){
            if(dis[v.F]>dis[cur_node]+v.S+city_cost[v.F]){
                dis[v.F]=dis[cur_node]+v.S+city_cost[v.F];
                pq.push({-dis[v.F],v.F});
            }
        }
    }
}
void solve(){
   cin>>n>>m;
   g.resize(n+1);
   city_cost.resize(n+1);
   for(int i=1;i<=n;i++){
    cin>>city_cost[i];
   }

   for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    g[a].push_back({b,w});
    g[b].push_back({a,w});
   }
    int sc,en;
    cin>>sc>>en;
    dijsktra(sc);

    if(dis[en]==1e18){
        cout<<"Not reachable"<<endl;
    }else{
        cout<<dis[en]<<endl;
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