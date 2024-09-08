#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
#define INF 10000
int mod = 1e9+7;
typedef pair<int, int> pii;
typedef pair<long, long> pll;

int n,m;
vector<vector<pair<int,int>>> g;
vector<int> dis,vis;

void dijsktra(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);

    priority_queue<pair<int,int>> pq;
    dis[sc] = 0;
    pq.push({-0,sc});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int node = cur.S;

        if(vis[node]){
            continue;
        }else{
            vis[node]=1;
        }

        for(auto v:g[node]){
            if(dis[v.F]>dis[node]+v.S){
                dis[v.F]=dis[node]+v.S;
                pq.push({-dis[v.F],v.F});
            }
        }

    }
}

void solve(){
   cin>>n>>m;
   g.resize(n+1);
   vector<pair<pair<int,int>,int>> edges;
   for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    edges.push_back({{a,b},w});
    g[a].push_back({b,w});
    g[b].push_back({a,w});
   }
    int sc;
    cin>>sc;
   dijsktra(sc);

   int time = 0;

   //time to burn rope between node 'a' and node 'b' is
   //dis[a] is time to fire come at node 'a' similary dis[b] is time  to fire come at node 'b'
    // time to burn rope between node a and node b is ((dis[a]+dis[b]+w)/2)
    //w is length of rope between node 'a' and node 'b'
   for(auto v:edges){
    int temp =(dis[v.F.F]+dis[v.F.S]+v.S)*5;
    time = max(time,temp);
   }

    cout<<time<<endl;
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