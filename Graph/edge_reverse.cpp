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
vector<int> vis;
vector<int> dis;
int n,m;

void bfs01(int sc){
    vis.assign(n+1,0);
    dis.assign(n+1,1e9);

    deque<int> dq;
    dis[sc] = 0;
    dq.push_back(sc);

    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();

        if(vis[cur]){
            continue;
        }else{
            vis[cur] = 1;
        }

        for(auto v:g[cur]){
            int neigh = v.F;
            int weight = v.S;
            if(dis[neigh]>dis[cur]+weight){
                dis[neigh]=dis[cur]+weight;
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
    int a,b;
    cin>>a>>b;
    g[a].push_back({b,0});
    g[b].push_back({a,1});
   }

   bfs01(1);
   if(dis[n]==1e9){
    dis[n] = -1;
   }

   cout<<dis[n]<<endl;
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