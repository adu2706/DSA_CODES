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

void zero_one_bfs(int sc){
    dis.assign(n+1,1e9);
    vis.assign(n+1,0);

    deque<int> dq;
    dis[sc] = 0;
    dq.push_front(sc);

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();

        if(vis[cur]==1){
            continue;
        }else{
            vis[cur] = 1;
        }

        for(auto v:g[cur]){
            int neigh = v.first;
            int weight = v.second;
            if(dis[neigh]>dis[cur]+weight){
                dis[neigh] = dis[cur]+weight;
                if(weight==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
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
   zero_one_bfs(sc);
    
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