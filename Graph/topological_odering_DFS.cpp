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
vector<int> vis;

vector<int> topo;

void dfs(int node){
    vis[node] = 1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    topo.push_back(node);
}

void solve(){
   int n,m;
   cin>>n>>m;
   g.resize(n+1);
   for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
   }

   vis.assign(n+1,0);

   for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);
    }
   }
    
    reverse(topo.begin(),topo.end());
    for(auto v:topo){
        cout<<v<<" ";
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