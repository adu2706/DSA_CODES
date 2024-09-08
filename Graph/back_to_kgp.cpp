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
vector<int> vis,dis,num_path,minimum_flight,maximum_flight;
int n,m;
void dijkstra(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e18);
    num_path.assign(n+1,0);
    minimum_flight.assign(n+1,0);
    maximum_flight.assign(n+1,0);
    priority_queue<pair<int,int>> pq;
    dis[sc] = 0;
    minimum_flight[sc] = 0;
    maximum_flight[sc] = 0;
    num_path[sc] = 1;
    pq.push({-dis[sc],sc});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        int cur_node = cur.S;

        if(vis[cur_node]){
            continue;
        }
        vis[cur_node]=1;

        for(auto v:g[cur_node]){
            if(dis[v.F]>dis[cur_node]+v.S){
                dis[v.F]=dis[cur_node]+v.S;
                minimum_flight[v.F]=minimum_flight[cur_node]+1;
                maximum_flight[v.F]=maximum_flight[cur_node]+1;
                num_path[v.F] = num_path[cur_node]%mod;
                pq.push({-dis[v.F],v.F});
            }else if(dis[v.F]==dis[cur_node]+v.S){
                (num_path[v.F] += num_path[cur_node])%=mod;
                minimum_flight[v.F]=min(minimum_flight[v.F],minimum_flight[cur_node]+1);
                maximum_flight[v.F]=max(maximum_flight[v.F],maximum_flight[cur_node]+1);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    
    dijkstra(1);

    if(dis[n]==1e18){
        cout<<-1<<endl;
    }else{
        cout<<dis[n]<<" ";
        cout<<num_path[n]%mod<<" ";
        cout<<minimum_flight[n]<<" ";
        cout<<maximum_flight[n]<<" ";
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